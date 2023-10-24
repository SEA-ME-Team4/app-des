#include "racerclient.h"

RacerClient::RacerClient() {
    gear=0;
    brake=true;
    steering=0;
    throttle=0;

    runtime = CommonAPI::Runtime::get();

    gearService = std::make_shared<GearStatusStubImpl>();
    gearServiceInit();

    gearselectorProxy = runtime->buildProxy<GearSelectorProxy>("local", "GearSelector", "Racer_GearSelector_Proxy");
    gearselectorProxyInit();

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "Racer_Brake_Proxy");
    brakeProxyInit();

    maneuverProxy = runtime->buildProxy<ManeuverProxy>("local", "Maneuver", "Racer_Maneuver_Proxy");
    maneuverProxyInit();
}

RacerClient::~RacerClient() {
}

void RacerClient::setGear(uint8_t gear) {
    this->gear = gear;
    gearService->setGearAttribute(gear);
}

void RacerClient::gearServiceInit() {
    while (!runtime->registerService("local", "GearStatus", gearService, "Racer_Gear_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Gear Service!" << std::endl;
    gearService->setGearAttribute(gear);
}

void RacerClient::gearselectorProxyInit() {
    std::cout << "Checking GearSelector availability!" << std::endl;
    while (!gearselectorProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    
    gearselectorProxy->getGearSelectEvent().subscribe([&](const uint8_t& gear) {
        this->setGear(gear);
    });
}

void RacerClient::brakeProxyInit() {
    std::cout << "Checking Brake availability!" << std::endl;
    while (!brakeProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    brakeProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        this->brake = brake;
    });
}

void RacerClient::maneuverProxyInit() {
    std::cout << "Checking Maneuver availability!" << std::endl;
    while (!maneuverProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    maneuverProxy->getSteeringAttribute().getChangedEvent().subscribe([&](const float& steering) {
        this->steering = steering;
    });
    maneuverProxy->getThrottleAttribute().getChangedEvent().subscribe([&](const float& throttle) {
        this->throttle = throttle;
    });
}

int RacerClient::getGear() {
    return gear;
}
bool RacerClient::getBrake() {
    return brake;
}
float RacerClient::getSteering() {
    return steering;
}
float RacerClient::getThrottle() {
    return throttle;
}

bool RacerClient::validCheck() {
    if (!brakeProxy->isAvailable() && !maneuverProxy->isAvailable()) {
        return false;
    }
    if (!gearselectorProxy->isAvailable()) {
        return false;
    }
    return true;
}
#include "racerclient.h"

RacerClient::RacerClient() {
    runtime = CommonAPI::Runtime::get();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "Racer_Gear_Proxy");
    gearProxyInit();

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "Racer_Brake_Proxy");
    brakeProxyInit();

    maneuverProxy = runtime->buildProxy<ManeuverProxy>("local", "Maneuver", "Racer_Maneuver_Proxy");
    maneuverProxyInit();

    statusService = std::make_shared<RacerStubImpl>();
    statusServiceInit();
}

RacerClient::~RacerClient() {
}

void RacerClient::gearProxyInit() {
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        this->gear = gear;
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

void RacerClient::statusServiceInit() {
    while (!runtime->registerService("local", "Racer", statusService, "Racer_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
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
    if (!gearProxy->isAvailable()) {
        return false;
    }
    return true;
}

void RacerClient::statusUpdate() {
    statusService->fireRacerStatusEventEvent(true);
}
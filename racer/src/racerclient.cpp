#include "racerclient.h"

RacerClient::RacerClient() {
    gear=0;
    brake=true;
    steering=0;
    throttle=0;

    runtime = CommonAPI::Runtime::get();

    gearService = std::make_shared<GearStatusStubImpl>();
    gearServiceInit();

    inputProxy = runtime->buildProxy<InputStatusProxy>("local", "InputStatus", "Racer_Input_Proxy");
    inputProxyInit();
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

void RacerClient::inputProxyInit() {
    std::cout << "Checking Input availability!" << std::endl;
    while (!inputProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    inputProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        this->brake = brake;
    });

    inputProxy->getSteeringAttribute().getChangedEvent().subscribe([&](const float& steering) {
        this->steering = steering;
    });
    inputProxy->getThrottleAttribute().getChangedEvent().subscribe([&](const float& throttle) {
        this->throttle = throttle;
    });

    inputProxy->getGearSelectEvent().subscribe([&](const uint8_t& gear) {
        this->setGear(gear);
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
    if (!(inputProxy->isAvailable())) {return false;}
    return true;
}
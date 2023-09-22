#include "racerclient.h"

RacerClient::RacerClient() {
    runtime = CommonAPI::Runtime::get();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "Racer_Gear_Client");
    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "Racer_Brake_Client");
    maneuverProxy = runtime->buildProxy<ManeuverProxy>("local", "Maneuver", "Racer_Maneuver_Client");
    statusService = std::make_shared<ToHandlerStubDefault>();

    gearClient();
    brakeClient();
    maneuverClient();
    statusServer();
}

RacerClient::~RacerClient() {
}

void RacerClient::gearClient() {
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;
    uint8_t value = 0;
    CommonAPI::CallInfo info(6000);
    gearProxy->getGearAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Gear failed!\n";
    }
    std::cout << "Got Gear: " << (int)value << std::endl;

    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        this->gear = gear;
    });
}

void RacerClient::brakeClient() {
    std::cout << "Checking Brake availability!" << std::endl;
    while (!brakeProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    
    CommonAPI::CallStatus callStatus;
    bool value = 0;
    CommonAPI::CallInfo info(7000);
    brakeProxy->getBrakeAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Brake failed!\n";
    }
    std::cout << "Got Brake: " << (int)value << std::endl;

    brakeProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        this->brake = brake;
    });
}

void RacerClient::maneuverClient() {
    std::cout << "Checking Maneuver availability!" << std::endl;
    while (!maneuverProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    
    CommonAPI::CallStatus callStatus1;
    float value1 = 0;
    CommonAPI::CallInfo info(8000);
    maneuverProxy->getSteeringAttribute().getValue(callStatus1, value1, &info);
    if (callStatus1 != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Maneuver_Steering failed!\n";
    }
    std::cout << "Got Steering: " << value1 << std::endl;

    CommonAPI::CallStatus callStatus2;
    float value2 = 0;
    maneuverProxy->getThrottleAttribute().getValue(callStatus2, value2, &info);
    if (callStatus2 != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Maneuver_Throttle failed!\n";
    }
    std::cout << "Got Throttle: " << value2 << std::endl;

    maneuverProxy->getSteeringAttribute().getChangedEvent().subscribe([&](const float& steering) {
        this->steering = steering;
    });

    maneuverProxy->getThrottleAttribute().getChangedEvent().subscribe([&](const float& throttle) {
        this->throttle = throttle;
    });
}

void RacerClient::statusServer() {
    while (!runtime->registerService("local", "ToHandler", statusService, "Racer_Status_Service")) {
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
    statusService->fireStatusEventEvent(project_name);
}
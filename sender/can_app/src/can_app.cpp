#include "can_app.h"

Can_App::Can_App() {
    runtime = CommonAPI::Runtime::get();

    speedService = std::make_shared<SpeedStatusStubImpl>();
    speedServiceInit();

    distanceService = std::make_shared<DistanceStatusStubImpl>();
    distanceServiceInit();
}

Can_App::~Can_App() {
}

void Can_App::speedServiceInit() {
    while (!runtime->registerService("local", "SpeedStatus", speedService, "Speed_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Speed Service!" << std::endl;
}

void Can_App::distanceServiceInit() {
    while (!runtime->registerService("local", "DistanceStatus", distanceService, "Distance_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Distance Service!" << std::endl;
}

void Can_App::setSpeed(int16_t speed) {
    speedService->setSpeedAttribute(speed);
}

void Can_App::setDistance(uint8_t distance) {
    distanceService->setDistanceAttribute(distance);
}
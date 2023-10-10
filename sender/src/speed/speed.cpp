#include "speed.h"

Speed::Speed() {
    runtime = CommonAPI::Runtime::get();

    speedService = std::make_shared<SpeedStatusStubImpl>();
    speedServiceInit();
    
    statusService = std::make_shared<SpeedToHandlerStubDefault>();
    statusServiceInit();
}

Speed::~Speed() {
}

void Speed::speedServiceInit() {
    while (!runtime->registerService("local", "SpeedStatus", speedService, "Speed_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Speed Service!" << std::endl;

}

void Speed::statusServiceInit() {
    while (!runtime->registerService("local", "SpeedToHandler", statusService, "Speed_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
}

void Speed::setSpeed(int16_t speed) {
    speedService->setSpeedAttribute(speed);
    statusService->fireSpeedStatusEventEvent(true);
}
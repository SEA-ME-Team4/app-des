#include "input.h"

Input::Input() {
    runtime = CommonAPI::Runtime::get();

    brakeService = std::make_shared<BrakeStatusStubImpl>();
    brakeServiceInit();

    maneuverService = std::make_shared<ManeuverStubImpl>();
    maneuverServiceInit();

    statusService = std::make_shared<InputToHandlerStubDefault>();
    statusServiceInit();
}

Input::~Input() {
}

void Input::brakeServiceInit() {
    while (!runtime->registerService("local", "BrakeStatus", brakeService, "Input_Brake_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Brake Service!" << std::endl;
}

void Input::maneuverServiceInit() {
    while (!runtime->registerService("local", "Maneuver", maneuverService, "Input_Maneuver_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Maneuver Service!" << std::endl;
}

void Input::statusServiceInit() {
    while (!runtime->registerService("local", "InputToHandler", statusService, "Input_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
}

void Input::setBrake(bool brake) {
    brakeService->setBrakeAttribute(brake);
}

void Input::setSteering(float steering) {
    maneuverService->setSteeringAttribute(steering);
}

void Input::setThrottle(float throttle) {
    maneuverService->setThrottleAttribute(throttle);
}

void Input::setStatusEvent(bool status) {
    statusService->fireInputStatusEventEvent(status);
}
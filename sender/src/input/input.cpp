#include "gamepad.h"
#include "BrakeStatusStubImpl.hpp"
#include "ManeuverStubImpl.hpp"
#include <v1/commonapi/ToHandlerStubDefault.hpp>

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

#define project_name "input"

using namespace v1::commonapi;

int main() {
    float steering;
    float throttle;

    Gamepad gamepad = Gamepad();

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BrakeStatusStubImpl> brakeService;
    std::shared_ptr<ManeuverStubImpl> maneuverService;
    std::shared_ptr<ToHandlerStubDefault> statusService;

    runtime = CommonAPI::Runtime::get();

    brakeService = std::make_shared<BrakeStatusStubImpl>();
    while (!runtime->registerService("local", "BrakeStatus", brakeService, "Input_Brake_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Brake Service!" << std::endl;
    
    maneuverService = std::make_shared<ManeuverStubImpl>();
    while (!runtime->registerService("local", "Maneuver", maneuverService, "Input_Maneuver_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Maneuver Service!" << std::endl;

    statusService = std::make_shared<ToHandlerStubDefault>();
    while (!runtime->registerService("local", "ToHandler", statusService, "Input_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    while (gamepad.read_data()) {
        brakeService->setBrakeAttribute(gamepad.getBrake());
        maneuverService->setSteeringAttribute(gamepad.getSteering());
        maneuverService->setThrottleAttribute(gamepad.getThrottle());

        std::cout<<"getBrake: "<<gamepad.getBrake()<<'\n';
        std::cout<<"getSteering: "<<gamepad.getSteering()<<'\n';
        std::cout<<"getThrottle: "<<gamepad.getThrottle()<<'\n'<<std::endl;
        
        statusService->fireStatusEventEvent(project_name);
    }
}
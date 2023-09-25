#include "gamepad.h"
#include "BrakeStatusStubImpl.hpp"
#include "ManeuverStubImpl.hpp"
#include <v1/commonapi/InputToHandlerStubDefault.hpp>

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

using namespace v1::commonapi;

int main() {
    float steering;
    float throttle;

    Gamepad gamepad = Gamepad();

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BrakeStatusStubImpl> brakeService;
    std::shared_ptr<ManeuverStubImpl> maneuverService;
    std::shared_ptr<InputToHandlerStubDefault> statusService;

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

    statusService = std::make_shared<InputToHandlerStubDefault>();
    while (!runtime->registerService("local", "InputToHandler", statusService, "Input_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    if (gamepad.isOkay()) {
        while (gamepad.read_data()) {
            brakeService->setBrakeAttribute(gamepad.getBrake());
            maneuverService->setSteeringAttribute(gamepad.getSteering());
            maneuverService->setThrottleAttribute(gamepad.getThrottle());

            std::cout<<"getBrake: "<<gamepad.getBrake()<<'\n';
            std::cout<<"getSteering: "<<gamepad.getSteering()<<'\n';
            std::cout<<"getThrottle: "<<gamepad.getThrottle()<<'\n'<<std::endl;
            
            statusService->fireInputStatusEventEvent(true);
        }
        std::cout<<"\nReturn: Gamepad Connection Lost\n"<<std::endl;
        brakeService->setBrakeAttribute(true);
        maneuverService->setSteeringAttribute(0);
        maneuverService->setThrottleAttribute(0);
    }
    else {
        std::cout<<"\nReturn: Gamepad is Not Connected\n"<<std::endl;
    }
    return 0;
}
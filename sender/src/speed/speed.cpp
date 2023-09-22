#include "canreceiver.h"
#include "SpeedStatusStubImpl.hpp"
#include <v1/commonapi/ToHandlerStubDefault.hpp>

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <unistd.h>

#define project_name "speed"

using namespace v1::commonapi;

int main() {
    // Arduino Speed Sender ID: 0x0F6
    CanReceiver canreceiver = CanReceiver("vcan0", 0x0F6); 
    int16_t speed = 0;

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusStubImpl> speedService;
    std::shared_ptr<ToHandlerStubDefault> statusService;

    runtime = CommonAPI::Runtime::get();

    speedService = std::make_shared<SpeedStatusStubImpl>();
    while (!runtime->registerService("local", "SpeedStatus", speedService, "Speed_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Speed Service!" << std::endl;
    
    statusService = std::make_shared<ToHandlerStubDefault>();
    while (!runtime->registerService("local", "ToHandler", statusService, "Speed_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    while (canreceiver.canRead())
    {
        speed = canreceiver.getSpeed();
        speedService->setSpeedAttribute(speed);

        statusService->fireStatusEventEvent(project_name);
    }
    
}
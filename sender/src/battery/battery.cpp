#include "piracer.h"
#include "BatteryStatusStubImpl.hpp"
#include <v1/commonapi/ToHandlerStubDefault.hpp>

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

#define project_name "battery"

using namespace v1::commonapi;

int main() {
    Piracer piracer = Piracer();
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStatusStubImpl> batteryService;
    std::shared_ptr<ToHandlerStubDefault> statusService;

    runtime = CommonAPI::Runtime::get();

    batteryService = std::make_shared<BatteryStatusStubImpl>();
    while (!runtime->registerService("local", "BatteryStatus", batteryService, "Battery_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battery Service!" << std::endl;

    statusService = std::make_shared<ToHandlerStubDefault>();
    while (!runtime->registerService("local", "ToHandler", statusService, "Battery_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
    
    while (1)
    {
        batteryService->setBatteryAttribute(piracer.getVoltage());

        statusService->fireStatusEventEvent(project_name);

        usleep(10000);
    }
    
}
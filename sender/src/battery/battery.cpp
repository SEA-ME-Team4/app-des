#include "piracer.h"
#include "BatteryStatusStubImpl.hpp"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

int main()
{
    Piracer piracer = Piracer();
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStatusStubImpl> batteryService;

    runtime = CommonAPI::Runtime::get();

    batteryService = std::make_shared<BatteryStatusStubImpl>();
    while (!runtime->registerService("local", "BatteryStatus", batteryService, "Battery_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battery Service!" << std::endl;
    
    while (1)
    {
        batteryService->setBatteryAttribute(piracer.getVoltage());
    }
    
}
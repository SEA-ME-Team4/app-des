#include "battery.h"

Battery::Battery() {

    runtime = CommonAPI::Runtime::get();

    batteryService = std::make_shared<BatteryStatusStubImpl>();
    batteryServiceInit();

    statusService = std::make_shared<BatteryToHandlerStubDefault>();
    statusServiceInit();
}

Battery::~Battery() {
}

void Battery::batteryServiceInit() {
    while (!runtime->registerService("local", "BatteryStatus", batteryService, "Battery_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Battery Service!" << std::endl;
}

void Battery::statusServiceInit() {
    while (!runtime->registerService("local", "BatteryToHandler", statusService, "Battery_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;    
}

void Battery::setBattery(uint8_t voltage) {
    batteryService->setBatteryAttribute(voltage);
    statusService->fireBatteryStatusEventEvent(true);
}
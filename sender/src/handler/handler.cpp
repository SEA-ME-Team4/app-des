#include "gamepad.h"
#include "BrakeStatusStubImpl.hpp"

#include <v1/commonapi/GearStatusProxy.hpp>
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <stdint.h>

using namespace v1::commonapi;

int main()
{
    Gamepad gamepad = Gamepad();
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BrakeStatusStubImpl> brakeService;
    std::shared_ptr<GearStatusProxy<>> gearProxy;

    int gearstatus = 9;

    runtime = CommonAPI::Runtime::get();

    brakeService = std::make_shared<BrakeStatusStubImpl>();
    while (!runtime->registerService("local", "BrakeStatus", brakeService, "Handler_Brake_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Brake Service!" << std::endl;

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "Handler_Gear_Client");
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;
    uint8_t value = 0;
    CommonAPI::CallInfo info(8000);
    gearProxy->getGearAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Gear failed!\n";
    }
    std::cout << "Got Gear: " << value << std::endl;

    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        gearstatus = gear;
        std::cout<<"gearstatus: "<<gearstatus<<std::endl;
    });
    
    while (gamepad.read_data())
    {
        std::cout<<"gamepad: "<<gamepad.brake_status()<<'\t';
        std::cout<<"gearstatus: "<<gearstatus<<std::endl;
        brakeService->setBrakeAttribute(gamepad.brake_status());   
    }
    
}
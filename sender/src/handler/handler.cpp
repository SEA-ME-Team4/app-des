#include "piracer.h"
#include "gamepad.h"
#include "BrakeStatusStubImpl.hpp"

#include <v1/commonapi/GearStatusProxy.hpp>
#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

using namespace v1::commonapi;

int main() {
    int gearstatus;
    float steering;
    float throttle;

    Piracer piracer = Piracer();
    Gamepad gamepad = Gamepad();

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BrakeStatusStubImpl> brakeService;
    std::shared_ptr<GearStatusProxy<>> gearProxy;

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
    gearstatus = (int)value;

    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        gearstatus = (int)gear;
    });
    
    while (gamepad.read_data())
    {
        std::cout<<"gamepad: "<<gamepad.brake_status()<<'\t';
        std::cout<<"gearstatus: "<<gearstatus<<std::endl;
        brakeService->setBrakeAttribute(gamepad.brake_status());

        steering = gamepad.gamepad_inputLX;
        throttle = gamepad.gamepad_inputRY;
        
        // If Condition Gear and Gamepad
        // gearstatus 01234 = PRNDS
        if (gearstatus==0) {
            steering = 0;
            throttle = 0;
        }
        else if (gearstatus==1) {
            throttle = -throttle;
            if (throttle<0) {
                throttle = 0;
            }
        }
        else if (gearstatus==2) {
            throttle = 0;
        }
        else if (gearstatus==3) {
            if (throttle<0) {
                throttle = 0;
            }
        }
        else {
            throttle = 1.5*throttle;
        }

        piracer.set_steering_percent(steering);
        piracer.set_throttle_percent(throttle);
    }
}
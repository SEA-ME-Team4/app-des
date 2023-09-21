#include "SpeedStatusStubImpl.hpp"
#include "canreceiver.h"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <unistd.h>

int main() {
    // Arduino Speed Sender ID: 0x0F6
    CanReceiver canreceiver = CanReceiver("vcan0", 0x0F6); 
    int16_t speed = 0;

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusStubImpl> speedService;

    runtime = CommonAPI::Runtime::get();

    speedService = std::make_shared<SpeedStatusStubImpl>();
    while (!runtime->registerService("local", "SpeedStatus", speedService, "Speed_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Speed Service!" << std::endl;
    
    while (canreceiver.canRead())
    {
        speed = canreceiver.getSpeed();
        speedService->setSpeedAttribute(speed);
        
        // speed++;
        // usleep(50000);
        // std::cout<<speed<<std::endl;
        // if (speed==160) {
        //     speed = 0;
        // }
    }
    
}
#include "gamepad.h"
#include "BrakeStatusStubImpl.hpp"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

int main()
{
    Gamepad gamepad = Gamepad();
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BrakeStatusStubImpl> brakeService;

    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "BrakeStatus";
    std::string connection = "Brake_Service";

    brakeService = std::make_shared<BrakeStatusStubImpl>();
    while (!runtime->registerService(domain, instance, brakeService, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Brake Service!" << std::endl;
    
    while (gamepad.read_data())
    {
        std::cout<<gamepad.brake_status()<<'\n';
        brakeService->setBrakeAttribute(gamepad.brake_status());
    }
    
}
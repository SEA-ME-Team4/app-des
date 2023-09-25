#include "vehiclestatus.h"
#include <unistd.h>

VehicleStatus::VehicleStatus() {
    runtime = CommonAPI::Runtime::get();

    gearService = std::make_shared<GearStatusStubImpl>();
    while (!runtime->registerService("local", "GearStatus", gearService, "HeadUnit_Gear_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
    gear = 0;

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "HeadUnit_Brake_Client");
    brakeClient();

    statusService = std::make_shared<GearToHandlerStubDefault>();
    while (!runtime->registerService("local", "GearToHandler", statusService, "Gear_Status_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    sendGear(0);

    errorProxy = runtime->buildProxy<ToApplicationProxy>("local", "ToApplication", "HeadUnit_Error_Client");
    errorClient();
}

VehicleStatus::~VehicleStatus() {
}

void VehicleStatus::sendGear(quint8 gear) {
    gearService->setGearAttribute(gear);
    statusService->fireGearStatusEventEvent(true);
}

void VehicleStatus::brakeClient() {
    std::cout << "Checking Brake availability!" << std::endl;
    while (!brakeProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    
    CommonAPI::CallStatus callStatus;
    bool value = 0;
    CommonAPI::CallInfo info(6000);
    brakeProxy->getBrakeAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Brake failed!\n";
    }
    std::cout << "Got Brake: " << (int)value << std::endl;

    brakeProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        emit brakeChanged(brake);
    });
}

void VehicleStatus::errorClient() {
    std::cout << "Checking Error Handling availability!" << std::endl;
    while (!errorProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    errorProxy->getErrorEventEvent().subscribe([&](const std::string& name) {
        if (name=="speed_error") {emit speedStatus(false);}
        else if (name=="battery_error") {emit batteryStatus(false);}
        else if (name=="input_error") {emit inputStatus(false);}
        else if (name=="racer_error") {emit racerStatus(false);}
        else if (name=="gear_error") {emit gearStatus(false);}

        else if (name=="speed_okay") {emit speedStatus(true);}
        else if (name=="battery_okay") {emit batteryStatus(true);}
        else if (name=="input_okay") {emit inputStatus(true);}
        else if (name=="racer_okay") {emit racerStatus(true);}
        else if (name=="gear_okay") {emit gearStatus(true);}
    });
}
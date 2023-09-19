#include "vehiclestatus.h"
#include <unistd.h>

// #include <QDebug>

VehicleStatus::VehicleStatus() {
    runtime = CommonAPI::Runtime::get();

    gearService = std::make_shared<GearStatusStubImpl>();
    while (!runtime->registerService("local", "GearStatus", gearService, "HeadUnit_Gear_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
    gear = 0;
    sendGear(0);

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "HeadUnit_Brake_Client");
    brakeClient();
}

VehicleStatus::~VehicleStatus() {
}

void VehicleStatus::sendGear(quint8 gear) {
    gearService->setGearAttribute(gear);
    // this->gear = gear;
    // qDebug()<<gear;
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
        // qDebug()<<brake;
        emit brakeChanged(brake);
    });
}

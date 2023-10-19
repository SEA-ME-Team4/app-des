#include "vehiclestatus.h"
#include <unistd.h>

VehicleStatus::VehicleStatus() {
    runtime = CommonAPI::Runtime::get();

    gearService = std::make_shared<GearStatusStubImpl>();
    gearServiceInit();
    sendGear(gear);

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "HeadUnit_Brake_Proxy");
    brakeProxyInit();

    speedProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "HeadUnit_Speed_Proxy");
    speedProxyInit();

}

VehicleStatus::~VehicleStatus() {
}

void VehicleStatus::sendGear(quint8 gear) {
    gearService->setGearAttribute(gear);
}

void VehicleStatus::gearServiceInit() {
    while (!runtime->registerService("local", "GearStatus", gearService, "HeadUnit_Gear_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
    gear = 0;
}

void VehicleStatus::brakeProxyInit() {
    std::cout << "Checking Brake availability!" << std::endl;
    while (!brakeProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    brakeProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        emit brakeChanged(brake);
    });
}

void VehicleStatus::speedProxyInit() {
    std::cout << "Checking Speed availability!" << std::endl;
    while (!speedProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    speedProxy->getSpeedAttribute().getChangedEvent().subscribe([&](const int16_t& speed) {
        emit speedChanged(speed);
    });
}
#include "vehiclestatus.h"
#include <unistd.h>

VehicleStatus::VehicleStatus() {
    runtime = CommonAPI::Runtime::get();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "HeadUnit_Gear_Proxy");
    gearProxyInit();

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "HeadUnit_Brake_Proxy");
    brakeProxyInit();

    speedProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "HeadUnit_Speed_Proxy");
    speedProxyInit();
}

VehicleStatus::~VehicleStatus() {
}

void VehicleStatus::gearProxyInit() {
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        emit gearChanged(gear);
    });
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
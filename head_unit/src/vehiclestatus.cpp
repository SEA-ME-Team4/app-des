#include "vehiclestatus.h"
#include <unistd.h>

VehicleStatus::VehicleStatus() {
    runtime = CommonAPI::Runtime::get();

    gearselectorService = std::make_shared<GearSelectorStubImpl>();
    gearselectorServiceInit();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "HeadUnit_Gear_Proxy");
    gearProxyInit();

    inputProxy = runtime->buildProxy<InputStatusProxy>("local", "InputStatus", "HeadUnit_Input_Proxy");
    inputProxyInit();

    speedProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "HeadUnit_Speed_Proxy");
    speedProxyInit();

    distanceProxy = runtime->buildProxy<DistanceStatusProxy>("local", "DistanceStatus", "HeadUnit_Distance_Proxy");
    distanceProxyInit();

    gearHere = true;
}

VehicleStatus::~VehicleStatus() {
}

void VehicleStatus::sendGear(quint8 gear) {
    if (gear==6) {
        if (gearHere) {
            gearHere = false;
            gearselectorService->fireGearSelectEvent(gear);
        }
        else {
            gearHere = true;
            gearselectorService->fireGearSelectEvent(this->gear);
        }
    }
    else {
        gearselectorService->fireGearSelectEvent(gear);
    }
}

int VehicleStatus::getGear() {
    return gear;
}

bool VehicleStatus::getBrake() {
    return brake;
}

int VehicleStatus::getSpeed() {
    return speed;
}

int VehicleStatus::getDistance() {
    return distance;
}

void VehicleStatus::gearselectorServiceInit() {
    while (!runtime->registerService("local", "GearSelector", gearselectorService, "HeadUnit_GearSelector_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
}

void VehicleStatus::gearProxyInit() {
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        this->gear = gear;
        emit gearChanged(gear);
    });
}

void VehicleStatus::inputProxyInit() {
    std::cout << "Checking Brake availability!" << std::endl;
    while (!inputProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    inputProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        this->brake = brake;
        emit brakeChanged(brake);
    });
}

void VehicleStatus::speedProxyInit() {
    std::cout << "Checking Speed availability!" << std::endl;
    while (!speedProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    speedProxy->getSpeedAttribute().getChangedEvent().subscribe([&](const int16_t& speed) {
        this->speed = speed;
        emit speedChanged(speed);
    });
}

void VehicleStatus::distanceProxyInit() {
    std::cout << "Checking Distance availability!" << std::endl;
    while (!distanceProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    distanceProxy->getDistanceAttribute().getChangedEvent().subscribe([&](const int16_t& distance) {
        this->distance = distance;
        emit distanceChanged(distance);
    });
}
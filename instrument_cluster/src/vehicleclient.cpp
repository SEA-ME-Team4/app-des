#include "vehicleclient.h"
#include <QDebug>

VehicleClient::VehicleClient() {
    runtime = CommonAPI::Runtime::get();

    // speedProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "InstrumentCluster_Speed_Client");
    // batteryProxy = runtime->buildProxy<BatteryStatusProxy>("local", "BatteryStatus", "InstrumentCluster_Battery_Client");
    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "InstrumentCluster_Brake_Client");
    // tempProxy = runtime->buildProxy<TempStatusProxy>("local", "TempStatus", "InstrumentCluster_Temp_Client");
    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "InstrumentCluster_Gear_Client");

    // speedClient();
    // batteryClient();
    brakeClient();
    // tempClient();
    gearClient();
}

VehicleClient::~VehicleClient() {
}

void VehicleClient::speedClient() {
    std::cout << "Checking Speed availability!" << std::endl;
    while (!speedProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    CommonAPI::CallStatus callStatus;
    int16_t value = 0;
    CommonAPI::CallInfo info(4000);
    speedProxy->getSpeedAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Speed failed!\n";
    }
    std::cout << "Got Speed: " << (int)value << std::endl;

    speedProxy->getSpeedAttribute().getChangedEvent().subscribe([&](const int16_t& speed) {
        // qDebug()<<speed;
        emit speedChanged(speed);
    });
}

void VehicleClient::batteryClient() {
    std::cout << "Checking Battery availability!" << std::endl;
    while (!batteryProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    
    CommonAPI::CallStatus callStatus;
    uint8_t value = 0;
    CommonAPI::CallInfo info(5000);
    batteryProxy->getBatteryAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Battery failed!\n";
    }
    std::cout << "Got Battery: " << (int)value << std::endl;

    batteryProxy->getBatteryAttribute().getChangedEvent().subscribe([&](const uint8_t& battery) {
        // qDebug()<<battery;
        emit batteryChanged(battery);
    });
}
void VehicleClient::brakeClient() {
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

void VehicleClient::tempClient() {
    std::cout << "Checking Temp availability!" << std::endl;
    while (!tempProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    
    CommonAPI::CallStatus callStatus;
    int16_t value = 0;
    CommonAPI::CallInfo info(7000);
    tempProxy->getTempAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Temp failed!\n";
    }
    std::cout << "Got Temp: " << (int)value << std::endl;

    tempProxy->getTempAttribute().getChangedEvent().subscribe([&](const int16_t& temp) {
        // qDebug()<<temp;
        emit tempChanged(temp);
    });
}

void VehicleClient::gearClient() {
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
    std::cout << "Got Gear: " << (int)value << std::endl;

    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        // qDebug()<<gear;
        emit gearChanged(gear);
    });
}
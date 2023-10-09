#include "vehicleclient.h"
#include <QDebug>

VehicleClient::VehicleClient() {
    runtime = CommonAPI::Runtime::get();

    speedProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "InstrumentCluster_Speed_Proxy");
    speedProxyInit();

    batteryProxy = runtime->buildProxy<BatteryStatusProxy>("local", "BatteryStatus", "InstrumentCluster_Battery_Proxy");
    batteryProxyInit();

    brakeProxy = runtime->buildProxy<BrakeStatusProxy>("local", "BrakeStatus", "InstrumentCluster_Brake_Proxy");
    brakeProxyInit();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "InstrumentCluster_Gear_Proxy");
    gearProxyInit();

    errorProxy = runtime->buildProxy<ToApplicationProxy>("local", "ToApplication", "InstrumentCluster_Error_Proxy");
    errorProxyInit();
}

VehicleClient::~VehicleClient() {
}

void VehicleClient::speedProxyInit() {
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

void VehicleClient::batteryProxyInit() {
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

void VehicleClient::brakeProxyInit() {
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

void VehicleClient::gearProxyInit() {
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

void VehicleClient::errorProxyInit() {
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

#include "vehicleclient.h"
#include <QDebug>

VehicleClient::VehicleClient() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "VehicleStatus";
    std::string connection = "InstrumentCluster_Vehicle_Client";

    vehicleProxy = runtime->buildProxy<VehicleStatusProxy>(domain, instance, connection);

    std::cout << "Checking availability!" << std::endl;
    while (!vehicleProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    speedClient();
    batteryClient();
    brakeClient();
    tempClient();
}

VehicleClient::~VehicleClient() {
}

void VehicleClient::speedClient() {
    CommonAPI::CallStatus callStatus;
    int16_t value = 0;
    CommonAPI::CallInfo info(4000);
    vehicleProxy->getSpeedAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Speed failed!\n";
    }
    std::cout << "Got Speed: " << value << std::endl;

    vehicleProxy->getSpeedAttribute().getChangedEvent().subscribe([&](const int16_t& speed) {
        // qDebug()<<speed;
        emit speedChanged(speed);
    });
}

void VehicleClient::batteryClient() {
    CommonAPI::CallStatus callStatus;
    uint8_t value = 0;
    CommonAPI::CallInfo info(5000);
    vehicleProxy->getBatteryAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Battery failed!\n";
    }
    std::cout << "Got Battery: " << value << std::endl;

    vehicleProxy->getBatteryAttribute().getChangedEvent().subscribe([&](const uint8_t& battery) {
        // qDebug()<<battery;
        emit batteryChanged(battery);
    });
}
void VehicleClient::brakeClient() {
    CommonAPI::CallStatus callStatus;
    bool value = 0;
    CommonAPI::CallInfo info(6000);
    vehicleProxy->getBrakeAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Brake failed!\n";
    }
    std::cout << "Got Brake: " << value << std::endl;

    vehicleProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        // qDebug()<<brake;
        emit brakeChanged(brake);
    });
}

void VehicleClient::tempClient() {
    CommonAPI::CallStatus callStatus;
    int16_t value = 0;
    CommonAPI::CallInfo info(7000);
    vehicleProxy->getTempAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call Temp failed!\n";
    }
    std::cout << "Got Temp: " << value << std::endl;

    vehicleProxy->getTempAttribute().getChangedEvent().subscribe([&](const int16_t& temp) {
        // qDebug()<<temp;
        emit tempChanged(temp);
    });
}
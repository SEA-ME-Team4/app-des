#include "vehicleclient.h"

VehicleClient::VehicleClient() {
    runtime = CommonAPI::Runtime::get();

    speedProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "InstrumentCluster_Speed_Proxy");
    speedProxyInit();

    batteryProxy = runtime->buildProxy<BatteryStatusProxy>("local", "BatteryStatus", "InstrumentCluster_Battery_Proxy");
    batteryProxyInit();

    inputProxy = runtime->buildProxy<InputStatusProxy>("local", "InputStatus", "InstrumentCluster_Input_Proxy");
    inputProxyInit();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "InstrumentCluster_Gear_Proxy");
    gearProxyInit();

    errorProxy = runtime->buildProxy<ToApplicationProxy>("local", "ToApplication", "InstrumentCluster_Error_Proxy");
    errorProxyInit();
    errorProxyStatus = true;

    errorProxyStatusTimer = new QTimer(this);
    errorProxyStatusTimer->start(1000);
    connect(errorProxyStatusTimer, SIGNAL(timeout()), this, SLOT(checkAvailable()));
}

VehicleClient::~VehicleClient() {
}

void VehicleClient::speedProxyInit() {
    std::cout << "Checking Speed availability!" << std::endl;
    while (!speedProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    speedProxy->getSpeedAttribute().getChangedEvent().subscribe([&](const int16_t& speed) {
        emit speedChanged(speed);
    });
}

void VehicleClient::batteryProxyInit() {
    std::cout << "Checking Battery availability!" << std::endl;
    while (!batteryProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    batteryProxy->getBatteryAttribute().getChangedEvent().subscribe([&](const uint8_t& battery) {
        emit batteryChanged(battery);
    });
}

void VehicleClient::inputProxyInit() {
    std::cout << "Checking Input availability!" << std::endl;
    while (!inputProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    inputProxy->getBrakeAttribute().getChangedEvent().subscribe([&](const bool& brake) {
        emit brakeChanged(brake);
    });
}

void VehicleClient::gearProxyInit() {
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        emit gearChanged(gear);
    });
}

void VehicleClient::errorProxyInit() {
    std::cout << "Checking Error Handling availability!" << std::endl;
    while (!errorProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    errorProxy->getErrorEvent().subscribe([&](const std::string& name) {
        if (name=="speed_error") {emit speedStatus(false);}
        else if (name=="battery_error") {emit batteryStatus(false);}
        else if (name=="input_error") {emit inputStatus(false);}
        else if (name=="gear_error") {emit gearStatus(false);}

        else if (name=="speed_okay") {emit speedStatus(true);}
        else if (name=="battery_okay") {emit batteryStatus(true);}
        else if (name=="input_okay") {emit inputStatus(true);}
        else if (name=="gear_okay") {emit gearStatus(true);}
    });
}

void VehicleClient::checkAvailable() {
    if (!errorProxy->isAvailable()) {
        errorProxyStatus = false;
        emit racerStatus(false);
    }
    else if (!errorProxyStatus) {
        errorProxyStatus = true;
        emit racerStatus(true);
    }
}
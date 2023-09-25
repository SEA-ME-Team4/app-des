#include "handler.h"

Handler::Handler() {
    speedStatus = false;
    batteryStatus = false;
    inputStatus = false;
    racerStatus = false;
    gearStatus = false;

    speedStatusTime = std::chrono::steady_clock::now();
    batteryStatusTime = std::chrono::steady_clock::now();
    inputStatusTime = std::chrono::steady_clock::now();
    racerStatusTime = std::chrono::steady_clock::now();
    gearStatusTime = std::chrono::steady_clock::now();

    // std::this_thread::sleep_for(std::chrono::milliseconds(10000));

    runtime = CommonAPI::Runtime::get();

    // speedHandlerProxy = runtime->buildProxy<SpeedToHandlerProxy>("local", "SpeedToHandler", "Handler_Speed_Client");
    // speedHandlerProxyInit();
    // batteryHandlerProxy = runtime->buildProxy<BatteryToHandlerProxy>("local", "BatteryToHandler", "Handler_Battery_Client");
    // batteryHandlerProxyInit();
    inputHandlerProxy = runtime->buildProxy<InputToHandlerProxy>("local", "InputToHandler", "Handler_Input_Client");
    inputHandlerProxyInit();
    // racerHandlerProxy = runtime->buildProxy<RacerToHandlerProxy>("local", "RacerToHandler", "Handler_Racer_Client");
    // racerHandlerProxyInit();
    gearHandlerProxy = runtime->buildProxy<GearToHandlerProxy>("local", "GearToHandler", "Handler_Gear_Client");
    gearHandlerProxyInit();

    handlerService = std::make_shared<ToApplicationStubImpl>();
    ServiceInitialize();
}

Handler::~Handler() {
}

void Handler::speedHandlerProxyInit() {
    std::cout << "Checking Speed Handling availability!" << std::endl;
    while (!speedHandlerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    speedHandlerProxy->getSpeedStatusEventEvent().subscribe([&](const bool& status) {
        valueChanged("speed");
    });
}

void Handler::batteryHandlerProxyInit() {
    std::cout << "Checking Battery Handling availability!" << std::endl;
    while (!batteryHandlerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    batteryHandlerProxy->getBatteryStatusEventEvent().subscribe([&](const bool& status) {
        valueChanged("battery");
    });
}


void Handler::inputHandlerProxyInit() {
    std::cout << "Checking Input Handling availability!" << std::endl;
    while (!inputHandlerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    inputHandlerProxy->getInputStatusEventEvent().subscribe([&](const bool& status) {
        valueChanged("input");
    });
}

void Handler::racerHandlerProxyInit() {
    std::cout << "Checking Temp Handling availability!" << std::endl;
    while (!racerHandlerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    racerHandlerProxy->getRacerStatusEventEvent().subscribe([&](const bool& status) {
        valueChanged("racer");
    });
}

void Handler::gearHandlerProxyInit() {
    std::cout << "Checking Handling availability!" << std::endl;
    while (!gearHandlerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    gearHandlerProxy->getGearStatusEventEvent().subscribe([&](const bool& status) {
        valueChanged("gear");
    });
}

void Handler::valueChanged(std::string name) {
    if (name=="speed") {speedStatusTime = std::chrono::steady_clock::now();}
    else if (name=="battery") {batteryStatusTime = std::chrono::steady_clock::now();}
    else if (name=="input") {inputStatusTime = std::chrono::steady_clock::now();}
    else if (name=="racer") {racerStatusTime = std::chrono::steady_clock::now();}
    else if (name=="gear") {gearStatusTime = std::chrono::steady_clock::now();}
}

void Handler::ServiceInitialize() {
    while (!runtime->registerService("local", "ToApplication", handlerService, "Handler_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
}

void Handler::okayCheck(std::string name) {
    if (name=="speed") {if (!speedStatus) {okayEvent("speed_okay");};}
    else if (name=="battery") {if (!batteryStatus)  {okayEvent("battery_okay");};}
    else if (name=="input") {if (!inputStatus) {okayEvent("input_okay");};}
    else if (name=="racer") {if (!racerStatus) {okayEvent("racer_okay");};}
    else if (name=="gear") {if (!gearStatus) {okayEvent("gear_okay");};}
}

void Handler::errorCheck(std::string name) {
    if (name=="speed") {speedHandlerProxy->isAvailable() ? valueChanged("speed") : errorEvent("speed_error");}
    else if (name=="battery") {batteryHandlerProxy->isAvailable() ? valueChanged("battery") : errorEvent("battery_error");}
    else if (name=="input") {inputHandlerProxy->isAvailable() ? valueChanged("input") : errorEvent("input_error");}
    else if (name=="racer") {racerHandlerProxy->isAvailable() ? valueChanged("racer") : errorEvent("racer_error");}
    else if (name=="gear") {gearHandlerProxy->isAvailable() ? valueChanged("gear") : errorEvent("gear_error");}
}

void Handler::okayEvent(std::string name) {
    if (name=="speed_okay") {speedStatus=true;}
    else if (name=="battery_okay") {batteryStatus=true;}
    else if (name=="input_okay") {inputStatus=true;}
    else if (name=="racer_okay") {racerStatus=true;}
    else if (name=="gear_okay") {gearStatus=true;}

    handlerService->fireErrorEventEvent(name);
    std::cout<<"Stablized: "<<name<<std::endl;
}

void Handler::errorEvent(std::string name) {
    if (name=="speed_error") {speedStatus=false;} 
    else if (name=="battery_error") {batteryStatus=false;}
    else if (name=="input_error") {inputStatus=false;}
    else if (name=="racer_error") {racerStatus=false;}
    else if (name=="gear_error") {gearStatus=false;}

    handlerService->fireErrorEventEvent(name);
    std::cout<<"Service '"<<name<<"' Error Detected!"<<std::endl;
}

void Handler::handlerProcess() {
    checkTime = std::chrono::steady_clock::now();
    // intervalCalculate(speedStatusTime)>SPEED_INTERVAL_MAX ? errorCheck("speed") : okayCheck("speed");
    // intervalCalculate(batteryStatusTime)>BATTERY_INTERVAL_MAX ? errorCheck("battery") : okayCheck("speed");
    intervalCalculate(inputStatusTime)>INPUT_INTERVAL_MAX ? errorCheck("input") : okayCheck("input");
    // intervalCalculate(racerStatusTime)>RACER_INTERVAL_MAX ? errorCheck("racer") : okayCheck("racer");
    intervalCalculate(gearStatusTime)>GEAR_INTERVAL_MAX ? errorCheck("gear") : okayCheck("gear");
}

unsigned short Handler::intervalCalculate(std::chrono::time_point<std::chrono::steady_clock> time_point) {
    unsigned short interval = std::chrono::duration_cast<std::chrono::milliseconds>(checkTime - time_point).count();

    // Data Type Exception Process (unsigned short: 0~65535)
    (interval>32767) ? interval=32767 : interval=interval;
    return interval;
}
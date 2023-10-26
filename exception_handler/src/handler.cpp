#include "handler.h"

Handler::Handler() {
    speedStatus = false;
    batteryStatus = false;
    inputStatus = false;
    gearStatus = false;

    speedStatusTime = std::chrono::steady_clock::now();
    batteryStatusTime = std::chrono::steady_clock::now();
    inputStatusTime = std::chrono::steady_clock::now();
    gearStatusTime = std::chrono::steady_clock::now();

    runtime = CommonAPI::Runtime::get();

    handlerService = std::make_shared<ToApplicationStubImpl>();
    handlerServiceInit();
    
    speedHandlerProxy = runtime->buildProxy<SpeedStatusProxy>("local", "SpeedStatus", "Handler_Speed_Proxy");
    batteryHandlerProxy = runtime->buildProxy<BatteryStatusProxy>("local", "BatteryStatus", "Handler_Battery_Proxy");
    inputHandlerProxy = runtime->buildProxy<InputStatusProxy>("local", "InputStatus", "Handler_Input_Proxy");
    gearHandlerProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "Handler_Gear_Proxy");
}

Handler::~Handler() {
}

void Handler::handlerServiceInit() {
    while (!runtime->registerService("local", "ToApplication", handlerService, "Handler_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
}

void Handler::valueChanged(std::string name) {
    if (name=="speed") {speedStatusTime = std::chrono::steady_clock::now();}
    else if (name=="battery") {batteryStatusTime = std::chrono::steady_clock::now();}
    else if (name=="input") {inputStatusTime = std::chrono::steady_clock::now();}
    else if (name=="gear") {gearStatusTime = std::chrono::steady_clock::now();}
}

void Handler::okayCheck(std::string name) {
    if (name=="speed") {if (!speedStatus) {okayEvent("speed_okay");};}
    else if (name=="battery") {if (!batteryStatus)  {okayEvent("battery_okay");};}
    else if (name=="input") {if (!inputStatus) {okayEvent("input_okay");};}
    else if (name=="gear") {if (!gearStatus) {okayEvent("gear_okay");};}
}

void Handler::errorCheck(std::string name) {
    if (name=="speed") {speedHandlerProxy->isAvailable() ? valueChanged("speed") : errorEvent("speed_error");}
    else if (name=="battery") {batteryHandlerProxy->isAvailable() ? valueChanged("battery") : errorEvent("battery_error");}
    else if (name=="input") {inputHandlerProxy->isAvailable() ? valueChanged("input") : errorEvent("input_error");}
    else if (name=="gear") {gearHandlerProxy->isAvailable() ? valueChanged("gear") : errorEvent("gear_error");}
}

void Handler::okayEvent(std::string name) {
    if (name=="speed_okay") {speedStatus=true;}
    else if (name=="battery_okay") {batteryStatus=true;}
    else if (name=="input_okay") {inputStatus=true;}
    else if (name=="gear_okay") {gearStatus=true;}

    handlerService->fireErrorEvent(name);
    std::cout<<"Stablized: "<<name<<std::endl;
}

void Handler::errorEvent(std::string name) {
    if (name=="speed_error") {speedStatus=false;} 
    else if (name=="battery_error") {batteryStatus=false;}
    else if (name=="input_error") {inputStatus=false;}
    else if (name=="gear_error") {gearStatus=false;}

    handlerService->fireErrorEvent(name);
    std::cout<<"Service "<<name<<" Detected!"<<std::endl;
}

void Handler::handlerProcess() {
    std::cout<<"\n[Handler]"<<std::endl;
    checkTime = std::chrono::steady_clock::now();
    intervalCalculate(speedStatusTime)>SPEED_INTERVAL_MAX ? errorCheck("speed") : okayCheck("speed");
    intervalCalculate(batteryStatusTime)>BATTERY_INTERVAL_MAX ? errorCheck("battery") : okayCheck("battery");
    intervalCalculate(inputStatusTime)>INPUT_INTERVAL_MAX ? errorCheck("input") : okayCheck("input");
    intervalCalculate(gearStatusTime)>GEAR_INTERVAL_MAX ? errorCheck("gear") : okayCheck("gear");
}

unsigned short Handler::intervalCalculate(std::chrono::time_point<std::chrono::steady_clock> time_point) {
    unsigned short interval = std::chrono::duration_cast<std::chrono::milliseconds>(checkTime - time_point).count();

    // Data Type Exception Process (unsigned short: 0~65535)
    (interval>32767) ? interval=32767 : interval=interval;
    return interval;
}
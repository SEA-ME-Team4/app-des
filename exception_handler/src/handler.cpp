#include "handler.h"

Handler::Handler() {
    speedStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};
    batteryStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};
    inputStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};
    tempStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};
    gearStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};

    runtime = CommonAPI::Runtime::get();

    handlerProxy = runtime->buildProxy<ToHandlerProxy>("local", "ToHandler", "Handler_Client");
    handlerClient();

    handlerService = std::make_shared<ToApplicationStubImpl>();
    handlerServer();
}

Handler::~Handler() {
}

void Handler::handlerClient() {
    std::cout << "Checking Handling availability!" << std::endl;
    while (!handlerProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;

    handlerProxy->getStatusEventEvent().subscribe([&](const std::string& name) {
        valueChanged(name);
    });
}

void Handler::valueChanged(std::string name) {
    if (name=="speed") {speedStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};}
    else if (name=="battery") {batteryStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};}
    else if (name=="input") {inputStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};}
    else if (name=="temp") {tempStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};}
    else if (name=="gear") {gearStatusTimer = std::chrono::time_point<std::chrono::steady_clock>{};}
}

void Handler::handlerServer() {
    while (!runtime->registerService("local", "ToApplication", handlerService, "Handler_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;
}

void Handler::errorEvent(std::string name) {
    handlerService->fireErrorEventEvent(name);
    std::cout<<name<<" error Detected in Handler"<<std::endl;
}

void Handler::handlerProcess() {
    // Condition for Error Detect!
    std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(inputStatusTimer.time_since_epoch()).count();
    
    // errorEvent("bat");
}
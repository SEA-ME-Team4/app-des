#include "input.h"
#include <unistd.h>

Input::Input() {
    runtime = CommonAPI::Runtime::get();

    inputService = std::make_shared<InputStatusStubImpl>();
    inputServiceInit();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "Input_Gear_Proxy");
    gearProxyInit();
}

Input::~Input() {
}

void Input::inputServiceInit() {
    while (!runtime->registerService("local", "InputStatus", inputService, "Input_Input_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Input Service!" << std::endl;
}

void Input::gearProxyInit() {
    std::cout << "Checking Gear availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;
    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        this->gear=gear;
    });
}

void Input::setBrake(bool brake) {
    inputService->setBrakeAttribute(brake);
}

void Input::setSteering(float steering) {
    inputService->setSteeringAttribute(steering);
}

void Input::setThrottle(float throttle) {
    inputService->setThrottleAttribute(throttle);
}

void Input::sendGear(uint8_t gear) {
    inputService->fireGearSelectEvent(gear);
}

int Input::getGear() {
    return gear;
}
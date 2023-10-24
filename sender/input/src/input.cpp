#include "input.h"
#include <unistd.h>

Input::Input() {
    runtime = CommonAPI::Runtime::get();

    brakeService = std::make_shared<BrakeStatusStubImpl>();
    brakeServiceInit();

    maneuverService = std::make_shared<ManeuverStubImpl>();
    maneuverServiceInit();

    gearselectorService = std::make_shared<GearSelectorStubImpl>();
    gearselectorServiceInit();

    gearProxy = runtime->buildProxy<GearStatusProxy>("local", "GearStatus", "Input_Gear_Proxy");
    gearProxyInit();
}

Input::~Input() {
}

void Input::brakeServiceInit() {
    while (!runtime->registerService("local", "BrakeStatus", brakeService, "Input_Brake_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Brake Service!" << std::endl;
}

void Input::maneuverServiceInit() {
    while (!runtime->registerService("local", "Maneuver", maneuverService, "Input_Maneuver_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Maneuver Service!" << std::endl;
}

void Input::gearselectorServiceInit() {
    while (!runtime->registerService("local", "GearSelector", gearselectorService, "Input_GearSelector_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered GearSelector Service!" << std::endl;
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
    brakeService->setBrakeAttribute(brake);
}

void Input::setSteering(float steering) {
    maneuverService->setSteeringAttribute(steering);
}

void Input::setThrottle(float throttle) {
    maneuverService->setThrottleAttribute(throttle);
}

void Input::sendGear(uint8_t gear) {
    gearselectorService->fireGearSelectEvent(gear);
    std::cout << gear << std::endl;
}

int Input::getGear() {
    return gear;
}
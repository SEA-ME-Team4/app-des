#include "speed.h"

Speed::Speed() {
    runtime = CommonAPI::Runtime::get();

    speedService = std::make_shared<SpeedStatusStubImpl>();
    speedServiceInit();
}

Speed::~Speed() {
}

void Speed::speedServiceInit() {
    while (!runtime->registerService("local", "SpeedStatus", speedService, "Speed_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Speed Service!" << std::endl;

}

void Speed::setSpeed(int16_t speed) {
    speedService->setSpeedAttribute(speed);
}
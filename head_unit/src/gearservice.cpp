#include "gearservice.h"
// #include <QDebug>

GearService::GearService() {
    runtime = CommonAPI::Runtime::get();

    gearService = std::make_shared<GearStatusStubImpl>();
    while (!runtime->registerService("local", "GearStatus", gearService, "HeadUnit_Gear_Service")) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    gear = 0;
    sendGear(0);
}

GearService::~GearService() {
}

void GearService::sendGear(quint8 gear) {
    gearService->setGearAttribute(gear);
    // this->gear = gear;
    // qDebug()<<gear;
}
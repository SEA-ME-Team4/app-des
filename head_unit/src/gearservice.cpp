#include "gearservice.h"
// #include <QDebug>

GearService::GearService() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "GearStatus";
    std::string connection = "HeadUnit_Gear_Service";

    myService = std::make_shared<GearStatusStubImpl>();
    while (!runtime->registerService(domain, instance, myService, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    gear = 0;
}

GearService::~GearService() {
}

void GearService::sendGear(quint8 gear) {
    myService->setGearAttribute(gear);
    // this->gear = gear;
    // qDebug()<<gear;
}
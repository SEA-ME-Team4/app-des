#include "gearservice.h"

GearService::GearService() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "carinformation";
    std::string instance = "gear";
    std::string connection = "headunit";

    myService = std::make_shared<TestStubImpl>();
    while (!runtime->registerService(domain, instance, myService, connection)) {
        std::cout << "Register Service failed, trying again in 100 milliseconds..." << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << "Successfully Registered Service!" << std::endl;

    gear = 0;
}

GearService::~GearService() {
}

void GearService::sendGear(int gear) {
    myService->setXAttribute(gear);
    // this->gear = gear;
    qDebug()<<gear;
}
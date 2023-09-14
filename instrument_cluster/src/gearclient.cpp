#include "gearclient.h"
#include <QDebug>

GearClient::GearClient() {
    runtime = CommonAPI::Runtime::get();

    std::string domain = "local";
    std::string instance = "GearStatus";
    std::string connection = "InstrumentCluster_Gear_Client";

    gearProxy = runtime->buildProxy<GearStatusProxy>(domain, instance, connection);

    std::cout << "Checking availability!" << std::endl;
    while (!gearProxy->isAvailable())
        usleep(10);
    std::cout << "Available..." << std::endl;


    CommonAPI::CallStatus callStatus;
    int8_t value = 0;
    CommonAPI::CallInfo info(1000);
    gearProxy->getGearAttribute().getValue(callStatus, value, &info);
    if (callStatus != CommonAPI::CallStatus::SUCCESS) {
        std::cerr << "Remote call A failed!\n";
    }
    std::cout << "Got attribute value: " << value << std::endl;

    gearProxy->getGearAttribute().getChangedEvent().subscribe([&](const uint8_t& gear) {
        // qDebug()<<gearstatus;
        emit gearChanged(gear);
    });
}

GearClient::~GearClient() {
}

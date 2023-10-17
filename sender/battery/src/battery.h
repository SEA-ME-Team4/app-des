#include "BatteryStatusStubImpl.hpp"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

using namespace v1::commonapi;

class Battery {
public:
    Battery();
    ~Battery();
    void setBattery(uint8_t voltage);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BatteryStatusStubImpl> batteryService;

    void batteryServiceInit();
};

    
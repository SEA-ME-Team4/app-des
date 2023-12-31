#include <v1/commonapi/SpeedStatusProxy.hpp>
#include <v1/commonapi/BatteryStatusProxy.hpp>
#include <v1/commonapi/InputStatusProxy.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include "ToApplicationStubImpl.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>

#include <chrono>
#include <limits>

#define SPEED_INTERVAL_MAX 100 //milli
#define BATTERY_INTERVAL_MAX 1000 //milli
#define INPUT_INTERVAL_MAX 100 //milli
#define GEAR_INTERVAL_MAX 500 //milli

using namespace v1::commonapi;

class Handler
{
public:
    Handler();
    ~Handler();
    void handlerProcess();

private:
    bool speedStatus;
    bool batteryStatus;
    bool inputStatus;
    bool gearStatus;

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<ToApplicationStubImpl> handlerService;
    std::shared_ptr<SpeedStatusProxy<>> speedHandlerProxy;
    std::shared_ptr<BatteryStatusProxy<>> batteryHandlerProxy;
    std::shared_ptr<InputStatusProxy<>> inputHandlerProxy;
    std::shared_ptr<GearStatusProxy<>> gearHandlerProxy;

    void handlerServiceInit();

    void valueChanged(std::string name);
    void okayCheck(std::string name);
    void okayEvent(std::string name);
    void errorCheck(std::string name);
    void errorEvent(std::string name);

    std::chrono::time_point<std::chrono::steady_clock> checkTime;

    std::chrono::time_point<std::chrono::steady_clock> speedStatusTime;
    std::chrono::time_point<std::chrono::steady_clock> batteryStatusTime;
    std::chrono::time_point<std::chrono::steady_clock> inputStatusTime;
    std::chrono::time_point<std::chrono::steady_clock> gearStatusTime;

    unsigned short intervalCalculate(std::chrono::time_point<std::chrono::steady_clock> time_point);
};
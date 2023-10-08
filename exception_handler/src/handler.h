#include <v1/commonapi/SpeedToHandlerProxy.hpp>
#include <v1/commonapi/BatteryToHandlerProxy.hpp>
#include <v1/commonapi/InputToHandlerProxy.hpp>
#include <v1/commonapi/RacerToHandlerProxy.hpp>
#include <v1/commonapi/GearToHandlerProxy.hpp>
#include "ToApplicationStubImpl.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>

#include <chrono>
#include <limits>

#define SPEED_INTERVAL_MAX 1000 //milli
#define BATTERY_INTERVAL_MAX 1000 //milli
#define INPUT_INTERVAL_MAX 1000 //milli
#define RACER_INTERVAL_MAX 1000 //milli
#define GEAR_INTERVAL_MAX 1000 //milli

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
    bool racerStatus;
    bool gearStatus;

    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedToHandlerProxy<>> speedHandlerProxy;
    std::shared_ptr<BatteryToHandlerProxy<>> batteryHandlerProxy;
    std::shared_ptr<InputToHandlerProxy<>> inputHandlerProxy;
    std::shared_ptr<RacerToHandlerProxy<>> racerHandlerProxy;
    std::shared_ptr<GearToHandlerProxy<>> gearHandlerProxy;
    std::shared_ptr<ToApplicationStubImpl> handlerService;

    void speedHandlerProxyInit();
    void batteryHandlerProxyInit();
    void inputHandlerProxyInit();
    void racerHandlerProxyInit();
    void gearHandlerProxyInit();
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
    std::chrono::time_point<std::chrono::steady_clock> racerStatusTime;
    std::chrono::time_point<std::chrono::steady_clock> gearStatusTime;

    unsigned short intervalCalculate(std::chrono::time_point<std::chrono::steady_clock> time_point);
};
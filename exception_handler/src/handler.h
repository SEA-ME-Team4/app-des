#include <v1/commonapi/ToHandlerProxy.hpp>
#include "ToApplicationStubImpl.hpp"
#include <iostream>
#include <thread>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>

#include <chrono>
#include <ctime>

using namespace v1::commonapi;

class Handler
{
public:
    Handler();
    ~Handler();
    void handlerProcess();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<ToHandlerProxy<>> handlerProxy;
    std::shared_ptr<ToApplicationStubImpl> handlerService;

    void handlerClient();
    void handlerServer();

    void valueChanged(std::string name);
    void errorEvent(std::string name);

    std::chrono::time_point<std::chrono::steady_clock> speedStatusTimer;
    std::chrono::time_point<std::chrono::steady_clock> batteryStatusTimer;
    std::chrono::time_point<std::chrono::steady_clock> inputStatusTimer;
    std::chrono::time_point<std::chrono::steady_clock> tempStatusTimer;
    std::chrono::time_point<std::chrono::steady_clock> gearStatusTimer;
};
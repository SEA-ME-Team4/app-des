#include "GearStatusStubImpl.hpp"
#include <v1/commonapi/InputStatusProxy.hpp>

#include <iostream>
#include <thread>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>

using namespace v1::commonapi;

class RacerClient
{
public:
    RacerClient();
    ~RacerClient();

    int getGear();
    bool getBrake();
    float getSteering();
    float getThrottle();

    bool validCheck();
    void statusUpdate();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusStubImpl> gearService;
    std::shared_ptr<InputStatusProxy<>> inputProxy;


    void gearServiceInit();
    void inputProxyInit();

    void setGear(uint8_t gear);

    uint8_t gear;
    bool brake;
    float steering;
    float throttle;
};
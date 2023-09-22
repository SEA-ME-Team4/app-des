#include <v1/commonapi/BrakeStatusProxy.hpp>
#include <v1/commonapi/ManeuverProxy.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/ToHandlerStubDefault.hpp>
#include <iostream>
#include <thread>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>

#define project_name "racer"

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
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<BrakeStatusProxy<>> brakeProxy;
    std::shared_ptr<ManeuverProxy<>> maneuverProxy;
    std::shared_ptr<ToHandlerStubDefault> statusService;

    void gearClient();
    void brakeClient();
    void maneuverClient();
    void statusServer();

    int gear;
    bool brake;
    float steering;
    float throttle;
};
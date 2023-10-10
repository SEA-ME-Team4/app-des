#include "BrakeStatusStubImpl.hpp"
#include "ManeuverStubImpl.hpp"
#include <v1/commonapi/InputToHandlerStubDefault.hpp>

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>

using namespace v1::commonapi;

class Input {
public:
    Input();
    ~Input();
    void setBrake(bool brake);
    void setSteering(float steering);
    void setThrottle(float throttle);
    void setStatusEvent(bool status);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<BrakeStatusStubImpl> brakeService;
    std::shared_ptr<ManeuverStubImpl> maneuverService;
    std::shared_ptr<InputToHandlerStubDefault> statusService;

    void brakeServiceInit();
    void maneuverServiceInit();
    void statusServiceInit();
};
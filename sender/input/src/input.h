#include "InputStatusStubImpl.hpp"
#include <v1/commonapi/GearStatusProxy.hpp>

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
    void sendGear(uint8_t gear);
    int getGear();

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<InputStatusStubImpl> inputService;
    std::shared_ptr<GearStatusProxy<>> gearProxy;

    void inputServiceInit();
    void gearProxyInit();

    int gear;
};
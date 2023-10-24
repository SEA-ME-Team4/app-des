#include "BrakeStatusStubImpl.hpp"
#include "ManeuverStubImpl.hpp"
#include "GearSelectorStubImpl.hpp"
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
    std::shared_ptr<BrakeStatusStubImpl> brakeService;
    std::shared_ptr<ManeuverStubImpl> maneuverService;
    std::shared_ptr<GearSelectorStubImpl> gearselectorService;
    std::shared_ptr<GearStatusProxy<>> gearProxy;

    void brakeServiceInit();
    void maneuverServiceInit();
    void gearselectorServiceInit();
    void gearProxyInit();

    int gear;
};
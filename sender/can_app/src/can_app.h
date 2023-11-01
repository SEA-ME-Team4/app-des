#include "SpeedStatusStubImpl.hpp"
#include "DistanceStatusStubImpl.hpp"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <unistd.h>

using namespace v1::commonapi;

class Can_App {
public:
    Can_App();
    ~Can_App();
    void setSpeed(int16_t speed);
    void setDistance(uint8_t distance);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusStubImpl> speedService;
    std::shared_ptr<DistanceStatusStubImpl> distanceService;

    void speedServiceInit();
    void distanceServiceInit();
};
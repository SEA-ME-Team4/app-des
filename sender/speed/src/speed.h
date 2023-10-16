#include "SpeedStatusStubImpl.hpp"

#include <iostream>
#include <thread>
#include <CommonAPI/CommonAPI.hpp>
#include <unistd.h>

using namespace v1::commonapi;

class Speed {
public:
    Speed();
    ~Speed();
    void setSpeed(int16_t speed);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<SpeedStatusStubImpl> speedService;

    void speedServiceInit();
};
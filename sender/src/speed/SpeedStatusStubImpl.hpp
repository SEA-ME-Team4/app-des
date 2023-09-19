#ifndef SPEEDSTATUSSTUBIMPL_H_
#define SPEEDSTATUSSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusStubDefault.hpp>

class SpeedStatusStubImpl: public v1_0::commonapi::SpeedStatusStubDefault {
public:
    SpeedStatusStubImpl();
    virtual ~SpeedStatusStubImpl();
};
#endif

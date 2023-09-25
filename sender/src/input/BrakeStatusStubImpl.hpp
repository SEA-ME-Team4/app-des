#ifndef BRAKESTATUSSTUBIMPL_H_
#define BRAKESTATUSSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/BrakeStatusStubDefault.hpp>

class BrakeStatusStubImpl: public v1_0::commonapi::BrakeStatusStubDefault {
public:
    BrakeStatusStubImpl();
    virtual ~BrakeStatusStubImpl();
};
#endif

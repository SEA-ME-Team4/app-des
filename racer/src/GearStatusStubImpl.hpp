#ifndef GEARSTATUSSTUBIMPL_H_
#define GEARSTATUSSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusStubDefault.hpp>

class GearStatusStubImpl: public v1_0::commonapi::GearStatusStubDefault {
public:
    GearStatusStubImpl();
    virtual ~GearStatusStubImpl();
};
#endif
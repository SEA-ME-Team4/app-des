#ifndef BATTERYSTATUSSTUBIMPL_H_
#define BATTERYSTATUSSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/BatteryStatusStubDefault.hpp>

class BatteryStatusStubImpl: public v1_0::commonapi::BatteryStatusStubDefault {
public:
    BatteryStatusStubImpl();
    virtual ~BatteryStatusStubImpl();
};
#endif

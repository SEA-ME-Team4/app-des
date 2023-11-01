#ifndef DISTANCESTATUSSTUBIMPL_H_
#define DISTANCESTATUSSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/DistanceStatusStubDefault.hpp>

class DistanceStatusStubImpl: public v1_0::commonapi::DistanceStatusStubDefault {
public:
    DistanceStatusStubImpl();
    virtual ~DistanceStatusStubImpl();
};
#endif

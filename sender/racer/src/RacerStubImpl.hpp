#ifndef RACERSTUBIMPL_H_
#define RACERSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/RacerStubDefault.hpp>

class RacerStubImpl: public v1_0::commonapi::RacerStubDefault {
public:
    RacerStubImpl();
    virtual ~RacerStubImpl();
};
#endif

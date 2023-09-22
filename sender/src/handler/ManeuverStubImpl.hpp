#ifndef MANEUVERSTUBIMPL_H_
#define MANEUVERSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ManeuverStubDefault.hpp>

class ManeuverStubImpl: public v1_0::commonapi::ManeuverStubDefault {
public:
    ManeuverStubImpl();
    virtual ~ManeuverStubImpl();
};
#endif

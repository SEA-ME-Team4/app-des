#ifndef TOAPPLICATIONSTUBIMPL_H_
#define TOAPPLICATIONSTUBIMPL_H_
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/ToApplicationStubDefault.hpp>

class ToApplicationStubImpl: public v1_0::commonapi::ToApplicationStubDefault {
public:
    ToApplicationStubImpl();
    virtual ~ToApplicationStubImpl();
};
#endif

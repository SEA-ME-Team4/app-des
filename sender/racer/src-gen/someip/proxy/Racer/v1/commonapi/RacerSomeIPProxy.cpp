/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/RacerSomeIPProxy.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

std::shared_ptr<CommonAPI::SomeIP::Proxy> createRacerSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< RacerSomeIPProxy>(_address, _connection);
}

void initializeRacerSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.Racer:v1_0:Racer",
        0x4, 0x2c, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.Racer:v1_0",
        &createRacerSomeIPProxy);
}

INITIALIZER(registerRacerSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeRacerSomeIPProxy);
}

RacerSomeIPProxy::RacerSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          racerStatus_(*this, 0x8006, CommonAPI::SomeIP::event_id_t(0x8006), CommonAPI::SomeIP::event_type_e::ET_EVENT , CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, std::make_tuple(static_cast< CommonAPI::EmptyDeployment* >(nullptr)))
{
}

RacerSomeIPProxy::~RacerSomeIPProxy() {
    completed_.set_value();
}


RacerSomeIPProxy::RacerStatusEvent& RacerSomeIPProxy::getRacerStatusEvent() {
    return racerStatus_;
}

void RacerSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> RacerSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1

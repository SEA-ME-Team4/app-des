/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#include <v1/commonapi/AEBSomeIPProxy.hpp>

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

std::shared_ptr<CommonAPI::SomeIP::Proxy> createAEBSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection) {
    return std::make_shared< AEBSomeIPProxy>(_address, _connection);
}

void initializeAEBSomeIPProxy() {
    CommonAPI::SomeIP::AddressTranslator::get()->insert(
        "local:commonapi.AEB:v1_0:AEB",
        0x123a, 0x567e, 1, 0);
    CommonAPI::SomeIP::Factory::get()->registerProxyCreateMethod(
        "commonapi.AEB:v1_0",
        &createAEBSomeIPProxy);
}

INITIALIZER(registerAEBSomeIPProxy) {
    CommonAPI::SomeIP::Factory::get()->registerInterface(initializeAEBSomeIPProxy);
}

AEBSomeIPProxy::AEBSomeIPProxy(
    const CommonAPI::SomeIP::Address &_address,
    const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection)
        : CommonAPI::SomeIP::Proxy(_address, _connection),
          status_(*this, 0x8004, CommonAPI::SomeIP::event_id_t(0x8004), CommonAPI::SomeIP::event_type_e::ET_EVENT , CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE, false, std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)))
{
}

AEBSomeIPProxy::~AEBSomeIPProxy() {
    completed_.set_value();
}


AEBSomeIPProxy::StatusEvent& AEBSomeIPProxy::getStatusEvent() {
    return status_;
}

void AEBSomeIPProxy::OnOff(uint8_t _setStatus, CommonAPI::CallStatus &_internalCallStatus, bool &_getStatus, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> deploy_setStatus(_setStatus, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr));
    CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_getStatus(static_cast< CommonAPI::EmptyDeployment* >(nullptr));
    CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                uint8_t,
                CommonAPI::SomeIP::IntegerDeployment<uint8_t>
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                bool,
                CommonAPI::EmptyDeployment
            >
        >
    >::callMethodWithReply(
        *this,
        CommonAPI::SomeIP::method_id_t(0x2af8),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_setStatus,
        _internalCallStatus,
        deploy_getStatus);
    _getStatus = deploy_getStatus.getValue();
}

std::future<CommonAPI::CallStatus> AEBSomeIPProxy::OnOffAsync(const uint8_t &_setStatus, OnOffAsyncCallback _callback, const CommonAPI::CallInfo *_info) {
    CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> deploy_setStatus(_setStatus, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr));
    CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment> deploy_getStatus(static_cast< CommonAPI::EmptyDeployment* >(nullptr));
    return CommonAPI::SomeIP::ProxyHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                uint8_t,
                CommonAPI::SomeIP::IntegerDeployment<uint8_t>
            >
        >,
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                bool,
                CommonAPI::EmptyDeployment
            >
        >
    >::callMethodAsync(
        *this,
        CommonAPI::SomeIP::method_id_t(0x2af8),
        false,
        false,
        (_info ? _info : &CommonAPI::SomeIP::defaultCallInfo),
        deploy_setStatus,
        [_callback] (CommonAPI::CallStatus _internalCallStatus, CommonAPI::Deployable< bool, CommonAPI::EmptyDeployment > _getStatus) {
            if (_callback)
                _callback(_internalCallStatus, _getStatus.getValue());
        },
        std::make_tuple(deploy_getStatus));
}

void AEBSomeIPProxy::getOwnVersion(uint16_t& ownVersionMajor, uint16_t& ownVersionMinor) const {
    ownVersionMajor = 1;
    ownVersionMinor = 0;
}

std::future<void> AEBSomeIPProxy::getCompletionFuture() {
    return completed_.get_future();
}

} // namespace commonapi
} // namespace v1

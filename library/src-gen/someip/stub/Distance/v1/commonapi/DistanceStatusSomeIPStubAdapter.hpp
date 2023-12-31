/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_DISTANCE_STATUS_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_DISTANCE_STATUS_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/DistanceStatusStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::DistanceStatusStub, typename... _Stubs>
class DistanceStatusSomeIPStubAdapterInternal
    : public virtual DistanceStatusStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< DistanceStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> DistanceStatusSomeIPStubAdapterHelper;

    ~DistanceStatusSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        DistanceStatusSomeIPStubAdapterHelper::deinit();
    }

    void fireDistanceAttributeChanged(const uint8_t &_value);
    
    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::DistanceStatusStub,
        CommonAPI::Version
    > getDistanceStatusInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::DistanceStatusStub,
        uint8_t,
        CommonAPI::SomeIP::IntegerDeployment<uint8_t>
    > getDistanceAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::commonapi::DistanceStatusStub,
        uint8_t,
        CommonAPI::SomeIP::IntegerDeployment<uint8_t>
    > setDistanceAttributeStubDispatcher;
    
    DistanceStatusSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        DistanceStatusSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< DistanceStatusStub>(_stub)),
        getDistanceStatusInterfaceVersionStubDispatcher(&DistanceStatusStub::lockInterfaceVersionAttribute, &DistanceStatusStub::getInterfaceVersion, false, true),
        getDistanceAttributeStubDispatcher(
            &::v1::commonapi::DistanceStatusStub::lockDistanceAttribute,
            &::v1::commonapi::DistanceStatusStub::getDistanceAttribute,
            false,
            _stub->hasElement(0)),
        setDistanceAttributeStubDispatcher(
            &::v1::commonapi::DistanceStatusStub::lockDistanceAttribute,
            &::v1::commonapi::DistanceStatusStub::getDistanceAttribute,
            &DistanceStatusStubRemoteEvent::onRemoteSetDistanceAttribute,
            &DistanceStatusStubRemoteEvent::onRemoteDistanceAttributeChanged,
            &DistanceStatusStubAdapter::fireDistanceAttributeChanged,
            false,
            _stub->hasElement(0))
    {
        DistanceStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2710) }, &getDistanceAttributeStubDispatcher );
        DistanceStatusSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2711) }, &setDistanceAttributeStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>(0xFFFF, 0xFFFFFFFF, 0xFFFFFFFF);

        // Provided events/fields
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x814c)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x814c), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireDistanceAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::DistanceStatusStub>(_stub)->getDistanceAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void DistanceStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireDistanceAttributeChanged(const uint8_t &_value) {
    CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> deployedValue(_value, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            CommonAPI::Deployable<
                uint8_t,
                CommonAPI::SomeIP::IntegerDeployment<uint8_t>
            >
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x814c),
        false,
        deployedValue
    );
}


template <typename _Stub, typename... _Stubs>
void DistanceStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void DistanceStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::DistanceStatusStub, typename... _Stubs>
class DistanceStatusSomeIPStubAdapter
    : public DistanceStatusSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    DistanceStatusSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          DistanceStatusSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_Distance_Status_SOMEIP_STUB_ADAPTER_HPP_

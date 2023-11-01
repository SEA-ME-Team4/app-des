/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.0.v202012010944.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_AEB_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_AEB_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/AEBStub.hpp>

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

template <typename _Stub = ::v1::commonapi::AEBStub, typename... _Stubs>
class AEBSomeIPStubAdapterInternal
    : public virtual AEBStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< AEBSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> AEBSomeIPStubAdapterHelper;

    ~AEBSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        AEBSomeIPStubAdapterHelper::deinit();
    }

    void fireStatusEvent(const uint8_t &_status);

    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::AEBStub,
        CommonAPI::Version
    > getAEBInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::MethodWithReplyStubDispatcher<
        ::v1::commonapi::AEBStub,
        std::tuple< uint8_t>,
        std::tuple< bool>,
        std::tuple< CommonAPI::SomeIP::IntegerDeployment<uint8_t>>,
        std::tuple< CommonAPI::EmptyDeployment>
    > onOffStubDispatcher;
    
    AEBSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        AEBSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< AEBStub>(_stub)),
        getAEBInterfaceVersionStubDispatcher(&AEBStub::lockInterfaceVersionAttribute, &AEBStub::getInterfaceVersion, false, true),
        onOffStubDispatcher(
            &AEBStub::OnOff,
            false,
            _stub->hasElement(1),
            std::make_tuple(static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr)),
            std::make_tuple(static_cast< CommonAPI::EmptyDeployment* >(nullptr)))
        
    {
        AEBSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0x2af8) }, &onOffStubDispatcher );
        // Provided events/fields
        {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(0x8004));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x8004), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_EVENT, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
        }
    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void AEBSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireStatusEvent(const uint8_t &_status) {
    CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t>> deployed_status(_status, static_cast< CommonAPI::SomeIP::IntegerDeployment<uint8_t>* >(nullptr));
    CommonAPI::SomeIP::StubEventHelper<CommonAPI::SomeIP::SerializableArguments<  CommonAPI::Deployable< uint8_t, CommonAPI::SomeIP::IntegerDeployment<uint8_t> > 
    >>
        ::sendEvent(
            *this,
            CommonAPI::SomeIP::event_id_t(0x8004),
            false,
             deployed_status 
    );
}


template <typename _Stub, typename... _Stubs>
void AEBSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {
}

template <typename _Stub, typename... _Stubs>
void AEBSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {
}

template <typename _Stub = ::v1::commonapi::AEBStub, typename... _Stubs>
class AEBSomeIPStubAdapter
    : public AEBSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    AEBSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          AEBSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_AEB_SOMEIP_STUB_ADAPTER_HPP_

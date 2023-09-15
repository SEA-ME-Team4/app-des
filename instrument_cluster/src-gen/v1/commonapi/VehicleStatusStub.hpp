/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_Vehicle_Status_STUB_HPP_
#define V1_COMMONAPI_Vehicle_Status_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/commonapi/VehicleStatus.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif


#include <mutex>

#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service VehicleStatus. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class VehicleStatusStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual VehicleStatus {
 public:
    ///Notifies all remote listeners about a change of value of the attribute Speed.
    virtual void fireSpeedAttributeChanged(const int16_t &Speed) = 0;
    ///Notifies all remote listeners about a change of value of the attribute Battery.
    virtual void fireBatteryAttributeChanged(const uint8_t &Battery) = 0;
    ///Notifies all remote listeners about a change of value of the attribute Brake.
    virtual void fireBrakeAttributeChanged(const bool &Brake) = 0;
    ///Notifies all remote listeners about a change of value of the attribute Temp.
    virtual void fireTempAttributeChanged(const int16_t &Temp) = 0;


    virtual void deactivateManagedInstances() = 0;

    void lockSpeedAttribute(bool _lockAccess) {
        if (_lockAccess) {
            speedMutex_.lock();
        } else {
            speedMutex_.unlock();
        }
    }
    void lockBatteryAttribute(bool _lockAccess) {
        if (_lockAccess) {
            batteryMutex_.lock();
        } else {
            batteryMutex_.unlock();
        }
    }
    void lockBrakeAttribute(bool _lockAccess) {
        if (_lockAccess) {
            brakeMutex_.lock();
        } else {
            brakeMutex_.unlock();
        }
    }
    void lockTempAttribute(bool _lockAccess) {
        if (_lockAccess) {
            tempMutex_.lock();
        } else {
            tempMutex_.unlock();
        }
    }

protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */
    std::recursive_mutex speedMutex_;
    std::recursive_mutex batteryMutex_;
    std::recursive_mutex brakeMutex_;
    std::recursive_mutex tempMutex_;

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for VehicleStatus.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class VehicleStatusStubRemoteEvent
{
public:
    virtual ~VehicleStatusStubRemoteEvent() { }

    /// Verification callback for remote set requests on the attribute Speed
    virtual bool onRemoteSetSpeedAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int16_t _value) = 0;
    /// Action callback for remote set requests on the attribute Speed
    virtual void onRemoteSpeedAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute Battery
    virtual bool onRemoteSetBatteryAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, uint8_t _value) = 0;
    /// Action callback for remote set requests on the attribute Battery
    virtual void onRemoteBatteryAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute Brake
    virtual bool onRemoteSetBrakeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, bool _value) = 0;
    /// Action callback for remote set requests on the attribute Brake
    virtual void onRemoteBrakeAttributeChanged() = 0;
    /// Verification callback for remote set requests on the attribute Temp
    virtual bool onRemoteSetTempAttribute(const std::shared_ptr<CommonAPI::ClientId> _client, int16_t _value) = 0;
    /// Action callback for remote set requests on the attribute Temp
    virtual void onRemoteTempAttributeChanged() = 0;
};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service VehicleStatus to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class VehicleStatusStub
    : public virtual CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>
{
public:

    virtual ~VehicleStatusStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 4);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Provides getter access to the attribute Speed
    virtual const int16_t &getSpeedAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireSpeedAttributeChanged(int16_t _value) {
    auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireSpeedAttributeChanged(_value);
    }
    void lockSpeedAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockSpeedAttribute(_lockAccess);
    }
    /// Provides getter access to the attribute Battery
    virtual const uint8_t &getBatteryAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireBatteryAttributeChanged(uint8_t _value) {
    auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireBatteryAttributeChanged(_value);
    }
    void lockBatteryAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockBatteryAttribute(_lockAccess);
    }
    /// Provides getter access to the attribute Brake
    virtual const bool &getBrakeAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireBrakeAttributeChanged(bool _value) {
    auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireBrakeAttributeChanged(_value);
    }
    void lockBrakeAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockBrakeAttribute(_lockAccess);
    }
    /// Provides getter access to the attribute Temp
    virtual const int16_t &getTempAttribute(const std::shared_ptr<CommonAPI::ClientId> _client) = 0;
    /// sets attribute with the given value and propagates it to the adapter
    virtual void fireTempAttributeChanged(int16_t _value) {
    auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
    if (stubAdapter)
        stubAdapter->fireTempAttributeChanged(_value);
    }
    void lockTempAttribute(bool _lockAccess) {
        auto stubAdapter = CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->lockTempAttribute(_lockAccess);
    }


    using CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<VehicleStatusStubAdapter, VehicleStatusStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef VehicleStatusStubRemoteEvent RemoteEventType;
    typedef VehicleStatus StubInterface;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_Vehicle_Status_STUB_HPP_
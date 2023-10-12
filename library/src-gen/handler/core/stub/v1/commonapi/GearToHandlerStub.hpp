/*
* This file was generated by the CommonAPI Generators.
* Used org.genivi.commonapi.core 3.2.0.v202012010850.
* Used org.franca.core 0.13.1.201807231814.
*
* This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
* If a copy of the MPL was not distributed with this file, You can obtain one at
* http://mozilla.org/MPL/2.0/.
*/
#ifndef V1_COMMONAPI_Gear_To_Handler_STUB_HPP_
#define V1_COMMONAPI_Gear_To_Handler_STUB_HPP_

#include <functional>
#include <sstream>




#include <v1/commonapi/GearToHandler.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <unordered_set>
#include <vector>


#include <CommonAPI/Stub.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

/**
 * Receives messages from remote and handles all dispatching of deserialized calls
 * to a stub for the service GearToHandler. Also provides means to send broadcasts
 * and attribute-changed-notifications of observable attributes as defined by this service.
 * An application developer should not need to bother with this class.
 */
class GearToHandlerStubAdapter
    : public virtual CommonAPI::StubAdapter,
      public virtual GearToHandler {
 public:
    /**
    * Sends a broadcast event for GearStatusEvent. Should not be called directly.
    * Instead, the "fire<broadcastName>Event" methods of the stub should be used.
    */
    virtual void fireGearStatusEventEvent(const bool &_Status) = 0;


    virtual void deactivateManagedInstances() = 0;


protected:
    /**
     * Defines properties for storing the ClientIds of clients / proxies that have
     * subscribed to the selective broadcasts
     */

};

/**
 * Defines the necessary callbacks to handle remote set events related to the attributes
 * defined in the IDL description for GearToHandler.
 * For each attribute two callbacks are defined:
 * - a verification callback that allows to verify the requested value and to prevent setting
 *   e.g. an invalid value ("onRemoteSet<AttributeName>").
 * - an action callback to do local work after the attribute value has been changed
 *   ("onRemote<AttributeName>Changed").
 *
 * This class and the one below are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class GearToHandlerStubRemoteEvent
{
public:
    virtual ~GearToHandlerStubRemoteEvent() { }

};

/**
 * Defines the interface that must be implemented by any class that should provide
 * the service GearToHandler to remote clients.
 * This class and the one above are the ones an application developer needs to have
 * a look at if he wants to implement a service.
 */
class GearToHandlerStub
    : public virtual CommonAPI::Stub<GearToHandlerStubAdapter, GearToHandlerStubRemoteEvent>
{
public:

    virtual ~GearToHandlerStub() {}
    void lockInterfaceVersionAttribute(bool _lockAccess) { static_cast<void>(_lockAccess); }
    bool hasElement(const uint32_t _id) const {
        return (_id < 1);
    }
    virtual const CommonAPI::Version& getInterfaceVersion(std::shared_ptr<CommonAPI::ClientId> _client) = 0;

    /// Sends a broadcast event for GearStatusEvent.
    virtual void fireGearStatusEventEvent(const bool &_Status) {
        auto stubAdapter = CommonAPI::Stub<GearToHandlerStubAdapter, GearToHandlerStubRemoteEvent>::stubAdapter_.lock();
        if (stubAdapter)
            stubAdapter->fireGearStatusEventEvent(_Status);
    }


    using CommonAPI::Stub<GearToHandlerStubAdapter, GearToHandlerStubRemoteEvent>::initStubAdapter;
    typedef CommonAPI::Stub<GearToHandlerStubAdapter, GearToHandlerStubRemoteEvent>::StubAdapterType StubAdapterType;
    typedef CommonAPI::Stub<GearToHandlerStubAdapter, GearToHandlerStubRemoteEvent>::RemoteEventHandlerType RemoteEventHandlerType;
    typedef GearToHandlerStubRemoteEvent RemoteEventType;
    typedef GearToHandler StubInterface;
};

} // namespace commonapi
} // namespace v1


// Compatibility
namespace v1_0 = v1;

#endif // V1_COMMONAPI_Gear_To_Handler_STUB_HPP_
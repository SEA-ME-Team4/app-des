#ifndef GEARSERVICE_H
#define GEARSERVICE_H

#include <thread>
#include <iostream>

#include <CommonAPI/CommonAPI.hpp>
#include "GearStatusStubImpl.hpp"
#include <v1/commonapi/BrakeStatusProxy.hpp>
#include <v1/commonapi/ToApplicationProxy.hpp>
#include <v1/commonapi/GearToHandlerStubDefault.hpp>
#include <QObject>

using namespace v1_0::commonapi;

class VehicleStatus: public QObject {
    Q_OBJECT
    
public:
    VehicleStatus();
    ~VehicleStatus();

    Q_INVOKABLE void sendGear(quint8 gear);

signals:
    void brakeChanged(bool brake);

    void speedStatus(bool status);
    void batteryStatus(bool status);
    void inputStatus(bool status);
    void racerStatus(bool status);
    void gearStatus(bool status);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusStubImpl> gearService;
    std::shared_ptr<GearToHandlerStubDefault> statusService;
    std::shared_ptr<BrakeStatusProxy<>> brakeProxy;
    std::shared_ptr<ToApplicationProxy<>> errorProxy;
    int gear;

    void gearServiceInit();
    void brakeProxyInit();
    void statusServiceInit();
    void errorProxyInit();
};

#endif

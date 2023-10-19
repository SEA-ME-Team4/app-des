#ifndef GEARSERVICE_H
#define GEARSERVICE_H

#include <thread>
#include <iostream>

#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/BrakeStatusProxy.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>
#include "GearStatusStubImpl.hpp"
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
    void speedChanged(bool speed);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusStubImpl> gearService;
    std::shared_ptr<BrakeStatusProxy<>> brakeProxy;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy;
    int gear;

    void gearServiceInit();
    void brakeProxyInit();
    void speedProxyInit();
};

#endif

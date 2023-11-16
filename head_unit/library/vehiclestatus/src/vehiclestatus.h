#ifndef GEARSERVICE_H
#define GEARSERVICE_H

#include <thread>
#include <iostream>

#include <CommonAPI/CommonAPI.hpp>
#include "GearSelectorStubImpl.hpp"
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/InputStatusProxy.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>
#include <v1/commonapi/DistanceStatusProxy.hpp>
#include <QObject>
#include <QtQml>
#include <QQmlExtensionPlugin>

using namespace v1_0::commonapi;

class VehicleStatus: public QObject {
    Q_OBJECT
    
public:
    VehicleStatus();
    ~VehicleStatus();

Q_INVOKABLE void sendGear(quint8 gear);
Q_INVOKABLE int getGear();
Q_INVOKABLE bool getBrake();
Q_INVOKABLE int getSpeed();
Q_INVOKABLE int getDistance();

signals:
    void gearChanged(int gear);
    void brakeChanged(bool brake);
    void speedChanged(int speed);
    void distanceChanged(int distance);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearSelectorStubImpl> gearselectorService;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<InputStatusProxy<>> inputProxy;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy;
    std::shared_ptr<DistanceStatusProxy<>> distanceProxy;

    void gearselectorServiceInit();
    void gearProxyInit();
    void inputProxyInit();
    void speedProxyInit();
    void distanceProxyInit();
    
    int gear;
    bool brake;
    int speed;
    int distance;
    bool gearHere;
};

#endif

#ifndef GEARSERVICE_H
#define GEARSERVICE_H

#include <thread>
#include <iostream>

#include <CommonAPI/CommonAPI.hpp>
#include "GearStatusStubImpl.hpp"
#include <QObject>

using namespace v1_0::commonapi;

class VehicleStatus: public QObject {
    Q_OBJECT
    
public:
    VehicleStatus();
    ~VehicleStatus();

    Q_INVOKABLE void sendGear(quint8 gear);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusStubImpl> gearService;
    int gear;

    void gearServiceInit();
};

#endif

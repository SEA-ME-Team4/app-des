#ifndef GEARSERVICE_H
#define GEARSERVICE_H

#include <thread>
#include <iostream>

#include <CommonAPI/CommonAPI.hpp>
#include "GearStatusStubImpl.hpp"
#include <QObject>

class GearService: public QObject {
    Q_OBJECT
    
public:
    GearService();
    ~GearService();

    Q_INVOKABLE void sendGear(quint8 gear);

// public slots:
//     void setGear(int gear);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<GearStatusStubImpl> myService;
    int gear;
};

#endif

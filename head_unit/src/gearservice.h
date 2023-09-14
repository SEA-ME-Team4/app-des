#ifndef GEARSERVICE_H
#define GEARSERVICE_H

#include <thread>
#include <iostream>

#include <CommonAPI/CommonAPI.hpp>
#include "HeadUnitStubImpl.hpp"
#include <QObject>

class GearService: public QObject {
    Q_OBJECT
    
public:
    GearService(/* args */);
    ~GearService();

    Q_INVOKABLE void sendGear(int gear);

// public slots:
//     void setGear(int gear);

private:
    std::shared_ptr<CommonAPI::Runtime> runtime;
    std::shared_ptr<HeadUnitStubImpl> myService;
    int gear;
};

#endif

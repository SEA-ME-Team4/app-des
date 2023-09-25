#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/SpeedStatusProxy.hpp>
#include <v1/commonapi/BatteryStatusProxy.hpp>
#include <v1/commonapi/BrakeStatusProxy.hpp>
#include <v1/commonapi/TempStatusProxy.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <v1/commonapi/ToApplicationProxy.hpp>
#include <QObject>

using namespace v1_0::commonapi;

class VehicleClient: public QObject {
    Q_OBJECT

public:
    VehicleClient();
    ~VehicleClient();

signals:
    void speedChanged(qint16 speed);
    void batteryChanged(quint8 battery);
    void brakeChanged(bool brake);
    void tempChanged(qint16 temp);
    void gearChanged(quint8 gear);

    void speedStatus(bool status);
    void batteryStatus(bool status);
    void inputStatus(bool status);
    void racerStatus(bool status);
    void gearStatus(bool status);

private:
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<SpeedStatusProxy<>> speedProxy;
    std::shared_ptr<BatteryStatusProxy<>> batteryProxy;
    std::shared_ptr<BrakeStatusProxy<>> brakeProxy;
    std::shared_ptr<TempStatusProxy<>> tempProxy;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
    std::shared_ptr<ToApplicationProxy<>> errorProxy;

    void speedClient();
    void batteryClient();
    void brakeClient();
    void tempClient();
    void gearClient();
    void errorClient();
};

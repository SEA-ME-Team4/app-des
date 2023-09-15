#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/VehicleStatusProxy.hpp>
#include <QObject>

using namespace v1_0::commonapi;

class VehicleClient: public QObject {
    Q_OBJECT

public:
    VehicleClient();
    ~VehicleClient();

    void speedClient();
    void batteryClient();
    void brakeClient();
    void tempClient();

signals:
    void speedChanged(qint16 speed);
    void batteryChanged(quint8 battery);
    void brakeChanged(bool brake);
    void tempChanged(qint16 temp);

private:
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<VehicleStatusProxy<>> vehicleProxy;
};

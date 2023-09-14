#include <iostream>
#include <string>
#include <unistd.h>
#include <CommonAPI/CommonAPI.hpp>
#include <v1/commonapi/GearStatusProxy.hpp>
#include <QObject>

using namespace v1_0::commonapi;

class GearClient: public QObject {
    Q_OBJECT

public:
    GearClient();
    ~GearClient();

signals:
    void gearChanged(quint8 gear);

private:
    std::shared_ptr < CommonAPI::Runtime > runtime;
    std::shared_ptr<GearStatusProxy<>> gearProxy;
};

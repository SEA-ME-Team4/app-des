#include "plugin.h"

void Plugin::registerTypes(const char* uri)
{
    qmlRegisterType<VehicleStatus>(uri, 1, 0, "VehicleStatus");
}
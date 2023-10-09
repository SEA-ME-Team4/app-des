#include "piracer.h"
#include "battery.h"

int main() {
    Piracer piracer = Piracer();
    Battery battery = Battery();
    
    while (1) {
        battery.setBattery(piracer.getVoltage());
        usleep(10000);
    }   
}
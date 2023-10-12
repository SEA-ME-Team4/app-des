#include "piracer.h"
#include "battery.h"

int main() {
    uint8_t battery_percent = 0; 

    Piracer piracer = Piracer();
    Battery battery = Battery();
    
    while (1) {
        battery_percent = ((((piracer.getVoltage() / 3) - 3.1) / 1.1) * 100);
        battery.setBattery(battery_percent);
        usleep(10000);
    }   
}
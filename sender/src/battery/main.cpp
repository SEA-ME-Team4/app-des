#include "piracer.h"
#include "battery.h"

int main() {
    uint8_t battery_percent = 0; 

    Battery battery = Battery();
    Piracer piracer = Piracer();
    
    while (1) {
        battery_percent = ((((piracer.getVoltage() / 3) - 3.1) / 1.1) * 100);
        battery.setBattery(battery_percent);
        usleep(10000);
    }   
}
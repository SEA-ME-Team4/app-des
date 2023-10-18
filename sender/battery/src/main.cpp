#include "piracer.h"
#include "battery.h"

#include <iostream>

int main() {
    uint8_t battery_percent = 0; 

    Battery battery = Battery();
    Piracer piracer = Piracer();
    
    while (1) {
        std::cout<<"voltage : "<<piracer.getVoltage()<<std::endl;
        battery_percent = ((((piracer.getVoltage() / 3) - 3.1) / 1.1) * 100);
        std::cout<<"percent : "<<battery_percent<<std::endl;
        battery.setBattery(battery_percent);
        usleep(10000);
    }   
}
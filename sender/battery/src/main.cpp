#include "piracer.h"
#include "battery.h"

#include <algorithm>
#include <iostream>
#include <deque>

int main() {
    Battery battery = Battery();
    Piracer piracer = Piracer();

    uint8_t battery_percent = 0; 
    std::deque<uint8_t> battery_filter = {};
    std::deque<uint8_t>::iterator battery_filter_iterator;
    uint8_t filtered_battery_percent = 0;
    
    while (1) {
        std::cout<<"voltage : "<<piracer.getVoltage()<<std::endl;
        battery_percent = (uint8_t)((((piracer.getVoltage() / 3) - 3.1) / 1.1) * 100);
        std::cout<<"percent : "<<battery_percent<<std::endl;

        // Percentage Threshold
        if ((battery_percent-100)>0) {battery_percent = 100;}
        else if ((battery_percent)<0) {battery_percent = 0;}
        
        // Filter Deque
        battery_filter.push_back(battery_percent);
        if (battery_filter.size()>100) {battery_filter.pop_front();}

        // Find maximun value
        battery_filter_iterator = std::max_element(std::begin(battery_filter), std::end(battery_filter));
        filtered_battery_percent = *battery_filter_iterator;
        std::cout<<"filtered percent : "<<filtered_battery_percent<<std::endl;

        // Send Filtered Battery Percentage 
        battery.setBattery(filtered_battery_percent);
        usleep(10000);
    }   
}
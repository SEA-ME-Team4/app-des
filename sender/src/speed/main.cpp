#include "canreceiver.h"
#include "speed.h"

int main() {
    Speed speed = Speed();
    // Arduino Speed Sender ID: 0x0F6
    CanReceiver canreceiver = CanReceiver("can0", 0x0F6);

    int16_t filtered_speed = 0;
    float weight = 0.6;

    while (canreceiver.canRead()) {
        filtered_speed = (1-weight)*filtered_speed + (weight)*canreceiver.getSpeed();
        speed.setSpeed(filtered_speed);
    }
    
}
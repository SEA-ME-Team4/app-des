#include "canreceiver.h"
#include "speed.h"

int main() {
    // Arduino Speed Sender ID: 0x0F6
    CanReceiver canreceiver = CanReceiver("vcan0", 0x0F6); 
    Speed speed = Speed();

    while (canreceiver.canRead()) {
        speed.setSpeed(canreceiver.getSpeed());
    }
    
}
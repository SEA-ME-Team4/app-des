#include "canreceiver.h"
#include "can_app.h"
// Arduino Speed Sender ID: 0x0F6
// Arduino Distance Sender ID: 0x0D4
#define SPEED_ID 0x0F6
#define DISTANCE_ID 0x0D4

int main() {
    Can_App can_app = Can_App();
    CanReceiver canreceiver = CanReceiver("can0", SPEED_ID, DISTANCE_ID);

    int16_t filtered_speed = 0;
    float speed_filter_weight = 0.6;

    while (canreceiver.canRead()) {
        switch (canreceiver.getID()) {
            case SPEED_ID:
                filtered_speed = (1-speed_filter_weight)*filtered_speed + (speed_filter_weight)*canreceiver.getSpeed();
                can_app.setSpeed(filtered_speed);
                break;
            case DISTANCE_ID:
                can_app.setDistance(canreceiver.getDistance());
                break;
        }
    }
}
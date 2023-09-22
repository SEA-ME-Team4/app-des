#include "piracer.h"
#include "racerclient.h"

int main() {
    int gear;
    bool brake;
    float steering;
    float throttle;

    Piracer piracer = Piracer();
    RacerClient racerclient = RacerClient();
    
    while (racerclient.validCheck()) {
        gear = racerclient.getGear();
        brake = racerclient.getBrake();
        steering = racerclient.getSteering();
        throttle = racerclient.getThrottle();

        piracer.setRacer(gear, brake, steering, throttle);
    }
    piracer.emergencyStop();
}
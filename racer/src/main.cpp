#include "piracer.h"
#include "racerclient.h"

int main() {
    int gear=0;
    bool brake=true;
    float steering=0;
    float throttle=0;

    RacerClient racerclient = RacerClient();
    Piracer piracer = Piracer();
    
    while (1) {
        if (racerclient.validCheck()) {
            gear = racerclient.getGear();
            brake = racerclient.getBrake();
            steering = racerclient.getSteering();
            throttle = racerclient.getThrottle();

            piracer.setRacer(gear, brake, steering, throttle);
            sleep(0.01);
        }
        else {
            piracer.emergencyStop();
            sleep(1);
        }
    }
}
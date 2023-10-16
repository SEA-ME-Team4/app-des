#include "gamepad.h"
#include "input.h"

int main() {
    Input input = Input();
    Gamepad gamepad = Gamepad();

    // Check Initial Status
    if (gamepad.getStatus()) {
        gamepad.setInitStatus(true);
        // Check Connection
        while (gamepad.read_data()) {
            input.setBrake(gamepad.getBrake());
            input.setSteering(gamepad.getSteering());
            input.setThrottle(gamepad.getThrottle());
            input.setStatusEvent(true);

            std::cout << "getBrake: " << gamepad.getBrake() << '\n';
            std::cout << "getSteering: " << gamepad.getSteering() << '\n';
            std::cout << "getThrottle: " << gamepad.getThrottle() << '\n' << std::endl;
        }
        // Emergency Stop
        input.setBrake(true);
        input.setSteering(0);
        input.setThrottle(0);
        std::cout << "\nReturn: Gamepad Connection Lost\n" << std::endl;
    }
    else {
        // Emergency Stop
        input.setBrake(true);
        input.setSteering(0);
        input.setThrottle(0);
        std::cout<<"\nReturn: Gamepad is Not Connected\n"<<std::endl;
    }
    return 0;
}
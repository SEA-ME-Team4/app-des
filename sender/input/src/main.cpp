#include "gamepad.h"
#include "input.h"

int main() {
    Input input = Input();
    Gamepad gamepad = Gamepad();
    // Check Initial Status
    if (gamepad.getStatus()) {
        gamepad.setInitStatus(true);
        gamepad.setGear(input.getGear());
        // Check Connection
        while (gamepad.read_data()) {
            input.setBrake(gamepad.getBrake());
            input.setSteering(gamepad.getSteering());
            input.setThrottle(gamepad.getThrottle());
            input.sendGear(gamepad.getGear());

            std::cout << "getBrake: " << gamepad.getBrake() << '\n';
            std::cout << "getSteering: " << gamepad.getSteering() << '\n';
            std::cout << "getThrottle: " << gamepad.getThrottle() << '\n';
            std::cout << "getGear: " << gamepad.getGear() << '\n' << std::endl;
        }
        // Emergency Stop
        input.setSteering(0);
        input.setThrottle(0);
        std::cout << "\nReturn: Gamepad Connection Lost\n" << std::endl;
    }
    else {
        // Emergency Stop
        input.setSteering(0);
        input.setThrottle(0);
        std::cout<<"\nReturn: Gamepad is Not Connected\n"<<std::endl;
    }
    return 0;
}
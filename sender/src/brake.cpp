#include "gamepad.h"
#include <iostream>

int main()
{
    Gamepad gamepad = Gamepad();

    while (gamepad.read_data())
    {
        std::cout<<gamepad.gamepad_inputLX<<'\t'<<gamepad.gamepad_inputRY<<'\n';
    }
    
}
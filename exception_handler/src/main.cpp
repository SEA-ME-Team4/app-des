#include "handler.h"

#define HANDLE_INTERVAL 100000 //micro (Faster than VALUE_INTERVAL_MAX)

int main() {
    Handler handler = Handler();

    while (!usleep(HANDLE_INTERVAL)) {
        handler.handlerProcess();
    }
}
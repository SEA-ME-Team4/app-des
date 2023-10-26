#include "handler.h"

#define HANDLE_INTERVAL 50000 //micro (Faster than VALUE_INTERVAL_MAX)

int main() {
    Handler handler = Handler();
    sleep(1);
    while (!usleep(HANDLE_INTERVAL)) {
        handler.handlerProcess();
    }
}
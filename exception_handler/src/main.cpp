#include "handler.h"

int main() {
    Handler handler = Handler();

    while (1) {
        handler.handlerProcess();
    // std::time_t oldt = std::time({});
    //         auto const now = std::chrono::system_clock::now();
    // std::time_t newt = std::chrono::system_clock::to_time_t(now);
 
    // std::cout << "newt - oldt == " << newt - oldt << " s\n";
        usleep(1000);
    }
}
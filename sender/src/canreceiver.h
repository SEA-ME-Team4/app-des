#include <linux/can.h>
#include <net/if.h>
#include <cstring>
#include <sys/ioctl.h>
#include <unistd.h>

#include <iostream>

class CanReceiver
{
public:
    CanReceiver(const char* port_name);
    ~CanReceiver();
    bool canRead();
    int16_t getSpeed();

private:
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_frame frame;
    int nbytes;
    int16_t speed;
    int decimal0, decimal1, decimal2;
};

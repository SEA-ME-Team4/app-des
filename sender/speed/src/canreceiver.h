#include <linux/can.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <linux/can/raw.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

class CanReceiver
{
public:
    CanReceiver(const char* port_name, canid_t can_id);
    ~CanReceiver();
    bool canRead();
    int16_t getSpeed();

private:
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_filter rfilter[2];
    struct can_frame frame;
    int nbytes;
    float speed;
    int decimal0, decimal1, decimal2;
};

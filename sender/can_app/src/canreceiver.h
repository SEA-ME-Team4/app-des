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
    CanReceiver(const char* port_name, canid_t can_id_1, canid_t can_id_2);
    ~CanReceiver();
    bool canRead();
    canid_t getID();
    int16_t getSpeed();
    uint8_t getDistance();

private:
    int s;
    struct sockaddr_can addr;
    struct ifreq ifr;
    struct can_filter rfilter[2];
    struct can_frame frame;
    int nbytes;
    float speed;
    float distance;
    int speed_decimal0, speed_decimal1, speed_decimal2;
    int distance_decimal0, distance_decimal1, distance_decimal2;
};

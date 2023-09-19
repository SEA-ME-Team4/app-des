#include "canreceiver.h"

CanReceiver::CanReceiver(const char* port_name) {
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    strcpy(ifr.ifr_name, port_name);
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));
}

CanReceiver::~CanReceiver() {
}

bool CanReceiver::canRead() {
    nbytes = read(s, &frame, sizeof(struct can_frame));

    if (nbytes < 0) {
        std::cout<<"can raw socket read";
        return false;
    }
    if (nbytes < sizeof(struct can_frame)) {
        std::cout<<(stderr, "read: incomplete CAN frame\n");
        return false;
    }
    return true;
}

int16_t CanReceiver::getSpeed() {
    // #define slave 0x0F6
    // std::cout<<frame.can_id<<'\t'<<frame.can_dlc<<'\n';
    // std::cout << frame.data[0] << std::endl;
    // std::cout << frame.data[1] << std::endl;
    // std::cout << frame.data[2] << '\n' << std::endl;

    // speed = (decimal0*256)  + decimal1 + (decimal2*0.01);
    // return (float)speed;
    return 0;
}
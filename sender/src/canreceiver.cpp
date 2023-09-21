#include "canreceiver.h"

CanReceiver::CanReceiver(const char* port_name, canid_t can_id) {
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    strcpy(ifr.ifr_name, port_name);
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    rfilter[0].can_id = can_id;
    rfilter[0].can_mask = (CAN_EFF_FLAG | CAN_RTR_FLAG | CAN_SFF_MASK);

    setsockopt(s, SOL_CAN_RAW, CAN_RAW_FILTER, &rfilter, sizeof(rfilter));
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
    decimal0 = static_cast<int>(frame.data[0]);
    decimal1 = static_cast<int>(frame.data[1]);
    decimal2 = static_cast<int>(frame.data[2]);
    speed = (decimal0*256) + decimal1 + (decimal2*0.01);


    // std::cout << "frame.can_id: "<< frame.can_id << std::endl;
    // std::cout << decimal0 << std::endl;
    // std::cout << decimal1 << std::endl;
    // std::cout << decimal2 << std::endl;
    // std::cout << "speed: "<< speed << '\n' << std::endl;

    return (int16_t)speed;
}
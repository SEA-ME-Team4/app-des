#include "canreceiver.h"

CanReceiver::CanReceiver(const char* port_name, canid_t can_id_1, canid_t can_id_2) {
    s = socket(PF_CAN, SOCK_RAW, CAN_RAW);

    strcpy(ifr.ifr_name, port_name);
    ioctl(s, SIOCGIFINDEX, &ifr);

    addr.can_family = AF_CAN;
    addr.can_ifindex = ifr.ifr_ifindex;

    bind(s, (struct sockaddr *)&addr, sizeof(addr));

    rfilter[0].can_id = can_id_1;
    rfilter[0].can_mask = (CAN_EFF_FLAG | CAN_RTR_FLAG | CAN_SFF_MASK);

    rfilter[1].can_id = can_id_2;
    rfilter[1].can_mask = (CAN_EFF_FLAG | CAN_RTR_FLAG | CAN_SFF_MASK);

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

canid_t CanReceiver::getID() {
    return frame.can_id;
}


int16_t CanReceiver::getSpeed() {
    speed_decimal0 = static_cast<int>(frame.data[0]);
    speed_decimal1 = static_cast<int>(frame.data[1]);
    speed_decimal2 = static_cast<int>(frame.data[2]);

    speed = (speed_decimal0*256) + speed_decimal1 + (speed_decimal2*0.01);
    return (int16_t)speed;
}

uint8_t CanReceiver::getDistance() {
    distance_decimal0 = static_cast<int>(frame.data[0]);
    distance_decimal1 = static_cast<int>(frame.data[1]);
    distance_decimal2 = static_cast<int>(frame.data[2]);
    
    distance = (distance_decimal0*256) + distance_decimal1 + (distance_decimal2*0.01);
    return (uint8_t)distance;
}
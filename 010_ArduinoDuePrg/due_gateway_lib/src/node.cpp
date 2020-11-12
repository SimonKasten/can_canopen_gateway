#include "node.h"


void Node::set_nmt_state(uint16_t state)
{
    nmt_state = state;

    CAN_FRAME init_Msg;
    init_Msg.id = 0x0;
    init_Msg.length = 2;
    init_Msg.data.byte[0] = state;
    init_Msg.data.byte[1] = id;

    Can0.sendFrame(init_Msg);
}

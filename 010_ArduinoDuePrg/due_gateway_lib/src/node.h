#pragma once

#include <stdint.h>
#include "variant.h"
#include <due_can.h>


#define NMT_OP 0x01
#define NMT_STOP 0x02
#define NMT_PRE_OP 0x80
#define NMT_RESET_NODE 0x81
#define NMT_RESET_COMM 0x82

// NMT
#define STATE_BOOTUP 0x00
#define STATE_STOPPED 0x04
#define STATE_OP 0x05
#define STATE_PRE_OP 0x7F


class Node {
private:
    const uint32_t id;
    const uint32_t _sdoID;

    uint16_t nmt_state;

public:
    Node(uint32_t _id) : id(_id), _sdoID(_id + 0x600) { }
    virtual ~Node() = default;


    uint32_t getID() {
        return id;
    }
    uint32_t sdoID() {
        return _sdoID;
    }
    uint16_t getState() {
        return nmt_state;
    }

    void set_nmt_state(uint16_t state);
    void update_nmt_state(CAN_FRAME &f) {
        nmt_state = f.data.bytes[0];
    }
};
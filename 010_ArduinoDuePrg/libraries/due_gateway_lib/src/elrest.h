#pragma once

#include "variant.h"
#include <due_can.h>
#include <string.h>

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

#define RELAIS 5

class Gateway;

class Elrest { 
private:
    Gateway* g;
    CAN_FRAME send_Msg;
    CAN_FRAME r1, r2;
    CAN_FRAME t1, t2;
    const uint32_t id; 
public:
    Elrest(uint32_t _id, Gateway* _g) : id(_id) {
        g = _g;
        
        r1.id = 0x200 + _id;
        r1.length = 8;
        r2.id = 0x300 + _id;
        r2.length = 8;

        t1.extended = 1;
        t2.extended = 1;
        t1.id = 0x1000180 + _id;
        t1.length = 8;
        t2.id = 0x1000280 + _id;
        t2.length = 8;
    }

    ~Elrest() {}
    
    bool fetch_state();

    void update_tpdos(CAN_FRAME &f);
    void update_rpdos();
    void send_rpdos();
    void send_tpdos();

    uint16_t state;

    uint32_t getID() const {
        return id;
    }

    void update_nmt_state(CAN_FRAME &f);

    void relais();
    void initialisierung();

    struct TPDO { // bitweise
        uint8_t din_0_7 = 0;
        uint8_t din_8_15 = 0;
        // Analog A0 bis A3
        int16_t a_in[4] = {0};
    } tpdo;

    struct RPDO {
        uint8_t dout_0_7 = 0;
        uint8_t dout_8_15 = 0;
        int16_t a_out[4] = {0};
    } rpdo;



};

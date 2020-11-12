#pragma once

#include <string.h>
#include "variant.h"
#include <due_can.h>
#include "node.h"

#define RELAIS 5

class Gateway;

class Elrest : public Node {
private:
    Gateway* g;
    CAN_FRAME send_Msg;
    CAN_FRAME r1, r2;
    CAN_FRAME t1, t2;
public:
    Elrest(uint32_t _id, Gateway* _g) : Node(_id) {
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

    virtual ~Elrest() = default;
    
    void update_tpdos(CAN_FRAME &f);
    void update_rpdos();
    void send_rpdos();
    void send_tpdos();

    void powerON();
    void powerOFF();
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

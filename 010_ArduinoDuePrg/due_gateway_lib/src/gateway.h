#pragma once

#include "variant.h"
#include <due_can.h>
#include <string.h>
#include <vector>

#include "adrive_binUtil.h"
#include "cdhd.h"
#include "elrest.h"

using namespace std;

class Gateway
{     
private:
    const float const_scale_num = 262144.0;
    const float const_scale_velo = (const_scale_num / 60.0);
    CAN_FRAME init_Msg;
    CAN_FRAME akzept;
    CAN_FRAME sdoAntwort;

    CAN_FRAME canopen_incoming;

    struct SDO {
        CAN_FRAME frame;
        uint16_t obj_index = 0;
        uint8_t sub_index = 0;
        uint16_t timeoutZaehler = 0; 
    }; 
    vector<SDO> pendingSDOs;

    // flags for cyclic CAN comm
    bool _sdoTimoutFLAG = false;

    bool securityFLAG = false;
    uint32_t securityTimeout = 0;

    CAN_FRAME sync_msg;
    bool _syncFLAG = false;
    bool _statusFLAG = false;
    bool _sendRPDOsFLAG = false;
    bool _forwardTPDOsFLAG = false;

    
public:
    Gateway() {
        init_Msg.id = 0x0;
        init_Msg.length = 2;

        sync_msg.id = 0x80;
        sync_msg.length = 0;
        sync_msg.data.byte[0] = 0;
    }
    ~Gateway() {}

    ADrive_rx_t ADrive_rx;
    CDHD_Drive servo1 = {1, this};
    CDHD_Drive servo2 = {2, this};
    Elrest elrest1 = {3, this};
    // Elrest elrest2 = {4, this};
    // Elrest elrest3 = {5, this};

    void mainloop();
    void sendSync();
    void sendRPDOs();
    void forwardTPDOs();
    void sendSTATUS();
    void recieve_canopen();
    void process_canopen(CAN_FRAME &f);
    CAN_FRAME process_can(CAN_FRAME &f);
    CAN_FRAME akzepiert_senden(bool success, uint32_t decID);


    void printFrame(CAN_FRAME &frame);
    void paramter_empfangen(const uint32_t decID);

    void forwardSDO(CAN_FRAME &f);
    void clearSDO(CAN_FRAME &f);
    void packSDO(uint32_t s_id, uint8_t s_cb, uint16_t s_od, uint8_t s_sub, uint32_t s_data);
        
    bool changeMode(CDHD_Drive& servo, int8_t mode);
    bool changeState(CDHD_Drive& servo, uint16_t control, uint16_t wantedState);

    void resetSecurityFLAG() {
        securityFLAG = false;
    }
    uint32_t getSecurityTimeout() const {
        return securityTimeout;
    }
    void setSyncFLAG() {
        _syncFLAG = true;
    }
    void setStatusFLAG() {
        _statusFLAG = true;
        _sdoTimoutFLAG = true;
    }
    void setRPDOsFLAG() {
        _sendRPDOsFLAG = true;
    }
    void setTPDOsFLAG() {
        _forwardTPDOsFLAG = true;
    }    
};



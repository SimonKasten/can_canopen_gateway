#pragma once

#include <string.h>

#include "variant.h"
#include <due_can.h>
#include "node.h"

// Controlword
#define CONTROL_DISABLE         0x00
#define CONTROL_SWITCH_ON       0x06
#define CONTROL_ENABLE          0x07
#define CONTROL_OP_START        0x0F
#define CONTROL_POS_ABS_START   0x3F
#define CONTROL_POS_REL_START   0x7F
#define CONTROL_CLR_FAULT       0x80

#define STATUS_MASK             0b1111111
#define STATUS_DISABLED         0b1010000
#define STATUS_SWITCHED_ON      0b0110001
#define STATUS_ENABLED          0b0110011
#define STATUS_OP_STARTED       0b0110111

// OPModes
#define OP_VELO     0x3
#define OP_TORQ     0x4
#define OP_POS      0x1

class Gateway;

class CDHD_Drive : public Node {
private:
    Gateway* g;
    CAN_FRAME send_Msg;
    CAN_FRAME r1, r2, r3, r4;
    CAN_FRAME t1, t2, t3, t4;
    CAN_FRAME s1, s2, s3, s4;

    const float const_scale_num = 262144.0;
    const float const_scale_velo = (const_scale_num / 60.0);

    uint32_t statusCounter = 0;
public:
    CDHD_Drive(uint32_t _id, Gateway* _g) : Node(_id) {
        g = _g;

        r1.id = 0x200 + _id;
        r1.length = 3;
        r2.id = 0x300 + _id;
        r2.length = 8;
        r3.id = 0x400 + _id;
        r3.length = 8;
        r4.id = 0x500 + _id;
        r4.length = 6;

        t1.extended = 1;
        t2.extended = 1;
        t3.extended = 1;
        t4.extended = 1;
        t1.id = 0x1000180 + _id;
        t1.length = 5;
        t2.id = 0x1000280 + _id;
        t2.length = 8;
        t3.id = 0x1000380 + _id;
        t3.length = 8;
        t4.id = 0x1000480 + _id;
        t4.length = 8;

        s1.extended = 1;
        s2.extended = 1;
        s3.extended = 1;
        s4.extended = 1;
        s1.id = 0x1100010 + _id;
        s1.length = 8;
        s2.id = 0x1100020 + _id;
        s2.length = 8;
        s3.id = 0x1100030 + _id;
        s3.length = 8;
        s4.id = 0x1100040 + _id;
        s4.length = 8;
    }

    virtual ~CDHD_Drive() = default;

    bool controlMode = false;

    void update_tpdos(CAN_FRAME &f);
    void update_rpdos();
    void update_status();
    void request_status();
    void send_rpdos();
    void send_tpdos();
    void send_status();

    void motorpar_config(); // grundlegende Config
    void motorpar_update(); // update die Motorparameter beim Betrieb

    void initialisierung();
    
    float MICONTtoTorque(int16_t micont);
    int16_t TorquetoMICONT(float torq);
    
    struct TPDO {
        uint16_t statusword = 0;
        int8_t opmode_display = 0;
        int16_t ist_torq = 0;
        int32_t ist_pos = 0;
        int32_t ist_rpm = 0;
        int16_t ist_curr = 0;
        int16_t soll_torq = 0;
        int16_t analog1 = 0;
        int16_t analog2 = 0;
        uint32_t dig_in = 0;
        int32_t pos_ext = 0;
    } tpdo;

    struct RPDO {
        uint16_t controlword = 0;
        int8_t opmode = 0;
        int32_t target_position = 0;
        int32_t profile_velocity = 0;
        int32_t target_velocity = 0;
        int16_t target_torque = 0;
    } rpdo;

    struct PLUS {
        int16_t max_torque = 0;
        int32_t max_rpm = 0; 
        int32_t max_acc = 0;
        int32_t max_dec = 0;
    } plus;
    struct _PLUS {
        int16_t max_torque = -10;
        int32_t max_rpm = -10; 
        int32_t max_acc = -10;
        int32_t max_dec = -10;
    } oldPlus;

    struct STATUS {
        float drehzahl = 0;
        float position = 0;
        float ist_strom = 0;
        float limit_torque = 0;
        float ist_torque = 0;
        float soll_torque = 0;
        float motor_temp = 0;
    } status;  

    // Motorparameter
    struct MOT_PAR {
        float cur_P_gain;       //  Current P-Gain [0-1000] , REAL32
        float cur_I_gain;       //  Current I-Gain [0-1000] , REAL32

        float vel_P_gain;       //  Velocity P-Gain [A/rps] , REAL32
        float vel_I_gain;       //  Velocity I-Gain [Hz] , REAL32

        float pos_P_gain;       //  Position Controller P-Gain [0-1200] , REAL32
        float pos_I_gain;       //  Position Controller I-Gain [0-1000] , REAL32
        float pos_D_gain;       //  Position Controller D-Gain [0-1000] , REAL32
        uint32_t pos_saturation;       //  Position Controller D-Gain [0-1000] , REAL32
        float faktor_Nm_A = 0.63;
              
        float foldback_delay_time;      // Foldback delay time
        float foldback_time_const;      // Foldback time constant
        float foldback_recovery_time;   // Foldback Recovery Time (Angabe normalerweise direkt in ms)
        uint16_t foldback_disable;      // Motor Foldback Disable

        float motor_L;          //  Motor Inductance [MHz] , REAL32
        float motor_R;          //  Motor Resistance [Ohm] , REAL32

        uint32_t peak_I;        //  Motor Peak Current [mA] , UINT32
        uint32_t rated_I;       //  Motor Rated Current [mA], UINT32
   
        uint32_t max_I;         // Maximum Current [MICONT], Rated Current / 1000
                                //   =>  Rated Current / 1000 * [0x6073]; also bei 1000 ist MAX_CURR = Motor Rated Current
        uint32_t rated_torque;  // Motor Rated Torque [mNm], UINT32
        uint32_t torque_slope;  // Torque Slope [mNm/s], UINT32


        uint32_t max_speed;     //  Max Motor Speed [rpm * const_scale_velo], UINT32 
        uint32_t max_acc;       //  Max Acceleration [user] 
        uint32_t max_dec;       //  Max Deceleration [user]

        uint32_t max_profile_speed; //  Max Profile Velocity [user]
        uint32_t max_profile_acc;   // Profile Acceleration [user]
        uint32_t max_profile_dec;   // Profile Deceleration [user]
    } mot_par;




};

#include "cdhd.h"
#include "gateway.h"


void CDHD_Drive::update_tpdos(CAN_FRAME &f){
    int tpdo_id = f.id - getID();
    if (tpdo_id == 0x180){
        t1.data = f.data;
        tpdo.statusword = f.data.uint16[0];
        tpdo.opmode_display = f.data.int8[2];
        tpdo.ist_torq = static_cast<int16_t>( f.data.byte[3] | f.data.byte[4] << 8 );

        status.ist_torque = tpdo.ist_torq / 1000.0 * mot_par.rated_I * mot_par.faktor_Nm_A / 1000.0;
    }
    else if (tpdo_id == 0x280){
        t2.data = f.data;
        tpdo.ist_pos = f.data.int32[0];
        tpdo.ist_rpm = f.data.int32[1];

        status.position = tpdo.ist_pos / const_scale_num;
        status.drehzahl = tpdo.ist_rpm / const_scale_velo;
    }
    else if (tpdo_id == 0x380){
        t3.data = f.data;
        tpdo.ist_curr = f.data.int16[0];
        tpdo.soll_torq = f.data.int16[1];
        tpdo.analog1 = f.data.int16[2]; 
        tpdo.analog2 = f.data.int16[3];

        status.ist_strom = tpdo.ist_curr / 1000.0 * mot_par.rated_I / 1000.0;
        status.soll_torque = tpdo.soll_torq / 1000.0 * mot_par.rated_I * mot_par.faktor_Nm_A / 1000.0;
    }
    else if (tpdo_id == 0x480){
        t4.data = f.data;
        tpdo.dig_in = f.data.uint32[0];
        tpdo.pos_ext = f.data.int32[1];
    }
}

void CDHD_Drive::update_rpdos(){
    r1.data.uint16[0] = rpdo.controlword;
    r1.data.int8[2] = rpdo.opmode;

    r2.data.int32[0] = rpdo.target_position;
    r2.data.int32[1] = rpdo.profile_velocity;

    r3.data.int32[0] = rpdo.target_velocity;
    
    r4.data.int16[0] = rpdo.target_torque;
}

float CDHD_Drive::MICONTtoTorque(int16_t micont) {
    float f;
    f = micont / 1000000.0 * mot_par.rated_I * mot_par.faktor_Nm_A;
    return f;
}

int16_t CDHD_Drive::TorquetoMICONT(float torq) {
    float f;
    f = torq * 1000000.0 / mot_par.faktor_Nm_A / mot_par.rated_I;
    return static_cast<int16_t>(f);
}

void CDHD_Drive::request_status() {
    g->packSDO(sdoID(), 0x40, 0x6073, 0, 0);
    g->packSDO(sdoID(), 0x40, 0x20C7, 0, 0);
}

void CDHD_Drive::update_status(){
    uint32_t ftoi;

    memcpy(&ftoi, &status.drehzahl, sizeof(uint32_t));  
    s1.data.uint32[0] = ftoi;

    memcpy(&ftoi, &status.position, sizeof(uint32_t));  
    s1.data.uint32[1] = ftoi;

    memcpy(&ftoi, &status.ist_strom, sizeof(uint32_t));  
    s2.data.uint32[0] = ftoi;
    memcpy(&ftoi, &status.limit_torque, sizeof(uint32_t));  
    s2.data.uint32[1] = ftoi;

    memcpy(&ftoi, &status.ist_torque, sizeof(uint32_t));  
    s3.data.uint32[0] = ftoi;
    memcpy(&ftoi, &status.soll_torque, sizeof(uint32_t));  
    s3.data.uint32[1] = ftoi;
    
    memcpy(&ftoi, &status.motor_temp, sizeof(uint32_t));  
    s4.data.uint32[0] = ftoi;
}




void CDHD_Drive::send_rpdos(){
    Can0.sendFrame(r1);
    Can0.sendFrame(r2);
    Can0.sendFrame(r3);
    Can0.sendFrame(r4);
}

void CDHD_Drive::send_tpdos(){
    Can1.sendFrame(t1);
    Can1.sendFrame(t2);
    Can1.sendFrame(t3);
    Can1.sendFrame(t4);
}

void CDHD_Drive::send_status(){
    Can1.sendFrame(s1);
    Can1.sendFrame(s2);
    Can1.sendFrame(s3);
    Can1.sendFrame(s4);
}

void CDHD_Drive::initialisierung()
{
    g->packSDO(sdoID(), 0x23, 0x1005, 0x00, 0x80); //   0x80  #1005h – COB-ID SYNC Message
    g->packSDO(sdoID(), 0x23, 0x1007, 0x00, 0x2710); //  0x00002710  #1007h – Synchronous Window Length
    g->packSDO(sdoID(), 0x23, 0x1014, 0x00, 0x80 + getID()); //  0x81  #1014h – COB-ID EMCY

    // 1400h – Receive PDO Communication Parameter 1
    g->packSDO(sdoID(), 0x23, 0x1400, 0x01, 0x200 + getID()); 
    g->packSDO(sdoID(), 0x23, 0x1401, 0x01, 0x300 + getID()); 
    g->packSDO(sdoID(), 0x23, 0x1402, 0x01, 0x400 + getID()); 
    g->packSDO(sdoID(), 0x23, 0x1403, 0x01, 0x500 + getID()); 
    // 1600h – Receive PDO Mapping Parameter 1
    //TODO 06040041 error cannt set PDO
    // g->packSDO(sdoID(), 0x2f, 0x1600, 0x00, 2); 
    // g->packSDO(sdoID(), 0x2f, 0x1601, 0x00, 2); 
    // g->packSDO(sdoID(), 0x2f, 0x1602, 0x00, 2); 
    // g->packSDO(sdoID(), 0x2f, 0x1603, 0x00, 2); 

    // 1800h – Transmit PDO Communication Parameter 1
    g->packSDO(sdoID(), 0x23, 0x1800, 0x01, 0x180 + getID()); 
    g->packSDO(sdoID(), 0x23, 0x1801, 0x01, 0x280 + getID()); 
    g->packSDO(sdoID(), 0x23, 0x1802, 0x01, 0x380 + getID()); 
    g->packSDO(sdoID(), 0x23, 0x1803, 0x01, 0x480 + getID()); 

    // 1A00h – Transmit PDO Mapping Parameter 1
    // TODO 06040041 error cannt set PDO
    // g->packSDO(sdoID(), 0x2f, 0x1A00, 0x00, 3);
    // g->packSDO(sdoID(), 0x2f, 0x1A01, 0x00, 2);
    // g->packSDO(sdoID(), 0x2f, 0x1A02, 0x00, 4);
    // g->packSDO(sdoID(), 0x2f, 0x1A03, 0x00, 2); 
}





void CDHD_Drive::motorpar_update()  // update die Motorparameter beim Betrieb
{
    //  SDO Motordaten        Bsp DSD2-045LO64U an Controller mit ID = 2
    uint32_t ftoi;


    memcpy(&ftoi, &mot_par.cur_I_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2006, 0x00, ftoi);   //  Current I-Gain [0-100] , REAL32
    memcpy(&ftoi, &mot_par.cur_P_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2007, 0x00, ftoi);   //  Current P-Gain [0-100] , REAL32

    memcpy(&ftoi, &mot_par.vel_P_gain, sizeof(uint32_t));
    g->packSDO(sdoID(), 0x23, 0x2027, 0x00, ftoi); //  Velocity Proportional (KP) , REAL32
    memcpy(&ftoi, &mot_par.vel_I_gain, sizeof(uint32_t));
    g->packSDO(sdoID(), 0x23, 0x2026, 0x00, ftoi); //  Velocity I-Gain [Hz] , REAL32
       
    
    memcpy(&ftoi, &mot_par.pos_P_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2022, 0x00, ftoi); //  Position Controller P-Gain [0-1200] , REAL32
    memcpy(&ftoi, &mot_par.pos_I_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2020, 0x00, ftoi); //  Position Controller I-Gain [0-1000] , REAL32
    memcpy(&ftoi, &mot_par.pos_D_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x201E, 0x00, ftoi); //  Position Controller D-Gain [0-1000] , REAL32
    g->packSDO(sdoID(), 0x23, 0x2021, 0x00, mot_par.pos_saturation); //  Position Integral Output Saturation [pos] , UINT32


    g->packSDO(sdoID(), 0x2B, 0x6073, 0x00, mot_par.max_I);          // Maximum Current [MICONT], Rated Current / 1000, UINT16
                                                                //   =>  Rated Current / 1000 * [0x6073]; also bei 1000 ist MAX_CURR = Motor Rated Current

    g->packSDO(sdoID(), 0x23, 0x6080, 0x00, mot_par.max_speed * const_scale_velo);   //  Max Motor Speed [rpm * const_scale_velo], UINT32 
    g->packSDO(sdoID(), 0x23, 0x607F, 0x00, mot_par.max_profile_speed * const_scale_velo);   //  Max Profile Velocity [user]
    
    g->packSDO(sdoID(), 0x23, 0x60C5, 0x00, mot_par.max_acc * const_scale_velo);     //  Max Acceleration [user] 
    g->packSDO(sdoID(), 0x23, 0x60C6, 0x00, mot_par.max_dec * const_scale_velo);     //  Max Deceleration [user]

    g->packSDO(sdoID(), 0x23, 0x6083, 0x00, mot_par.max_profile_acc * const_scale_velo);     // Profile Acceleration [user]
    g->packSDO(sdoID(), 0x23, 0x6084, 0x00, mot_par.max_profile_dec * const_scale_velo);     // Profile Deceleration [user]
}






void CDHD_Drive::motorpar_config()  // grundlegende Config
{
    //  SDO Motordaten        Bsp DSD2-045LO64U an Controller mit ID = 2
    g->packSDO(sdoID(), 0x2F, 0x2002, 0x00, 1);      // Konfigurationssequenz

    uint32_t ftoi;

    memcpy(&ftoi, &mot_par.cur_I_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2006, 0x00, ftoi);   //  Current I-Gain [0-100] , REAL32
    memcpy(&ftoi, &mot_par.cur_P_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2007, 0x00, ftoi);   //  Current P-Gain [0-100] , REAL32
    
    memcpy(&ftoi, &mot_par.vel_P_gain, sizeof(uint32_t));
    g->packSDO(sdoID(), 0x23, 0x2027, 0x00, ftoi); //  Velocity Proportional (KP) , REAL32
    memcpy(&ftoi, &mot_par.vel_I_gain, sizeof(uint32_t));
    g->packSDO(sdoID(), 0x23, 0x2026, 0x00, ftoi); //  Velocity I-Gain [Hz] , REAL32
       
    
    memcpy(&ftoi, &mot_par.pos_P_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2022, 0x00, ftoi); //  Position Controller P-Gain [0-1200] , REAL32
    memcpy(&ftoi, &mot_par.pos_I_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x2020, 0x00, ftoi); //  Position Controller I-Gain [0-1000] , REAL32
    memcpy(&ftoi, &mot_par.pos_D_gain, sizeof(uint32_t));  
    g->packSDO(sdoID(), 0x23, 0x201E, 0x00, ftoi); //  Position Controller D-Gain [0-1000] , REAL32
    g->packSDO(sdoID(), 0x23, 0x2021, 0x00, mot_par.pos_saturation); //  Position Integral Output Saturation [pos] , UINT32

       
    // Foldback 
    // g->packSDO(sdoID(), 0x23, 0x202F, 0x00, mot_par.foldback_delay_time); //  36,00 s Angabe als "real" (float) foldback delay time
    // g->packSDO(sdoID(), 0x23, 0x2032, 0x00, mot_par.foldback_time_const); //  6,00  s   foldback time constant
    // g->packSDO(sdoID(), 0x23, 0x2031, 0x00, mot_par.foldback_recovery_time); //  24,00 ms  *1  Foldback Recovery Time (Angabe normalerweise direkt in ms)
    // g->packSDO(sdoID(), 0x2b, 0x2030, 0x00, mot_par.foldback_disable); // Foldback_disable
    
    memcpy(&ftoi, &mot_par.motor_L, sizeof(uint32_t));
    g->packSDO(sdoID(), 0x23, 0x203A, 0x00, ftoi);        //  Motor Inductance [MHz] , REAL32
    memcpy(&ftoi, &mot_par.motor_R, sizeof(uint32_t));
    g->packSDO(sdoID(), 0x23, 0x207F, 0x00, ftoi);        //  Motor Resistance [Ohm] , REAL32

    g->packSDO(sdoID(), 0x23, 0x2036, 0x00, mot_par.peak_I);         //  Motor Peak Current [mA] , UINT32
    g->packSDO(sdoID(), 0x23, 0x6075, 0x00, mot_par.rated_I);        //  Motor Rated Current [mA], UINT32
    g->packSDO(sdoID(), 0x2B, 0x6073, 0x00, mot_par.max_I);          // Maximum Current [MICONT], Rated Current / 1000, UINT16
                                                                //   =>  Rated Current / 1000 * [0x6073]; also bei 1000 ist MAX_CURR = Motor Rated Current


    g->packSDO(sdoID(), 0x23, 0x6076, 0x00, mot_par.rated_torque);   // Motor Rated Torque [mNm], UINT32
    g->packSDO(sdoID(), 0x23, 0x6087, 0x00, mot_par.torque_slope);   // Torque Slope [mNm/s], UINT32
  
    g->packSDO(sdoID(), 0x23, 0x6080, 0x00, mot_par.max_speed * const_scale_velo);   //  Max Motor Speed [rpm * const_scale_velo], UINT32 
    g->packSDO(sdoID(), 0x23, 0x607F, 0x00, mot_par.max_profile_speed * const_scale_velo);   //  Max Profile Velocity [user]
    
    g->packSDO(sdoID(), 0x23, 0x60C5, 0x00, mot_par.max_acc * const_scale_velo);     //  Max Acceleration [user] 
    g->packSDO(sdoID(), 0x23, 0x60C6, 0x00, mot_par.max_dec * const_scale_velo);     //  Max Deceleration [user]

    g->packSDO(sdoID(), 0x23, 0x6083, 0x00, mot_par.max_profile_acc * const_scale_velo);     // Profile Acceleration [user]
    g->packSDO(sdoID(), 0x23, 0x6084, 0x00, mot_par.max_profile_dec * const_scale_velo);     // Profile Deceleration [user]
}



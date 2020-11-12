#include "gateway.h"

void Gateway::sendSync()
{
    if (_syncFLAG)
    {
        Can0.sendFrame(sync_msg);
        _syncFLAG = false;
    }
}

void Gateway::mainloop()
{
    sendSync();

    if (_sendRPDOsFLAG)
    {
        sendRPDOs();
        _sendRPDOsFLAG = false;
        return;
    }

    if (_forwardTPDOsFLAG)
    {
        forwardTPDOs();

        sendSTATUS();
        _forwardTPDOsFLAG = false;
        return;
    }

    if (_statusFLAG)
    {    
        servo1.request_status();
        servo2.request_status();
        _statusFLAG = false;
        return;
    }

    if (_sdoTimoutFLAG) {
        auto s = pendingSDOs.begin();
        while (s < pendingSDOs.end())
        { 
            s->timeoutZaehler++;
            if(s->timeoutZaehler > 3) {
                Serial.print("SDO Timeout: ");
                printFrame(s->frame);
                s = pendingSDOs.erase(s);
            }
            s++;
        }
        _sdoTimoutFLAG = false;
        return;
    }
}


void Gateway::sendRPDOs()
{
    servo1.send_rpdos();
    servo2.send_rpdos();
    elrest1.send_rpdos();
}

void Gateway::forwardTPDOs()
{
    servo1.send_tpdos();
    servo2.send_tpdos();
    elrest1.send_tpdos();
    // elrest2.send_tpdos();
    // elrest3.send_tpdos();
}

void Gateway::sendSTATUS()
{
    servo1.update_status();
    servo2.update_status();

    servo1.send_status();
    servo2.send_status();
}


void Gateway::recieve_canopen()
{
    if (Can0.available())
    {
        Can0.read(canopen_incoming);
        process_canopen(canopen_incoming);
    }

    sendSync();
}

bool Gateway::changeMode(CDHD_Drive &servo, int8_t mode)
{
    servo.rpdo.opmode = mode;
    servo.update_rpdos();
    servo.send_rpdos();

    uint32_t timeout = millis();
    while (true)
    {
        recieve_canopen();

        if (servo.tpdo.opmode_display == mode)
        {
            Serial.print("OPMode 0x");
            Serial.print(mode, HEX);
            Serial.println(" übernommen :)");
            return true;
        }
        if (millis() > (timeout + 150))
        {
            Serial.println("OPMode Timout ...");
            return false;
        }
    }
}

bool Gateway::changeState(CDHD_Drive &servo, uint16_t control, uint16_t wantedState)
{
    servo.rpdo.controlword = control;
    servo.update_rpdos();
    servo.send_rpdos();

    uint16_t _actualState = 0;
    uint32_t timeout = millis();
    while (true)
    {
        recieve_canopen();
        _actualState = servo.tpdo.statusword & STATUS_MASK;

        if (wantedState == _actualState)
        {
            Serial.print("State 0x");
            Serial.print(_actualState, HEX);
            Serial.println(" übernommen :)");
            return true;
        }
        if (millis() > (timeout + 150))
        {
            Serial.println("State Timout ...");
            return false;
        }
    }
}

void Gateway::process_canopen(CAN_FRAME &f)
{
    if (f.id > 0x179 && f.id < 0x580)
    {
        uint32_t incID = f.id & 0x7F;
        if (incID == servo1.getID())
            servo1.update_tpdos(f);
        else if (incID == servo2.getID())
            servo2.update_tpdos(f);
        else if (incID == elrest1.getID())
            elrest1.update_tpdos(f);
        // else if(incID == elrest2.getID())
        //     elrest2.update_tpdos(f);
        // else if(incID == elrest3.getID())
        //     elrest3.update_tpdos(f);
    }
    if (f.id > 0x580 && f.id < 0x600) {
        clearSDO(f);
    }
}

CAN_FRAME Gateway::process_can(CAN_FRAME &f)
{
    const uint32_t decodedID = ADrive_Receive(&ADrive_rx, &f.data.byte[0], f.id, f.length);

    if (decodedID == WATCHDOG_ID1_CANID || decodedID == WATCHDOG_ID2_CANID)
    {
        securityTimeout = millis() + 300;
        securityFLAG = true;
    }
    if (!securityFLAG)
    {
        Serial.println("Msg ignoriert. -> WATCHDOG aktivieren !!");
        return akzepiert_senden(false, WATCHDOG_ID1_CANID);
    }

    if (decodedID == INIT_ID1_CANID)
    {
        Serial.println("INIT_ID1_CANID");
        servo1.set_nmt_state(ADrive_rx.INIT_ID1.befehl);
        servo1.initialisierung();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == INIT_ID2_CANID)
    {
        Serial.println("INIT_ID2_CANID");
        servo2.set_nmt_state(ADrive_rx.INIT_ID2.befehl);
        servo2.initialisierung();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == INIT_ELREST_CANID)
    {
        Serial.println("INIT_ELREST_CANID");
        elrest1.set_nmt_state(ADrive_rx.INIT_ELREST.befehl);
        //elrest2.set_nmt_state(ADrive_rx.INIT_ELREST.befehl);
        //elrest3.set_nmt_state(ADrive_rx.INIT_ELREST.befehl);
        elrest1.initialisierung();
        // elrest2.initialisierung();
        // elrest3.initialisierung();
        elrest1.powerON();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == MODE_ID1_CANID)
    {
        servo1.controlMode = ADrive_rx.MODE_ID1.control_mode;
    }
    else if (decodedID == MODE_ID2_CANID)
    {
        servo2.controlMode = ADrive_rx.MODE_ID2.control_mode;
    }

    else if (decodedID == CONTROL_ID1_CANID)
    {
        if (!servo1.controlMode)
            return akzepiert_senden(false, decodedID);
        servo1.rpdo.controlword = ADrive_rx.CONTROL_ID1.controlword;
        servo1.rpdo.opmode = ADrive_rx.CONTROL_ID1.op_mode;
        servo1.update_rpdos();

        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == CONTROL_ID2_CANID)
    {
        if (!servo2.controlMode)
            return akzepiert_senden(false, decodedID);
        servo2.rpdo.controlword = ADrive_rx.CONTROL_ID2.controlword;
        servo2.rpdo.opmode = ADrive_rx.CONTROL_ID2.op_mode;
        servo2.update_rpdos();

        return akzepiert_senden(true, decodedID);
    }

    else if (decodedID == START_MODUS_ID1_CANID)
    {
        if (servo1.controlMode)
            return akzepiert_senden(false, decodedID);
        Serial.println("START_MODUS_ID1_CANID");

        // keine aenderung in statusword bei clr flt
        servo1.rpdo.controlword = CONTROL_CLR_FAULT;
        servo1.update_rpdos();
        servo1.send_rpdos();

        if (ADrive_rx.START_MODUS_ID1.op_mode == OP_POS || ADrive_rx.START_MODUS_ID1.op_mode == OP_VELO)
        {
            if (servo1.mot_par.max_profile_speed > 0)
                packSDO(0x600 + servo1.getID(), 0x23, 0x607F, 0x00, servo1.mot_par.max_profile_speed * const_scale_velo);
        }
        if (ADrive_rx.START_MODUS_ID1.op_mode == OP_TORQ || ADrive_rx.START_MODUS_ID1.op_mode == OP_VELO)
        {
            if (servo1.mot_par.max_profile_acc > 0)
                packSDO(0x600 + servo1.getID(), 0x23, 0x6083, 0x00, servo1.mot_par.max_profile_acc * const_scale_velo); // Profile Acceleration [user]
            if (servo1.mot_par.max_profile_dec > 0)
                packSDO(0x600 + servo1.getID(), 0x23, 0x6084, 0x00, servo1.mot_par.max_profile_dec * const_scale_velo); // Profile Deceleration [user]
        }

        changeMode(servo1, ADrive_rx.START_MODUS_ID1.op_mode);

        //changeState(servo1, CONTROL_DISABLE, STATUS_DISABLED);
        changeState(servo1, CONTROL_SWITCH_ON, STATUS_SWITCHED_ON);
        changeState(servo1, CONTROL_ENABLE, STATUS_ENABLED);
        changeState(servo1, CONTROL_OP_START, STATUS_OP_STARTED);

        if (ADrive_rx.START_MODUS_ID1.op_mode == OP_POS)
        {
            servo1.send_rpdos();
            delay(5);
            Serial.println("5ms Verzoegerung :)");

            if (ADrive_rx.START_MODUS_ID1.relative_absolut)
            {
                servo1.rpdo.controlword = CONTROL_POS_ABS_START;
                servo1.update_rpdos();
                servo1.send_rpdos();
            }
            else
            {
                servo1.rpdo.controlword = CONTROL_POS_REL_START;
                servo1.update_rpdos();
                servo1.send_rpdos();
            }
            delay(100);
            changeState(servo1, CONTROL_OP_START, STATUS_OP_STARTED);
        }
        return akzepiert_senden(true, decodedID);
    }

    else if (decodedID == START_MODUS_ID2_CANID)
    {
        if (servo2.controlMode)
            return akzepiert_senden(false, decodedID);
        Serial.println("START_MODUS_ID2_CANID");

        // keine aenderung in statusword bei clr flt
        servo2.rpdo.controlword = CONTROL_CLR_FAULT;
        servo2.update_rpdos();
        servo2.send_rpdos();

        if(ADrive_rx.START_MODUS_ID2.op_mode == OP_TORQ) {



        }
        if (ADrive_rx.START_MODUS_ID2.op_mode == OP_POS || ADrive_rx.START_MODUS_ID2.op_mode == OP_VELO)
        {
            if (servo2.mot_par.max_profile_speed > 0)
                packSDO(0x600 + servo2.getID(), 0x23, 0x607F, 0x00, servo2.mot_par.max_profile_speed * const_scale_velo);
        }
        if (ADrive_rx.START_MODUS_ID2.op_mode == OP_TORQ || ADrive_rx.START_MODUS_ID2.op_mode == OP_VELO)
        {
            if (servo2.mot_par.max_profile_acc > 0)
                packSDO(0x600 + servo2.getID(), 0x23, 0x6083, 0x00, servo2.mot_par.max_profile_acc * const_scale_velo); // Profile Acceleration [user]
            if (servo2.mot_par.max_profile_dec > 0)
                packSDO(0x600 + servo2.getID(), 0x23, 0x6084, 0x00, servo2.mot_par.max_profile_dec * const_scale_velo); // Profile Deceleration [user]
        }

        changeMode(servo2, ADrive_rx.START_MODUS_ID2.op_mode);

        //changeState(servo2, CONTROL_DISABLE, STATUS_DISABLED);
        changeState(servo2, CONTROL_SWITCH_ON, STATUS_SWITCHED_ON);
        changeState(servo2, CONTROL_ENABLE, STATUS_ENABLED);
        changeState(servo2, CONTROL_OP_START, STATUS_OP_STARTED);

        if (ADrive_rx.START_MODUS_ID2.op_mode == OP_POS)
        {
            servo2.send_rpdos();
            delay(5);
            Serial.println("5ms Verzoegerung :)");

            if (ADrive_rx.START_MODUS_ID2.relative_absolut)
            {
                servo2.rpdo.controlword = CONTROL_POS_ABS_START;
                servo2.update_rpdos();
                servo2.send_rpdos();
            }
            else
            {
                servo2.rpdo.controlword = CONTROL_POS_REL_START;
                servo2.update_rpdos();
                servo2.send_rpdos();
            }
            delay(5);
            changeState(servo2, CONTROL_OP_START, STATUS_OP_STARTED);
        }
        return akzepiert_senden(true, decodedID);
    }

    else if (decodedID == STOP_MODUS_ID1_CANID)
    {
        Serial.println("STOP_MODUS_ID1_CANID");

        changeState(servo1, CONTROL_DISABLE, STATUS_DISABLED);
        changeState(servo1, CONTROL_SWITCH_ON, STATUS_SWITCHED_ON);

        changeState(servo1, CONTROL_CLR_FAULT, servo1.tpdo.statusword & 0b1110111);
        changeState(servo1, CONTROL_SWITCH_ON, STATUS_SWITCHED_ON);
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == STOP_MODUS_ID2_CANID)
    {
        Serial.println("STOP_MODUS_ID2_CANID");

        changeState(servo2, CONTROL_DISABLE, STATUS_DISABLED);
        changeState(servo2, CONTROL_SWITCH_ON, STATUS_SWITCHED_ON);

        changeState(servo2, CONTROL_CLR_FAULT, servo2.tpdo.statusword & 0b1110111);
        changeState(servo2, CONTROL_SWITCH_ON, STATUS_SWITCHED_ON);
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Drehzahl_Werte_ID1_CANID)
    {
        servo1.rpdo.target_velocity = static_cast<int32_t>(ADrive_rx.Drehzahl_Werte_ID1.D_soll_rpm * const_scale_velo);

        if (servo1.mot_par.rated_I)
        {
            servo1.plus.max_torque = servo1.TorquetoMICONT(ADrive_rx.Drehzahl_Werte_ID1.D_max_torq);
        }
        else
        {
            servo1.plus.max_torque = 1000;
        } 

        if(servo1.plus.max_torque != servo1.oldPlus.max_torque){
            packSDO(0x600 + servo1.getID(), 0x2B, 0x6073, 0x00, servo1.plus.max_torque);
            servo1.oldPlus.max_torque = servo1.plus.max_torque;
        }
        servo1.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Drehzahl_Werte_ID2_CANID)
    {
        float f = ADrive_rx.Drehzahl_Werte_ID2.D_soll_rpm * const_scale_velo;
        servo2.rpdo.target_velocity = static_cast<int32_t>(f);

        if (servo2.mot_par.rated_I)
        {
            servo2.plus.max_torque = servo2.TorquetoMICONT(ADrive_rx.Drehzahl_Werte_ID2.D_max_torq);
        }
        else
        {
            servo2.plus.max_torque = 1000;
        }
        if(servo2.plus.max_torque != servo2.oldPlus.max_torque){
            packSDO(0x600 + servo2.getID(), 0x2B, 0x6073, 0x00, servo2.plus.max_torque);
            servo2.oldPlus.max_torque = servo2.plus.max_torque;
        }
        servo2.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Drehmoment_Werte_ID1_CANID)
    {
        if (servo1.mot_par.rated_I)
        {
            servo1.rpdo.target_torque = servo1.TorquetoMICONT(ADrive_rx.Drehmoment_Werte_ID1.T_soll_torq);
        }
        else
        {
            servo1.rpdo.target_torque = 0;
            Serial.println("Brauche rated_I");
        }

        servo1.plus.max_rpm = static_cast<int32_t>(ADrive_rx.Drehmoment_Werte_ID1.T_max_rpm * const_scale_velo);
        if (servo1.plus.max_rpm <= 0)
        {
            servo1.plus.max_rpm = 100 * const_scale_velo;
        }

        packSDO(0x600 + servo1.getID(), 0x23, 0x607F, 0x00, servo1.plus.max_rpm); //  Max Profile Velocity [user]

        servo1.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Drehmoment_Werte_ID2_CANID)
    {
        if (servo2.mot_par.rated_I)
        {
            servo2.rpdo.target_torque = servo2.TorquetoMICONT(ADrive_rx.Drehmoment_Werte_ID2.T_soll_torq);
        }
        else
        {
            servo2.rpdo.target_torque = 0;
            Serial.println("Brauche rated_I");
        }

        servo2.plus.max_rpm = static_cast<int32_t>(ADrive_rx.Drehmoment_Werte_ID2.T_max_rpm * const_scale_velo);
        if (servo2.plus.max_rpm <= 0)
        {
            servo2.plus.max_rpm = 100 * const_scale_velo;
        }

        packSDO(0x600 + servo2.getID(), 0x23, 0x607F, 0x00, servo2.plus.max_rpm); //  Max Profile Velocity [user]

        servo2.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Postion_Werte_ID1_CANID)
    {
        Serial.println("Postion_Werte_ID1_CANID");
        Serial.print("Sollposition: ");
        Serial.println(ADrive_rx.Postion_Werte_ID1.P_soll_pos);
        Serial.print("MaxRPMPOS: ");
        Serial.println(ADrive_rx.Postion_Werte_ID1.P_soll_rpm);

        servo1.rpdo.target_position = static_cast<int32_t>(ADrive_rx.Postion_Werte_ID1.P_soll_pos * const_scale_num);
        servo1.rpdo.profile_velocity = static_cast<int32_t>(ADrive_rx.Postion_Werte_ID1.P_soll_rpm * const_scale_velo);

        servo1.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Postion_Werte_ID2_CANID)
    {

        servo2.rpdo.target_position = static_cast<int32_t>(ADrive_rx.Postion_Werte_ID2.P_soll_pos * const_scale_num);
        servo2.rpdo.profile_velocity = static_cast<int32_t>(ADrive_rx.Postion_Werte_ID2.P_soll_rpm * const_scale_velo);

        Serial.print("target_position: ");
        Serial.println(servo2.rpdo.target_position);
        servo2.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Postion_Beschl_ID1_CANID)
    {
        servo1.plus.max_acc = static_cast<int32_t>(ADrive_rx.Postion_Beschl_ID1.P_max_acc * const_scale_velo);
        servo1.plus.max_dec = static_cast<int32_t>(ADrive_rx.Postion_Beschl_ID1.P_max_dec * const_scale_velo);

        packSDO(0x600 + servo1.getID(), 0x23, 0x6083, 0x00, servo1.plus.max_acc); // Profile Acceleration [user]
        packSDO(0x600 + servo1.getID(), 0x23, 0x6084, 0x00, servo1.plus.max_dec); // Profile Deceleration [user]

        servo1.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == Postion_Beschl_ID2_CANID)
    {
        servo2.plus.max_acc = static_cast<int32_t>(ADrive_rx.Postion_Beschl_ID2.P_max_acc * const_scale_velo);
        servo2.plus.max_dec = static_cast<int32_t>(ADrive_rx.Postion_Beschl_ID2.P_max_dec * const_scale_velo);

        packSDO(0x600 + servo2.getID(), 0x23, 0x6083, 0x00, servo2.plus.max_acc); // Profile Acceleration [user]
        packSDO(0x600 + servo2.getID(), 0x23, 0x6084, 0x00, servo2.plus.max_dec); // Profile Deceleration [user]
  
        servo2.update_rpdos();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == MOT_CONFIG_ID1_CANID)
    {
        Serial.println("Config Servo 1 Motor");
        servo1.motorpar_config();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == MOT_CONFIG_ID2_CANID)
    {
        Serial.println("Config Servo 2 Motor");
        servo2.motorpar_config();
        return akzepiert_senden(true, decodedID);
    }

    else if (decodedID == MOT_PARAM_ID1_CANID)
    {
        Serial.println("Update PARAM Servo 1 Motor");
        servo1.motorpar_update();
        return akzepiert_senden(true, decodedID);
    }
    else if (decodedID == MOT_PARAM_ID2_CANID)
    {
        Serial.println("Update PARAM Servo 2 Motor");
        servo2.motorpar_update();
        return akzepiert_senden(true, decodedID);
    }

    else if (decodedID >= PAR_1_ID1_CANID && decodedID < MOT_PARAM_ID1_CANID)
    {
        paramter_empfangen(decodedID);
    }

    return akzepiert_senden(false, decodedID);
}

CAN_FRAME Gateway::akzepiert_senden(bool success, uint32_t decID)
{
    akzept.id = AKZEPTIERT_CANID;
    akzept.extended = AKZEPTIERT_IDE;
    akzept.length = AKZEPTIERT_DLC;

    akzept.data.byte[0] = success;
    akzept.data.uint32[1] = decID;

    return akzept;
}

void Gateway::paramter_empfangen(const uint32_t decID)
{
    if (decID == PAR_1_ID1_CANID)
    {
        servo1.mot_par.pos_P_gain = ADrive_rx.PAR_1_ID1.M_pos_P_gain;
        servo1.mot_par.max_I = ADrive_rx.PAR_1_ID1.M_max_I;
        Serial.print("Saved pos_P_gain = ");
        Serial.println(servo1.mot_par.pos_P_gain);
        Serial.print("Saved max_I = ");
        Serial.println(servo1.mot_par.max_I);
    }
    else if (decID == PAR_1_ID2_CANID)
    {
        servo2.mot_par.pos_P_gain = ADrive_rx.PAR_1_ID2.M_pos_P_gain;
        servo2.mot_par.max_I = ADrive_rx.PAR_1_ID2.M_max_I;

        Serial.print("Saved pos_P_gain = ");
        Serial.println(servo2.mot_par.pos_P_gain);
        Serial.print("Saved max_I = ");
        Serial.println(servo2.mot_par.max_I);
    }
    else if (decID == PAR_2_ID1_CANID)
    {
        servo1.mot_par.vel_P_gain = ADrive_rx.PAR_2_ID1.M_vel_P_gain;
        servo1.mot_par.vel_I_gain = ADrive_rx.PAR_2_ID1.M_vel_I_gain;
        Serial.print("Saved vel_P_gain = ");
        Serial.println(servo1.mot_par.vel_P_gain);
        Serial.print("Saved vel_I_gain = ");
        Serial.println(servo1.mot_par.vel_I_gain);
    }
    else if (decID == PAR_2_ID2_CANID)
    {
        servo2.mot_par.vel_P_gain = ADrive_rx.PAR_2_ID2.M_vel_P_gain;
        servo2.mot_par.vel_I_gain = ADrive_rx.PAR_2_ID2.M_vel_I_gain;

        Serial.print("Saved vel_P_gain = ");
        Serial.println(servo2.mot_par.vel_P_gain);
        Serial.print("Saved vel_I_gain = ");
        Serial.println(servo2.mot_par.vel_I_gain);
    }
    else if (decID == PAR_3_ID1_CANID)
    {
        servo1.mot_par.motor_L = ADrive_rx.PAR_3_ID1.M_L;
        servo1.mot_par.motor_R = ADrive_rx.PAR_3_ID1.M_R;
        Serial.print("Saved motor_L = ");
        Serial.println(servo1.mot_par.motor_L);
        Serial.print("Saved motor_R = ");
        Serial.println(servo1.mot_par.motor_R);
    }
    else if (decID == PAR_3_ID2_CANID)
    {
        servo2.mot_par.motor_L = ADrive_rx.PAR_3_ID2.M_L;
        servo2.mot_par.motor_R = ADrive_rx.PAR_3_ID2.M_R;

        Serial.print("Saved motor_L = ");
        Serial.println(servo2.mot_par.motor_L);
        Serial.print("Saved motor_R = ");
        Serial.println(servo2.mot_par.motor_R);
    }
    else if (decID == PAR_4_ID1_CANID)
    {
        servo1.mot_par.peak_I = ADrive_rx.PAR_4_ID1.M_peak_I;
        servo1.mot_par.rated_I = ADrive_rx.PAR_4_ID1.M_rated_I;
        Serial.print("Saved peak_I = ");
        Serial.println(servo1.mot_par.peak_I);
        Serial.print("Saved rated_I = ");
        Serial.println(servo1.mot_par.rated_I);
    }
    else if (decID == PAR_4_ID2_CANID)
    {
        servo2.mot_par.peak_I = ADrive_rx.PAR_4_ID2.M_peak_I;
        servo2.mot_par.rated_I = ADrive_rx.PAR_4_ID2.M_rated_I;

        Serial.print("Saved peak_I = ");
        Serial.println(servo2.mot_par.peak_I);
        Serial.print("Saved rated_I = ");
        Serial.println(servo2.mot_par.rated_I);
    }
    else if (decID == PAR_5_ID1_CANID)
    {
        servo1.mot_par.rated_torque = ADrive_rx.PAR_5_ID1.M_rated_torque;
        servo1.mot_par.torque_slope = ADrive_rx.PAR_5_ID1.M_torque_slope;
        Serial.print("Saved rated_torque = ");
        Serial.println(servo1.mot_par.rated_torque);
        Serial.print("Saved torque_slope = ");
        Serial.println(servo1.mot_par.torque_slope);
    }
    else if (decID == PAR_5_ID2_CANID)
    {
        servo2.mot_par.rated_torque = ADrive_rx.PAR_5_ID2.M_rated_torque;
        servo2.mot_par.torque_slope = ADrive_rx.PAR_5_ID2.M_torque_slope;

        Serial.print("Saved rated_torque = ");
        Serial.println(servo2.mot_par.rated_torque);
        Serial.print("Saved torque_slope = ");
        Serial.println(servo2.mot_par.torque_slope);
    }
    else if (decID == PAR_6_ID1_CANID)
    {
        servo1.mot_par.max_profile_speed = ADrive_rx.PAR_6_ID1.M_max_profile_speed;
        servo1.mot_par.max_speed = ADrive_rx.PAR_6_ID1.M_max_speed;
        Serial.print("Saved max_profile_speed = ");
        Serial.println(servo1.mot_par.max_profile_speed);
        Serial.print("Saved max_speed = ");
        Serial.println(servo1.mot_par.max_speed);
    }
    else if (decID == PAR_6_ID2_CANID)
    {
        servo2.mot_par.max_profile_speed = ADrive_rx.PAR_6_ID2.M_max_profile_speed;
        servo2.mot_par.max_speed = ADrive_rx.PAR_6_ID2.M_max_speed;

        Serial.print("Saved max_profile_speed = ");
        Serial.println(servo2.mot_par.max_profile_speed);
        Serial.print("Saved max_speed = ");
        Serial.println(servo2.mot_par.max_speed);
    }
    else if (decID == PAR_7_ID1_CANID)
    {
        servo1.mot_par.max_acc = ADrive_rx.PAR_7_ID1.M_max_acc;
        servo1.mot_par.max_dec = ADrive_rx.PAR_7_ID1.M_max_dec;
        Serial.print("Saved max_acc = ");
        Serial.println(servo1.mot_par.max_acc);
        Serial.print("Saved max_dec = ");
        Serial.println(servo1.mot_par.max_dec);
    }
    else if (decID == PAR_7_ID2_CANID)
    {
        servo2.mot_par.max_acc = ADrive_rx.PAR_7_ID2.M_max_acc;
        servo2.mot_par.max_dec = ADrive_rx.PAR_7_ID2.M_max_dec;

        Serial.print("Saved max_acc = ");
        Serial.println(servo2.mot_par.max_acc);
        Serial.print("Saved max_dec = ");
        Serial.println(servo2.mot_par.max_dec);
    }
    else if (decID == PAR_8_ID1_CANID)
    {
        servo1.mot_par.max_profile_acc = ADrive_rx.PAR_8_ID1.M_max_profile_acc;
        servo1.mot_par.max_profile_dec = ADrive_rx.PAR_8_ID1.M_max_profile_dec;
        Serial.print("Saved max_profile_acc = ");
        Serial.println(servo1.mot_par.max_profile_acc);
        Serial.print("Saved max_profile_dec = ");
        Serial.println(servo1.mot_par.max_profile_dec);
    }
    else if (decID == PAR_8_ID2_CANID)
    {
        servo2.mot_par.max_profile_acc = ADrive_rx.PAR_8_ID2.M_max_profile_acc;
        servo2.mot_par.max_profile_dec = ADrive_rx.PAR_8_ID2.M_max_profile_dec;

        Serial.print("Saved max_profile_acc = ");
        Serial.println(servo2.mot_par.max_profile_acc);
        Serial.print("Saved max_profile_dec = ");
        Serial.println(servo2.mot_par.max_profile_dec);
    }
    else if (decID == PAR_9_ID1_CANID)
    {
        servo1.mot_par.cur_P_gain = ADrive_rx.PAR_9_ID1.M_cur_P_gain;
        servo1.mot_par.cur_I_gain = ADrive_rx.PAR_9_ID1.M_cur_I_gain;
        Serial.print("Saved cur_P_gain = ");
        Serial.println(servo1.mot_par.cur_P_gain);
        Serial.print("Saved cur_I_gain = ");
        Serial.println(servo1.mot_par.cur_I_gain);
    }
    else if (decID == PAR_9_ID2_CANID)
    {
        servo2.mot_par.cur_P_gain = ADrive_rx.PAR_9_ID2.M_cur_P_gain;
        servo2.mot_par.cur_I_gain = ADrive_rx.PAR_9_ID2.M_cur_I_gain;

        Serial.print("Saved cur_P_gain = ");
        Serial.println(servo2.mot_par.cur_P_gain);
        Serial.print("Saved cur_I_gain = ");
        Serial.println(servo2.mot_par.cur_I_gain);
    }
    else if (decID == PAR_A_ID1_CANID)
    {
        servo1.mot_par.pos_I_gain = ADrive_rx.PAR_A_ID1.M_pos_I_gain;
        servo1.mot_par.pos_D_gain = ADrive_rx.PAR_A_ID1.M_pos_D_gain;
        Serial.print("Saved pos_I_gain = ");
        Serial.println(servo1.mot_par.pos_I_gain);
        Serial.print("Saved pos_D_gain = ");
        Serial.println(servo1.mot_par.pos_D_gain);
    }
    else if (decID == PAR_A_ID2_CANID)
    {
        servo2.mot_par.pos_I_gain = ADrive_rx.PAR_A_ID2.M_pos_I_gain;
        servo2.mot_par.pos_D_gain = ADrive_rx.PAR_A_ID2.M_pos_D_gain;

        Serial.print("Saved pos_I_gain = ");
        Serial.println(servo2.mot_par.pos_I_gain);
        Serial.print("Saved pos_D_gain = ");
        Serial.println(servo2.mot_par.pos_D_gain);
    }
    else if (decID == PAR_B_ID1_CANID)
    {
        servo1.mot_par.pos_saturation = ADrive_rx.PAR_B_ID1.M_pos_saturation;
        servo1.mot_par.faktor_Nm_A = ADrive_rx.PAR_B_ID1.faktor_Nm_A;
        Serial.print("Saved pos_saturation = ");
        Serial.println(servo1.mot_par.pos_saturation);
        Serial.print("Saved FAKTOR_NM_A = ");
        Serial.println(servo1.mot_par.faktor_Nm_A);
    }
    else if (decID == PAR_B_ID2_CANID)
    {
        servo2.mot_par.pos_saturation = ADrive_rx.PAR_B_ID2.M_pos_saturation;
        servo2.mot_par.faktor_Nm_A = ADrive_rx.PAR_B_ID2.faktor_Nm_A;

        Serial.print("Saved pos_saturation = ");
        Serial.println(servo2.mot_par.pos_saturation);
        Serial.print("Saved FAKTOR_NM_A = ");
        Serial.println(servo2.mot_par.faktor_Nm_A);
    }
}

void Gateway::forwardSDO(CAN_FRAME &frame)
{
    sdoAntwort.id = SDO_ANTWORT_CANID;
    sdoAntwort.extended = SDO_ANTWORT_IDE;
    sdoAntwort.length = SDO_ANTWORT_DLC;

    sdoAntwort.data = frame.data;

    Can1.sendFrame(sdoAntwort);
}

void Gateway::printFrame(CAN_FRAME &frame)
{
    Serial.print("ID: 0x");
    Serial.print(frame.id, HEX);
    Serial.print(" Len: ");
    Serial.print(frame.length);
    Serial.print(" Data: 0x");
    for (int count = 0; count < frame.length; count++)
    {
        Serial.print(frame.data.bytes[count], HEX);
        Serial.print(" ");
    }
    Serial.print("\r\n");
}


// non blocking
void Gateway::packSDO(uint32_t s_id, uint8_t s_cb, uint16_t s_od, uint8_t s_sub, uint32_t s_data) 
{
    SDO s;
    
    s.frame.id = s_id;
    s.frame.length = 8;
    s.frame.data.byte[0] = s_cb;                   // Command Byte
    s.frame.data.byte[1] = (s_od & 0x00FF);
    s.frame.data.byte[2] = (s_od & 0xFF00) >> 8;   // OB-Index
    s.frame.data.byte[3] = s_sub;                  // Sub-Index
    s.frame.data.uint32[1] = s_data;               // Data

    s.obj_index = s_od;
    s.sub_index = s_sub;

    pendingSDOs.push_back(s);
    Can0.sendFrame(s.frame);
}

void Gateway::clearSDO(CAN_FRAME &f)
{
    uint8_t commandbyte = f.data.bytes[0];
    uint16_t obj_index = f.data.bytes[1] + f.data.bytes[2] * 256;
    uint8_t sub_index = f.data.bytes[3];

    auto s = pendingSDOs.begin();
    while (s < pendingSDOs.end())
    {
        if (f.id == (s->frame.id - 0x80))
        {
            if (s->obj_index == obj_index && s->sub_index == sub_index)
            {
                if (commandbyte == 0x60)
                {
                    Serial.print("<SDO (0x");
                    Serial.print(obj_index, HEX);
                    Serial.println(") OK");      
                    //forwardSDO(s.frame);
                }
                else if (commandbyte >= 0x40 && commandbyte < 0x60)
                {
                    if((s->frame.id & 0xF) == servo1.getID()) {
                        if(s->obj_index == 0x20C7) {
                            servo1.status.motor_temp = static_cast<float>(f.data.uint32[1]);
                        }else if(s->obj_index == 0x6073) {
                            servo1.status.limit_torque = servo1.MICONTtoTorque(f.data.uint32[1]);
                        }
                    }else if((s->frame.id & 0xF) == servo2.getID()){
                        if(s->obj_index == 0x20C7) {
                            servo2.status.motor_temp = static_cast<float>(f.data.uint32[1]);
                        }else if(s->obj_index == 0x6073) {
                            servo2.status.limit_torque = servo2.MICONTtoTorque(f.data.uint32[1]);
                        }
                    }
                    //forwardSDO(s.frame);
                }
                else
                {
                    Serial.println("SDO ERROR: ");
                    printFrame(s->frame);
                }     
                s = pendingSDOs.erase(s);
                return;
            }
        }
        s++;
    }
}
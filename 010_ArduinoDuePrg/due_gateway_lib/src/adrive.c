
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#include "adrive.h"

// --------------------------------------------------------------------------
uint32_t Unpack_INIT_ID1_ADrive(INIT_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->befehl = (_d[2] & (0xFFU));
  return INIT_ID1_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_INIT_ID2_ADrive(INIT_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->befehl = (_d[2] & (0xFFU));
  return INIT_ID2_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_INIT_ELREST_ADrive(INIT_ELREST_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->befehl = (_d[2] & (0xFFU));
  return INIT_ELREST_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_MODE_ID1_ADrive(MODE_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->control_mode = (_d[0] & (0xFFU));
  return MODE_ID1_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_MODE_ID2_ADrive(MODE_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->control_mode = (_d[0] & (0xFFU));
  return MODE_ID2_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_START_MODUS_ID1_ADrive(START_MODUS_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->op_mode = (_d[0] & (0xFFU));
  _m->op_enable = (_d[1] & (0x01U));
  _m->relative_absolut = (_d[2] & (0x01U));
  return START_MODUS_ID1_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_START_MODUS_ID2_ADrive(START_MODUS_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->op_mode = (_d[0] & (0xFFU));
  _m->op_enable = (_d[1] & (0x01U));
  _m->relative_absolut = (_d[2] & (0x01U));
  return START_MODUS_ID2_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_Drehzahl_Werte_ID1_ADrive(Drehzahl_Werte_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->D_soll_rpm, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->D_max_torq, &x, sizeof(float));

  return Drehzahl_Werte_ID1_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_Drehzahl_Werte_ID2_ADrive(Drehzahl_Werte_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->D_soll_rpm, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->D_max_torq, &x, sizeof(float));

  return Drehzahl_Werte_ID2_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_Drehmoment_Werte_ID1_ADrive(Drehmoment_Werte_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->T_soll_torq, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->T_max_rpm, &x, sizeof(float));

  return Drehmoment_Werte_ID1_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_Drehmoment_Werte_ID2_ADrive(Drehmoment_Werte_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->T_soll_torq, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->T_max_rpm, &x, sizeof(float));

  return Drehmoment_Werte_ID2_CANID;
}
// --------------------------------------------------------------------------
uint32_t Unpack_Postion_Werte_ID1_ADrive(Postion_Werte_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->P_soll_pos, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->P_soll_rpm, &x, sizeof(float));
  return Postion_Werte_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_Postion_Werte_ID2_ADrive(Postion_Werte_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->P_soll_pos, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->P_soll_rpm, &x, sizeof(float));
  return Postion_Werte_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_Postion_Beschl_ID1_ADrive(Postion_Beschl_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->P_max_acc, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->P_max_dec, &x, sizeof(float));
  return Postion_Beschl_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_Postion_Beschl_ID2_ADrive(Postion_Beschl_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->P_max_acc, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->P_max_dec, &x, sizeof(float));
  return Postion_Beschl_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_CONTROL_ID1_ADrive(CONTROL_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->controlword = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->op_mode = (_d[2] & (0xFFU));
  return CONTROL_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_CONTROL_ID2_ADrive(CONTROL_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->controlword = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->op_mode = (_d[2] & (0xFFU));
  return CONTROL_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STOP_MODUS_ID1_ADrive(STOP_MODUS_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->stop_mode = (_d[1] & (0xFFU));
  return STOP_MODUS_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STOP_MODUS_ID2_ADrive(STOP_MODUS_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->stop_mode = (_d[1] & (0xFFU));
  return STOP_MODUS_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_MOT_CONFIG_ID1_ADrive(MOT_CONFIG_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return MOT_CONFIG_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_MOT_CONFIG_ID2_ADrive(MOT_CONFIG_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return MOT_CONFIG_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_1_ID1_ADrive(PAR_1_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_pos_P_gain, &x, sizeof(float));  
  _m->M_max_I = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_1_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_1_ID2_ADrive(PAR_1_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_pos_P_gain, &x, sizeof(float));  
  _m->M_max_I = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_1_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_2_ID1_ADrive(PAR_2_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_vel_P_gain, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_vel_I_gain, &x, sizeof(float));
  return PAR_2_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_2_ID2_ADrive(PAR_2_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_vel_P_gain, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_vel_I_gain, &x, sizeof(float));
  return PAR_2_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_3_ID1_ADrive(PAR_3_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_L, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_R, &x, sizeof(float));
  return PAR_3_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_3_ID2_ADrive(PAR_3_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_L, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_R, &x, sizeof(float));
  return PAR_3_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_4_ID1_ADrive(PAR_4_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_peak_I = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_rated_I = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_4_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_4_ID2_ADrive(PAR_4_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_peak_I = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_rated_I = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_4_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_5_ID1_ADrive(PAR_5_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_rated_torque = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_torque_slope = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_5_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_5_ID2_ADrive(PAR_5_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_rated_torque = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_torque_slope = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_5_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_6_ID1_ADrive(PAR_6_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_max_profile_speed = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_max_speed = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_6_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_6_ID2_ADrive(PAR_6_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_max_profile_speed = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_max_speed = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_6_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_7_ID1_ADrive(PAR_7_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_max_acc = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_max_dec = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_7_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_7_ID2_ADrive(PAR_7_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_max_acc = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_max_dec = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_7_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_8_ID1_ADrive(PAR_8_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_max_profile_acc = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_max_profile_dec = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_8_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_8_ID2_ADrive(PAR_8_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_max_profile_acc = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->M_max_profile_dec = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return PAR_8_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_9_ID1_ADrive(PAR_9_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_cur_P_gain, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_cur_I_gain, &x, sizeof(float));
  return PAR_9_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_9_ID2_ADrive(PAR_9_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_cur_P_gain, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_cur_I_gain, &x, sizeof(float));
  return PAR_9_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_A_ID1_ADrive(PAR_A_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_pos_I_gain, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_pos_D_gain, &x, sizeof(float));
  return PAR_A_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_A_ID2_ADrive(PAR_A_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  uint32_t x = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  memcpy(&_m->M_pos_I_gain, &x, sizeof(float));
  x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->M_pos_D_gain, &x, sizeof(float));
  return PAR_A_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_B_ID1_ADrive(PAR_B_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_pos_saturation = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  uint32_t x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->faktor_Nm_A, &x, sizeof(float));
  return PAR_B_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_B_ID2_ADrive(PAR_B_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->M_pos_saturation = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  uint32_t x = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  memcpy(&_m->faktor_Nm_A, &x, sizeof(float));
  return PAR_B_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_C_ID1_ADrive(PAR_C_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return PAR_C_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_C_ID2_ADrive(PAR_C_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return PAR_C_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_D_ID1_ADrive(PAR_D_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return PAR_D_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_D_ID2_ADrive(PAR_D_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return PAR_D_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_E_ID1_ADrive(PAR_E_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return PAR_E_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_PAR_E_ID2_ADrive(PAR_E_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return PAR_E_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_MOT_PARAM_ID1_ADrive(MOT_PARAM_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return MOT_PARAM_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_MOT_PARAM_ID2_ADrive(MOT_PARAM_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return MOT_PARAM_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_AKZEPTIERT_ADrive(AKZEPTIERT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->success = (_d[0] & (0x01U));
  return AKZEPTIERT_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_SDO_ANTWORT_ADrive(SDO_ANTWORT_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->sdo_rw = (_d[0] & (0xFFU));
  _m->sdo_cob = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->sdo_sub = (_d[3] & (0xFFU));
  _m->sdo_antwort = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return SDO_ANTWORT_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_SDO_ADrive(SDO_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->sdo_rw = (_d[0] & (0xFFU));
  _m->sdo_cob = ((_d[2] & (0xFFU)) << 8) | (_d[1] & (0xFFU));
  _m->sdo_sub = (_d[3] & (0xFFU));
  _m->sdo_wert = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return SDO_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO1_1_ADrive(TPDO1_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->rdy_switch_on = (_d[0] & (0x01U));
  _m->switched_on = ((_d[0] >> 1) & (0x01U));
  _m->op_enable = ((_d[0] >> 2) & (0x01U));
  _m->fault = ((_d[0] >> 3) & (0x01U));
  _m->voltage_en = ((_d[0] >> 4) & (0x01U));
  _m->quick_stop = ((_d[0] >> 5) & (0x01U));
  _m->switch_on_disabled = ((_d[0] >> 6) & (0x01U));
  _m->warning = ((_d[0] >> 7) & (0x01U));
  _m->man = (_d[1] & (0x01U));
  _m->remote = ((_d[1] >> 1) & (0x01U));
  _m->target_reached = ((_d[1] >> 2) & (0x01U));
  _m->internal_limit_active = ((_d[1] >> 3) & (0x01U));
  _m->mode_specific = ((_d[1] >> 4) & (0x03U));
  _m->man2 = ((_d[1] >> 6) & (0x03U));
  _m->opmode = (_d[2] & (0xFFU));
  _m->ist_torq = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  return TPDO1_1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO1_2_ADrive(TPDO1_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->rdy_switch_on = (_d[0] & (0x01U));
  _m->switched_on = ((_d[0] >> 1) & (0x01U));
  _m->op_enable = ((_d[0] >> 2) & (0x01U));
  _m->fault = ((_d[0] >> 3) & (0x01U));
  _m->voltage_en = ((_d[0] >> 4) & (0x01U));
  _m->quick_stop = ((_d[0] >> 5) & (0x01U));
  _m->switch_on_disabled = ((_d[0] >> 6) & (0x01U));
  _m->warning = ((_d[0] >> 7) & (0x01U));
  _m->man = (_d[1] & (0x01U));
  _m->remote = ((_d[1] >> 1) & (0x01U));
  _m->target_reached = ((_d[1] >> 2) & (0x01U));
  _m->internal_limit_active = ((_d[1] >> 3) & (0x01U));
  _m->mode_specific = ((_d[1] >> 4) & (0x03U));
  _m->man2 = ((_d[1] >> 6) & (0x03U));
  _m->opmode = (_d[2] & (0xFFU));
  _m->ist_torq = ((_d[4] & (0xFFU)) << 8) | (_d[3] & (0xFFU));
  return TPDO1_2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO1_3_ADrive(TPDO1_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->D0 = (_d[0] & (0x01U));
  _m->D1 = ((_d[0] >> 1) & (0x01U));
  _m->D2 = ((_d[0] >> 2) & (0x01U));
  _m->D3 = ((_d[0] >> 3) & (0x01U));
  _m->D4 = ((_d[0] >> 4) & (0x01U));
  _m->D5 = ((_d[0] >> 5) & (0x01U));
  _m->D6 = ((_d[0] >> 6) & (0x01U));
  _m->D7 = ((_d[0] >> 7) & (0x01U));
  _m->D8 = (_d[1] & (0x01U));
  _m->D9 = ((_d[1] >> 1) & (0x01U));
  _m->D10 = ((_d[1] >> 2) & (0x01U));
  _m->D11 = ((_d[1] >> 3) & (0x01U));
  _m->D12 = ((_d[1] >> 4) & (0x01U));
  _m->D13 = ((_d[1] >> 5) & (0x01U));
  _m->D14 = ((_d[1] >> 6) & (0x01U));
  _m->D15 = ((_d[1] >> 7) & (0x01U));
  return TPDO1_3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO1_4_ADrive(TPDO1_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->D0 = (_d[0] & (0x01U));
  _m->D1 = ((_d[0] >> 1) & (0x01U));
  _m->D2 = ((_d[0] >> 2) & (0x01U));
  _m->D3 = ((_d[0] >> 3) & (0x01U));
  _m->D4 = ((_d[0] >> 4) & (0x01U));
  _m->D5 = ((_d[0] >> 5) & (0x01U));
  _m->D6 = ((_d[0] >> 6) & (0x01U));
  _m->D7 = ((_d[0] >> 7) & (0x01U));
  _m->D8 = (_d[1] & (0x01U));
  _m->D9 = ((_d[1] >> 1) & (0x01U));
  _m->D10 = ((_d[1] >> 2) & (0x01U));
  _m->D11 = ((_d[1] >> 3) & (0x01U));
  _m->D12 = ((_d[1] >> 4) & (0x01U));
  _m->D13 = ((_d[1] >> 5) & (0x01U));
  _m->D14 = ((_d[1] >> 6) & (0x01U));
  _m->D15 = ((_d[1] >> 7) & (0x01U));
  return TPDO1_4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO1_5_ADrive(TPDO1_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->D0 = (_d[0] & (0x01U));
  _m->D1 = ((_d[0] >> 1) & (0x01U));
  _m->D2 = ((_d[0] >> 2) & (0x01U));
  _m->D3 = ((_d[0] >> 3) & (0x01U));
  _m->D4 = ((_d[0] >> 4) & (0x01U));
  _m->D5 = ((_d[0] >> 5) & (0x01U));
  _m->D6 = ((_d[0] >> 6) & (0x01U));
  _m->D7 = ((_d[0] >> 7) & (0x01U));
  _m->D8 = (_d[1] & (0x01U));
  _m->D9 = ((_d[1] >> 1) & (0x01U));
  _m->D10 = ((_d[1] >> 2) & (0x01U));
  _m->D11 = ((_d[1] >> 3) & (0x01U));
  _m->D12 = ((_d[1] >> 4) & (0x01U));
  _m->D13 = ((_d[1] >> 5) & (0x01U));
  _m->D14 = ((_d[1] >> 6) & (0x01U));
  _m->D15 = ((_d[1] >> 7) & (0x01U));
  return TPDO1_5_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO2_1_ADrive(TPDO2_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ist_pos = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->ist_rpm = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return TPDO2_1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO2_2_ADrive(TPDO2_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ist_pos = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->ist_rpm = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return TPDO2_2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO2_3_ADrive(TPDO2_3_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->A0 = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->A1 = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->A2 = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->A3 = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return TPDO2_3_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO2_4_ADrive(TPDO2_4_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->A0 = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->A1 = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->A2 = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->A3 = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return TPDO2_4_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO2_5_ADrive(TPDO2_5_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->A0 = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->A1 = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->A2 = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->A3 = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return TPDO2_5_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO3_1_ADrive(TPDO3_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ist_curr = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->soll_torq = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->analog1 = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->analog2 = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return TPDO3_1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO3_2_ADrive(TPDO3_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->ist_curr = ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->soll_torq = ((_d[3] & (0xFFU)) << 8) | (_d[2] & (0xFFU));
  _m->analog1 = ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  _m->analog2 = ((_d[7] & (0xFFU)) << 8) | (_d[6] & (0xFFU));
  return TPDO3_2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO4_1_ADrive(TPDO4_1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->dig_in = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->pos_ext = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return TPDO4_1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_TPDO4_2_ADrive(TPDO4_2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->dig_in = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->pos_ext = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return TPDO4_2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_1_ID1_ADrive(STATUS_1_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_drehzahl = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->S_position = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return STATUS_1_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_1_ID2_ADrive(STATUS_1_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_drehzahl = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->S_position = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return STATUS_1_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_2_ID1_ADrive(STATUS_2_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_ist_strom = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->S_limit_torque = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return STATUS_2_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_2_ID2_ADrive(STATUS_2_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_ist_strom = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->S_limit_torque = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return STATUS_2_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_3_ID1_ADrive(STATUS_3_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_ist_torque = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->S_soll_torque = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return STATUS_3_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_3_ID2_ADrive(STATUS_3_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_ist_torque = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  _m->S_soll_torque = ((_d[7] & (0xFFU)) << 24) | ((_d[6] & (0xFFU)) << 16) | ((_d[5] & (0xFFU)) << 8) | (_d[4] & (0xFFU));
  return STATUS_3_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_4_ID1_ADrive(STATUS_4_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_motor_temp = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  return STATUS_4_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_STATUS_4_ID2_ADrive(STATUS_4_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  _m->S_motor_temp = ((_d[3] & (0xFFU)) << 24) | ((_d[2] & (0xFFU)) << 16) | ((_d[1] & (0xFFU)) << 8) | (_d[0] & (0xFFU));
  return STATUS_4_ID2_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_WATCHDOG_ID1_ADrive(WATCHDOG_ID1_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return WATCHDOG_ID1_CANID;
}

// --------------------------------------------------------------------------
uint32_t Unpack_WATCHDOG_ID2_ADrive(WATCHDOG_ID2_t* _m, const uint8_t* _d, uint8_t dlc_)
{
  return WATCHDOG_ID2_CANID;
}

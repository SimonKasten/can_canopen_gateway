
// this file were genereted by coderdbc.com web service
// any questions - mailto:coderdbc@gmail.com

#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <string.h>

// def @INIT_ID1 CAN Message (4097)
#define INIT_ID1_IDE (1U)
#define INIT_ID1_DLC (3U)
#define INIT_ID1_CANID (0x1001U)
typedef struct
{

  uint8_t befehl;                           //      Bits=08.  [ 0     , 0      ]  Unit:''     
} INIT_ID1_t;

// def @INIT_ID2 CAN Message (4098)
#define INIT_ID2_IDE (1U)
#define INIT_ID2_DLC (3U)
#define INIT_ID2_CANID (0x1002U)
typedef struct
{

  uint8_t befehl;                           //      Bits=08.  [ 0     , 0      ]  Unit:''     
} INIT_ID2_t;

// def @INIT_ELREST CAN Message (4099)
#define INIT_ELREST_IDE (1U)
#define INIT_ELREST_DLC (3U)
#define INIT_ELREST_CANID (0x1003U)
typedef struct
{

  uint8_t befehl;                           //      Bits=08.  [ 0     , 0      ]  Unit:''     
} INIT_ELREST_t;

// def @MODE_ID1 CAN Message (5377)
#define MODE_ID1_IDE (1U)
#define MODE_ID1_DLC (8U)
#define MODE_ID1_CANID (0x1501U)
typedef struct
{

  uint8_t control_mode;                     //      Bits=08.  [ 0     , 0      ]  Unit:''     
} MODE_ID1_t;

// def @MODE_ID2 CAN Message (5378)
#define MODE_ID2_IDE (1U)
#define MODE_ID2_DLC (8U)
#define MODE_ID2_CANID (0x1502U)
typedef struct
{

  uint8_t control_mode;                     //      Bits=08.  [ 0     , 0      ]  Unit:''     
} MODE_ID2_t;

// def @START_MODUS_ID1 CAN Message (8193)
#define START_MODUS_ID1_IDE (1U)
#define START_MODUS_ID1_DLC (3U)
#define START_MODUS_ID1_CANID (0x2001U)
typedef struct
{

  int8_t op_mode;                           //  [-] Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t op_enable;                        //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t relative_absolut;                 //      Bits=01.  [ 0     , 0      ]  Unit:''     
} START_MODUS_ID1_t;

// def @START_MODUS_ID2 CAN Message (8194)
#define START_MODUS_ID2_IDE (1U)
#define START_MODUS_ID2_DLC (3U)
#define START_MODUS_ID2_CANID (0x2002U)
typedef struct
{

  int8_t op_mode;                           //  [-] Bits=08.  [ 0     , 0      ]  Unit:''     

  uint8_t op_enable;                        //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t relative_absolut;                 //      Bits=01.  [ 0     , 0      ]  Unit:''     
} START_MODUS_ID2_t;

// def @Drehzahl_Werte_ID1 CAN Message (8449)
#define Drehzahl_Werte_ID1_IDE (1U)
#define Drehzahl_Werte_ID1_DLC (8U)
#define Drehzahl_Werte_ID1_CANID (0x2101U)
typedef struct
{

  float D_soll_rpm;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  

  float D_max_torq;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   
} Drehzahl_Werte_ID1_t;

// def @Drehzahl_Werte_ID2 CAN Message (8450)
#define Drehzahl_Werte_ID2_IDE (1U)
#define Drehzahl_Werte_ID2_DLC (8U)
#define Drehzahl_Werte_ID2_CANID (0x2102U)
typedef struct
{

  float D_soll_rpm;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  

  float D_max_torq;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   
} Drehzahl_Werte_ID2_t;

// def @Drehmoment_Werte_ID1 CAN Message (8705)
#define Drehmoment_Werte_ID1_IDE (1U)
#define Drehmoment_Werte_ID1_DLC (8U)
#define Drehmoment_Werte_ID1_CANID (0x2201U)
typedef struct
{

  float T_soll_torq;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   

  float T_max_rpm;                        //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  
} Drehmoment_Werte_ID1_t;

// def @Drehmoment_Werte_ID2 CAN Message (8706)
#define Drehmoment_Werte_ID2_IDE (1U)
#define Drehmoment_Werte_ID2_DLC (8U)
#define Drehmoment_Werte_ID2_CANID (0x2202U)
typedef struct
{

  float T_soll_torq;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   

  float T_max_rpm;                        //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  
} Drehmoment_Werte_ID2_t;

// def @Postion_Werte_ID1 CAN Message (8961)
#define Postion_Werte_ID1_IDE (1U)
#define Postion_Werte_ID1_DLC (8U)
#define Postion_Werte_ID1_CANID (0x2301U)
typedef struct
{

  float P_soll_pos;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float P_soll_rpm;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  
} Postion_Werte_ID1_t;

// def @Postion_Werte_ID2 CAN Message (8962)
#define Postion_Werte_ID2_IDE (1U)
#define Postion_Werte_ID2_DLC (8U)
#define Postion_Werte_ID2_CANID (0x2302U)
typedef struct
{

  float P_soll_pos;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float P_soll_rpm;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  
} Postion_Werte_ID2_t;

// def @Postion_Beschl_ID1 CAN Message (9217)
#define Postion_Beschl_ID1_IDE (1U)
#define Postion_Beschl_ID1_DLC (8U)
#define Postion_Beschl_ID1_CANID (0x2401U)
typedef struct
{

  float P_max_acc;                        //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm/s'

  float P_max_dec;                        //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm/s'
} Postion_Beschl_ID1_t;

// def @Postion_Beschl_ID2 CAN Message (9218)
#define Postion_Beschl_ID2_IDE (1U)
#define Postion_Beschl_ID2_DLC (8U)
#define Postion_Beschl_ID2_CANID (0x2402U)
typedef struct
{

  float P_max_acc;                        //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm/s'

  float P_max_dec;                        //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm/s'
} Postion_Beschl_ID2_t;

// def @CONTROL_ID1 CAN Message (12289)
#define CONTROL_ID1_IDE (1U)
#define CONTROL_ID1_DLC (3U)
#define CONTROL_ID1_CANID (0x3001U)
typedef struct
{

  uint16_t controlword;                     //      Bits=16.  [ 0     , 0      ]  Unit:''     

  int8_t op_mode;                           //  [-] Bits=08.  [ -128  , 127    ]  Unit:''     
} CONTROL_ID1_t;

// def @CONTROL_ID2 CAN Message (12290)
#define CONTROL_ID2_IDE (1U)
#define CONTROL_ID2_DLC (3U)
#define CONTROL_ID2_CANID (0x3002U)
typedef struct
{

  uint16_t controlword;                     //      Bits=16.  [ 0     , 0      ]  Unit:''     

  int8_t op_mode;                           //  [-] Bits=08.  [ 0     , 0      ]  Unit:''     
} CONTROL_ID2_t;

// def @STOP_MODUS_ID1 CAN Message (16385)
#define STOP_MODUS_ID1_IDE (1U)
#define STOP_MODUS_ID1_DLC (2U)
#define STOP_MODUS_ID1_CANID (0x4001U)
typedef struct
{

  uint8_t stop_mode;                        //      Bits=08.  [ 0     , 0      ]  Unit:''     
} STOP_MODUS_ID1_t;

// def @STOP_MODUS_ID2 CAN Message (16386)
#define STOP_MODUS_ID2_IDE (1U)
#define STOP_MODUS_ID2_DLC (2U)
#define STOP_MODUS_ID2_CANID (0x4002U)
typedef struct
{

  uint8_t stop_mode;                        //      Bits=08.  [ 0     , 0      ]  Unit:''     
} STOP_MODUS_ID2_t;

// def @MOT_CONFIG_ID1 CAN Message (32769)
#define MOT_CONFIG_ID1_IDE (1U)
#define MOT_CONFIG_ID1_DLC (8U)
#define MOT_CONFIG_ID1_CANID (0x8001U)
typedef struct
{
} MOT_CONFIG_ID1_t;

// def @MOT_CONFIG_ID2 CAN Message (32770)
#define MOT_CONFIG_ID2_IDE (1U)
#define MOT_CONFIG_ID2_DLC (8U)
#define MOT_CONFIG_ID2_CANID (0x8002U)
typedef struct
{
} MOT_CONFIG_ID2_t;

// def @PAR_1_ID1 CAN Message (32785)
#define PAR_1_ID1_IDE (1U)
#define PAR_1_ID1_DLC (8U)
#define PAR_1_ID1_CANID (0x8011U)
typedef struct
{

  float M_pos_P_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  uint16_t M_max_I;                         //      Bits=16.  [ 0     , 0      ]  Unit:''     
} PAR_1_ID1_t;

// def @PAR_1_ID2 CAN Message (32786)
#define PAR_1_ID2_IDE (1U)
#define PAR_1_ID2_DLC (8U)
#define PAR_1_ID2_CANID (0x8012U)
typedef struct
{

  float M_pos_P_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  uint16_t M_max_I;                         //      Bits=16.  [ 0     , 0      ]  Unit:''     
} PAR_1_ID2_t;

// def @PAR_2_ID1 CAN Message (32801)
#define PAR_2_ID1_IDE (1U)
#define PAR_2_ID1_DLC (8U)
#define PAR_2_ID1_CANID (0x8021U)
typedef struct
{

  float M_vel_P_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_vel_I_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_2_ID1_t;

// def @PAR_2_ID2 CAN Message (32802)
#define PAR_2_ID2_IDE (1U)
#define PAR_2_ID2_DLC (8U)
#define PAR_2_ID2_CANID (0x8022U)
typedef struct
{

  float M_vel_P_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_vel_I_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_2_ID2_t;

// def @PAR_3_ID1 CAN Message (32817)
#define PAR_3_ID1_IDE (1U)
#define PAR_3_ID1_DLC (8U)
#define PAR_3_ID1_CANID (0x8031U)
typedef struct
{

  float M_L;                              //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_R;                              //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_3_ID1_t;

// def @PAR_3_ID2 CAN Message (32818)
#define PAR_3_ID2_IDE (1U)
#define PAR_3_ID2_DLC (8U)
#define PAR_3_ID2_CANID (0x8032U)
typedef struct
{

  float M_L;                              //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_R;                              //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_3_ID2_t;

// def @PAR_4_ID1 CAN Message (32833)
#define PAR_4_ID1_IDE (1U)
#define PAR_4_ID1_DLC (8U)
#define PAR_4_ID1_CANID (0x8041U)
typedef struct
{

  uint32_t M_peak_I;                        //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_rated_I;                       //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_4_ID1_t;

// def @PAR_4_ID2 CAN Message (32834)
#define PAR_4_ID2_IDE (1U)
#define PAR_4_ID2_DLC (8U)
#define PAR_4_ID2_CANID (0x8042U)
typedef struct
{

  uint32_t M_peak_I;                        //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_rated_I;                       //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_4_ID2_t;

// def @PAR_5_ID1 CAN Message (32849)
#define PAR_5_ID1_IDE (1U)
#define PAR_5_ID1_DLC (8U)
#define PAR_5_ID1_CANID (0x8051U)
typedef struct
{

  uint32_t M_rated_torque;                  //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_torque_slope;                  //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_5_ID1_t;

// def @PAR_5_ID2 CAN Message (32850)
#define PAR_5_ID2_IDE (1U)
#define PAR_5_ID2_DLC (8U)
#define PAR_5_ID2_CANID (0x8052U)
typedef struct
{

  uint32_t M_rated_torque;                  //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_torque_slope;                  //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_5_ID2_t;

// def @PAR_6_ID1 CAN Message (32865)
#define PAR_6_ID1_IDE (1U)
#define PAR_6_ID1_DLC (8U)
#define PAR_6_ID1_CANID (0x8061U)
typedef struct
{

  uint32_t M_max_profile_speed;             //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_max_speed;                     //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_6_ID1_t;

// def @PAR_6_ID2 CAN Message (32866)
#define PAR_6_ID2_IDE (1U)
#define PAR_6_ID2_DLC (8U)
#define PAR_6_ID2_CANID (0x8062U)
typedef struct
{

  uint32_t M_max_profile_speed;             //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_max_speed;                     //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_6_ID2_t;

// def @PAR_7_ID1 CAN Message (32881)
#define PAR_7_ID1_IDE (1U)
#define PAR_7_ID1_DLC (8U)
#define PAR_7_ID1_CANID (0x8071U)
typedef struct
{

  uint32_t M_max_acc;                       //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_max_dec;                       //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_7_ID1_t;

// def @PAR_7_ID2 CAN Message (32882)
#define PAR_7_ID2_IDE (1U)
#define PAR_7_ID2_DLC (8U)
#define PAR_7_ID2_CANID (0x8072U)
typedef struct
{

  uint32_t M_max_acc;                       //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_max_dec;                       //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_7_ID2_t;

// def @PAR_8_ID1 CAN Message (32897)
#define PAR_8_ID1_IDE (1U)
#define PAR_8_ID1_DLC (8U)
#define PAR_8_ID1_CANID (0x8081U)
typedef struct
{

  uint32_t M_max_profile_acc;               //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_max_profile_dec;               //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_8_ID1_t;

// def @PAR_8_ID2 CAN Message (32898)
#define PAR_8_ID2_IDE (1U)
#define PAR_8_ID2_DLC (8U)
#define PAR_8_ID2_CANID (0x8082U)
typedef struct
{

  uint32_t M_max_profile_acc;               //      Bits=32.  [ 0     , 0      ]  Unit:''     

  uint32_t M_max_profile_dec;               //      Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_8_ID2_t;

// def @PAR_9_ID1 CAN Message (32913)
#define PAR_9_ID1_IDE (1U)
#define PAR_9_ID1_DLC (8U)
#define PAR_9_ID1_CANID (0x8091U)
typedef struct
{

  float M_cur_P_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_cur_I_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_9_ID1_t;

// def @PAR_9_ID2 CAN Message (32914)
#define PAR_9_ID2_IDE (1U)
#define PAR_9_ID2_DLC (8U)
#define PAR_9_ID2_CANID (0x8092U)
typedef struct
{

  float M_cur_P_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_cur_I_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_9_ID2_t;

// def @PAR_A_ID1 CAN Message (32929)
#define PAR_A_ID1_IDE (1U)
#define PAR_A_ID1_DLC (8U)
#define PAR_A_ID1_CANID (0x80A1U)
typedef struct
{

  float M_pos_I_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_pos_D_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_A_ID1_t;

// def @PAR_A_ID2 CAN Message (32930)
#define PAR_A_ID2_IDE (1U)
#define PAR_A_ID2_DLC (8U)
#define PAR_A_ID2_CANID (0x80A2U)
typedef struct
{

  float M_pos_I_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  float M_pos_D_gain;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} PAR_A_ID2_t;

// def @PAR_B_ID1 CAN Message (32945)
#define PAR_B_ID1_IDE (1U)
#define PAR_B_ID1_DLC (8U)
#define PAR_B_ID1_CANID (0x80B1U)
typedef struct
{

  uint32_t M_pos_saturation;                //      Bits=32.  [ 0     , 0      ]  Unit:''     

  float faktor_Nm_A;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm/A' 
} PAR_B_ID1_t;

// def @PAR_B_ID2 CAN Message (32946)
#define PAR_B_ID2_IDE (1U)
#define PAR_B_ID2_DLC (8U)
#define PAR_B_ID2_CANID (0x80B2U)
typedef struct
{

  uint32_t M_pos_saturation;                //      Bits=32.  [ 0     , 0      ]  Unit:''     

  float faktor_Nm_A;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm/A' 
} PAR_B_ID2_t;

// def @PAR_C_ID1 CAN Message (32961)
#define PAR_C_ID1_IDE (1U)
#define PAR_C_ID1_DLC (8U)
#define PAR_C_ID1_CANID (0x80C1U)
typedef struct
{
} PAR_C_ID1_t;

// def @PAR_C_ID2 CAN Message (32962)
#define PAR_C_ID2_IDE (1U)
#define PAR_C_ID2_DLC (8U)
#define PAR_C_ID2_CANID (0x80C2U)
typedef struct
{
} PAR_C_ID2_t;

// def @PAR_D_ID1 CAN Message (32977)
#define PAR_D_ID1_IDE (1U)
#define PAR_D_ID1_DLC (8U)
#define PAR_D_ID1_CANID (0x80D1U)
typedef struct
{
} PAR_D_ID1_t;

// def @PAR_D_ID2 CAN Message (32978)
#define PAR_D_ID2_IDE (1U)
#define PAR_D_ID2_DLC (8U)
#define PAR_D_ID2_CANID (0x80D2U)
typedef struct
{
} PAR_D_ID2_t;

// def @PAR_E_ID1 CAN Message (32993)
#define PAR_E_ID1_IDE (1U)
#define PAR_E_ID1_DLC (8U)
#define PAR_E_ID1_CANID (0x80E1U)
typedef struct
{
} PAR_E_ID1_t;

// def @PAR_E_ID2 CAN Message (32994)
#define PAR_E_ID2_IDE (1U)
#define PAR_E_ID2_DLC (8U)
#define PAR_E_ID2_CANID (0x80E2U)
typedef struct
{
} PAR_E_ID2_t;

// def @MOT_PARAM_ID1 CAN Message (36865)
#define MOT_PARAM_ID1_IDE (1U)
#define MOT_PARAM_ID1_DLC (8U)
#define MOT_PARAM_ID1_CANID (0x9001U)
typedef struct
{
} MOT_PARAM_ID1_t;

// def @MOT_PARAM_ID2 CAN Message (36866)
#define MOT_PARAM_ID2_IDE (1U)
#define MOT_PARAM_ID2_DLC (8U)
#define MOT_PARAM_ID2_CANID (0x9002U)
typedef struct
{
} MOT_PARAM_ID2_t;

// def @AKZEPTIERT CAN Message (65535)
#define AKZEPTIERT_IDE (1U)
#define AKZEPTIERT_DLC (8U)
#define AKZEPTIERT_CANID (0xFFFFU)
typedef struct
{

  uint8_t success;                          //      Bits=01.  [ 0     , 1      ]  Unit:''     
} AKZEPTIERT_t;

// def @SDO_ANTWORT CAN Message (66945)
#define SDO_ANTWORT_IDE (1U)
#define SDO_ANTWORT_DLC (8U)
#define SDO_ANTWORT_CANID (0x10581U)
typedef struct
{

  uint8_t sdo_rw;                           //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t sdo_cob;                         //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint8_t sdo_sub;                          //      Bits=08.  [ 0     , 0      ]  Unit:''     

  int32_t sdo_antwort;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} SDO_ANTWORT_t;

// def @SDO CAN Message (67073)
#define SDO_IDE (1U)
#define SDO_DLC (8U)
#define SDO_CANID (0x10601U)
typedef struct
{

  uint8_t sdo_rw;                           //      Bits=08.  [ 0     , 0      ]  Unit:''     

  uint16_t sdo_cob;                         //      Bits=16.  [ 0     , 0      ]  Unit:''     

  uint8_t sdo_sub;                          //      Bits=08.  [ 0     , 0      ]  Unit:''     

  int32_t sdo_wert;                         //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} SDO_t;

// def @TPDO1_1 CAN Message (16777601)
#define TPDO1_1_IDE (1U)
#define TPDO1_1_DLC (5U)
#define TPDO1_1_CANID (0x1000181U)
typedef struct
{

  uint8_t rdy_switch_on;                    //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t switched_on;                      //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t op_enable;                        //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t fault;                            //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t voltage_en;                       //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t quick_stop;                       //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t switch_on_disabled;               //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t warning;                          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t man;                              //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t remote;                           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t target_reached;                   //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t internal_limit_active;            //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t mode_specific;                    //      Bits=02.  [ 0     , 3      ]  Unit:''     

  uint8_t man2;                             //      Bits=02.  [ 0     , 3      ]  Unit:''     

  int8_t opmode;                            //  [-] Bits=08.  [ 0     , 0      ]  Unit:''     

  int16_t ist_torq;                         //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO1_1_t;

// def @TPDO1_2 CAN Message (16777602)
#define TPDO1_2_IDE (1U)
#define TPDO1_2_DLC (5U)
#define TPDO1_2_CANID (0x1000182U)
typedef struct
{

  uint8_t rdy_switch_on;                    //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t switched_on;                      //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t op_enable;                        //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t fault;                            //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t voltage_en;                       //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t quick_stop;                       //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t switch_on_disabled;               //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t warning;                          //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t man;                              //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t remote;                           //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t target_reached;                   //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t internal_limit_active;            //      Bits=01.  [ 0     , 1      ]  Unit:''     

  uint8_t mode_specific;                    //      Bits=02.  [ 0     , 3      ]  Unit:''     

  uint8_t man2;                             //      Bits=02.  [ 0     , 3      ]  Unit:''     

  int8_t opmode;                            //  [-] Bits=08.  [ 0     , 0      ]  Unit:''     

  int16_t ist_torq;                         //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO1_2_t;

// def @TPDO1_3 CAN Message (16777603)
#define TPDO1_3_IDE (1U)
#define TPDO1_3_DLC (2U)
#define TPDO1_3_CANID (0x1000183U)
typedef struct
{

  uint8_t D0;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D1;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D2;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D3;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D4;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D5;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D6;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D7;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D8;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D9;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D10;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D11;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D12;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D13;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D14;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D15;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     
} TPDO1_3_t;

// def @TPDO1_4 CAN Message (16777604)
#define TPDO1_4_IDE (1U)
#define TPDO1_4_DLC (2U)
#define TPDO1_4_CANID (0x1000184U)
typedef struct
{

  uint8_t D0;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D1;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D2;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D3;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D4;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D5;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D6;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D7;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D8;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D9;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D10;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D11;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D12;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D13;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D14;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D15;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     
} TPDO1_4_t;

// def @TPDO1_5 CAN Message (16777605)
#define TPDO1_5_IDE (1U)
#define TPDO1_5_DLC (2U)
#define TPDO1_5_CANID (0x1000185U)
typedef struct
{

  uint8_t D0;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D1;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D2;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D3;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D4;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D5;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D6;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D7;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D8;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D9;                               //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D10;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D11;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D12;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D13;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D14;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     

  uint8_t D15;                              //      Bits=01.  [ 0     , 0      ]  Unit:''     
} TPDO1_5_t;

// def @TPDO2_1 CAN Message (16777857)
#define TPDO2_1_IDE (1U)
#define TPDO2_1_DLC (8U)
#define TPDO2_1_CANID (0x1000281U)
typedef struct
{

  int32_t ist_pos;                          //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  int32_t ist_rpm;                          //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} TPDO2_1_t;

// def @TPDO2_2 CAN Message (16777858)
#define TPDO2_2_IDE (1U)
#define TPDO2_2_DLC (8U)
#define TPDO2_2_CANID (0x1000282U)
typedef struct
{

  int32_t ist_pos;                          //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     

  int32_t ist_rpm;                          //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} TPDO2_2_t;

// def @TPDO2_3 CAN Message (16777859)
#define TPDO2_3_IDE (1U)
#define TPDO2_3_DLC (8U)
#define TPDO2_3_CANID (0x1000283U)
typedef struct
{

  int16_t A0;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A1;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A2;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A3;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO2_3_t;

// def @TPDO2_4 CAN Message (16777860)
#define TPDO2_4_IDE (1U)
#define TPDO2_4_DLC (8U)
#define TPDO2_4_CANID (0x1000284U)
typedef struct
{

  int16_t A0;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A1;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A2;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A3;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO2_4_t;

// def @TPDO2_5 CAN Message (16777861)
#define TPDO2_5_IDE (1U)
#define TPDO2_5_DLC (8U)
#define TPDO2_5_CANID (0x1000285U)
typedef struct
{

  int16_t A0;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A1;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A2;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t A3;                               //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO2_5_t;

// def @TPDO3_1 CAN Message (16778113)
#define TPDO3_1_IDE (1U)
#define TPDO3_1_DLC (8U)
#define TPDO3_1_CANID (0x1000381U)
typedef struct
{

  int16_t ist_curr;                         //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t soll_torq;                        //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t analog1;                          //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t analog2;                          //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO3_1_t;

// def @TPDO3_2 CAN Message (16778114)
#define TPDO3_2_IDE (1U)
#define TPDO3_2_DLC (8U)
#define TPDO3_2_CANID (0x1000382U)
typedef struct
{

  int16_t ist_curr;                         //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t soll_torq;                        //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t analog1;                          //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     

  int16_t analog2;                          //  [-] Bits=16.  [ 0     , 0      ]  Unit:''     
} TPDO3_2_t;

// def @TPDO4_1 CAN Message (16778369)
#define TPDO4_1_IDE (1U)
#define TPDO4_1_DLC (8U)
#define TPDO4_1_CANID (0x1000481U)
typedef struct
{

  uint32_t dig_in;                          //      Bits=32.  [ 0     , 0      ]  Unit:''     

  int32_t pos_ext;                          //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} TPDO4_1_t;

// def @TPDO4_2 CAN Message (16778370)
#define TPDO4_2_IDE (1U)
#define TPDO4_2_DLC (8U)
#define TPDO4_2_CANID (0x1000482U)
typedef struct
{

  uint32_t dig_in;                          //      Bits=32.  [ 0     , 0      ]  Unit:''     

  int32_t pos_ext;                          //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} TPDO4_2_t;

// def @STATUS_1_ID1 CAN Message (17825809)
#define STATUS_1_ID1_IDE (1U)
#define STATUS_1_ID1_DLC (8U)
#define STATUS_1_ID1_CANID (0x1100011U)
typedef struct
{

  int32_t S_drehzahl;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  

  int32_t S_position;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'revs' 
} STATUS_1_ID1_t;

// def @STATUS_1_ID2 CAN Message (17825810)
#define STATUS_1_ID2_IDE (1U)
#define STATUS_1_ID2_DLC (8U)
#define STATUS_1_ID2_CANID (0x1100012U)
typedef struct
{

  int32_t S_drehzahl;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'rpm'  

  int32_t S_position;                       //  [-] Bits=32.  [ 0     , 0      ]  Unit:'revs' 
} STATUS_1_ID2_t;

// def @STATUS_2_ID1 CAN Message (17825825)
#define STATUS_2_ID1_IDE (1U)
#define STATUS_2_ID1_DLC (8U)
#define STATUS_2_ID1_CANID (0x1100021U)
typedef struct
{

  int32_t S_ist_strom;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:'A'    

  int32_t S_limit_torque;                   //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} STATUS_2_ID1_t;

// def @STATUS_2_ID2 CAN Message (17825826)
#define STATUS_2_ID2_IDE (1U)
#define STATUS_2_ID2_DLC (8U)
#define STATUS_2_ID2_CANID (0x1100022U)
typedef struct
{

  int32_t S_ist_strom;                      //  [-] Bits=32.  [ 0     , 0      ]  Unit:'A'    

  int32_t S_limit_torque;                   //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} STATUS_2_ID2_t;

// def @STATUS_3_ID1 CAN Message (17825841)
#define STATUS_3_ID1_IDE (1U)
#define STATUS_3_ID1_DLC (8U)
#define STATUS_3_ID1_CANID (0x1100031U)
typedef struct
{

  int32_t S_ist_torque;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   

  int32_t S_soll_torque;                    //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   
} STATUS_3_ID1_t;

// def @STATUS_3_ID2 CAN Message (17825842)
#define STATUS_3_ID2_IDE (1U)
#define STATUS_3_ID2_DLC (8U)
#define STATUS_3_ID2_CANID (0x1100032U)
typedef struct
{

  int32_t S_ist_torque;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   

  int32_t S_soll_torque;                    //  [-] Bits=32.  [ 0     , 0      ]  Unit:'Nm'   
} STATUS_3_ID2_t;

// def @STATUS_4_ID1 CAN Message (17825857)
#define STATUS_4_ID1_IDE (1U)
#define STATUS_4_ID1_DLC (8U)
#define STATUS_4_ID1_CANID (0x1100041U)
typedef struct
{

  int32_t S_motor_temp;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} STATUS_4_ID1_t;

// def @STATUS_4_ID2 CAN Message (17825858)
#define STATUS_4_ID2_IDE (1U)
#define STATUS_4_ID2_DLC (8U)
#define STATUS_4_ID2_CANID (0x1100042U)
typedef struct
{

  int32_t S_motor_temp;                     //  [-] Bits=32.  [ 0     , 0      ]  Unit:''     
} STATUS_4_ID2_t;

// def @WATCHDOG_ID1 CAN Message (17895697)
#define WATCHDOG_ID1_IDE (1U)
#define WATCHDOG_ID1_DLC (8U)
#define WATCHDOG_ID1_CANID (0x1111111U)
typedef struct
{
} WATCHDOG_ID1_t;

// def @WATCHDOG_ID2 CAN Message (17895698)
#define WATCHDOG_ID2_IDE (1U)
#define WATCHDOG_ID2_DLC (8U)
#define WATCHDOG_ID2_CANID (0x1111112U)
typedef struct
{
} WATCHDOG_ID2_t;

uint32_t Unpack_INIT_ID1_ADrive(INIT_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_INIT_ID2_ADrive(INIT_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_INIT_ELREST_ADrive(INIT_ELREST_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_MODE_ID1_ADrive(MODE_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_MODE_ID2_ADrive(MODE_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_START_MODUS_ID1_ADrive(START_MODUS_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_START_MODUS_ID2_ADrive(START_MODUS_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Drehzahl_Werte_ID1_ADrive(Drehzahl_Werte_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Drehzahl_Werte_ID2_ADrive(Drehzahl_Werte_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Drehmoment_Werte_ID1_ADrive(Drehmoment_Werte_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Drehmoment_Werte_ID2_ADrive(Drehmoment_Werte_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Postion_Werte_ID1_ADrive(Postion_Werte_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Postion_Werte_ID2_ADrive(Postion_Werte_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Postion_Beschl_ID1_ADrive(Postion_Beschl_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_Postion_Beschl_ID2_ADrive(Postion_Beschl_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_CONTROL_ID1_ADrive(CONTROL_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_CONTROL_ID2_ADrive(CONTROL_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STOP_MODUS_ID1_ADrive(STOP_MODUS_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STOP_MODUS_ID2_ADrive(STOP_MODUS_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_MOT_CONFIG_ID1_ADrive(MOT_CONFIG_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_MOT_CONFIG_ID2_ADrive(MOT_CONFIG_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_1_ID1_ADrive(PAR_1_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_1_ID2_ADrive(PAR_1_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_2_ID1_ADrive(PAR_2_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_2_ID2_ADrive(PAR_2_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_3_ID1_ADrive(PAR_3_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_3_ID2_ADrive(PAR_3_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_4_ID1_ADrive(PAR_4_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_4_ID2_ADrive(PAR_4_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_5_ID1_ADrive(PAR_5_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_5_ID2_ADrive(PAR_5_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_6_ID1_ADrive(PAR_6_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_6_ID2_ADrive(PAR_6_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_7_ID1_ADrive(PAR_7_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_7_ID2_ADrive(PAR_7_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_8_ID1_ADrive(PAR_8_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_8_ID2_ADrive(PAR_8_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_9_ID1_ADrive(PAR_9_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_9_ID2_ADrive(PAR_9_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_A_ID1_ADrive(PAR_A_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_A_ID2_ADrive(PAR_A_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_B_ID1_ADrive(PAR_B_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_B_ID2_ADrive(PAR_B_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_C_ID1_ADrive(PAR_C_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_C_ID2_ADrive(PAR_C_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_D_ID1_ADrive(PAR_D_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_D_ID2_ADrive(PAR_D_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_E_ID1_ADrive(PAR_E_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_PAR_E_ID2_ADrive(PAR_E_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_MOT_PARAM_ID1_ADrive(MOT_PARAM_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_MOT_PARAM_ID2_ADrive(MOT_PARAM_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_AKZEPTIERT_ADrive(AKZEPTIERT_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_SDO_ANTWORT_ADrive(SDO_ANTWORT_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_SDO_ADrive(SDO_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO1_1_ADrive(TPDO1_1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO1_2_ADrive(TPDO1_2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO1_3_ADrive(TPDO1_3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO1_4_ADrive(TPDO1_4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO1_5_ADrive(TPDO1_5_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO2_1_ADrive(TPDO2_1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO2_2_ADrive(TPDO2_2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO2_3_ADrive(TPDO2_3_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO2_4_ADrive(TPDO2_4_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO2_5_ADrive(TPDO2_5_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO3_1_ADrive(TPDO3_1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO3_2_ADrive(TPDO3_2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO4_1_ADrive(TPDO4_1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_TPDO4_2_ADrive(TPDO4_2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_1_ID1_ADrive(STATUS_1_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_1_ID2_ADrive(STATUS_1_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_2_ID1_ADrive(STATUS_2_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_2_ID2_ADrive(STATUS_2_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_3_ID1_ADrive(STATUS_3_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_3_ID2_ADrive(STATUS_3_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_4_ID1_ADrive(STATUS_4_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_STATUS_4_ID2_ADrive(STATUS_4_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_WATCHDOG_ID1_ADrive(WATCHDOG_ID1_t* _m, const uint8_t* _d, uint8_t dlc_);
uint32_t Unpack_WATCHDOG_ID2_ADrive(WATCHDOG_ID2_t* _m, const uint8_t* _d, uint8_t dlc_);

#ifdef __cplusplus
}
#endif


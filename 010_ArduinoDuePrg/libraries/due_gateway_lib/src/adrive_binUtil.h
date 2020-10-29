
#pragma once


#ifdef __cplusplus
extern "C" {
#endif

#include "adrive.h"

typedef struct
{
  INIT_ID1_t INIT_ID1;                           // TX [Vector__XXX].RX [Vector__XXX ].
  INIT_ID2_t INIT_ID2;                           // TX [Vector__XXX].RX [Vector__XXX ].
  INIT_ELREST_t INIT_ELREST;                     // TX [Vector__XXX].RX [Vector__XXX ].
  MODE_ID1_t MODE_ID1;                           // TX [Vector__XXX].RX [Vector__XXX ].
  MODE_ID2_t MODE_ID2;                           // TX [Vector__XXX].RX [Vector__XXX ].
  START_MODUS_ID1_t START_MODUS_ID1;             // TX [Vector__XXX].RX [Vector__XXX ].
  START_MODUS_ID2_t START_MODUS_ID2;             // TX [Vector__XXX].RX [Vector__XXX ].
  Drehzahl_Werte_ID1_t Drehzahl_Werte_ID1;       // TX [Vector__XXX].RX [].
  Drehzahl_Werte_ID2_t Drehzahl_Werte_ID2;       // TX [Vector__XXX].RX [Vector__XXX ].
  Drehmoment_Werte_ID1_t Drehmoment_Werte_ID1;   // TX [Vector__XXX].RX [Vector__XXX ].
  Drehmoment_Werte_ID2_t Drehmoment_Werte_ID2;   // TX [Vector__XXX].RX [Vector__XXX ].
  Postion_Werte_ID1_t Postion_Werte_ID1;         // TX [Vector__XXX].RX [Vector__XXX ].
  Postion_Werte_ID2_t Postion_Werte_ID2;         // TX [Vector__XXX].RX [Vector__XXX ].
  Postion_Beschl_ID1_t Postion_Beschl_ID1;       // TX [Vector__XXX].RX [Vector__XXX ].
  Postion_Beschl_ID2_t Postion_Beschl_ID2;       // TX [Vector__XXX].RX [Vector__XXX ].
  CONTROL_ID1_t CONTROL_ID1;                     // TX [Vector__XXX].RX [Vector__XXX ].
  CONTROL_ID2_t CONTROL_ID2;                     // TX [Vector__XXX].RX [Vector__XXX ].
  STOP_MODUS_ID1_t STOP_MODUS_ID1;               // TX [Vector__XXX].RX [Vector__XXX ].
  STOP_MODUS_ID2_t STOP_MODUS_ID2;               // TX [Vector__XXX].RX [Vector__XXX ].
  MOT_CONFIG_ID1_t MOT_CONFIG_ID1;               // TX [Vector__XXX].RX [].
  MOT_CONFIG_ID2_t MOT_CONFIG_ID2;               // TX [Vector__XXX].RX [].
  PAR_1_ID1_t PAR_1_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_1_ID2_t PAR_1_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_2_ID1_t PAR_2_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_2_ID2_t PAR_2_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_3_ID1_t PAR_3_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_3_ID2_t PAR_3_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_4_ID1_t PAR_4_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_4_ID2_t PAR_4_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_5_ID1_t PAR_5_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_5_ID2_t PAR_5_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_6_ID1_t PAR_6_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_6_ID2_t PAR_6_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_7_ID1_t PAR_7_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_7_ID2_t PAR_7_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_8_ID1_t PAR_8_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_8_ID2_t PAR_8_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_9_ID1_t PAR_9_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_9_ID2_t PAR_9_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_A_ID1_t PAR_A_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_A_ID2_t PAR_A_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_B_ID1_t PAR_B_ID1;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_B_ID2_t PAR_B_ID2;                         // TX [Vector__XXX].RX [Vector__XXX ].
  PAR_C_ID1_t PAR_C_ID1;                         // TX [Vector__XXX].RX [].
  PAR_C_ID2_t PAR_C_ID2;                         // TX [Vector__XXX].RX [].
  PAR_D_ID1_t PAR_D_ID1;                         // TX [Vector__XXX].RX [].
  PAR_D_ID2_t PAR_D_ID2;                         // TX [Vector__XXX].RX [].
  PAR_E_ID1_t PAR_E_ID1;                         // TX [Vector__XXX].RX [].
  PAR_E_ID2_t PAR_E_ID2;                         // TX [Vector__XXX].RX [].
  MOT_PARAM_ID1_t MOT_PARAM_ID1;                 // TX [Vector__XXX].RX [].
  MOT_PARAM_ID2_t MOT_PARAM_ID2;                 // TX [Vector__XXX].RX [].
  AKZEPTIERT_t AKZEPTIERT;                       // TX [Vector__XXX].RX [Vector__XXX ].
  SDO_ANTWORT_t SDO_ANTWORT;                     // TX [Vector__XXX].RX [Vector__XXX ].
  SDO_t SDO;                                     // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO1_1_t TPDO1_1;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO1_2_t TPDO1_2;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO1_3_t TPDO1_3;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO1_4_t TPDO1_4;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO1_5_t TPDO1_5;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO2_1_t TPDO2_1;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO2_2_t TPDO2_2;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO2_3_t TPDO2_3;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO2_4_t TPDO2_4;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO2_5_t TPDO2_5;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO3_1_t TPDO3_1;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO3_2_t TPDO3_2;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO4_1_t TPDO4_1;                             // TX [Vector__XXX].RX [Vector__XXX ].
  TPDO4_2_t TPDO4_2;                             // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_1_ID1_t STATUS_1_ID1;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_1_ID2_t STATUS_1_ID2;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_2_ID1_t STATUS_2_ID1;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_2_ID2_t STATUS_2_ID2;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_3_ID1_t STATUS_3_ID1;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_3_ID2_t STATUS_3_ID2;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_4_ID1_t STATUS_4_ID1;                   // TX [Vector__XXX].RX [Vector__XXX ].
  STATUS_4_ID2_t STATUS_4_ID2;                   // TX [Vector__XXX].RX [Vector__XXX ].
  WATCHDOG_ID1_t WATCHDOG_ID1;                   // TX [Vector__XXX].RX [].
  WATCHDOG_ID2_t WATCHDOG_ID2;                   // TX [Vector__XXX].RX [].
} ADrive_rx_t;

// There is no any message detected with tx direction.

uint32_t ADrive_Receive(ADrive_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_);


#ifdef __cplusplus
}
#endif


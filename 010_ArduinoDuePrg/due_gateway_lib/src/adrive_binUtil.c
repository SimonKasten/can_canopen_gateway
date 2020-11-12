#include "adrive_binUtil.h"

uint32_t ADrive_Receive(ADrive_rx_t* _m, const uint8_t* _d, uint32_t _id, uint8_t dlc_)
{
 uint32_t recid = 0;
 if (_id >= 0x1001U && _id < 0x80A1U) {
  if (_id >= 0x1001U && _id < 0x8001U) {
   if (_id >= 0x1001U && _id < 0x2201U) {
    if (_id >= 0x1001U && _id < 0x1502U) {
     if (_id >= 0x1001U && _id < 0x1003U) {
      if (_id == 0x1001U) {
       recid = Unpack_INIT_ID1_ADrive(&(_m->INIT_ID1), _d, dlc_);
      } else if (_id == 0x1002U) {
       recid = Unpack_INIT_ID2_ADrive(&(_m->INIT_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x1003U) {
       recid = Unpack_INIT_ELREST_ADrive(&(_m->INIT_ELREST), _d, dlc_);
      } else if (_id == 0x1501U) {
       recid = Unpack_MODE_ID1_ADrive(&(_m->MODE_ID1), _d, dlc_);
      }
     }
    } else {
     if (_id >= 0x1502U && _id < 0x2002U) {
      if (_id == 0x1502U) {
       recid = Unpack_MODE_ID2_ADrive(&(_m->MODE_ID2), _d, dlc_);
      } else if (_id == 0x2001U) {
       recid = Unpack_START_MODUS_ID1_ADrive(&(_m->START_MODUS_ID1), _d, dlc_);
      }
     } else {
      if (_id == 0x2002U) {
       recid = Unpack_START_MODUS_ID2_ADrive(&(_m->START_MODUS_ID2), _d, dlc_);
      } else {
       if (_id == 0x2101U) {
        recid = Unpack_Drehzahl_Werte_ID1_ADrive(&(_m->Drehzahl_Werte_ID1), _d, dlc_);
       } else if (_id == 0x2102U) {
        recid = Unpack_Drehzahl_Werte_ID2_ADrive(&(_m->Drehzahl_Werte_ID2), _d, dlc_);
       }
      }
     }
    }
   } else {
    if (_id >= 0x2201U && _id < 0x2402U) {
     if (_id >= 0x2201U && _id < 0x2301U) {
      if (_id == 0x2201U) {
       recid = Unpack_Drehmoment_Werte_ID1_ADrive(&(_m->Drehmoment_Werte_ID1), _d, dlc_);
      } else if (_id == 0x2202U) {
       recid = Unpack_Drehmoment_Werte_ID2_ADrive(&(_m->Drehmoment_Werte_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x2301U) {
       recid = Unpack_Postion_Werte_ID1_ADrive(&(_m->Postion_Werte_ID1), _d, dlc_);
      } else {
       if (_id == 0x2302U) {
        recid = Unpack_Postion_Werte_ID2_ADrive(&(_m->Postion_Werte_ID2), _d, dlc_);
       } else if (_id == 0x2401U) {
        recid = Unpack_Postion_Beschl_ID1_ADrive(&(_m->Postion_Beschl_ID1), _d, dlc_);
       }
      }
     }
    } else {
     if (_id >= 0x2402U && _id < 0x3002U) {
      if (_id == 0x2402U) {
       recid = Unpack_Postion_Beschl_ID2_ADrive(&(_m->Postion_Beschl_ID2), _d, dlc_);
      } else if (_id == 0x3001U) {
       recid = Unpack_CONTROL_ID1_ADrive(&(_m->CONTROL_ID1), _d, dlc_);
      }
     } else {
      if (_id == 0x3002U) {
       recid = Unpack_CONTROL_ID2_ADrive(&(_m->CONTROL_ID2), _d, dlc_);
      } else {
       if (_id == 0x4001U) {
        recid = Unpack_STOP_MODUS_ID1_ADrive(&(_m->STOP_MODUS_ID1), _d, dlc_);
       } else if (_id == 0x4002U) {
        recid = Unpack_STOP_MODUS_ID2_ADrive(&(_m->STOP_MODUS_ID2), _d, dlc_);
       }
      }
     }
    }
   }
  } else {
   if (_id >= 0x8001U && _id < 0x8051U) {
    if (_id >= 0x8001U && _id < 0x8022U) {
     if (_id >= 0x8001U && _id < 0x8011U) {
      if (_id == 0x8001U) {
       recid = Unpack_MOT_CONFIG_ID1_ADrive(&(_m->MOT_CONFIG_ID1), _d, dlc_);
      } else if (_id == 0x8002U) {
       recid = Unpack_MOT_CONFIG_ID2_ADrive(&(_m->MOT_CONFIG_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x8011U) {
       recid = Unpack_PAR_1_ID1_ADrive(&(_m->PAR_1_ID1), _d, dlc_);
      } else {
       if (_id == 0x8012U) {
        recid = Unpack_PAR_1_ID2_ADrive(&(_m->PAR_1_ID2), _d, dlc_);
       } else if (_id == 0x8021U) {
        recid = Unpack_PAR_2_ID1_ADrive(&(_m->PAR_2_ID1), _d, dlc_);
       }
      }
     }
    } else {
     if (_id >= 0x8022U && _id < 0x8032U) {
      if (_id == 0x8022U) {
       recid = Unpack_PAR_2_ID2_ADrive(&(_m->PAR_2_ID2), _d, dlc_);
      } else if (_id == 0x8031U) {
       recid = Unpack_PAR_3_ID1_ADrive(&(_m->PAR_3_ID1), _d, dlc_);
      }
     } else {
      if (_id == 0x8032U) {
       recid = Unpack_PAR_3_ID2_ADrive(&(_m->PAR_3_ID2), _d, dlc_);
      } else {
       if (_id == 0x8041U) {
        recid = Unpack_PAR_4_ID1_ADrive(&(_m->PAR_4_ID1), _d, dlc_);
       } else if (_id == 0x8042U) {
        recid = Unpack_PAR_4_ID2_ADrive(&(_m->PAR_4_ID2), _d, dlc_);
       }
      }
     }
    }
   } else {
    if (_id >= 0x8051U && _id < 0x8072U) {
     if (_id >= 0x8051U && _id < 0x8061U) {
      if (_id == 0x8051U) {
       recid = Unpack_PAR_5_ID1_ADrive(&(_m->PAR_5_ID1), _d, dlc_);
      } else if (_id == 0x8052U) {
       recid = Unpack_PAR_5_ID2_ADrive(&(_m->PAR_5_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x8061U) {
       recid = Unpack_PAR_6_ID1_ADrive(&(_m->PAR_6_ID1), _d, dlc_);
      } else {
       if (_id == 0x8062U) {
        recid = Unpack_PAR_6_ID2_ADrive(&(_m->PAR_6_ID2), _d, dlc_);
       } else if (_id == 0x8071U) {
        recid = Unpack_PAR_7_ID1_ADrive(&(_m->PAR_7_ID1), _d, dlc_);
       }
      }
     }
    } else {
     if (_id >= 0x8072U && _id < 0x8082U) {
      if (_id == 0x8072U) {
       recid = Unpack_PAR_7_ID2_ADrive(&(_m->PAR_7_ID2), _d, dlc_);
      } else if (_id == 0x8081U) {
       recid = Unpack_PAR_8_ID1_ADrive(&(_m->PAR_8_ID1), _d, dlc_);
      }
     } else {
      if (_id == 0x8082U) {
       recid = Unpack_PAR_8_ID2_ADrive(&(_m->PAR_8_ID2), _d, dlc_);
      } else {
       if (_id == 0x8091U) {
        recid = Unpack_PAR_9_ID1_ADrive(&(_m->PAR_9_ID1), _d, dlc_);
       } else if (_id == 0x8092U) {
        recid = Unpack_PAR_9_ID2_ADrive(&(_m->PAR_9_ID2), _d, dlc_);
       }
      }
     }
    }
   }
  }
 } else {
  if (_id >= 0x80A1U && _id < 0x1000185U) {
   if (_id >= 0x80A1U && _id < 0x80E2U) {
    if (_id >= 0x80A1U && _id < 0x80C1U) {
     if (_id >= 0x80A1U && _id < 0x80B1U) {
      if (_id == 0x80A1U) {
       recid = Unpack_PAR_A_ID1_ADrive(&(_m->PAR_A_ID1), _d, dlc_);
      } else if (_id == 0x80A2U) {
       recid = Unpack_PAR_A_ID2_ADrive(&(_m->PAR_A_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x80B1U) {
       recid = Unpack_PAR_B_ID1_ADrive(&(_m->PAR_B_ID1), _d, dlc_);
      } else if (_id == 0x80B2U) {
       recid = Unpack_PAR_B_ID2_ADrive(&(_m->PAR_B_ID2), _d, dlc_);
      }
     }
    } else {
     if (_id >= 0x80C1U && _id < 0x80D1U) {
      if (_id == 0x80C1U) {
       recid = Unpack_PAR_C_ID1_ADrive(&(_m->PAR_C_ID1), _d, dlc_);
      } else if (_id == 0x80C2U) {
       recid = Unpack_PAR_C_ID2_ADrive(&(_m->PAR_C_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x80D1U) {
       recid = Unpack_PAR_D_ID1_ADrive(&(_m->PAR_D_ID1), _d, dlc_);
      } else {
       if (_id == 0x80D2U) {
        recid = Unpack_PAR_D_ID2_ADrive(&(_m->PAR_D_ID2), _d, dlc_);
       } else if (_id == 0x80E1U) {
        recid = Unpack_PAR_E_ID1_ADrive(&(_m->PAR_E_ID1), _d, dlc_);
       }
      }
     }
    }
   } else {
    if (_id >= 0x80E2U && _id < 0x10601U) {
     if (_id >= 0x80E2U && _id < 0x9002U) {
      if (_id == 0x80E2U) {
       recid = Unpack_PAR_E_ID2_ADrive(&(_m->PAR_E_ID2), _d, dlc_);
      } else if (_id == 0x9001U) {
       recid = Unpack_MOT_PARAM_ID1_ADrive(&(_m->MOT_PARAM_ID1), _d, dlc_);
      }
     } else {
      if (_id == 0x9002U) {
       recid = Unpack_MOT_PARAM_ID2_ADrive(&(_m->MOT_PARAM_ID2), _d, dlc_);
      } else {
       if (_id == 0xFFFFU) {
        recid = Unpack_AKZEPTIERT_ADrive(&(_m->AKZEPTIERT), _d, dlc_);
       } else if (_id == 0x10581U) {
        recid = Unpack_SDO_ANTWORT_ADrive(&(_m->SDO_ANTWORT), _d, dlc_);
       }
      }
     }
    } else {
     if (_id >= 0x10601U && _id < 0x1000182U) {
      if (_id == 0x10601U) {
       recid = Unpack_SDO_ADrive(&(_m->SDO), _d, dlc_);
      } else if (_id == 0x1000181U) {
       recid = Unpack_TPDO1_1_ADrive(&(_m->TPDO1_1), _d, dlc_);
      }
     } else {
      if (_id == 0x1000182U) {
       recid = Unpack_TPDO1_2_ADrive(&(_m->TPDO1_2), _d, dlc_);
      } else {
       if (_id == 0x1000183U) {
        recid = Unpack_TPDO1_3_ADrive(&(_m->TPDO1_3), _d, dlc_);
       } else if (_id == 0x1000184U) {
        recid = Unpack_TPDO1_4_ADrive(&(_m->TPDO1_4), _d, dlc_);
       }
      }
     }
    }
   }
  } else {
   if (_id >= 0x1000185U && _id < 0x1100011U) {
    if (_id >= 0x1000185U && _id < 0x1000285U) {
     if (_id >= 0x1000185U && _id < 0x1000282U) {
      if (_id == 0x1000185U) {
       recid = Unpack_TPDO1_5_ADrive(&(_m->TPDO1_5), _d, dlc_);
      } else if (_id == 0x1000281U) {
       recid = Unpack_TPDO2_1_ADrive(&(_m->TPDO2_1), _d, dlc_);
      }
     } else {
      if (_id == 0x1000282U) {
       recid = Unpack_TPDO2_2_ADrive(&(_m->TPDO2_2), _d, dlc_);
      } else {
       if (_id == 0x1000283U) {
        recid = Unpack_TPDO2_3_ADrive(&(_m->TPDO2_3), _d, dlc_);
       } else if (_id == 0x1000284U) {
        recid = Unpack_TPDO2_4_ADrive(&(_m->TPDO2_4), _d, dlc_);
       }
      }
     }
    } else {
     if (_id >= 0x1000285U && _id < 0x1000382U) {
      if (_id == 0x1000285U) {
       recid = Unpack_TPDO2_5_ADrive(&(_m->TPDO2_5), _d, dlc_);
      } else if (_id == 0x1000381U) {
       recid = Unpack_TPDO3_1_ADrive(&(_m->TPDO3_1), _d, dlc_);
      }
     } else {
      if (_id == 0x1000382U) {
       recid = Unpack_TPDO3_2_ADrive(&(_m->TPDO3_2), _d, dlc_);
      } else {
       if (_id == 0x1000481U) {
        recid = Unpack_TPDO4_1_ADrive(&(_m->TPDO4_1), _d, dlc_);
       } else if (_id == 0x1000482U) {
        recid = Unpack_TPDO4_2_ADrive(&(_m->TPDO4_2), _d, dlc_);
       }
      }
     }
    }
   } else {
    if (_id >= 0x1100011U && _id < 0x1100032U) {
     if (_id >= 0x1100011U && _id < 0x1100021U) {
      if (_id == 0x1100011U) {
       recid = Unpack_STATUS_1_ID1_ADrive(&(_m->STATUS_1_ID1), _d, dlc_);
      } else if (_id == 0x1100012U) {
       recid = Unpack_STATUS_1_ID2_ADrive(&(_m->STATUS_1_ID2), _d, dlc_);
      }
     } else {
      if (_id == 0x1100021U) {
       recid = Unpack_STATUS_2_ID1_ADrive(&(_m->STATUS_2_ID1), _d, dlc_);
      } else {
       if (_id == 0x1100022U) {
        recid = Unpack_STATUS_2_ID2_ADrive(&(_m->STATUS_2_ID2), _d, dlc_);
       } else if (_id == 0x1100031U) {
        recid = Unpack_STATUS_3_ID1_ADrive(&(_m->STATUS_3_ID1), _d, dlc_);
       }
      }
     }
    } else {
     if (_id >= 0x1100032U && _id < 0x1100042U) {
      if (_id == 0x1100032U) {
       recid = Unpack_STATUS_3_ID2_ADrive(&(_m->STATUS_3_ID2), _d, dlc_);
      } else if (_id == 0x1100041U) {
       recid = Unpack_STATUS_4_ID1_ADrive(&(_m->STATUS_4_ID1), _d, dlc_);
      }
     } else {
      if (_id == 0x1100042U) {
       recid = Unpack_STATUS_4_ID2_ADrive(&(_m->STATUS_4_ID2), _d, dlc_);
      } else {
       if (_id == 0x1111111U) {
        recid = Unpack_WATCHDOG_ID1_ADrive(&(_m->WATCHDOG_ID1), _d, dlc_);
       } else if (_id == 0x1111112U) {
        recid = Unpack_WATCHDOG_ID2_ADrive(&(_m->WATCHDOG_ID2), _d, dlc_);
       }
      }
     }
    }
   }
  }
 }

 return recid;
}


#include "elrest.h"
#include "gateway.h"

void Elrest::update_tpdos(CAN_FRAME &f){
    int tpdo_id = f.id - getID();
    if (tpdo_id == 0x180){
        t1.data = f.data;
        
        tpdo.din_0_7 = f.data.uint8[0];
        tpdo.din_8_15 = f.data.uint8[1];
    }
    else if (tpdo_id == 0x280){
        t2.data = f.data;

        for(int i=0;i<4;i++)
            tpdo.a_in[i] = f.data.int16[i];
    }
}

void Elrest::update_rpdos(){
    r1.data.uint8[0] = rpdo.dout_0_7;
    r1.data.uint8[1] = rpdo.dout_8_15;

    for(int i=0;i<4;i++)
        r2.data.int16[i] = rpdo.a_out[i];
}

void Elrest::send_rpdos(){
    Can0.sendFrame(r1);
    Can0.sendFrame(r2);
}
void Elrest::send_tpdos(){
    Can1.sendFrame(t1);
    Can1.sendFrame(t2);
}

void Elrest::powerON()
{
    rpdo.dout_8_15 = 0x5;   // D8 und D10 setzten
    update_rpdos();
}

void Elrest::powerOFF()
{
    rpdo.dout_8_15 = 0;     // D8 und D10 loeschen
    update_rpdos();
}

void Elrest::initialisierung()
{
    g->packSDO(sdoID(), 0x23, 0x1005, 0x00, 0x80); // SYNC
    g->packSDO(sdoID(), 0x23, 0x1014, 0x00, 0x80 + getID()); //  EMCY ID
    // RPDO Comm Parameter
    g->packSDO(sdoID(), 0x23, 0x1400, 0x01, 0x200 + getID()); 
    g->packSDO(sdoID(), 0x2f, 0x1400, 0x02, 1); 
    g->packSDO(sdoID(), 0x23, 0x1401, 0x01, 0x300 + getID()); 
    g->packSDO(sdoID(), 0x2f, 0x1401, 0x02, 1); 
    // RPDO Mapping
    //packSDO(sdoID(), 0x2f, 0x1600, 0x00, 4); 

    // TPDO Comm Parameter
    g->packSDO(sdoID(), 0x23, 0x1800, 0x01, 0x180 + getID()); //
    g->packSDO(sdoID(), 0x2f, 0x1800, 0x02, 1); //
    g->packSDO(sdoID(), 0x23, 0x1801, 0x01, 0x280 + getID()); //
    g->packSDO(sdoID(), 0x2f, 0x1801, 0x02, 1); //
    // TPDO Mapping
    //packSDO(sdoID(), 0x2f, 0x1A00, 0x00, 4); 

    // Config Analog und Digital Pins
    g->packSDO(sdoID(), 0x2b, 0x5010, 0x01, 0x5); 
    g->packSDO(sdoID(), 0x2b, 0x5010, 0x02, 0x5); 
    g->packSDO(sdoID(), 0x2b, 0x5010, 0x03, 0x5); 
    g->packSDO(sdoID(), 0x2b, 0x5010, 0x04, 0x5); 
    g->packSDO(sdoID(), 0x2b, 0x5011, 0x01, 0x33); 
    g->packSDO(sdoID(), 0x2b, 0x5011, 0x02, 0x33); 
    g->packSDO(sdoID(), 0x2b, 0x5011, 0x03, 0x33); 
    g->packSDO(sdoID(), 0x2b, 0x5011, 0x04, 0x33); 
    g->packSDO(sdoID(), 0x2b, 0x5012, 0x01, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5012, 0x02, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5012, 0x03, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5012, 0x04, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5013, 0x01, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5013, 0x02, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5013, 0x03, 0xFA0); 
    g->packSDO(sdoID(), 0x2b, 0x5013, 0x04, 0xFA0); 

    g->packSDO(sdoID(), 0x2f, 0x6423, 0x00, 1); 
}
//extern "C" char* sbrk(int incr);
//
//int freeMemory() {

//  char top;
//  return &top - reinterpret_cast<char*>(sbrk(0));
//}

#include <DueTimer.h>
#include <gateway.h>

#define LED_SHIELD 11

CAN_FRAME can0_req;
CAN_FRAME can0_res;
CAN_FRAME can1_req;
CAN_FRAME can1_res;

Gateway gateway;

void forwPDO(){
    gateway.setTPDOsFLAG();
    gateway.setRPDOsFLAG();
}

void forwStatus(){
    gateway.setStatusFLAG();
}

void sync(){     // only Flags
    gateway.setSyncFLAG();
}

void resetSaftey(){  // only Flags
  if(gateway.getSecurityTimeout() < millis())
    gateway.resetSecurityFLAG();
    gateway.elrest1.powerOFF();
}

void init_canbus(){
    Can0.setRxBufferSize(256);
    Can0.setTxBufferSize(128);
    
    Can1.setRxBufferSize(256);
    Can1.setTxBufferSize(128);

    Can0.begin(CAN_BPS_500K);
    Can1.begin(CAN_BPS_500K);

    int filter;
    //extended
    for (filter = 0; filter < 3; filter++)
    {
        Can0.setRXFilter(filter, 0, 0, true);
        Can1.setRXFilter(filter, 0, 0, true);
    }
    //standard
    for (filter = 3; filter < 7; filter++)
    {
        Can0.setRXFilter(filter, 0, 0, false);
        Can1.setRXFilter(filter, 0, 0, false);
    }
}


void setup()
{ 
    pinMode(LED_SHIELD, OUTPUT);
    digitalWrite(LED_SHIELD, HIGH);

    Serial.begin(115200);

    init_canbus();
    
    Timer3.attachInterrupt(sync).start(20000);
    delay(10);
    Timer4.attachInterrupt(forwPDO).start(20000);
    delay(10);
    Timer5.attachInterrupt(resetSaftey).start(200000);
    delay(10);
    Timer6.attachInterrupt(forwStatus).start(500000);
    delay(10);
    
    Serial.println("------- DUE-CAN-SETUP --------");
}


void loop()
{
    gateway.mainloop();
    
    // CANOPEN
    if (Can0.available())
    { 
        digitalWrite(LED_SHIELD, HIGH);
        Can0.read(can0_req);
        gateway.process_canopen(can0_req);      
    }

    // CAN
    if (Can1.available())
    { 
        digitalWrite(LED_SHIELD, HIGH);
        Can1.read(can1_req);
        can1_res = gateway.process_can(can1_req);
        Can1.sendFrame(can1_res);
    }

    if(digitalRead(LED_SHIELD) == HIGH)
        digitalWrite(LED_SHIELD, LOW);
}

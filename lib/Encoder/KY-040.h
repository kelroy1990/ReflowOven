#ifndef KY-040_h
#define KY-040_h


#include "Arduino.h"


//Settings
#include <Settings.h>

#ifdef ARDUINO_ARCH_AVR
#include <avr/pgmspace.h>
#endif

//Esta va a ser la clase padre que contenga la pantalla y la sd, el resto heredan de la misma.

class Encoder {

public:

Encoder();
int GetPosition();
void SetZero();
void SetSwitchStop(){ //Aqui llama la interrupcion para detener
  _Switchstop=true;
}

protected:



private:

bool _Switchstop=false;
  int pinA = 3;  // Connected to CLK on KY-040
int pinB = 4;  // Connected to DT on KY-040
int encoderPosCount = 0;
int pinALast;
int aVal;
boolean bCW;




};

#endif

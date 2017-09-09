#ifndef Utilities_h
#define Utilities_h

#include "Arduino.h"
#include <TouchScreen.h>
#include <ILI9341_due.h>
#include <Settings.h>
#include <SdFat.h>
#include <ILI9341_due_config.h>
#include <touchcalibration.h>



#ifdef ARDUINO_ARCH_AVR
#include <avr/pgmspace.h>
#endif

//Esta va a ser la clase padre que contenga la pantalla y la sd, el resto heredan de la misma.

class Utilities {
public:
   Utilities();
   void SetScreenObject(ILI9341_due *IliObject);
   void PrintGrid(int StartX, int StartY, int FinishX, int FinishY, int Escale, String Xlabel, String Ylabel);


private:

   bool SD_state = false;
   void ClearScreen(uint16_t Color);

   //Constructores que tiene la pantalla, recogemos con puntero.
   ILI9341_due      *_tft;
   gTextArea _GridArea {30,20,WideScreen,HeigthScreen-50}; //Area del grid
   gTextArea _Xlabel {0,HeigthScreen-30,WideScreen,HeigthScreen};//Area del texto inferior
   gTextArea _Ylabel {0,20,30,HeigthScreen};//Area del texto Y

protected:


};

#endif

#ifndef menu_h
#define menu_h
#include "Arduino.h"


#ifdef ARDUINO_ARCH_AVR
#include <avr/pgmspace.h>
#endif

class Menu {
public:
   Menu();
//   ~Menu();

   void PrintStartMenu();
   void StartScreen();

private:



   void screenLoading();
   void drawButtons();


protected:
};

#endif

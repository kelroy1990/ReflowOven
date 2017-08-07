#ifndef pantalla_h
#define pantalla_h

#include "Arduino.h"
#include <TouchScreen.h>
#include <ILI9341_due.h>
#include <Settings.h>
#include <SdFat.h>
#include <ILI9341_due_config.h>
#include <touchcalibration.h>
#include <Utilities.h>


//Settings
#include <Settings.h>

#ifdef ARDUINO_ARCH_AVR
#include <avr/pgmspace.h>
#endif

//Esta va a ser la clase padre que contenga la pantalla y la sd, el resto heredan de la misma.

class Pantalla {
public:
   Pantalla();
   void InitialMenu();
   void StartScreen();
   void StartSD();
   void Menu();



private:

   bool SD_state = false;
   void ClearScreen(uint16_t Color);


protected:
   //Constructores que tiene la pantalla.
   TouchScreen      ts = TouchScreen(XP, YP, XM, YM, 300);
   TSPoint          p;
   ILI9341_due      tft = ILI9341_due(LCD_CS, LCD_DC, LCD_RST);
   SdFat            sd;
   SdFile           myFile;
   TouchCalibration CalibrateTouch = TouchCalibration(&tft);

   //Utilidades y funciones
   Utilities _Utilities;

   uint16_t colorLightGray = tft.color565(192, 192, 192);
   uint16_t colorGray      = tft.color565(127, 127, 127);
   uint16_t colorDarkGray  = tft.color565(64, 64, 64);
};

#endif

#ifndef touchcalibration_h
#define touchcalibration_h
#include "Arduino.h"
#include <TouchScreen.h>
#include <ILI9341_due.h>
#include <Settings.h>



class TouchCalibration {
public:

   TouchCalibration(ILI9341_due *tft);


   void CalibrateRutine();
   void SetUpScreenObject(ILI9341_due *tft);
   void readCoordinates();
   void drawCrossHair(int x,
                      int y,
                      uint16_t color);
   void calibrate(int x,
                  int y,
                  int i);
   void startup();


private:
   void waitForTouch();
   void toHex();
   void drawButtons();

protected:



   // For better pressure precision, we need to know the resistance
   // between X+ and X- Use any multimeter to read it
   // For the one we're using, its 300 ohms across the X plate
   TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
   TSPoint     p;
   ILI9341_due *_ILI9341;
};

#endif // ifndef touchcalibration_h

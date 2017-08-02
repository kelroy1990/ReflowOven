#include <Arduino.h>
#include <touchcalibration.h>
#include "TouchScreen.h"
#include <ILI9341_due.h>



TouchCalibration::TouchCalibration(ILI9341_due *tft)
{
   _ILI9341 = tft;
}

void TouchCalibration::CalibrateRutine()
{
   startup();
   drawCrossHair(10, 10, ILI9341_WHITE);
   delay(200);   //esto es para que no lea la medida anterior.
   readCoordinates();
   //Ahora tendremos las cordenadas 10-10, pero en forma X_Y dada por el touch, el cual es más grande por lo tanto está desplazado.
   //Tambien con esto sabemos el X min, para llamar a la función map. Mas fácil, así como la Y minima.
   delay(200);
   //320 pixeles que tiene de ancho, entre dos para obtener la mitad, más el offset inicial.
   _ILI9341->setTextColor(ILI9341_WHITE, ILI9341_RED);
   _ILI9341->printAligned("RELEASE", gTextAlignMiddleCenter);
   waitForTouch();
   drawCrossHair(10, 10, ILI9341_DARKGRAY);

   //zona dos.
   drawCrossHair((320 / 2), 10, ILI9341_WHITE);

   readCoordinates();
}

void TouchCalibration::waitForTouch()
{
   boolean Presion       = false;
   int     iteracion     = 0;
   int     LastPreassure = 0;

   p = ts.getPoint();

//Como es analógico necesitamos unas 25 iteracciones para decir que esta soltado.

//Lo lógico  sería siempre y cuand oesté pulsado no avanzar, pero resulta que de vez en cuando lee pulsaciones vacias.
//por lo tanto tienen que ser seguidas.

   while(Presion == false){
//para poder hacer esto va a tener que ser mediante estados, cojo 5 estados y voy sumando, cuando cumplan entonces cierro.
//Estado uno coge el primer p.z, estado dos el segundo.... etc, si los 5 son iguales a cero entonces es que solto.
         }
}

void TouchCalibration::drawCrossHair(int x, int y, uint16_t color)
{
   _ILI9341->drawRect(x - 10, y - 10, 20, 20, color);
   _ILI9341->drawLine(x - 5, y, x + 5, y, color);
   _ILI9341->drawLine(x, y - 5, x, y + 5, color);
}

void TouchCalibration::readCoordinates()
{
   boolean OK = false;

   while(OK == false){
         _ILI9341->setTextColor(ILI9341_WHITE, ILI9341_RED);
         _ILI9341->printAligned("PRESS", gTextAlignMiddleCenter, 10, 10);

         //cogemos el punto para ver si hay presion.
         p = ts.getPoint();
         while(p.z < ts.pressureThreshhold){
               //Si no la tenemos entonces lo que hacemos es esperar por ella.
               p = ts.getPoint();
               }
         _ILI9341->printAligned("HOLD!", gTextAlignMiddleCenter);


//volvemos a recoger la precision
//para poder calibrar vamos a hacer la media, pero con un buffer de 100 posiciones.
         // int BuffX[100], BuffY[100];
         int X = 0, Y = 0;

         for(int h = 0; h < 100; h){
             p = ts.getPoint();
             if(p.z > ts.pressureThreshhold){
                //leemos el dato.
                X += p.x;
                Y += p.y;
                Serial.print("X = ");
                Serial.print(p.x);
                Serial.print("\tY = ");
                Serial.print(p.y);
                Serial.print("\tPressure = ");
                Serial.println(p.z);
                h++;
                }
             } //Final bucle for
         OK = true;

         //Ahora debemos coger los valores y dividir entre 100.



         //imprimimos
         int FinalX = X / 100;
         int FinalY = Y / 100;


         Serial.println("Valor final X:");
         Serial.println(FinalX, DEC);
         Serial.println("Valor final Y:");
         Serial.println(FinalY, DEC);
         } //final while OK.
}

void TouchCalibration::startup()
{
   _ILI9341->fillScreen(ILI9341_BLACK);
   _ILI9341->setTextColor(ILI9341_WHITE, ILI9341_RED);
   _ILI9341->fillRect(0, 0, 320, 20, ILI9341_RED);
   _ILI9341->drawLine(0, 20, 320, 20, ILI9341_WHITE);
   _ILI9341->printAlignedOffseted("Touch Calibration", gTextAlignTopCenter, 0, 2);

   _ILI9341->setTextColor(ILI9341_WHITE, ILI9341_BLACK);
   _ILI9341->printAlignedOffseted("INSTRUCTIONS", gTextAlignTopCenter, 0, 30);
   _ILI9341->printAlignedOffseted("Use a stylus or something similar to", gTextAlignTopCenter, 0, 50);
   _ILI9341->printAlignedOffseted("touch as close to the center of the", gTextAlignTopCenter, 0, 62);
   _ILI9341->printAlignedOffseted("highlighted crosshair as possible. Keep", gTextAlignTopCenter, 0, 74);
   _ILI9341->printAlignedOffseted("as still as possible and keep holding", gTextAlignTopCenter, 0, 86);
   _ILI9341->printAlignedOffseted("until the highlight is removed. Repeat", gTextAlignTopCenter, 0, 98);
   _ILI9341->printAlignedOffseted("for all crosshairs in sequence.", gTextAlignTopCenter, 0, 110);

   _ILI9341->printAlignedOffseted("Further instructions will be displayed", gTextAlignTopCenter, 0, 134);
   _ILI9341->printAlignedOffseted("when the calibration is complete.", gTextAlignTopCenter, 0, 146);

   _ILI9341->printAlignedOffseted("Do NOT use your finger as a calibration", gTextAlignTopCenter, 0, 170);
   _ILI9341->printAlignedOffseted("stylus or the result WILL BE imprecise.", gTextAlignTopCenter, 0, 182);

   _ILI9341->printAlignedOffseted("Touch screen to continue", gTextAlignTopCenter, 0, 226);

   p = ts.getPoint();
   while(p.z < ts.pressureThreshhold){
         p = ts.getPoint();
         }
   _ILI9341->fillScreen(ILI9341_BLACK);
}

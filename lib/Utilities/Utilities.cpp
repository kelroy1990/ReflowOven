#include <Arduino.h>
#include <Utilities.h>




Utilities::Utilities()
{
   //Constructor
   //Constructores que tiene la pantalla.

  //  tft= IliObject;



}

void Utilities::SetScreenObject(ILI9341_due *IliObject){
_tft=IliObject;

}

//TODO Corregir el grid pues sale siempre cortado.
void Utilities::PrintGrid(int StartX, int StartY, int FinishX, int FinishY, int Escale){
   //LA PANTALLA ES DE 320x240 px
  _tft->fillRect(StartX, StartY, 320, (FinishY-StartY), ILI9341_BLACK);

  //Ahora necesitamos separar las lineas escala.

  for(int h=StartY;h<=240;h++){
    if((h%Escale)==0)_tft->drawFastHLine(StartX, h, WithScreen, ILI9341_GREEN);
      // Serial.println(h);
  }



  //Lo mismo para vertical

  for(int h=StartX;h<=WithScreen;h++){
    if((h%Escale)==0)_tft->drawFastVLine(h, StartY, (HeighScreen-StartY), ILI9341_GREEN);
      // Serial.println(h);
  }



  // _tft->printAlignedOffseted(("Reflow Oven T-962 -- V " + (String)Version), gTextAlignBottomCenter, 0, -50);
}

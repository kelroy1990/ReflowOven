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
void Utilities::PrintGrid(int StartX, int StartY, int FinishX, int FinishY, int Escale, String Xlabel,String Ylabel){
   //LA PANTALLA ES DE 320x240 px
  _tft->fillRect(StartX, StartY, WithScreen, (FinishY-StartY), ILI9341_BLACK);
  //Variables
    int _YOffset =30;

  //label x and y

  gTextArea _Xlabel{ 0, FinishY-_YOffset, WithScreen, _YOffset }; // define a 300px wide and 170px high description area
  gTextArea _Ylabel{ 10, 60, 300, 170 }; // define a 300px wide and 170px high description area
  //Ahora necesitamos separar las lineas escala.


  //Hace falta de corregir del grid en X y en Y, en el resto está correcto.
  for(int h=StartY;h<=HeigthScreen-_YOffset;h++){
    if((h%Escale)==0)_tft->drawFastHLine(StartX, h, WithScreen, ILI9341_GREEN);
      // Serial.println(h);
  }



  //Lo mismo para vertical


  for(int h=StartX;h<=WithScreen;h++){
    if((h%Escale)==0)_tft->drawFastVLine(h, StartY, (HeigthScreen-StartY), ILI9341_GREEN);
      // Serial.println(h);
  }




_tft->setTextArea(_Xlabel);
_tft->setTextColor(ILI9341_WHITE,ILI9341_BLACK);
_tft->clearTextArea(ILI9341_BLACK);

//Texto mostrado correctamente abajo
_tft->printAlignedOffseted(Xlabel, gTextAlignBottomLeft , 0, 0);
//_tft->print(Xlabel);

  // _tft->printAlignedOffseted(("Reflow Oven T-962 -- V " + (String)Version), gTextAlignBottomCenter, 0, -50);
}

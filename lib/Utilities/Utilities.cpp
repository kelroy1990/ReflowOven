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
void Utilities::PrintGrid(int StartX, int StartY, int FinishX, int FinishY, int Escale, String Xlabel,String Ylabel)
{
   //LA PANTALLA ES DE 320x240 px
  _tft->fillRect(StartX, StartY, WideScreen, (FinishY-StartY), ILI9341_BLACK);
  //Variables


  //voy haacer un grid de 10x10, con un offset inicial de 30 y final de 30.



  _tft->setTextArea(_GridArea);
  _tft->clearTextArea(ILI9341_BLACK);

  _tft->setTextArea(_Xlabel);
  _tft->clearTextArea(ILI9341_BLACK);

  _tft->setTextArea(_Ylabel);
  _tft->clearTextArea(ILI9341_BLACK);

  //Ahora tengo lo siguient
  /*

  Cuadrado desde (30,20)->(320,210), que es el del grid

              En X total de 290 pixeles
              En Y total de 190 pixeles

  Cuadrado desde (0,210)->(320,240), que es el del x label

              En X total de 320 pixeles
              En Y total de 30 pixeles

  Cuadrado desde (0,20)->(30,240), que es el del y label

              En Y total de 30 pixeles
              En X total de 220 pixeles

    *///

  //Como el último pixel no lo dibuja hacemos un grid de 5 de desplazamiento.



  for(int h=35;h<=WideScreen-5;h++){
    if(((h-5)%Escale)==0){
      _tft->drawFastVLine(h, 20, HeigthScreen-30-20-5-5, ILI9341_GREEN); //x,y,h,color
      Serial.print("#");
      Serial.println(h);
  }
  Serial.println(h);

  }


  for(int h=20;h<=HeigthScreen-30;h++){
    if(((h-0)%Escale)==0)_tft->drawFastHLine(40+5, h, WideScreen-40-5-5-5-5, ILI9341_GREEN);
      // Serial.println(h);
  }


  //Ahora los labels y los numeros del grid inferiores.

  _tft->setTextArea(_GridArea);
  _tft->setTextColor(ILI9341_WHITE,ILI9341_BLACK);
  // _tft->clearTextArea(ILI9341_BLACK);

  //Texto mostrado correctamente abajo, parte inferior
  //Ahora imprimo los numeros
  int _auxPos=15;
  for (int h=0;h<=13;h++){
    _tft->printAlignedOffseted((String)h,gTextAlignBottomLeft,_auxPos,5);
    _auxPos=_auxPos+20;

  }

  _tft->printAlignedOffseted("Minutos", gTextAlignBottomLeft , 0, 28);
  // _tft->printAlignedOffseted("Time:",gTextAlignBottomLeft,80,28);
  //Ahora toca imprimir eje Y

  _tft->setTextArea(_Ylabel);
  _auxPos=0;
  int _Celsius=252;
  for (int h=1;h<10;h++){
    _tft->printAt((String)_Celsius,18,_auxPos);
    _auxPos=_auxPos+20;
    _Celsius=_Celsius-30;

  }

  _tft->printAt("C",12,180);

  _tft->drawFastHLine(5,180+20,5,ILI9341_WHITE);
  _tft->drawFastHLine(5,181+20,5,ILI9341_WHITE);
  _tft->drawFastHLine(5,183+20,5,ILI9341_WHITE);




}

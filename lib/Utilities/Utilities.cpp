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
  _tft->fillRect(StartX, StartY, WideScreen, (FinishY-StartY), ILI9341_BLACK);
  //Variables


//voy haacer un grid de 10x10, con un offset inicial de 30 y final de 30.

gTextArea _GridArea {30,20,WideScreen,HeigthScreen-30}; //Area del grid
gTextArea _Xlabel {0,HeigthScreen-30,WideScreen,HeigthScreen};//Area del texto inferior
gTextArea _Ylabel {0,20,30,HeigthScreen};//Area del texto Y

_tft->setTextArea(_GridArea);
_tft->clearTextArea(ILI9341_BLACK);

_tft->setTextArea(_Xlabel);
_tft->clearTextArea(ILI9341_BLACK);

_tft->setTextArea(_Ylabel);
_tft->clearTextArea(ILI9341_BROWN);

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
  if(((h-5)%10)==0){
    _tft->drawFastVLine(h, 20, HeigthScreen-30-20, ILI9341_GREEN); //x,y,h,color
    Serial.print("#");
    Serial.println(h);
}
Serial.println(h);

}


for(int h=20;h<=HeigthScreen-30;h++){
  if(((h-0)%10)==0)_tft->drawFastHLine(35, h, WideScreen-40, ILI9341_GREEN);
    // Serial.println(h);
}


  //   int _YOffset =30;
  //   int _XOffset =30;
  //
  //
  // //label x and y
  //
  // gTextArea _Xlabel{ 0, FinishY-_YOffset, WithScreen, _YOffset }; // define a 300px wide and 170px high description area
  // gTextArea _Ylabel{ 10, 60, 300, 170 }; // define a 300px wide and 170px high description area
  // //Ahora necesitamos separar las lineas escala.
  //
  //
  // //Hace falta de corregir del grid en X y en Y, en el resto está correcto.
  // for(int h=StartY;h<=HeigthScreen-_YOffset;h++){
  //   if((h%Escale)==0)_tft->drawFastHLine(StartX, h, WithScreen, ILI9341_GREEN);
  //     // Serial.println(h);
  // }
  //
  //
  //
  // //Lo mismo para vertical
  //
  //
  // for(int h=StartX;h<=WithScreen;h++){
  //   if((h%Escale)==0)_tft->drawFastVLine(h, StartY, (HeigthScreen-StartY), ILI9341_GREEN);
  //     // Serial.println(h);
  // }




_tft->setTextArea(_GridArea);
_tft->setTextColor(ILI9341_WHITE,ILI9341_BLACK);
// _tft->clearTextArea(ILI9341_BLACK);

//Texto mostrado correctamente abajo
_tft->printAlignedOffseted(Xlabel, gTextAlignBottomLeft , 0, 0);
//_tft->print(Xlabel);

  // _tft->printAlignedOffseted(("Reflow Oven T-962 -- V " + (String)Version), gTextAlignBottomCenter, 0, -50);
}

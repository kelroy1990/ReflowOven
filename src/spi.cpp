/*
 * This sketch is demonstrating loading monochome images from a byte array.
 * The advantage of using monochrome images is its size. You could fit a fullscreen
 * monochrome image in Uno's program memory. You could not do that with
 * a full color image.
 */
#include <Arduino.h>

//Librerias externas
#include <TouchScreen.h>
#include <touchcalibration.h>
#include <stdint.h>
#include <SdFat.h>
#include "SPI.h"
#include "ILI9341_due_config.h"
#include "ILI9341_due.h"
#include <SystemFont5x7.h>
#include <Arial_bold_14.h>
#include <Alert.h>

//librerias propias
#include <Pantalla.h>
#include <Settings.h>
//#include <menu.h>
#include <KY-040.h>

Pantalla* Screen;

int _State=0;


void _SwitchPressed(){
  Screen->InterrupcionBoton();
}




void setup()
{
  pinMode(EncoderSwPin, INPUT);
  attachInterrupt(EncoderSwPin,_SwitchPressed,FALLING);
  Screen= new Pantalla();//Instancio el objeto
   // #ifdef _Serial
   Serial.begin(115200);
   Serial.println("Iniciando programa Reflow Oven...");
   //#endif
   //Screen.StartSD();    //carga la SD.
   Screen->StartScreen();
   Screen->InitialMenu();

   delay(1000);
  //  Screen->Menu();

      // Screen->EncoderRead();
}

void loop()
{
   /* add main program code here */

   if(_State==0){
     Screen->UpdateState(1);


   }

}

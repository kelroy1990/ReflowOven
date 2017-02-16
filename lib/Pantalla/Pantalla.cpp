#include <Pantalla.h>
#include <Alert.h>
#include <SystemFont5x7.h>
#include <Arial_bold_14.h>
#include <roboto16.h>
#include <roboto32.h>



Pantalla::Pantalla()
{
   //Constructor
}

void Pantalla::InitialMenu()
{
   //   const uint16_t x = 159;
   //   const uint16_t y = 149;

   tft.fillScreen(ILI9341_BLACK);
   tft.drawImage(alert, 40, 10, alertWidth, alertHeight);
   tft.setFont(roboto16);
   tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
   tft.printAlignedOffseted("-Hot instrument surface.", gTextAlignTopLeft, 80, 10);
   tft.printAlignedOffseted("-High voltage instrument.", gTextAlignTopLeft, 80, 30);

   tft.setFont(SystemFont5x7);
   tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
   tft.setTextScale(1);
   tft.printAlignedOffseted(("Reflow Oven T-962 -- V " + (String)Version), gTextAlignBottomCenter, 0, -50);
   tft.printAlignedOffseted("Autor: " + Autor + " Email: " + Email, gTextAlignBottomCenter, 0, -20);



   tft.setFont(Arial_bold_14);
   tft.setTextColor(ILI9341_WHITE, ILI9341_BLUE);
   // Draw the upper row of buttons

   /*
    * for(x = 0; x < 5; x++){
    *  tft.fillRoundRect(10 + (x * 60), 10, 50, 50, 5, ILI9341_BLUE);
    *  tft.drawRoundRect(10 + (x * 60), 10, 50, 50, 5, ILI9341_WHITE);
    *  itoa(x + 1, strBuff, 10);
    *  Serial.println(strBuff);
    *  tft.printAt(strBuff, 32 + (x * 60), 30);
    *  }
    * // Draw the center row of buttons
    * for(x = 0; x < 5; x++){
    *  tft.fillRoundRect(10 + (x * 60), 70, 50, 50, 5, ILI9341_BLUE);
    *  tft.drawRoundRect(10 + (x * 60), 70, 50, 50, 5, ILI9341_WHITE);
    *  if(x < 4){
    *     itoa(x + 6, strBuff, 10);
    *     tft.printAt(strBuff, 32 + (x * 60), 90);
    *     }
    *  }
    */
   //tft.printAt("0", 270, 90);
   // Draw the lower row of buttons


   tft.fillRoundRect(10, 100, 140, 50, 5, ILI9341_BLUE);
   tft.drawRoundRect(10, 100, 140, 50, 5, ILI9341_WHITE);
   tft.printAt("Touch Calibrate", 20, 120);
   tft.fillRoundRect(160, 100, 140, 50, 5, ILI9341_BLUE);
   tft.drawRoundRect(160, 100, 140, 50, 5, ILI9341_WHITE);
   tft.printAt("Start", 208, 120);
}

void Pantalla::StartScreen()
{
   tft.begin();
   //_CalTouch.SetUpScreenObject(&tft);
   tft.setRotation(iliRotation270);            // landscape

   tft.fillScreen(ILI9341_BLACK);

   // tft.drawBitmap(arduLogo, 160, 100, 40, 32, ILI9341_DARKCYAN);       // "transparent" background
   //tft.drawBitmap(arduLogo, 110, 100, 40, 32, ILI9341_WHITE, ILI9341_DARKCYAN);
   //delay(500);
}

void Pantalla::StartSD()
{
   pinMode(SD_Detect, INPUT_PULLUP); //Ponemos el pin como INPUT_PULLUP para saber si tenemos una tarjeta, pues cuando no tiene está en modo flotante.
   //Un 1(true) significa que tenemos tarjeta sd- un 0(false) significa que no tenemos tarjeta.
   if(!digitalRead(SD_Detect)){      //si no hay tarjeta salimos.
      SD_state = false;
      return;
      }
   SD_state = true;
   //iniciamos la tarjeta con el pin CS.
}

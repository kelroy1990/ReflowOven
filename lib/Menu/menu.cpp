#include <menu.h>
#include <Settings.h>
#include <ILI9341_due_config.h>
#include <ILI9341_due.h>
#include <SystemFont5x7.h>
#include <Arial_bold_14.h>
#include "roboto16.h"
#include "roboto32.h"
#include "Alert.h"
#include <touchcalibration.h>
//#include "roboto70.h"



ILI9341_due      tft(LCD_CS, LCD_DC, LCD_RST);
TouchCalibration _CalTouch(&tft); //le mandamos la dirección del objeto tft para que pueda indexarlo.


#if defined(ARDUINO_ARCH_AVR)
#include <avr/pgmspace.h>
#elif defined(ARDUINO_SAM_DUE)
#define PROGMEM
#endif


uint16_t colorLightGray = tft.color565(192, 192, 192);
uint16_t colorGray      = tft.color565(127, 127, 127);
uint16_t colorDarkGray  = tft.color565(64, 64, 64);



Menu::Menu()
{
   //En el contrusctor no se puede poner texto, pues el due lo carga antes que al resto. No permitidos println
}

void Menu::PrintStartMenu()
{
   //LA PANTALLA ES DE 320x240 px
   //Aquí vamos a hacer el menu que sería como sigue
   //Setup-Test-Perfiles-Punto Manual-Reflow-Info
   //-------------------------------------------
   //->Variables Hay sD?, Hay sensores?, cuantos, TIpo sensor..
   //Perfil en uso
   //Hora Fecha----------------------------------- Consumo actual
   //--------------------------------------------- Version

   Serial.println("Print start menu");
   //gtextArea x,y, W,H---> Cordenadas x y donde empieza, W ancho H alto de la pantalla.
   gTextArea titleArea {
      0, 0, 320, 30
   };                                      // define a 300px wide and 40px high title area
   gTextArea descriptionArea {
      0, 40, 320, 210
   };                                          // define a 300px wide and 170px high description area


   tft.setFont(Arial_bold_14);
   tft.setTextColor(ILI9341_WHITE, ILI9341_DARKBLUE);

   tft.setTextArea(titleArea);
   tft.clearTextArea(ILI9341_LIGHTBLUE); // just to see where the area is
   tft.println("Setup | Test | Profiles | Manual Set ");
   tft.print("Reflow | Info");
   tft.setTextArea(descriptionArea);
   tft.clearTextArea(ILI9341_LIGHTBLUE);
   tft.print("Pantalla donde mostramos.");
}

void Menu::StartScreen()
{
   tft.begin();
   //_CalTouch.SetUpScreenObject(&tft);
   tft.setRotation(iliRotation270);            // landscape

   tft.fillScreen(ILI9341_BLACK);

   // tft.drawBitmap(arduLogo, 160, 100, 40, 32, ILI9341_DARKCYAN);       // "transparent" background
   //tft.drawBitmap(arduLogo, 110, 100, 40, 32, ILI9341_WHITE, ILI9341_DARKCYAN);
   //delay(500);
   screenLoading();
}

void Menu::screenLoading()
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

   drawButtons();



/*
 * for(int i = 0; i < 2880; i += 4){
 *     tft.fillArc(x, y, 10, 3, (i >> 1) - 45, (i >> 1) + 45, colorDarkGray);
 *     tft.fillArc(x, y, 10, 3, (i >> 1) - 45 - 4, (i >> 1) - 45, colorLightGray);
 *
 *     tft.fillArc(x, y, 20, 3, 1440 - i - 45, 1440 - i + 45, colorDarkGray);
 *     tft.fillArc(x, y, 20, 3, 1440 - i + 45, 1440 - i + 45 + 4, colorLightGray);
 *     }
 */

   delay(1000);
   //vamos testear el touch.
}

void Menu::drawButtons()
{
   // int  x, y;
   //char strBuff[10];
   //char stCurrent[20] = "";
   //int  stCurrentLen  = 0;
   //char stLast[20]    = "";


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

// URTouch_ButtonTest
// Copyright (C)2015 Rinky-Dink Electronics, Henning Karlsen. All right reserved
// web: http://www.RinkyDinkElectronics.com/
//
// This program is a quick demo of how create and use buttons.
//
// This program requires the UTFT library.
//
// It is assumed that the display module is connected to an
// appropriate shield or that you know how to change the pin
// numbers in the setup.
//

#include <Arduino.h>
#include <URTouch.h>
#include <Adafruit_GFX.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_ILI9341.h>


// Initialize display
// ------------------
// Set the pins to the correct ones for your development board
// -----------------------------------------------------------
// Standard Arduino Uno/2009 Shield            : <display model>,19,18,17,16
// Standard Arduino Mega/Due shield            : <display model>,38,39,40,41
// CTE TFT LCD/SD Shield for Arduino Due       : <display model>,25,26,27,28
// Teensy 3.x TFT Test Board                   : <display model>,23,22, 3, 4
// ElecHouse TFT LCD/SD Shield for Arduino Due : <display model>,22,23,31,33
//
// Remember to change the model parameter to suit your display module!


// Initialize touchscreen
// ----------------------
// Set the pins to the correct ones for your development board
// -----------------------------------------------------------
// Standard Arduino Uno/2009 Shield            : 15,10,14, 9, 8
// Standard Arduino Mega/Due shield            :  6, 5, 4, 3, 2
// CTE TFT LCD/SD Shield for Arduino Due       :  6, 5, 4, 3, 2
// Teensy 3.x TFT Test Board                   : 26,31,27,28,29
// ElecHouse TFT LCD/SD Shield for Arduino Due : 25,26,27,29,30
//URTouch::URTouch(byte tclk, byte tcs, byte din, byte dout, byte irq)
URTouch myTouch(6, 5, 4, 3, 2);

// Declare which fonts we will be using
extern uint8_t BigFont[];

int  x, y;
char stCurrent[20] = "";
int  stCurrentLen  = 0;
char stLast[20]    = "";



#define TS_MINX     150
#define TS_MINY     130
#define TS_MAXX     3800
#define TS_MAXY     4000

#define STMPE_CS    8

#define TFT_CS      10
#define TFT_DC      9
//Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST, TFT_MISO);, 51, 52, 8, 50
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC);

boolean RecordOn = false;

#define FRAME_X          210
#define FRAME_Y          180
#define FRAME_W          100
#define FRAME_H          50

#define REDBUTTON_X      FRAME_X
#define REDBUTTON_Y      FRAME_Y
#define REDBUTTON_W      (FRAME_W / 2)
#define REDBUTTON_H      FRAME_H

#define GREENBUTTON_X    (REDBUTTON_X + REDBUTTON_W)
#define GREENBUTTON_Y    FRAME_Y
#define GREENBUTTON_W    (FRAME_W / 2)
#define GREENBUTTON_H    FRAME_H

void drawFrame()
{
   tft.drawRect(FRAME_X, FRAME_Y, FRAME_W, FRAME_H, ILI9341_BLACK);
}

void redBtn()
{
   tft.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, ILI9341_RED);
   tft.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, ILI9341_BLUE);
   drawFrame();
   tft.setCursor(GREENBUTTON_X + 6, GREENBUTTON_Y + (GREENBUTTON_H / 2));
   tft.setTextColor(ILI9341_WHITE);
   tft.setTextSize(2);
   tft.println("ON");
   RecordOn = false;
}

void greenBtn()
{
   tft.fillRect(GREENBUTTON_X, GREENBUTTON_Y, GREENBUTTON_W, GREENBUTTON_H, ILI9341_GREEN);
   tft.fillRect(REDBUTTON_X, REDBUTTON_Y, REDBUTTON_W, REDBUTTON_H, ILI9341_BLUE);
   drawFrame();
   tft.setCursor(REDBUTTON_X + 6, REDBUTTON_Y + (REDBUTTON_H / 2));
   tft.setTextColor(ILI9341_WHITE);
   tft.setTextSize(2);
   tft.println("OFF");
   RecordOn = true;
}

void setup()
{
// Initial setup

   Serial.begin(9600);
   tft.begin();


   tft.fillScreen(ILI9341_BLUE);
// origin = left,top landscape (USB left upper)
   tft.setRotation(1);
   redBtn();

   delay(100);
   myTouch.InitTouch();
   myTouch.setPrecision(PREC_MEDIUM);



   Serial.println("Start--");
}

void loop()
{
   //Serial.print("#!");
   if(myTouch.dataAvailable()){
      Serial.println("avaliable");
      myTouch.read();
      x = myTouch.getX();
      y = myTouch.getY();
      Serial.print("Valor x ");
      Serial.println(x);
      Serial.print("Valor y ");
      Serial.println(y);
      }
}

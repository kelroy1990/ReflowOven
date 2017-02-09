/*
 * This sketch is demonstrating loading monochome images from a byte array.
 * The advantage of using monochrome images is its size. You could fit a fullscreen
 * monochrome image in Uno's program memory. You could not do that with
 * a full color image.
 */
#include <Arduino.h>
#include "SPI.h"
#include "ILI9341_due_config.h"
#include "ILI9341_due.h"
#include <SystemFont5x7.h>
#include "menu.h"
#include <Arial_bold_14.h>
#include <Settings.h>
#include <Alert.h>

Menu _menu;

void setup()
{
   // #ifdef _Serial
   Serial.begin(9600);
   Serial.println("Iniciando programa Reflow Oven...");
   //#endif
   _menu.StartScreen();
   // _menu.PrintStartMenu();
}

void loop()
{
   /* add main program code here */
}

#include <Pantalla.h>
#include <Alert.h>
#include <SystemFont5x7.h>
#include <Arial_bold_14.h>
#include <roboto16.h>
#include <roboto32.h>
#include <Utilities.h>


Pantalla::Pantalla()
{
   //Constructor, paso objetos de construccion a Utilities


}

///////////////////////////////////Grupo interrupcion////////////////////

void Pantalla::InterrupcionBoton()
{
  _Encoder.SetSwitchStop();
}


/////////////////////////////////////////////////////////////////////////


void Pantalla::ClearScreen(uint16_t Color){
  //limpieza de pantalla para salto al siguiente menu.
  tft.fillScreen(Color);
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

void Pantalla::Menu()
{
  ClearScreen(ILI9341_WHITE);
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
      0, 0, 320, 20
   };                                     // define a 300px wide and 40px high title area
   gTextArea descriptionArea {
      0, 20, 320, 220
   };                                         // define a 300px wide and 170px high description area


   tft.setFont(Arial_bold_14);
   tft.setTextColor(ILI9341_WHITE, ILI9341_DARKBLUE);

   tft.setTextArea(titleArea);
   tft.clearTextArea(ILI9341_BLACK); // just to see where the area is

    //  void printAlignedOffseted(const char *str, gTextAlign align, uint16_t offsetX, uint16_t offsetY, gTextEraseLine eraseLine);
    //  tft.printAlignedOffseted("HOME | PROFILES | REFLOW | MANUAL ", gTextAlignTopCenter,0,5,gTextEraseFullLine);
   tft.printAligned("HOME | PROFILES | REFLOW | MANUAL ", gTextAlignTopCenter,gTextEraseFullLine);
    //  tft.println("HOME | PROFILES | REFLOW | MANUAL ");
    //  tft.print("Reflow | Info");


    //Parte inferior
   tft.setTextArea(descriptionArea);
   tft.clearTextArea(ILI9341_LIGHTBLUE);
    tft.printAlignedOffseted(("V" + (String)Version), gTextAlignBottomLeft, 0, 0);


    _Utilities.PrintGrid(0, 20, 320, 240, 20,"Segundos","Grados");
  _Encoder.SetZero();

}

void Pantalla::EncoderRead(){

  _Encoder.GetPosition();
  // _Encoder.GetSwPosition();

}

void Pantalla::StartScreen()
{

   tft.begin();
   //_CalTouch.SetUpScreenObject(&tft);
   tft.setRotation(iliRotation270);            // landscape

   tft.fillScreen(ILI9341_BLACK);

   //Inicio la librería de utilidades y funciones pasandole el objeto pantalla

   _Utilities.SetScreenObject(&tft);
}

void Pantalla::StartSD()
{
   //En esta parte vamos a cargar la sd y a la vez cuentear el número de encendidos, así como controlar la versión del firmware y variables de inicio....

   /*
    * Estructura del archivo Version
    * KP
    * KI
    * KD
    */

   pinMode(SD_Detect, INPUT_PULLUP); //Ponemos el pin como INPUT_PULLUP para saber si tenemos una tarjeta, pues cuando no tiene está en modo flotante.
   //Un 1(true) significa que tenemos tarjeta sd- un 0(false) significa que no tenemos tarjeta.
   if(!digitalRead(SD_Detect)){      //si no hay tarjeta salimos.
      SD_state = false;
      return;
      }
   SD_state = true;
   //iniciamos la tarjeta con el pin CS.
   if(!sd.begin(SD_CS)){
      //Documento esto pues da muchos errores el initErrorHalt mejor poner un return,
      return;
      //  sd.initErrorHalt();
      }



  // open the file for write at end like the Native SD library
   if(!myFile.open("test.txt", O_RDWR | O_CREAT | O_AT_END)){
      sd.errorHalt("opening test.txt for write failed");
      }
  // if the file opened okay, write to it:
   Serial.print("Writing to test.txt...");
   //forma de imprimir con myFile.
   myFile.println("testing 1, 2, 3.");

  // close the file:
   myFile.close();
   Serial.println("done.");

  // re-open the file for reading:
   if(!myFile.open("test.txt", O_READ)){
      sd.errorHalt("opening test.txt for read failed");
      }
   Serial.println("test.txt:");

  // read from the file until there's nothing else in it:
   int data;
   while((data = myFile.read()) >= 0){
         Serial.write(data);
         }
  // close the file:
   myFile.close();

   // Initialize SdFat or print a detailed error message and halt
  // Use half speed like the native library.
  // change to SPI_FULL_SPEED for more performance.
}

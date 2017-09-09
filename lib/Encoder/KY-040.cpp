#include <Arduino.h>
#include <KY-040.h>
#include <Settings.h>





Encoder::Encoder(){
  //Consturctor vacio de clase

  pinMode (EncoderPinA,INPUT);
  pinMode (EncoderPinB,INPUT);

}





void Encoder::SetZero(){

  encoderPosCount=1;
}

// bool Encoder::GetSwPosition(){


  // Serial.println(digitalRead(EncoderSwPin));

// }
int Encoder::GetPosition(){
  while (_Switchstop==false){

    aVal = digitalRead(EncoderPinA);
       if (aVal != pinALast){ // Means the knob is rotating
         // if the knob is rotating, we need to determine direction
         // We do that by reading pin B.
         if (digitalRead(EncoderPinB) != aVal) {  // Means pin A Changed first - We're Rotating Clockwise
           encoderPosCount ++;
           bCW = true;
         } else {// Otherwise B changed first and we're moving CCW
           bCW = false;
           encoderPosCount--;
         }
        //  Serial.print ("Rotated: ");
        //  if (bCW){
          //  Serial.println ("clockwise");
        //  }else{
          //  Serial.println("counterclockwise");
        //  }
         Serial.print("Encoder Position: ");
         Serial.println(encoderPosCount);

       }
       pinALast = aVal;

  }
  _Switchstop=true;
  Serial.println("############Posicion final##########");
           Serial.println(encoderPosCount);




}

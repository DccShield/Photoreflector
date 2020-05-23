//--------------------------------------------------------------------------------
// フォトリフレクタセンサテストスケッチ
// [Photoreflector.cpp]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
// https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include "Photoreflector.h"
#include  <arduino.h>

Photoreflector::Photoreflector(char ch , char chIR , char chAI, int LTh, int HTh){
  AIport = chAI;
  IRport = chIR;
//  cntup = ct;
  LThreshold = LTh;
  HThreshold = HTh;
  
  pinMode(chIR,OUTPUT);
  digitalWrite(chIR,LOW);

}

void Photoreflector::Reset( void ){
  state = ST_INIT;
}

char Photoreflector::statechk( char range ){
  static char nextTimer = 0;
  char temp[30];
//  sprintf(temp,"state:%d:",state);
//  Serial.println(temp);
    
  switch(state){
    case ST_INIT:
              state = ST_IRON;
              break;
    case ST_IRON:
              digitalWrite(IRport, HIGH);   // 赤外LEDをon
              nextTimer = 1;
              state = ST_WAIT;
              break;
    case ST_WAIT:
              nextTimer --;
              if(nextTimer <=0 ){
                state = ST_MEAS1;
              }
              break;          
    case ST_MEAS1:
              adf = analogRead( AIport );              
              digitalWrite(IRport, LOW);   // 赤外LEDをoff
              state = ST_MEAS2;
              break;
    case ST_MEAS2:
              ads = analogRead( AIport );       
  sprintf(temp,"adf:%d , ads:%d , dif:%d",adf,ads,adf-ads);
  Serial.println(temp);
              if( adf - ads >= 200 ) {
                state = ST_DETECTION;            //車両検知
              } else {
                state = ST_IRON;            //ノイズかな
              }
            break;
    case ST_DETECTION:
Serial.println("DETECTION");
              return HIGH;
              break;

    default:
              break;
  }
  return LOW;
}

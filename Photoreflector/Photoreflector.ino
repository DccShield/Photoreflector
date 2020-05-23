//--------------------------------------------------------------------------------
// フォトリフレクタテストスケッチ
// [CdsTest.ino]
// Copyright (c) 2020 Ayanosuke(Maison de DCC)
//
// http://maison-dcc.sblo.jp/ http://dcc.client.jp/ http://ayabu.blog.shinobi.jp/
// https://twitter.com/masashi_214
//
// DCC電子工作連合のメンバーです
// https://desktopstation.net/tmi/ https://desktopstation.net/bb/index.php
//
// This software is released under the MIT License.
// http://opensource.org/licenses/mit-license.php
//--------------------------------------------------------------------------------

#include "Photoreflector.h"
unsigned long PreviosTime = 0;
unsigned char a,b;

Photoreflector PhotoInt(0,13,A0,200,200);

void setup()
{
  Serial.begin(115200);
  PreviosTime = millis();
  Serial.println("Photoreflector test program");
//  pinMode(8,OUTPUT);
//  digitalWrite(8,LOW);
//  pinMode(5,OUTPUT);
//  digitalWrite(5,HIGH);
//  pinMode(11,OUTPUT);
//  digitalWrite(11,HIGH);
}

void loop()
{
  static int ret;
//  static Cds CdsA0(0,2,200,200);
//  static Cds CdsA1(1,2,200,200);
  
  if( (millis() - PreviosTime ) >= 10 ){  // 1000:1000msec 前回から1000ms経過したかチェック
    PreviosTime = millis();
    ret = PhotoInt.statechk(LOW);
    if(ret == HIGH )
      PhotoInt.Reset();
      
//    b = CdsA1.statechk(LOW);

//a = analogRead( 7 );

//char temp[20];
//sprintf(temp,"A0:%d , A1:%d",a,b);
//Serial.println(temp);
 
//    if(a==HIGH)
//      CdsA0.Reset();

//      if(b==HIGH)
//      CdsA1.Reset();

  
  }
}

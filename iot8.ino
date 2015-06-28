#include <LBT.h>
#include <LBTServer.h>
#define serverName "iot8_demo"
#define serverWaitTime 5
String BTread;


#include <LiquidCrystal.h>
const int RS = 8;
const int EN = 9;
const int D4 = 4;
const int D5 = 5;
const int D6 = 6;
const int D7 = 7;
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


void setup() {
  Serial.begin(115200);
  setupLCD();
  setupBT();
}

void loop() {
  if (LBTServer.available()){
    // wait a bit for the entire message to arrive
    delay(100);
    BTread = LBTServer.readString();
    setDisplay(BTread);
  }
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // read all the available characters
    String str = Serial.readString();
    setDisplay(str);
  }
}

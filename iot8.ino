#include <LBT.h>
#include <LBTServer.h>
#define serverName "BTserverTest"
#define serverWaitTime 5

char BTread;


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
  if(LBTServer.available()){
    BTread = LBTServer.read();
    if(BTread == 'T')
    {
      digitalWrite(13,HIGH);
    }
    else if(BTread == 'F')
    {
      digitalWrite(13,LOW);
    }
    Serial.println(BTread);
    delay(10);
  }
  if (Serial.available()) {
    // wait a bit for the entire message to arrive
    delay(100);
    // clear the screen
    lcd.clear();
    // read all the available characters
    while (Serial.available() > 0) {
      // display each character to the LCD
      //lcd.write(Serial.read());
      String str = Serial.readString();
      setDisplay(str);
    }
  }
}

#include <LBT.h>
#include <LBTServer.h>
#define serverName "BTserverTest"
#define serverWaitTime 5

char BTread;
void setup() {
  Serial.begin(115200);
  while (!Serial);
  pinMode(13,OUTPUT);
  LBTServer.begin((uint8_t*)serverName);
  Serial.printf("[%s] is waiting for any client...",serverName);
  
  /*while(!LBTServer.accept(serverWaitTime)){
    Serial.print(" ... ");
  }*/
  while(true){
    if(LBTServer.connected()){
      Serial.printf("lol");
      break;
    }else{
      LBTServer.accept(5);
      Serial.println("Waiting for connection");
    }
  }
  Serial.println("\n===Connected!===");
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
}

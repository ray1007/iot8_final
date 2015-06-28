static void setupBT(){
  while (!Serial);
  //pinMode(13,OUTPUT);
  LBTServer.begin((uint8_t*)serverName);
  Serial.printf("[%s] is waiting for any client...",serverName);
  
  while(true){
    if(LBTServer.connected()){
      Serial.printf("lol");
      break;
    }else{
      LBTServer.accept(serverWaitTime);
      Serial.println("Waiting for connection");
    }
  }
  Serial.println("\n===Connected!===");
}

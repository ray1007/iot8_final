static void setupLCD(){
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(RS, OUTPUT);
  pinMode(EN, OUTPUT);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  
  // Print init message to the LCD.
  setDisplay("Waiting for     connection.");
}

static void setDisplay(String msg){
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.clear();
  lcd.setCursor(0, 0);
  // print the number of seconds since reset:
  lcd.print(msg.substring(0,16));
  if(msg.length() > 16){
    lcd.setCursor(0, 1);
    lcd.print(msg.substring(16));
  }
}


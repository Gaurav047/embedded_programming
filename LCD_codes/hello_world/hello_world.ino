//Using LiquidCrystal library for the LCD 16X2 Display
#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup(){
  lcd.begin(16, 2);
  attachInterrupt(digitalPinToInterrupt(interruptPin), func, RISING);
}

void loop(){

  
  
  //lcd.setCursor(0,0);
  //lcd.print("HAHAHAHA");  
}

void func(){
    
}

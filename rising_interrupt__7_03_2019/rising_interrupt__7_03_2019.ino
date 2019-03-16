#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

volatile boolean flag;
void isr(){
  flag = true;
}

void setup(){
  attachInterrupt(digitalPinToInterrupt(2), isr, CHANGE);  
}

void loop(){
  if(flag){
    lcd.setCursor(0, 0);
    lcd.print("Interrupt_true");
  }  
}

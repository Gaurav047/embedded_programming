#include <avr/wdt.h>

#define led 13 // pin 13 is connected to a led on Arduino Uno

void setup()
{
  pinMode(led, OUTPUT);      // set pin mode
  
}

void loop(){
  if (millis() >= 17000 ){
  wdt_enable(WDTO_8S);     // enable the watchdog
                            // will fire after 25 S without reset                      
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level) for 10 Seconds
  delay(10000);
  while(1)
  {
     wdt_reset();          //RESET the microcontroller
  }
  }
}
 

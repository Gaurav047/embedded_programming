//Sample using LiquidCrystal library
#include <LiquidCrystal.h>
//EEPROM.h for writing into eeprom
#include <EEPROM.h>

// select the pins used on the LCD panel
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);


String line;
long eepvar;
long value;


void setup()
{
 lcd.begin(16, 2);              // start the library
 lcd.setCursor(0,0);
 Serial.begin(115200);
}
  
void loop()
{
    
  if (Serial.available() > 0){
    line = Serial.readString(); //reading the serial monitor input in line
    
    eepvar = line.toInt();     //converting line to long
    
    Serial.print("I received: ");   //printing line in serial monitor
    Serial.println(line);
    Serial.println(); 

     
    lcd.setCursor(0,0); //printing line to LCD
    lcd.print(line);

    EEPROM.write(85, eepvar);   //Write the line value in long format to EEPROM at location 85
    value = EEPROM.read(85);    // check the received value
    Serial.println("EEPROM stored:");
    Serial.println(value);
    
    delay(5000);        //clear the lcd screen after 5 seconds
    lcd.clear();
  }
  //delay(10000);
 
  
}

// Camera shutter speed timer
// Author: Nick Gammon
// Date: 15th January 2012

volatile boolean started;
volatile unsigned long startTime;
volatile unsigned long endTime;

// interrupt service routine
void shutter ()
{
  if (started)  
    endTime = micros ();
  else 
    startTime = micros ();

  started = !started;

} // end of shutter

void setup ()
{
  Serial.begin (115200);
  Serial.println ("Shutter test ...");
  attachInterrupt (digitalPinToInterrupt (2), shutter, RISING);
}  // end of setup


void loop ()
{

  if (endTime)
  {
    Serial.print ("Shutter open for ");
    Serial.print (endTime - startTime);
    Serial.println (" microseconds.");
    endTime = 0; 
  }  

} // end of loop

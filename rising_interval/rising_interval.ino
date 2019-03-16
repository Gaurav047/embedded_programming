unsigned long placeholder2;
volatile unsigned long placeholder1;
volatile boolean pressed;

void isPressed () 
{
  // wait until we noticed last one
  if (pressed)
    return;

  placeholder1 = micros ();
  pressed = true;
}  // end of isPressed

void setup() 
{
  digitalWrite (2, HIGH);  // pull-up
  attachInterrupt(digitalPinToInterrupt (2), isPressed, RISING);   
  Serial.begin (115200);
  Serial.println ("Started timing ...");  
}  // end of setup

void loop() 
{
  if (!pressed)
    return;
  
  unsigned long elapsed = placeholder1 - placeholder2;
  
  if (elapsed < 1000000L)
    {
    pressed = false;
    return;  // ignore if less than a second
    }
    
  placeholder2 = placeholder1;
  pressed = false;  // re-arm for next time
  
  Serial.print ("Took: ");
  Serial.print (elapsed);
  Serial.print (" microseconds. ");
  
  unsigned long ms;
  
  ms = elapsed / 1000;
 
  Serial.print (ms);
  Serial.println ("milliseconds.");
}  // end of loop

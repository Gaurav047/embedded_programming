/* This program calculates the time lag between two consequent interrupts RISINGS 
 * timer1 and timer2 are the checkpoints and the difference between them will give the lag
 * The ISR (switchPressed) would turn the flag value 'true' and reinitialise it to false in the loop
 * Turn on serial monitor at baud rate 115200 to see the printed value of lag.
 * To Calculate the timer1 and timer2, I have used micros() as it does not use any interrupt service to calculate the time.
 */



const byte LED = 13;
const byte BUTTON = 2;
volatile double timer1 = 0;
volatile double timer2 = 0;
volatile double lag = 0;
volatile boolean flag = false;

// Interrupt Service Routine (ISR)
void switchPressed ()
{
  if (digitalRead (BUTTON) == HIGH){
    digitalWrite (LED, HIGH);
    timer1 = micros();
  }
  else {
    digitalWrite (LED, LOW);
    timer2 = micros();
  }  // end of switchPressed
  lag = timer1 - timer2;
  flag = true;
}

void setup ()
{
  Serial.begin(115200);
  pinMode (LED, OUTPUT);  // so we can update the LED
  digitalWrite (BUTTON, HIGH);  // internal pull-up resistor
  attachInterrupt (digitalPinToInterrupt (BUTTON), switchPressed, RISING);  // attach interrupt handler
}  // end of setup

void loop ()
{
  if (flag){
        Serial.println(lag/1000);
        flag = false;
  }
} 

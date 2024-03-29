void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  pinMode(8, OUTPUT);  //DE/RE Controlling pin of RS485
}

void loop() {
  char getdata='m';
  
  digitalWrite(8, HIGH); //DE/RE-HIGH Transmit Enabled M1
  Serial1.print('9'); //Write '9' and Fetch Data from slave

  digitalWrite(8, LOW); //DE/RE-LOW Receive Enabled M1
  delay(1000);

  if(Serial1.available()){  //If serial Data is available

      while(Serial1.available() && getdata != 'd'){
        getdata = Serial1.read();
        Serial.print(getdata);
        }
      Serial.println("");
  }
}

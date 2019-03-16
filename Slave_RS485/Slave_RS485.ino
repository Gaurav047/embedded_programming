void setup() {
  Serial.begin(9600);

  pinMode(13, OUTPUT); //LED connected
  pinMode(8, OUTPUT);//DE/RE Controlling pin of RS-485

}

void loop() {
  char getdata = 'c';

  digitalWrite(13, LOW); //LED off
  digitalWrite(8, LOW); //DE/RE=LOW Receive Enabled

  if(Serial.available()){
      getdata=Serial.read();
    }
  if(getdata=='9'){
      digitalWrite(8, HIGH); //DE/RE=HIGH Transmit Enabled
      Serial.print("dhhdhdhd");
    }
    
  delay(2000);
  digitalWrite(13, HIGH);
  delay(2000);
}

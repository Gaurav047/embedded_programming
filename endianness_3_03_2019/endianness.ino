void setup() {
 Serial.begin(9600);
}

void loop() {
  unsigned int num = 1; // int num is declared 
 char *c = (char*)&num; // char pointer c points to integer num 
 
 /*After dereferencing c, it will only contain first byte of the integer
  If it Machine is little endian then *c == 1, because last byte will be stored first
  else it is big endian and *c == 0
 */
 
 if (*c){ 
      Serial.println("Little endian");
      delay(1000);
 }
 else{
      Serial.println("Big Endian");
      delay(1000);
 }
 getchar();
}

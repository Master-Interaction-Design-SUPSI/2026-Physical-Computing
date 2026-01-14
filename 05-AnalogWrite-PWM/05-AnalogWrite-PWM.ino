int potVal = 0;   // 12bit, 0 ... 4095  (2^12)
int ledVal = 0;   // 8bit, 0 .. 255 (2^8)

void setup() {
  Serial.println(9600);
  pinMode(D9, OUTPUT);  
}

void loop() {
  potVal = analogRead(A0);  // read pot
  Serial.println("potVal: " + String(potVal));

  ledVal = map(potVal, 0, 4095, 0, 255);  // scale values
  Serial.println("ledVal: " + String(ledVal));

  analogWrite(D9, ledVal);  // set LED value
  
  delay(1);
}

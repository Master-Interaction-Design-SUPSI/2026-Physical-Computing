int potVal = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  potVal = analogRead(A0);
  Serial.println(potVal);
  delay(10);
}

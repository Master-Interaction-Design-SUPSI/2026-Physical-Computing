int valPot = 0;
int blinkDelay = 0;

void setup() {
  pinMode(D2, OUTPUT);
}

void loop() {
  valPot = analogRead(A0);
  blinkDelay = map(valPot, 0, 4095, 5, 200);

  digitalWrite(D2, HIGH); // ON
  delay(blinkDelay);
  digitalWrite(D2, LOW);  // OFF
  delay(blinkDelay);
}

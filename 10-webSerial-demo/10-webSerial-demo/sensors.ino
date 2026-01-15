void readSensors() {
  x = analogRead(A0);
  y = analogRead(A1);

  x = map(x, 890, 2910, 0, 101);
  y = map(y, 920, 2860, 0, 101);
  
  Serial.println(String(x) + "," + String(y));
  delay(100);
}
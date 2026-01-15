void readSensors() {
  x = analogRead(A0);
  y = analogRead(A1);

  Serial.println(x);
  
  //Serial.println(String(x) + "," + String(y));
  delay(100);
}
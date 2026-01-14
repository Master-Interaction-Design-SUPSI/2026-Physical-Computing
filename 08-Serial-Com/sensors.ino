// Joystick
void readJoystick() {

  x = analogRead(A2);
  y = analogRead(A3);

  Serial.println("x: " + String(x) + ", y: " + String(y));

}
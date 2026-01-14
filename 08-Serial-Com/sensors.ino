// Joystick
void readJoystick() {

  x = analogRead(A2);
  y = analogRead(A3);

  Serial.println("x: " + String(x) + ", y: " + String(y));

  // button management
  if(x == 4095) { 
    button = 1;
  }
  else {
    button = 0;
    x_pos = map(x, 990, 2930, 1, 16); // from pot value to LCD col index
  }

  y_pos = map(y, 930, 2930, 1, 16); // from pot value to LCD col index

  Serial.println("x_pos: " + String(x_pos) + ", y_pos: " + String(y_pos));

}
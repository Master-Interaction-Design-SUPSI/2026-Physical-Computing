void updateLCD() {

  // joystic position
  String x_line = "x---------------";
  String y_line = "y---------------";

  x_line.setCharAt(x_pos, '#');
  y_line.setCharAt(y_pos, '#');

  lcd.setCursor(0, 0);  // 1st line
  lcd.print(x_line);

  lcd.setCursor(0, 1);  // 2nd line
  lcd.print(y_line);

  // button click
  if (button) {
    lcd.setRGB(255, 0, 0);
  }
  else {
    lcd.setRGB(0, 255, 0);
  }

}
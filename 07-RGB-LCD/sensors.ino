// potentiometer
void readPot() {

  // potentiomenter smooting
    pot = 0;
    for(int i=0; i<20; i++) {
      pot += analogRead(A1);
    }
    pot /= 20;  // pot = pot / 20;

    lcd.setCursor(12, 1);   // col (12), line (1)
    lcd.print("    ");
    lcd.setCursor(12, 1);
    lcd.print(pot);
}

// ultrasonic distance sensor
void readDistance() {

  distance = ultrasonic.MeasureInCentimeters();

  lcd.setCursor(8, 1);
  lcd.print("   ");
  lcd.setCursor(8, 1);
  lcd.print(distance);

}
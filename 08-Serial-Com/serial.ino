void manageSerial() {

  if (Serial.available() > 0) {  // check the serial buffer to income data
    String msg = Serial.readString();
    Serial.print(msg);

    msg.trim();

    if(msg.equals("red")) {
      lcd.setRGB(255, 0, 0);
    }
    else if (msg.equals("green")) {
      lcd.setRGB(0, 255, 0);
    }
    else if (msg.equals("blue")) {
      lcd.setRGB(0, 0, 255);
    }
    
    lcd.clear();
    lcd.print(msg);
  }

}
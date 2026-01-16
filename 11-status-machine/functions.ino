void runFunctions() {
  switch(currentFunction) {
    case 0:
      blinkFunction();
      break;
    case 1:
      countFunction();
      break;
    case 2:
      potFunction();
      break;
    default:
      Serial.println("Function not recognised");
      break;
  }
}

void blinkFunction() {
  lcd.print("blink");

  if(millis() - old_blinkTime > blinkInterval) {

    if(currentBlinkStatus) {
      lcd.setRGB(0, 0, 0);    // background off
    }
    else {
      lcd.setRGB(0, 0, 255);  // background on
    }

    currentBlinkStatus = !currentBlinkStatus;  // toggle
    
    old_blinkTime = millis();
  }
}

void countFunction() {



}

void potFunction() {



}
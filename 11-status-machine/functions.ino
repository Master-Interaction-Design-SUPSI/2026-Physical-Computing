void runFunctions() {

  if(currentFunction != old_currentFunction) {
    lcd.clear();
    lcd.setRGB(0, 0, 0);
    // print the title
    lcd.print(functionData[currentFunction][0]);
    timerInterval = functionData[currentFunction][1].toInt();
    old_currentFunction = currentFunction;
  }


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

  if(checkTimer()) {   // check the timer
    if(currentBlinkStatus) {
      lcd.setRGB(0, 0, 0);    // background off
    }
    else {
      lcd.setRGB(0, 0, 255);  // background on
    }

    currentBlinkStatus = !currentBlinkStatus;  // toggle
  }
    
}

void countFunction() {

  if(checkTimer()) {
    lcd.setCursor(0, 1);    // fist col, sencond line
    lcd.print(counter);
    counter++;
  }

}

void potFunction() {

  if(checkTimer()) {
    // values smoothing
    potVal = 0;
    for(int i=0; i<20; i++) {
      potVal += analogRead(pinPot);
    }
    potVal /= 20;

    lcd.setCursor(0, 1);
    lcd.print("    ");
    lcd.setCursor(0, 1);
    lcd.print(potVal);
  }

}

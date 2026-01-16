void readInterface() {
  
  buttonStatus = digitalRead(pinButton);

  // check if button has just been pressed (rising edge)
  if(buttonStatus && !old_buttonStatus) {   // same as: if(buttonStatus == 1 && old_buttonStatus == 0)
    
    if(currentFunction == 2) {  // 2 -> 0
      currentFunction = 0;
    }
    else {    // 0 -> 1, 1 -> 2
      currentFunction++;
    }

    Serial.println(currentFunction);
  }

  old_buttonStatus = buttonStatus;

}
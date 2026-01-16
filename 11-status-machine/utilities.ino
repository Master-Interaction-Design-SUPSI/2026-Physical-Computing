bool checkTimer() {

  bool timePassed = 0;

  if(millis() - old_timer > timerInterval) {
    timePassed = 1;
    old_timer = millis();
  }

  return timePassed;
}
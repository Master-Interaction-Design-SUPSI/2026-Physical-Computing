void readSerial() {
  if(Serial.available() > 0) {
    String msg = Serial.readString();
    Serial.print(msg);
    msg.trim();
    serialAPI(msg);
  }
}

void serialAPI(String msg) {
  if(msg.equals("LED ON")) {
    digitalWrite(13, HIGH);
  }
  else if(msg.equals("LED OFF")) {
    digitalWrite(13, LOW);
  }
}
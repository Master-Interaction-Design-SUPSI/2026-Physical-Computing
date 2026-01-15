void readSerial() {

  if(Serial.available() > 0) {
    String msg = Serial.readString();

    Serial.print(msg);

    msg.trim();

    if(msg.equals("LED ON")) {
      digitalWrite(13, HIGH);
    }
    else if(msg.equals("LED OFF")) {
      digitalWrite(13, LOW);
    }
  }
}
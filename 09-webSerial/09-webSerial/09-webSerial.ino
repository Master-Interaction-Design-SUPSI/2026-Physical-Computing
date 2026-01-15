void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  readSerial();

  Serial.println("Hi");
  delay(1000);

}

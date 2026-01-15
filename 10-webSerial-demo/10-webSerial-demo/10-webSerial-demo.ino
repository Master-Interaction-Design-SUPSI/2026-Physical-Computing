int x = 0;  // x axis
int y = 0;  // y axis

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  readSerial();
  readSensors();
  delay(1);
}

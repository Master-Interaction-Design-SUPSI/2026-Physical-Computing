int counter = 0;
int dir = 1;    // +1: count up, -1: count down
int potVal = 0;  // 0 ... 4095
int printDelay = 0;

void setup() {
  Serial.begin(9600);
}
void loop() {
  potVal = analogRead(A0); // reading the potentiometer
  printDelay = map(potVal, 0, 4095, 20, 200);

  for(int i=0; i<counter; i++) {
    Serial.print("=");
  }
  Serial.println();

  if(counter == 30) {
    dir = -1;
  }
  if (counter == 0) {
    dir = 1;
  }
  counter += dir;
  delay(printDelay);
}

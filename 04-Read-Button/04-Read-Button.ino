int buttonVal = 0;  // current button status (0/1)
int old_buttonVal = 0; // previous button status (0/1)

int pressCount = 0;  // how many times user press the button

void setup() {
  Serial.begin(9600);
  pinMode(D8, INPUT);
}

void loop() {
  buttonVal = digitalRead(D8);

  if(buttonVal == 1 && old_buttonVal == 0) {    // check if button is pressed
    pressCount++;
  }

  old_buttonVal = buttonVal;

  Serial.println(pressCount);
  delayMicroseconds(1);
}

#include <rgb_lcd.h>

rgb_lcd lcd;

// joystick
int x = 0;      // 16 bits (2 bytes)
int y = 0;      // 16 bits (2 bytes)
bool button = 0;  // 1 bit


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  manageSerial();
  readJoystick();
  
  delay(1);
}

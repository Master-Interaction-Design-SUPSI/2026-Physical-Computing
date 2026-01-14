#include <rgb_lcd.h>

rgb_lcd lcd;

// joystick
int x = 0;      // 16 bits (2 bytes)
int x_pos = 0;   // LCD 1st line col index (0-15)

int y = 0;      // 16 bits (2 bytes)
int y_pos = 0;    // LCD 2nd line col inex (0-15)

bool button = 0;  // 1 bit


void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  manageSerial();
  readJoystick();
  updateLCD();

  delay(1);
}

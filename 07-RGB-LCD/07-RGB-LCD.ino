#include <rgb_lcd.h>
#include <Wire.h>

rgb_lcd lcd;
int counter = 0;

// RGB backlight channels
int red = 0;
int green = 0;
int blue = 0;

// sensors
int pot = 0;


void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 0); // 0 ... 255
  lcd.print("Hello World");
}

void loop() {

  // potentiometer
  pot = analogRead(A1);
  lcd.setCursor(12, 1);   // col (12), line (1)
  lcd.print("    ");
  lcd.setCursor(12, 1);
  lcd.print(pot);

  // counter
  lcd.setCursor(0, 1);  // first col (0), second line (1)
  lcd.print(counter);
  counter++;

  // RGB backlight
  red = randomColor(); // 0 .. 255, 2^8 (1byte)
  green = randomColor(); // 0 .. 255, 2^8 (1byte)
  blue = randomColor(); // 0 .. 255, 2^8 (1byte)
  lcd.setRGB(red, green, blue);

  delay(1000);
}

int randomColor() {
  int newColor = int(random(0, 256));
  return newColor;
}



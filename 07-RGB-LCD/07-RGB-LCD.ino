#include <Ultrasonic.h>
#include <rgb_lcd.h>
#include <Wire.h>

// Libraries
rgb_lcd lcd;
Ultrasonic ultrasonic(D7);

// Variables
int counter = 0;

// RGB backlight channels
int red = 0;
int green = 0;
int blue = 0;

// sensors
int pot = 0;
int distance = 0;

// timing
unsigned long old_millis_counter = 0;
unsigned long old_millis_pot = 0;
const int counter_interval = 1000;  // 1000ms, 1s


void setup() {
  lcd.begin(16, 2);
  lcd.setRGB(0, 255, 0); // 0 ... 255
  lcd.print("Hello World");
}

void loop() {

  // sensors update
  if(millis() - old_millis_pot > 100) { // update sensors every 100ms

    readPot();

    readDistance();
    
    old_millis_pot = millis();
  }

  // seconds counter
  if(millis() - old_millis_counter > counter_interval) {
    lcd.setCursor(0, 1);  // first col (0), second line (1)
    lcd.print(counter);
    counter++;
    old_millis_counter = millis();

    // RGB backlight
    red = randomColor(); // 0 .. 255, 2^8 (1byte)
    green = randomColor(); // 0 .. 255, 2^8 (1byte)
    blue = randomColor(); // 0 .. 255, 2^8 (1byte)
    lcd.setRGB(red, green, blue);
  }
}

int randomColor() {
  int newColor = int(random(0, 256));
  return newColor;
}



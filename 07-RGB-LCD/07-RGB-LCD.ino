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

  // potentiometer
  if(millis() - old_millis_pot > 100) { // update pot every 100ms
    
    // potentiomenter smooting
    pot = 0;
    for(int i=0; i<20; i++) {
      pot += analogRead(A1);
    }
    pot /= 20;  // pot = pot / 20;

    lcd.setCursor(12, 1);   // col (12), line (1)
    lcd.print("    ");
    lcd.setCursor(12, 1);
    lcd.print(pot);
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



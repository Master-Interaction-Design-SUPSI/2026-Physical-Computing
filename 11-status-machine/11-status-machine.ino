/*
This sketch does three things:
1) blink the RGB background lights of the RGB LCD
2) count up
3) display the potentiometer value

The touch button will loop trough those functionalities.
*/

// libraries
#include <rgb_lcd.h>

// objects
rgb_lcd lcd;

// pinout
byte pinButton = D11;  // byte, 8bits, 1byte, 2^8 -> 0 ... 255
byte pinPot = A1;

// values
int potVal = 0;
bool buttonStatus = 0;
bool old_buttonStatus = 0;

// variables
byte currentFunction = 0;   // 0: blink, 1: count, 2: pot
byte old_currentFunction = 255;
bool currentBlinkStatus = 0;   // 0: backlight off, 1: backlight on
unsigned int counter = 0;
bool reset = false;   // used to reset functions at start

// timer
long old_timer = 0;
int timerInterval = 1000;   // 1s

// dataset
struct FunctionData {
  String name;
  int interval;
  byte color[3];
  bool resetAtStartup;
};

FunctionData data[] = {
  {"blink", 1000, {0, 0, 255}, false},
  {"count", 1000, {0, 255, 0}, true},
  {"potentiometer", 50, {255, 0, 0}, false}
};

void setup() {
  pinMode(pinButton, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  readInterface();
  runFunctions();
}





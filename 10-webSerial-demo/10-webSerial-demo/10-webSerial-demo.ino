#include <Adafruit_NeoPixel.h>

byte pinNeopixels = 6;  // !! on the board it's the D3 !!
byte pixelsCount = 24;

Adafruit_NeoPixel ring(pixelsCount, pinNeopixels, NEO_GRB + NEO_KHZ800);

int x = 0;  // x axis
int y = 0;  // y axis

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  ring.begin();
  ring.show();
}

void loop() {
  readSerial();
  readSensors();
  delay(1);
}

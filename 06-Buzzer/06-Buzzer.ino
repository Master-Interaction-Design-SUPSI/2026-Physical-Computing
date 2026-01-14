int pin_buzzer = D10;

void setup() {
}

void loop() {
  tone(pin_buzzer, 261);
	delay(1000);
	tone(pin_buzzer, 293);
	delay(1000);
	tone(pin_buzzer, 330);
	delay(1000);
	tone(pin_buzzer, 349);
	delay(1000);
	tone(pin_buzzer, 392);
	delay(1000);
	tone(pin_buzzer, 440);
	delay(1000);
	tone(pin_buzzer, 494);
	delay(1000);
	tone(pin_buzzer, 523);
	delay(1000);
}

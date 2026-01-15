void updatePixels(String msg) {
  int r, g, b;
  parseRGB(msg, r, g, b);
  Serial.println(String(r) + "," + String(g) + "," + String(b));
  ring.setPixelColor(0, ring.Color(r, g, b));
}

void parseRGB(String data, int &r, int &g, int &b) {
  int firstComma  = data.indexOf(',');
  int secondComma = data.indexOf(',', firstComma + 1);
  int thirdComma  = data.indexOf(',', secondComma + 1);

  r = data.substring(firstComma + 1, secondComma).toInt();
  g = data.substring(secondComma + 1, thirdComma).toInt();
  b = data.substring(thirdComma + 1).toInt();
}

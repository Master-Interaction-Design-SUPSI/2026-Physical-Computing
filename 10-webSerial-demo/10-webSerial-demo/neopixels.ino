void updatePixels(String msg) {
  int r, g, b, i;
  parseRGB(msg, r, g, b, i);
  Serial.println(String(i) + "," + String(r) + "," + String(g) + "," + String(b));

  ring.setPixelColor(i, ring.Color(r, g, b));
  ring.show();
}

void parseRGB(String data, int &r, int &g, int &b, int &i) {
  int firstComma  = data.indexOf(',');
  int secondComma = data.indexOf(',', firstComma + 1);
  int thirdComma  = data.indexOf(',', secondComma + 1);
  int fourthComma  = data.indexOf(',', thirdComma + 1);

  r = data.substring(firstComma + 1, secondComma).toInt();
  g = data.substring(secondComma + 1, thirdComma).toInt();
  b = data.substring(thirdComma + 1, fourthComma).toInt();
  i = data.substring(fourthComma + 1).toInt();
}

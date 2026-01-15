void updatePixels(String msg) {

  // API: "P,R,G,B,START,STOP"

  int r, g, b, iStart, iStop;
  parseRGB(msg, r, g, b, iStart, iStop);
  Serial.println(String(iStart) + "," + String(iStop) + "," + String(r) + "," + String(g) + "," + String(b));

  for(int i = iStart; i <= iStop; i++) {
    ring.setPixelColor(i, ring.Color(r, g, b));
    ring.show();
    delay(100);
  }

}

void parseRGB(String data, int &r, int &g, int &b, int &iStart, int &iStop) {
  int firstComma  = data.indexOf(',');
  int secondComma = data.indexOf(',', firstComma + 1);
  int thirdComma  = data.indexOf(',', secondComma + 1);
  int fourthComma  = data.indexOf(',', thirdComma + 1);
  int fifthComma  = data.indexOf(',', fourthComma + 1);

  r = data.substring(firstComma + 1, secondComma).toInt();
  g = data.substring(secondComma + 1, thirdComma).toInt();
  b = data.substring(thirdComma + 1, fourthComma).toInt();
  iStart = data.substring(fourthComma + 1, fifthComma).toInt();
  iStop = data.substring(fifthComma + 1).toInt(); 
}

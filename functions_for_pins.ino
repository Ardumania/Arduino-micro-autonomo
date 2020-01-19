void presentation(){
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(10, 10);
  display.println("Programed by");
  display.setCursor(20, 20);
  display.println("Josemanu");
  display.setCursor(20, 30);
  display.println("Push the");
  display.setCursor(26, 40);
  display.println("button");
}
  
void noThingToSee(){
  
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(15, 15);
  display.println("no thing");
  display.setCursor(21, 25);
  display.println("to see");
  display.setCursor(27, 35);
  display.println("here");
}

void showTempAndHumidity(){
  // read the DHT22 sensor and show temperature
  // and humidity in the screen
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0, 16);
  display.print(t);
  display.println(" C");
  display.setTextSize(1);
  display.setCursor(21, 36);
  display.print(h);
  display.println("%");
}

void showAnalogRead(){
  // read the 3rd pin (A1) and
  // show the value in the screen
  display.setTextSize(2);
  display.setTextColor(BLACK);
  display.setCursor(0, 16);
  display.print(analogRead(A1));
}
  

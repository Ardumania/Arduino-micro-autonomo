/*********************************************************************
  This sketch is a demostration of use for the autonomous
  Arduino Micro with Nokia 5110 screen and lipo batterie.

  All the libraries used were developed by Adafruit

  Programed by Josemanu
      @Ardumania_JManu

  Version 0.1 06/12/2019

*********************************************************************/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

// Software SPI (slower updates, more flexible pin options):
// Adafruit_PCD8544(SCLK, DIN, D/C, CS, RST)

// My breakout board:
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)

//
Adafruit_PCD8544 display = Adafruit_PCD8544(7, 6, 5, 4, 3);
// digital pin 9 (with PWM) is used for backlitgh,
// use values between 0 and 168 (3.3v)

// pins 10, 11 and 12 are used as digital input/output
// analog pins A1, A2 and A3 are used as inputs, they can
// be use as digital input/output pins numbered
// 15, 16 and 17
//
//               IMPORTANT
//  the order of the pins are, from left to right:
//        A3, A2, A1, 12, 11 and 10
//
// in this example I'm going to connec a force resistor sensor
// to pin A1 and a DHT22 sensor on pin 10

#include "DHT.h"
#define DHTPIN 10
#define DHTTYPE DHT22   // DHT 22
DHT dht(DHTPIN, DHTTYPE);

// digital pin 13 is used for push button with INPUYT_PULLUP
int pin = 13;

// these variables are needed for the push button
int lastState = 0;
int actualState;
int counter = 0;
int pinForStateChange = 13; 

// each level is a diferent screen
int level = 0;

void setup()   {
  pinMode(pin, INPUT_PULLUP);

  display.begin();    // init done
  dht.begin();

  // turn on backlight, be carefull with this, the screen works at 3.3v
  // so the analogWrite values must be betwin 0 and 168
  pinMode(9, OUTPUT);
  analogWrite(9, 120);

  // you can change the contrast to adapt the display
  // for the best viewing!
  display.setContrast(50);

  display.display(); // show splashscreen
  delay(2000);
}


void loop() {

  // if de push button change its state then the screen
  // changes too
  if(hasChanged(pinForStateChange)){
    level++;
    if (level > 6){
    level = 1;  // haha level 0 only be shown for the first time
    }
  }


  display.clearDisplay();  // clear screen and buffer

  // navigation for diferent screens
  switch (level){
    case 0:
      // begining function
      presentation();
       break;
    case 1:
      // function for input 10, it shows temperatura and humidity
      showTempAndHumidity();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin 10");
     break;
    case 2:
      // function for input 11
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin 11");
      break;
    case 3:
      // function for input 12
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin 12");
      break;
    case 4:
      // function for input A0
      // in this case a force resistor sensor
      showAnalogRead();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin A0");
      break;
    case 5:
      // function for input A1
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin A1");
     break;
    case 6:
      // function for input A2
      noThingToSee();
      display.setTextSize(1);
      display.setCursor(10, 0);
      display.println("Pin A2");
     break;
  }

  display.display(); // show data on screen
}


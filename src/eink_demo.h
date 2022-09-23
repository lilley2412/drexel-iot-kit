#ifndef EINK_DEMO_H
#define EINK_DEMO_H

#include "Adafruit_ThinkInk.h"
#include <Adafruit_GFX.h>
#include <SPI.h>

#define SD_CS 5
#define SRAM_CS 6
#define EPD_CS 9
#define EPD_DC 10
#define EPD_RESET -1 // can set to -1 and share with microcontroller Reset!
#define EPD_BUSY -1  // can set to -1 to not use a pin (will wait a fixed delay)

#define COLOR1 EPD_BLACK
#define COLOR2 EPD_LIGHT
#define COLOR3 EPD_DARK

#define BUTTON_1 A3
#define BUTTON_2 A4
#define BUTTON_3 A5

ThinkInk_290_Grayscale4_T5 display(EPD_DC, EPD_RESET, EPD_CS, SRAM_CS, EPD_BUSY);

void eink_setup() {  
  pinMode(BUTTON_1, INPUT_PULLUP); 
  pinMode(BUTTON_2, INPUT_PULLUP); 
  pinMode(BUTTON_3, INPUT_PULLUP);
  

  display.begin(THINKINK_GRAYSCALE4);
  display.clearBuffer();
  display.setTextSize(3);
  display.setTextColor(EPD_BLACK);
  display.setCursor(20, 40);

  display.print("The doctor is:");
  display.setCursor(120, 80);
  display.print("IN!");
  display.display();
}

void eink_loop() {
  if (!digitalRead(BUTTON_1)) {
    Serial.println("Button 1 pressed");
  }
  if (!digitalRead(BUTTON_2)) {
    Serial.println("Button 2 pressed");
  }
  if (!digitalRead(BUTTON_3)) {
    Serial.println("Button 3 pressed");
  }
}

#endif
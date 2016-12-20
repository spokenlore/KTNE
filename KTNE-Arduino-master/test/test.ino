#include <Wire.h>
#include "rgb_lcd.h"
#include "Grove_LED_Bar.h"

// red = (255, 0, 0);
// blue = (0, 0, 255);
// yellow = (255, 255, 0);
// green = (0, 128, 0);
const int red1 = 255;
const int red2 = 0;
const int red3 = 0;
const int blue1 = 0;
const int blue2 = 0;
const int blue3 = 255;
const int yellow1 = 255;
const int yellow2 = 255;
const int yellow3 = 0;
const int green1 = 0;
const int green2 = 128;
const int green3 = 0;

rgb_lcd lcd;

const int wires[] = {22, 24, 26, 28, 30};
const int numWires = 5;
const int buttons[] = {50, 51, 52, 53};
const int numButtons = 4;
int currentStage = 1;
int reset = 1;
int stage2part = 1;

void setup() {
  // Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 100);
  lcd.setCursor(0,1);
  lcd.print("Serial: AA00123");
  
  for (int i = 0; i < numWires; i++){
    pinMode(wires[i], INPUT);
  }
  for (int i = 0; i < numButtons; i++){
    pinMode(buttons[i], INPUT);
  }
  delay(1000);
//  lcd.setRGB(red1, red2, red3);
//  delay(200);
//  lcd.setRGB(green1, green2, green3);
//  delay(200);
//  lcd.setRGB(yellow1, yellow2, yellow3);
//  delay(200);
//  lcd.setRGB(blue1, blue2, blue3);
//  delay(200);
  lcd.setRGB(255, 255, 255);
  lcd.clear();
}

void loop() {

//  lcd.setCursor(0,0);
//  for (int i = 0; i < numWires; i++){
//     lcd.print(digitalRead(wires[i]));
//  }
//  lcd.setCursor(0,1);
//  for (int i = 0; i < numButtons; i++){
//    lcd.print(digitalRead(buttons[i]));
//  }
  currentStage = stage(currentStage);
  currentStage = currentStageMessage(currentStage);
  delay(500);
}

int stage(int number){
  if (number == 1) {
    return stage1();
  }
  else
    return stage2();
}

int stage1(){
  while(1){
    if (digitalRead(wires[0]) == 0){
      lcd.setRGB(0,0,0);
      delay(1000);
      lcd.setRGB(255,255,255);
      return 2;
    }
    else{
      for (int i = 1; i < numWires; i++){
        if (digitalRead(wires[i]) == 0){
          return 0;
        }
      }
    }
  }
}

int stage2(){
  // FLASH RED - BLUE - YELLOW - GREEN
  // PRESS BLUE - RED - GREEN - YELLOW
  // green 53 red 52 blue 51 yellow 50
  
  if (stage2part > 0 and reset == 1){
    while (true) {
      flash();
      if (digitalRead(51) == 1){
        lcd.setRGB(0, 0, 0);
        delay(1000);
        if (stage2part > 1)
          {
            reset = 1;
          }
        else{
          stage2part = 2;
          reset = 0;
        }
        break;
      }
      else { 
        if (digitalRead(50) == 1){
          return 0;
        }
        if (digitalRead(52) == 1){
          return 0;
        }
        if (digitalRead(53) == 1){
          return 0;
        }
      }
    }
  }
  if (stage2part > 1 and reset == 1){
    while (true) {
      flash();
      if (digitalRead(52) == 1){
        lcd.setRGB(0, 0, 0);
        delay(1000);
        if (stage2part > 2)
          {
            reset = 1;
          }
        else{
          stage2part = 3;
          reset = 0;
        }
      }
        else { 
          if (digitalRead(50) == 1){
            return 0;
          }
          if (digitalRead(51) == 1){
            return 0;
          }
          if (digitalRead(53) == 1){
            return 0;
    }
  }
    }
    }
  if (stage2part > 2 and reset == 1){
    while (true) {
      flash();
      if (digitalRead(53) == 1){
        lcd.setRGB(0, 0, 0);
        delay(1000);
       if (stage2part > 3)
          {
            reset = 1;
          }
        else{
          stage2part = 4;
          reset = 0;
        }
      }
        else { 
          if (digitalRead(50) == 1){
            return 0;
          }
          if (digitalRead(51) == 1){
            return 0;
          }
          if (digitalRead(52) == 1){
            return 0;
    }
  }
    }
    }
  if (stage2part > 3 and reset == 1){
    while (true) {
      flash();
      if (digitalRead(50) == 1){
        lcd.setRGB(0, 0, 0);
        delay(1000);
        return 3;
      }
        else { 
          if (digitalRead(51) == 1){
            return 0;
          }
          if (digitalRead(52) == 1){
            return 0;
          }
          if (digitalRead(53) == 1){
            return 0;
    }
  }
    }
  }
  reset = 1;
  return 2;
}

int currentStageMessage(int number){
  if (number == 0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YOU EXPLODED");
    // TRIGGER BUZZER
     return 0; 
  }
  if (number == 1){
    lcd.print("STAGE 1 CLEAR");
    return 2;
  }
  if (number == 3){
    lcd.print("STAGE 2 CLEAR");
    return 3;
  }
}

int flash(){
// Part 1
  lcd.setRGB(red1, red2, red3);
  delay(500);
  // Part 2
  if (stage2part > 1){
  lcd.setRGB(blue1, blue2, blue3);
  delay(500);
  }
  // Part 3
  if (stage2part > 2){
  lcd.setRGB(yellow1, yellow2, yellow3);
  delay(500);
  }
  // Part 4
  if (stage2part > 3){
  lcd.setRGB(green1, green2, green3);
  delay(500);
  }
  
  lcd.setRGB(255, 255, 255);
  delay(1000);
  
}

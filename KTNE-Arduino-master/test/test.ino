#include <Wire.h>
#include "elapsedMillis.h"
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

// Deprecated code
//int currentStage = 1;
//int reset = 1;
//int stage2part = 1;

// Color LEDs
const int LEDs[] = {41, 43, 45, 47};
const int numLEDs = 4;

// Buttons
const int Buttons[] = {31, 33, 35, 37};
const int numButtons = 4;
const int upButton = 30;
const int leftButton = 32;
const int rightButton = 34;
const int downButton = 36;

// Wires
const int Wires[] = {22, 24, 26};
const int numWires = 3;

// 2 - Up
// 3 - Left
// 4 - Right
// 5 - Down
// const int buttons[] = {2, 3, 4, 5};
// numButtons = 4;

// Buzzer
int buzzer = 3;

// Touch sensor
int touchSensor = 4;

elapsedMillis timeElapsed;
unsigned int interval = 1000;
int timeLeft = 300;
int chancesLeft = 3;

void setup() {
//  pinMode(13, OUTPUT);
//  for (int i = 0; i < numButtons; i++){
//    pinMode(Buttons[i], INPUT);
//  }
//  for (int i = 0; i < numLEDs; i++) {
//    pinMode(LEDs[i], OUTPUT);
//  }
//  for (int i = 0; i < numLEDs; i++){
//    digitalWrite(LEDs[i], HIGH);
//  }
//  for (int i = 0; i < numWires; i++){
//    pinMode(Wires[i], INPUT);
//  }
  pinMode(buzzer, OUTPUT);
  pinMode(touchSensor, INPUT);
  lcd.begin(16, 2);
  lcd.setRGB(255, 255, 100);
  lcd.setCursor(0, 0);
  lcd.print("Serial: AA00123");
  lcd.setCursor(0, 1);
  lcd.print("Initializing...");

  delay(1000);
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("You have: ");
  lcd.setCursor(0, 1);
  lcd.print("5 minutes.");
//   for (int i = 0; i < numWires; i++){
//  if (Wires[i] == HIGH){
//      lcd.clear();
//    }
//   }
  delay(2000);

  lcd.setRGB(255, 255, 255);
  lcd.clear();
}

void loop() {
boolean gameOver = false;
// Buttons Test
//  for (int i = 0; i < numButtons; i++){
//    if (digitalRead(Buttons[i]) == HIGH){
//      digitalWrite(13, HIGH);
//      delay(500);
//      digitalWrite(13, LOW);
//    }
//  }
//// LEDs Test
//for (int i = 0; i < numLEDs; i++){
//  digitalWrite(LEDs[i], HIGH);
//}

gameOver = passwords();
gameOverCheck(gameOver);
if (gameOver == true){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("YOU WON WITH:");
  lcd.setCursor(0, 1);
  lcd.print(timeLeft);
  lcd.setCursor(4, 1);
  lcd.print("SECS LEFT!");
  delay(500);
}
else{
  digitalWrite(buzzer, HIGH);
  delay(150);
  digitalWrite(buzzer, LOW);
}


  //  currentStage = stage(currentStage);
  //  currentStage = currentStageMessage(currentStage);
  //  delay(500);
}

//int stage(int number){
//  if (number == 1) {
//    return stage1();
//  }
//  else
//    return stage2();
//}

//int stage1(){
//  while(1){
//    if (digitalRead(wires[0]) == 0){
//      lcd.setRGB(0,0,0);
//      delay(1000);
//      lcd.setRGB(255,255,255);
//      return 2;
//    }
//    else{
//      for (int i = 1; i < numWires; i++){
//        if (digitalRead(wires[i]) == 0){
//          return 0;
//        }
//      }
//    }
//  }
//}
//
//boolean simonSays(){
//  // FLASH RED - BLUE - YELLOW - GREEN
//  // PRESS BLUE - RED - GREEN - YELLOW
//  // green 53 red 52 blue 51 yellow 50
//    while (true) {
//      flash();
//      if (digitalRead(51) == 1){
//        lcd.setRGB(0, 0, 0);
//        delay(1000);
//        if (stage2part > 1)
//          {
//            reset = 1;
//          }
//        else{
//          stage2part = 2;
//          reset = 0;
//        }
//        break;
//      }
//      else {
//        if (digitalRead(50) == 1){
//          return 0;
//        }
//        if (digitalRead(52) == 1){
//          return 0;
//        }
//        if (digitalRead(53) == 1){
//          return 0;
//        }
//      }
//    }
//  }
//  if (stage2part > 1 and reset == 1){
//    while (true) {
//      flash();
//      if (digitalRead(52) == 1){
//        lcd.setRGB(0, 0, 0);
//        delay(1000);
//        if (stage2part > 2)
//          {
//            reset = 1;
//          }
//        else{
//          stage2part = 3;
//          reset = 0;
//        }
//      }
//        else {
//          if (digitalRead(50) == 1){
//            return 0;
//          }
//          if (digitalRead(51) == 1){
//            return 0;
//          }
//          if (digitalRead(53) == 1){
//            return 0;
//    }
//  }
//    }
//    }
//  if (stage2part > 2 and reset == 1){
//    while (true) {
//      flash();
//      if (digitalRead(53) == 1){
//        lcd.setRGB(0, 0, 0);
//        delay(1000);
//       if (stage2part > 3)
//          {
//            reset = 1;
//          }
//        else{
//          stage2part = 4;
//          reset = 0;
//        }
//      }
//        else {
//          if (digitalRead(50) == 1){
//            return 0;
//          }
//          if (digitalRead(51) == 1){
//            return 0;
//          }
//          if (digitalRead(52) == 1){
//            return 0;
//    }
//  }
//    }
//    }
//  if (stage2part > 3 and reset == 1){
//    while (true) {
//      flash();
//      if (digitalRead(50) == 1){
//        lcd.setRGB(0, 0, 0);
//        delay(1000);
//        return 3;
//      }
//        else {
//          if (digitalRead(51) == 1){
//            return 0;
//          }
//          if (digitalRead(52) == 1){
//            return 0;
//          }
//          if (digitalRead(53) == 1){
//            return 0;
//    }
//  }
//    }
//  }
//  reset = 1;
//  return 2;
//}
//
//int currentStageMessage(int number){
//  if (number == 0){
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    lcd.print("YOU EXPLODED");
//    // TRIGGER BUZZER
//     return 0;
//  }
//  if (number == 1){
//    lcd.print("STAGE 1 CLEAR");
//    return 2;
//  }
//  if (number == 3){
//    lcd.print("STAGE 2 CLEAR");
//    return 3;
//  }
//}

// Page 16
boolean passwords() {
  int numLetters[] = {14, 10, 9, 10, 10};
  char letter0[] = {'a', 'b', 'c', 'e', 'f', 'g', 'h', 'l', 'o', 'p', 'r', 's', 't', 'w'};
  char letter1[] = {'a', 'e', 'f', 'h', 'i', 'l', 'o', 'r', 't', 'v'};
  char letter2[] = {'a', 'e', 'g', 'h', 'i', 'l', 'r', 't', 'u'};
  char letter3[] = {'c', 'e', 'h', 'i', 'l', 'n', 'o', 'r', 's', 't'};
  char letter4[] = {'d', 'e', 'h', 'k', 'l', 'n', 'r', 't', 'w', 'y'};

  char correct0 = 't';
  char correct1 = 'h';
  char correct2 = 'r';
  char correct3 = 'e';
  char correct4 = 'e';

  int selects[] = {0, 0, 0, 0, 0};

  int selectedCharacter = 0;
  int moveTaken = 0;
  
  while (timeLeft != 0 and chancesLeft != 0) {
    lcd.setCursor(0, 0);
    lcd.print("Time Left: ");
    lcd.setCursor(11, 0);
    lcd.print(timeLeft);
    lcd.setCursor(0, 1);
    lcd.print(letter0[selects[0]]);
    lcd.setCursor(1, 1);
    lcd.print(letter1[selects[1]]);
    lcd.setCursor(2, 1);
    lcd.print(letter2[selects[2]]);
    lcd.setCursor(3, 1);
    lcd.print(letter3[selects[3]]);
    lcd.setCursor(4, 1);
    lcd.print(letter4[selects[4]]);

    if ((letter0[selects[0]] == correct0) and (letter1[selects[1]] == correct1) and (letter2[selects[2]] == correct2) and (letter3[selects[3]] == correct3) and (letter4[selects[4]] == correct4)){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PASSWORDS CLEAR");
      timeLeft = timeLeft + 3;
      delay(1000);
      lcd.clear();
      return true;
    }

      if (digitalRead(upButton) == HIGH and moveTaken == 0){
        if (selects[selectedCharacter] != numLetters[selectedCharacter]-1){
        selects[selectedCharacter] = selects[selectedCharacter] + 1;
        }
        moveTaken = 1;
      }
      if (digitalRead(leftButton) == HIGH and moveTaken == 0){
        if (selectedCharacter != 0){
          selectedCharacter = selectedCharacter - 1;
        }
        moveTaken = 1;
      }
      if (digitalRead(rightButton) == HIGH and moveTaken == 0){
        if (selectedCharacter != 4){
          selectedCharacter = selectedCharacter + 1;
        }
        moveTaken = 1;
      }
      if (digitalRead(downButton) == HIGH and moveTaken == 0){
        if (selects[selectedCharacter] != 0){
        selects[selectedCharacter] = selects[selectedCharacter] - 1;
        }
        moveTaken = 1;
      }
    delay(200);
    moveTaken = 0;
    if (digitalRead(touchSensor) == LOW){
      decrementTime();
    }
    else{
      timeElapsed = 0;                      
    }
  }
  timeLeft = 0; 
  return false;
}

//int flash(){
//// Part 1
//  lcd.setRGB(red1, red2, red3);
//  delay(500);
//  // Part 2
//  if (stage2part > 1){
//  lcd.setRGB(blue1, blue2, blue3);
//  delay(500);
//  }
//  // Part 3
//  if (stage2part > 2){
//  lcd.setRGB(yellow1, yellow2, yellow3);
//  delay(500);
//  }
//  // Part 4
//  if (stage2part > 3){
//  lcd.setRGB(green1, green2, green3);
//  delay(500);
//  }
//
//  lcd.setRGB(255, 255, 255);
//  delay(1000);
//
//}

void decrementTime() {
  if (timeElapsed > interval and timeLeft != 0) {
    timeLeft = timeLeft - round(timeElapsed / 1000);
    timeElapsed = 0;
    if (timeLeft % 10 == 9) {
      lcd.clear();
    }
  }
}

void gameOverCheck(boolean isGameOver){
  if (isGameOver == true){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("YOU WON WITH:");
    lcd.setCursor(0, 1);
    lcd.print(timeLeft);
    lcd.setCursor(4, 1);
    lcd.print("SECS LEFT!");
    delay(1000);
  }
  else{
    while (true){
      digitalWrite(buzzer, HIGH);
      delay(150);
      digitalWrite(buzzer, LOW);
    }
  }
}


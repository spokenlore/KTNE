// LED Pins
int ledPin = 13;

// Button Pins
int redPin = 2;   
int bluePin = 3;
int greenPin = 4;
int yellowPin = 5;

// Button Array
int buttonArray[] = {redPin, bluePin, greenPin, yellowPin};
int buttonArrayLength = 4;
 
int redValue = 0;
int blueValue = 0;
int greenValue = 0;
int yellowValue = 0;

// Button Read Array
int buttonReadArray[] = {redValue, blueValue, greenValue, yellowValue};
int buttonReadArrayLength = 4;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  
  for (int i = 0 ; i < buttonArrayLength; i++){
    pinMode(buttonArray[i], INPUT); // loop through button array and declare as input
  }
}

void loop(){
  for (int i = 0; i < buttonArrayLength; i++) {
    buttonReadArray[i] = digitalRead(buttonArray[i]);
    if (buttonReadArray[i] == HIGH){
      for (int j = 0; j < buttonArray[i]; j++) {
        digitalWrite(ledPin, HIGH);
        delay(500);
        digitalWrite(ledPin, LOW);
        delay(500);
      }
      break;
    }
  }
  Serial.print("Loop complete.");
}

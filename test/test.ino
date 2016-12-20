 
/* Basic Digital Read
 * ------------------ 
 *
 * turns on and off a light emitting diode(LED) connected to digital  
 * pin 13, when pressing a pushbutton attached to pin 7. It illustrates the
 * concept of Active-Low, which consists in connecting buttons using a
 * 1K to 10K pull-up resistor.
 *
 * Created 1 December 2005
 * copyleft 2005 DojoDave <http://www.0j0.org>
 * http://arduino.berlios.de
 *
 */

int ledPin = 13; // choose the pin for the LED
int redPin = 2;   
int bluePin = 3;
int greenPin = 4;
int yellowPin = 5;
 
int redValue = 0;
int blueValue = 0;
int greenValue = 0;
int yellowValue = 0;

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  for (int i = 2; i < 6; i++){
    pinMode(i, INPUT);
  }
}

void loop(){
  redValue = digitalRead(redPin);  // read input value
  blueValue = digitalRead(bluePin);
  greenValue = digitalRead(greenPin);
  yellowValue = digitalRead(yellowPin);
  
  if (redValue == HIGH or blueValue == HIGH or greenValue == HIGH or yellowValue == HIGH) {         // check if the input is HIGH (button released)
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }
  Serial.print("Loop complete.");
}

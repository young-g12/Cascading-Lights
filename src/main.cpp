#include <Arduino.h>

const int buttonPin = 2;

const int leds[] = {4, 8, 11, 12};
const int numLeds = 4;

int currentLed = 0;
bool lastButtonState = HIGH;

void setup() {
  for (int i = 0; i < numLeds; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], LOW);
  }

  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);


  if (lastButtonState == HIGH && buttonState == LOW) {
    currentLed++;

    if (currentLed >= numLeds) {
      currentLed = 0;
    }

    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }


    digitalWrite(leds[currentLed], HIGH);
  }

  lastButtonState = buttonState;
}
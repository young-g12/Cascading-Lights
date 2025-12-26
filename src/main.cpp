#include <Arduino.h>

const int buttonPin = 2;

// LED pins stored in an array (professional style)
const int leds[] = {4, 8, 5};
const int numLeds = 3;

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

  // Detect button press (HIGH → LOW)
  if (lastButtonState == HIGH && buttonState == LOW) {
    currentLed++;

    if (currentLed >= numLeds) {
      currentLed = 0; // wrap around
    }

    // Turn all LEDs off
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(leds[i], LOW);
    }

    // Turn current LED on
    digitalWrite(leds[currentLed], HIGH);
  }

  lastButtonState = buttonState;
}
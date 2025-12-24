#include <Arduino.h>

int buttonState = 0;
const int buttonPin = 2;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;
const int ledPin4 = 7;
const int ledPin5 = 8;
const int ledPin6 = 9;


void setup() {
pinMode(ledPin1, OUTPUT);
pinMode(ledPin2, OUTPUT);
pinMode(ledPin3, OUTPUT);
pinMode(ledPin4, OUTPUT);
pinMode(ledPin5, OUTPUT);
pinMode(ledPin6, OUTPUT);
pinMode(buttonPin, INPUT);
}

void loop() {
  buttonState = digitalRead(buttonPin);
}


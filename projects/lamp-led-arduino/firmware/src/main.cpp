#include <Arduino.h>

const int ledPin = 13;

void setup() {
    pinMode(ledPin, OUTPUT);   // define o pino como saída
    digitalWrite(ledPin, HIGH); // liga o LED
}

void loop() {
}
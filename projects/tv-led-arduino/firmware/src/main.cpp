#include <Arduino.h>

const int PIN_R = 9;
const int PIN_G = 10;
const int PIN_B = 11;

const int BTN = 2;

enum Mode { RED, GREEN, BLUE, PARTY, OFF };
Mode mode = RED;

unsigned long lastPressMs = 0;
const unsigned long DEBOUNCE_MS = 250;

unsigned long lastPartyMs = 0;
const unsigned long PARTY_INTERVAL_MS = 150;
int partyStep = 0;

void setColor(int r, int g, int b) {
  analogWrite(PIN_R, r);
  analogWrite(PIN_G, g);
  analogWrite(PIN_B, b);
}

void setup() {
  pinMode(PIN_R, OUTPUT);
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(BTN, INPUT_PULLUP);

  setColor(0,0,0);
}

void loop() {

  if (digitalRead(BTN) == LOW && millis() - lastPressMs > DEBOUNCE_MS) {
    mode = (Mode)((mode + 1) % 5);
    lastPressMs = millis();

    if (mode != PARTY) {
      lastPartyMs = 0;
      partyStep = 0;
    }
  }

  switch(mode) {

    case RED:
      setColor(255,0,0);
      break;

    case GREEN:
      setColor(0,255,0);
      break;

    case BLUE:
      setColor(0,0,255);
      break;

    case PARTY:
      if (millis() - lastPartyMs > PARTY_INTERVAL_MS) {
        lastPartyMs = millis();
        partyStep = (partyStep + 1) % 6;

        switch(partyStep) {
          case 0: setColor(255,0,0); break;
          case 1: setColor(0,255,0); break;
          case 2: setColor(0,0,255); break;
          case 3: setColor(255,255,0); break;
          case 4: setColor(0,255,255); break;
          case 5: setColor(255,0,255); break;
        }
      }
      break;

    case OFF:
      setColor(0,0,0);
      break;
  }
}
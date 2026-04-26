#include <Arduino.h>

const int sensorPin = 2;
const int ledPin = 9;
const int buzzerPin = 8;

bool ledLigado = false;
int estadoAnterior = LOW;

unsigned long ultimoSom = 0;
const unsigned long tempoEspera = 500;

int melodia[] = {659, 659, 659, 659, 659, 659, 659, 784, 523, 587, 659};
int duracoes[] = {200,200,400,200,200,400,200,200,200,200,600};

int tamanhoMelodia = 11;

int notaAtual = 0;
unsigned long ultimoTempoNota = 0;

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  digitalWrite(ledPin, LOW);
}

void loop() {
  detectarPalma();
  tocarMusica();
}

void detectarPalma() {
  int estadoAtual = digitalRead(sensorPin);

  if (estadoAtual == HIGH && estadoAnterior == LOW) {
    if (millis() - ultimoSom > tempoEspera) {
      ledLigado = !ledLigado;

      digitalWrite(ledPin, ledLigado ? HIGH : LOW);

      if (!ledLigado) {
        noTone(buzzerPin);
      }

      ultimoSom = millis();
    }
  }

  estadoAnterior = estadoAtual;
}


void tocarMusica() {
  if (!ledLigado) return;

  unsigned long agora = millis();

  if (agora - ultimoTempoNota >= duracoes[notaAtual]) {

    tone(buzzerPin, melodia[notaAtual]);

    ultimoTempoNota = agora;
    notaAtual++;

    if (notaAtual >= tamanhoMelodia) {
      notaAtual = 0;
    }
  }
}
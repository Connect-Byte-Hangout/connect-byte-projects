#include <Arduino.h>

int bombaPin = 8;         // TIP120 na base (via resistor 1k).
int sensorUmidadePin = A0;    // saída analógica do sensor de umidade.
int limiteSeco = 1000;  // Maior que esse valor, quer dizer que o solo está seco.

// Aqui vamos pegar a média dos valores que o sensor de umidade lê
// Porque isso é importante? Para garantirmos uma leitura consistente, pois o sensor pode ter pequenas
// variações quando estiver lendo o solo.
int lerSensor() {
  int soma = 0;
  for (int i = 0; i < 10; i++) {
    soma += analogRead(A0);
    delay(10);
  }
  return soma / 10;
}

// Instruções para quando o Arduino liga pela primeira vez
void setup() {
  Serial.begin(9600);
  pinMode(bombaPin, OUTPUT);
  digitalWrite(bombaPin, LOW); // bomba desligada inicialmente
}

// Código que será executado em loop
void loop() {

  int leitura = lerSensor();
  Serial.print("Umidade: ");
  Serial.println(leitura);

  if (leitura > limiteSeco) {
    // solo seco → ligar bomba
    digitalWrite(bombaPin, HIGH);
  } else {
    // solo úmido → desligar bomba
    digitalWrite(bombaPin, LOW);
  }

  delay(2000); // 2 segundo
}

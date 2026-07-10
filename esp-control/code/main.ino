//#include <Arduino.h>
#include <HTTPClient.h>
#include <WiFi.h>
#include "config.h"

// 1. DEFINIÇÃO DOS PINOS (Onde as coisas estão ligadas)
const int BUTTON_A_PIN = 23;
const int BUTTON_B_PIN = 22;
const int BUTTON_C_PIN = 21;
const int BUTTON_D_PIN = 19;

const int LED_PIN    = 13;
const int BUZZER_PIN = 2;

// 2. CONFIGURAÇÃO DE TEMPO
const unsigned long DEBOUNCE_MS = 250;    // Tempo para evitar "clique duplo"
const unsigned long HEARTBEAT_MS = 10000;

// 3. MEMÓRIA DO PROGRAMA
unsigned long lastPressAt = 0;
unsigned long lastHeartbeatAt = 0;

bool previousA = HIGH;
bool previousB = HIGH;
bool previousC = HIGH;
bool previousD = HIGH;

// 4. FUNÇÕES DE COMUNICAÇÃO
String apiUrl(const char *path) {
#ifdef API_BASE_URL
  return String(API_BASE_URL) + path;
#else
  return String("http://") + API_HOST + ":" + String(API_PORT) + path;
#endif
}

String jsonPair(const char *key, const String &value) {
  return String("\"") + key + "\":\"" + value + "\"";
}

bool postJson(const char *path, const String &payload) {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi desconectado. Tentando reconectar...");
    WiFi.reconnect();
    return false;
  }

  HTTPClient http;
  http.begin(apiUrl(path));
  http.addHeader("Content-Type", "application/json");
  int statusCode = http.POST(payload);
  http.end();

  return statusCode >= 200 && statusCode < 300; // Retorna "verdadeiro" se deu tudo certo
}

void registerDevice() {
  String payload = "{" + jsonPair("deviceId", DEVICE_ID) + "," + jsonPair("teamName", TEAM_NAME) + "}";
  postJson("/devices/register", payload);
}

void sendHeartbeat() {
  String payload = "{" + jsonPair("deviceId", DEVICE_ID) + "}";
  postJson("/devices/heartbeat", payload);
}

// 5. Envia a resposta e dá o feedback
void sendAnswer(const char *resposta) {
  digitalWrite(LED_PIN, HIGH); // Acende o LED
  tone(BUZZER_PIN, 1000);      // Toca o buzzer
  
  delay(150);
  
  digitalWrite(LED_PIN, LOW);  // Apaga o LED
  noTone(BUZZER_PIN);          // Desliga o som

  String payload = "{" + jsonPair("deviceId", DEVICE_ID) + "," + jsonPair("answer", resposta) + "}";
  postJson("/answers", payload); 
}

void connectWifi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Conectando no Wi-Fi...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Wi-Fi conectado. IP do ESP32: ");
  Serial.println(WiFi.localIP());
}

void setup() {
  Serial.begin(115200);
  
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  
  pinMode(BUTTON_A_PIN, INPUT_PULLUP);
  pinMode(BUTTON_B_PIN, INPUT_PULLUP);
  pinMode(BUTTON_C_PIN, INPUT_PULLUP);
  pinMode(BUTTON_D_PIN, INPUT_PULLUP);

  connectWifi();
  registerDevice();
  sendHeartbeat();
}

void loop() {
  unsigned long now = millis();

  bool currentA = digitalRead(BUTTON_A_PIN);
  bool currentB = digitalRead(BUTTON_B_PIN);
  bool currentC = digitalRead(BUTTON_C_PIN);
  bool currentD = digitalRead(BUTTON_D_PIN);

  // 6. Lógica dos Botões
  if (previousA == HIGH && currentA == LOW && now - lastPressAt > DEBOUNCE_MS) {
    lastPressAt = now; // Atualiza a hora do último clique
    Serial.println("Botão A pressionado!");
    sendAnswer("A");
  }

  if (previousB == HIGH && currentB == LOW && now - lastPressAt > DEBOUNCE_MS) {
    lastPressAt = now;
    Serial.println("Botão B pressionado!");
    sendAnswer("B");
  }

  if (previousC == HIGH && currentC == LOW && now - lastPressAt > DEBOUNCE_MS) {
    lastPressAt = now;
    Serial.println("Botão C pressionado!");
    sendAnswer("C");
  }

  if (previousD == HIGH && currentD == LOW && now - lastPressAt > DEBOUNCE_MS) {
    lastPressAt = now;
    Serial.println("Botão D pressionado!");
    sendAnswer("D");
  }

  previousA = currentA;
  previousB = currentB;
  previousC = currentC;
  previousD = currentD;

  if (now - lastHeartbeatAt > HEARTBEAT_MS) {
    lastHeartbeatAt = now;
    sendHeartbeat();
  }

  delay(20);
}
#include <Arduino.h>

#include <WiFi.h>
#include <WiFiManager.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <Preferences.h>

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// =====================================================
// TIPO DE DISPLAY
// =====================================================

// true  = OLED-B 0.91" 128x32
// false = OLED 128x64
#define OLED_128X32 false

// =====================================================
// OLED
// =====================================================

#define SDA_PIN 4
#define SCL_PIN 3

#define SCREEN_WIDTH 128

#if OLED_128X32
    #define SCREEN_HEIGHT 32
#else
    #define SCREEN_HEIGHT 64
#endif

#define OLED_RESET -1
#define OLED_ADDRESS 0x3C

Adafruit_SSD1306 display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    OLED_RESET
);

// =====================================================
// BOOT
// =====================================================

#define BOOT_BUTTON_PIN 9
#define LONG_PRESS_TIME 5000

// =====================================================
// LED
// =====================================================

#define STATUS_LED_PIN 5

// =====================================================
// API - PRODUÇÃO
// =====================================================

const char* API_URL =
    "API_URL";

// =====================================================
// NVS / DEVICE IDENTITY
// =====================================================

Preferences preferences;

String deviceId = "";
String deviceToken = "";

// =====================================================
// PLANNER DATA
// =====================================================

float saved = 0;
float goal = 0;
int percentage = 0;

// =====================================================
// LED
// =====================================================

void ledOff() {
    digitalWrite(STATUS_LED_PIN, LOW);
}

void ledOn() {
    digitalWrite(STATUS_LED_PIN, HIGH);
}

void ledFeedback() {
    ledOn();
    delay(100);
    ledOff();
}

void ledSuccess() {
    for (int i = 0; i < 2; i++) {
        ledOn();
        delay(150);
        ledOff();
        delay(150);
    }
}

void ledError() {
    for (int i = 0; i < 3; i++) {
        ledOn();
        delay(250);
        ledOff();
        delay(250);
    }
}

// =====================================================
// OLED - MENSAGEM
// =====================================================

void showMessage(
    const String& line1,
    const String& line2 = ""
) {
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);

#if OLED_128X32

    display.setCursor(0, 5);
    display.println(line1);

    if (line2.length() > 0) {
        display.setCursor(0, 18);
        display.println(line2);
    }

#else

    display.setCursor(0, 10);
    display.println(line1);

    if (line2.length() > 0) {
        display.setCursor(0, 30);
        display.println(line2);
    }

#endif

    display.display();
}

// =====================================================
// OLED - PLANNER
// =====================================================

void showPlanner() {

    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);

    int safePercentage =
        constrain(percentage, 0, 100);

#if OLED_128X32

    // =================================================
    // LAYOUT 128x32
    // =================================================

    display.setTextSize(1);

    // Linha 1
    display.setCursor(0, 0);
    display.print("R$ ");
    display.print(saved, 0);

    display.setCursor(96, 0);
    display.print(safePercentage);
    display.print("%");

    // Linha 2
    display.setCursor(0, 11);
    display.print("Meta R$ ");
    display.print(goal, 0);

    // Barra
    const int barX = 0;
    const int barY = 23;
    const int barWidth = 128;
    const int barHeight = 8;

    display.drawRect(
        barX,
        barY,
        barWidth,
        barHeight,
        SSD1306_WHITE
    );

    int progressWidth =
        ((barWidth - 2) * safePercentage) / 100;

    display.fillRect(
        barX + 1,
        barY + 1,
        progressWidth,
        barHeight - 2,
        SSD1306_WHITE
    );

#else

    // =================================================
    // LAYOUT 128x64
    // =================================================

    display.setTextSize(1);

    display.setCursor(0, 0);
    display.println("CONNECT BYTE");

    // GUARDADO
    display.setCursor(0, 14);
    display.println("Guardado");

    display.setTextSize(2);
    display.setCursor(0, 24);

    display.print("R$ ");
    display.print(saved, 0);

    // META
    display.setTextSize(1);
    display.setCursor(0, 44);

    display.print("Meta R$ ");
    display.print(goal, 0);

    // BARRA
    const int barX = 0;
    const int barY = 55;
    const int barWidth = 95;
    const int barHeight = 8;

    display.drawRect(
        barX,
        barY,
        barWidth,
        barHeight,
        SSD1306_WHITE
    );

    int progressWidth =
        ((barWidth - 2) * safePercentage) / 100;

    display.fillRect(
        barX + 1,
        barY + 1,
        progressWidth,
        barHeight - 2,
        SSD1306_WHITE
    );

    // PORCENTAGEM
    display.setCursor(100, 55);
    display.print(safePercentage);
    display.print("%");

#endif

    display.display();
}

// =====================================================
// REINICIALIZAR OLED
// =====================================================

bool reinitializeDisplay() {

    Serial.println();
    Serial.println(
        "Reinicializando OLED apos HTTPS..."
    );

    delay(100);

    Wire.end();
    delay(50);

    Wire.begin(
        SDA_PIN,
        SCL_PIN
    );

    delay(50);

    if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
    )) {

        Serial.println(
            "ERRO reinicializando OLED!"
        );

        return false;
    }

    display.clearDisplay();
    display.display();

    delay(50);

    Serial.println(
        "OLED reinicializado."
    );

    return true;
}

// =====================================================
// SERIAL INPUT
// =====================================================

String readSerialLine() {

    String value = "";

    while (true) {

        if (Serial.available()) {

            char c = Serial.read();

            if (
                c == '\n' ||
                c == '\r'
            ) {

                if (value.length() > 0) {

                    value.trim();
                    return value;
                }

            } else {

                value += c;
            }
        }

        delay(10);
    }
}

// =====================================================
// LOAD DEVICE IDENTITY
// =====================================================

bool loadDeviceIdentity() {

    preferences.begin(
        "cb-planner",
        true
    );

    deviceId =
        preferences.getString(
            "deviceId",
            ""
        );

    deviceToken =
        preferences.getString(
            "token",
            ""
        );

    preferences.end();

    return (
        deviceId.length() > 0 &&
        deviceToken.length() > 0
    );
}

// =====================================================
// SAVE DEVICE IDENTITY
// =====================================================

bool saveDeviceIdentity(
    const String& newDeviceId,
    const String& newToken
) {

    preferences.begin(
        "cb-planner",
        false
    );

    size_t idResult =
        preferences.putString(
            "deviceId",
            newDeviceId
        );

    size_t tokenResult =
        preferences.putString(
            "token",
            newToken
        );

    preferences.end();

    return (
        idResult > 0 &&
        tokenResult > 0
    );
}

// =====================================================
// PROVISION DEVICE
// =====================================================

void provisionDevice() {

    Serial.println();
    Serial.println(
        "================================"
    );
    Serial.println(
        "CONNECT BYTE PLANNER"
    );
    Serial.println(
        "DEVICE NOT PROVISIONED"
    );
    Serial.println(
        "================================"
    );

    showMessage(
        "Device sem ID",
        "Abra o Serial"
    );

    // DEVICE ID

    Serial.println();
    Serial.println(
        "Enter Device ID:"
    );
    Serial.println(
        "Example: CB-FIN-001"
    );
    Serial.print("> ");

    String newDeviceId =
        readSerialLine();

    newDeviceId.trim();

    Serial.println();
    Serial.print(
        "Device ID received: "
    );
    Serial.println(
        newDeviceId
    );

    // TOKEN

    Serial.println();
    Serial.println(
        "Enter Device Token:"
    );
    Serial.println(
        "(the token will NOT be printed)"
    );
    Serial.print("> ");

    String newToken =
        readSerialLine();

    newToken.trim();

    // SALVAR

    bool savedSuccessfully =
        saveDeviceIdentity(
            newDeviceId,
            newToken
        );

    if (!savedSuccessfully) {

        Serial.println();
        Serial.println(
            "ERROR saving device identity."
        );

        showMessage(
            "Erro ao salvar",
            "Reinicie"
        );

        ledError();

        while (true) {
            delay(1000);
        }
    }

    deviceId = newDeviceId;
    deviceToken = newToken;

    Serial.println();
    Serial.println(
        "================================"
    );
    Serial.println(
        "DEVICE PROVISIONED"
    );
    Serial.println(
        "================================"
    );

    Serial.print(
        "Device: "
    );
    Serial.println(
        deviceId
    );

    Serial.println(
        "Token: ********"
    );

    Serial.println(
        "Identity saved in ESP32 NVS."
    );

    Serial.println(
        "================================"
    );

    showMessage(
        "Device configurado!",
        deviceId
    );

    ledSuccess();

    delay(2000);
}

// =====================================================
// DEVICE INFO
// =====================================================

void printDeviceInfo() {

    Serial.println();
    Serial.println(
        "================================"
    );
    Serial.println(
        "DEVICE INFO"
    );
    Serial.println(
        "================================"
    );

    Serial.print(
        "Device ID: "
    );
    Serial.println(
        deviceId
    );

    Serial.print(
        "Provisioned: "
    );

    if (
        deviceId.length() > 0 &&
        deviceToken.length() > 0
    ) {
        Serial.println("YES");
    } else {
        Serial.println("NO");
    }

    Serial.println(
        "Token: ********"
    );

    Serial.print(
        "WiFi: "
    );

    if (
        WiFi.status() ==
        WL_CONNECTED
    ) {

        Serial.println(
            WiFi.SSID()
        );

    } else {

        Serial.println(
            "Disconnected"
        );
    }

    Serial.print(
        "Backend: "
    );
    Serial.println(
        API_URL
    );

    Serial.print(
        "OLED: "
    );

#if OLED_128X32
    Serial.println("128x32");
#else
    Serial.println("128x64");
#endif

    Serial.println(
        "================================"
    );
}

// =====================================================
// RESET DEVICE IDENTITY
// =====================================================

void resetDeviceIdentity() {

    Serial.println();
    Serial.println(
        "Resetting device identity..."
    );

    preferences.begin(
        "cb-planner",
        false
    );

    preferences.remove(
        "deviceId"
    );

    preferences.remove(
        "token"
    );

    preferences.end();

    deviceId = "";
    deviceToken = "";

    Serial.println(
        "Device identity removed."
    );

    Serial.println(
        "WiFi credentials were NOT removed."
    );

    showMessage(
        "Device resetado",
        "Reiniciando..."
    );

    ledSuccess();

    delay(2000);

    ESP.restart();
}

// =====================================================
// FETCH PLANNER DATA
// =====================================================

bool fetchPlannerData() {

    Serial.println();
    Serial.println(
        "=============================="
    );
    Serial.println(
        "ATUALIZANDO PLANNER"
    );
    Serial.println(
        "=============================="
    );

    // WI-FI

    if (
        WiFi.status() !=
        WL_CONNECTED
    ) {

        Serial.println(
            "Wi-Fi desconectado."
        );

        return false;
    }

    // TOKEN

    if (
        deviceToken.length() == 0
    ) {

        Serial.println(
            "Device token ausente."
        );

        return false;
    }

    Serial.print(
        "Device: "
    );
    Serial.println(
        deviceId
    );

    Serial.print(
        "Wi-Fi: "
    );
    Serial.println(
        WiFi.SSID()
    );

    Serial.print(
        "IP ESP32: "
    );
    Serial.println(
        WiFi.localIP()
    );

    Serial.print(
        "API: "
    );
    Serial.println(
        API_URL
    );

    // HTTP

    HTTPClient http;

    http.begin(
        API_URL
    );

    http.addHeader(
        "Authorization",
        String("Bearer ") +
        deviceToken
    );

    Serial.println();
    Serial.println(
        "Enviando requisicao autenticada..."
    );

    int statusCode =
        http.GET();

    Serial.print(
        "HTTP Status: "
    );
    Serial.println(
        statusCode
    );

    // ERRO

    if (
        statusCode != 200
    ) {

        Serial.println();
        Serial.println(
            "Erro consultando backend."
        );

        if (
            statusCode > 0
        ) {

            String errorResponse =
                http.getString();

            Serial.print(
                "Resposta: "
            );

            Serial.println(
                errorResponse
            );

        } else {

            Serial.print(
                "Erro HTTP: "
            );

            Serial.println(
                http.errorToString(
                    statusCode
                )
            );
        }

        http.end();

        return false;
    }

    // RESPOSTA

    String response =
        http.getString();

    http.end();

    Serial.println();
    Serial.println(
        "Resposta da API:"
    );
    Serial.println(
        response
    );

    // JSON

    JsonDocument doc;

    DeserializationError error =
        deserializeJson(
            doc,
            response
        );

    if (error) {

        Serial.println();
        Serial.print(
            "Erro JSON: "
        );

        Serial.println(
            error.c_str()
        );

        return false;
    }

    // DADOS

    String responseDeviceId =
        doc["deviceId"].as<String>();

    saved =
        doc["saved"].as<float>();

    goal =
        doc["goal"].as<float>();

    percentage =
        doc["percentage"].as<int>();

    // DEBUG

    Serial.println();
    Serial.println(
        "=============================="
    );
    Serial.println(
        "DADOS DO PLANNER"
    );
    Serial.println(
        "=============================="
    );

    Serial.print(
        "Device ID: "
    );
    Serial.println(
        responseDeviceId
    );

    Serial.print(
        "Guardado: R$ "
    );
    Serial.println(
        saved,
        2
    );

    Serial.print(
        "Meta: R$ "
    );
    Serial.println(
        goal,
        2
    );

    Serial.print(
        "Progresso: "
    );
    Serial.print(
        percentage
    );
    Serial.println("%");

    Serial.println(
        "=============================="
    );

    return true;
}

// =====================================================
// UPDATE PLANNER
// =====================================================

void updatePlanner() {

    Serial.println();
    Serial.println(
        "Atualizacao solicitada!"
    );

    showMessage(
        "Atualizando...",
        "Aguarde"
    );

    ledOn();

    bool success =
        fetchPlannerData();

    ledOff();

    // Aguarda atividade HTTPS/Wi-Fi terminar
    delay(200);

    // Reinicializa o OLED para evitar
    // ficar preso em "Atualizando..."
    bool displayReady =
        reinitializeDisplay();

    if (!displayReady) {

        Serial.println(
            "OLED nao respondeu apos atualizacao."
        );

        ledError();

        return;
    }

    if (success) {

        showPlanner();

        Serial.println();
        Serial.println(
            "OLED atualizado!"
        );

        ledSuccess();

        // Garante frame final
        showPlanner();

    } else {

        showMessage(
            "Erro ao atualizar",
            "Tente novamente"
        );

        Serial.println();
        Serial.println(
            "Nao foi possivel atualizar."
        );

        ledError();

        showMessage(
            "Erro ao atualizar",
            "Tente novamente"
        );
    }

    ledOff();
}

// =====================================================
// WI-FI CONFIG PORTAL
// =====================================================

void startConfigPortal() {

    Serial.println();
    Serial.println(
        "=============================="
    );
    Serial.println(
        "MODO CONFIGURACAO WI-FI"
    );
    Serial.println(
        "=============================="
    );

    showMessage(
        "Configurar Wi-Fi",
        "ConnectByte-Planner"
    );

    ledOn();

    WiFi.setTxPower(
        WIFI_POWER_8_5dBm
    );

    WiFiManager wm;

    wm.setConfigPortalTimeout(
        300
    );

    bool connected =
        wm.startConfigPortal(
            "ConnectByte-Planner",
            "12345678"
        );

    ledOff();

    if (connected) {

        Serial.println();
        Serial.println(
            "WI-FI CONFIGURADO!"
        );

        Serial.print(
            "Rede: "
        );
        Serial.println(
            WiFi.SSID()
        );

        Serial.print(
            "IP: "
        );
        Serial.println(
            WiFi.localIP()
        );

        showMessage(
            "Wi-Fi conectado!",
            WiFi.SSID()
        );

        ledSuccess();

        delay(1000);

        updatePlanner();

    } else {

        Serial.println();
        Serial.println(
            "Portal encerrado."
        );

        showMessage(
            "Wi-Fi",
            "Portal encerrado"
        );

        ledError();

        delay(1000);

        showPlanner();
    }

    ledOff();
}

// =====================================================
// SERIAL COMMANDS
// =====================================================

void handleSerialCommands() {

    if (!Serial.available()) {
        return;
    }

    String command =
        Serial.readStringUntil('\n');

    command.trim();
    command.toUpperCase();

    if (
        command == "INFO"
    ) {

        printDeviceInfo();

    } else if (
        command ==
        "RESET_DEVICE"
    ) {

        resetDeviceIdentity();

    } else if (
        command ==
        "UPDATE"
    ) {

        updatePlanner();

    } else if (
        command.length() > 0
    ) {

        Serial.println();
        Serial.println(
            "Unknown command."
        );

        Serial.println(
            "Commands: INFO, UPDATE, RESET_DEVICE"
        );
    }
}

// =====================================================
// SETUP
// =====================================================

void setup() {

    Serial.begin(
        115200
    );

    delay(2000);

    Serial.println();
    Serial.println(
        "=============================="
    );
    Serial.println(
        "CONNECT BYTE PLANNER"
    );
    Serial.println(
        "=============================="
    );

    // =================================================
    // LED
    // =================================================

    pinMode(
        STATUS_LED_PIN,
        OUTPUT
    );

    ledOff();
    ledFeedback();

    // =================================================
    // BOOT
    // =================================================

    pinMode(
        BOOT_BUTTON_PIN,
        INPUT_PULLUP
    );

    // =================================================
    // OLED
    // =================================================

    Wire.begin(
        SDA_PIN,
        SCL_PIN
    );

    if (!display.begin(
        SSD1306_SWITCHCAPVCC,
        OLED_ADDRESS
    )) {

        Serial.println(
            "ERRO iniciando OLED!"
        );

        ledError();

        while (true) {
            delay(1000);
        }
    }

    display.clearDisplay();
    display.display();

    showMessage(
        "CONNECT BYTE",
        "Iniciando..."
    );

    // =================================================
    // DEVICE IDENTITY
    // =================================================

    bool provisioned =
        loadDeviceIdentity();

    if (!provisioned) {

        provisionDevice();

    } else {

        Serial.println();
        Serial.println(
            "Device identity loaded from NVS."
        );

        Serial.print(
            "Device: "
        );
        Serial.println(
            deviceId
        );

        Serial.println(
            "Token: ********"
        );
    }

    // =================================================
    // WI-FI
    // =================================================

    WiFi.mode(
        WIFI_STA
    );

    WiFi.setTxPower(
        WIFI_POWER_8_5dBm
    );

    WiFiManager wm;

    showMessage(
        "Wi-Fi",
        "Conectando..."
    );

    ledOn();

    bool connected =
        wm.autoConnect(
            "ConnectByte-Planner",
            "12345678"
        );

    ledOff();

    if (!connected) {

        Serial.println(
            "Falha Wi-Fi."
        );

        showMessage(
            "Erro Wi-Fi",
            "Reiniciando..."
        );

        ledError();

        delay(3000);

        ESP.restart();
    }

    // =================================================
    // CONNECTED
    // =================================================

    Serial.println();
    Serial.println(
        "=============================="
    );
    Serial.println(
        "WIFI CONECTADO"
    );
    Serial.println(
        "=============================="
    );

    Serial.print(
        "Rede: "
    );
    Serial.println(
        WiFi.SSID()
    );

    Serial.print(
        "IP ESP32: "
    );
    Serial.println(
        WiFi.localIP()
    );

    Serial.println(
        "=============================="
    );

    printDeviceInfo();

    // =================================================
    // FIRST UPDATE
    // =================================================

    updatePlanner();
}

// =====================================================
// LOOP
// =====================================================

void loop() {

    static bool buttonWasPressed =
        false;

    static unsigned long
        pressStartTime = 0;

    static bool longPressHandled =
        false;

    // =================================================
    // SERIAL COMMANDS
    // =================================================

    handleSerialCommands();

    // =================================================
    // BOOT
    // =================================================

    bool buttonPressed =
        digitalRead(
            BOOT_BUTTON_PIN
        ) == LOW;

    // -------------------------------------------------
    // COMECOU A PRESSIONAR
    // -------------------------------------------------

    if (
        buttonPressed &&
        !buttonWasPressed
    ) {

        buttonWasPressed =
            true;

        longPressHandled =
            false;

        pressStartTime =
            millis();

        Serial.println();
        Serial.println(
            "BOOT pressionado..."
        );

        ledFeedback();
    }

    // -------------------------------------------------
    // CONTINUA PRESSIONANDO
    // -------------------------------------------------

    if (
        buttonPressed &&
        buttonWasPressed &&
        !longPressHandled
    ) {

        unsigned long
            pressDuration =
                millis() -
                pressStartTime;

        if (
            pressDuration >=
            LONG_PRESS_TIME
        ) {

            longPressHandled =
                true;

            Serial.println();
            Serial.println(
                "=============================="
            );

            Serial.println(
                "BOOT SEGURADO POR 5 SEGUNDOS"
            );

            Serial.println(
                "=============================="
            );

            startConfigPortal();
        }
    }

    // -------------------------------------------------
    // SOLTOU
    // -------------------------------------------------

    if (
        !buttonPressed &&
        buttonWasPressed
    ) {

        buttonWasPressed =
            false;

        if (
            !longPressHandled
        ) {

            unsigned long
                pressDuration =
                    millis() -
                    pressStartTime;

            if (
                pressDuration >= 50
            ) {

                Serial.println();
                Serial.println(
                    "=============================="
                );

                Serial.println(
                    "CLIQUE CURTO NO BOOT"
                );

                Serial.println(
                    "=============================="
                );

                // Deixa GPIO9 estabilizar
                delay(150);

                updatePlanner();
            }
        }

        longPressHandled =
            false;

        delay(50);
    }

    delay(10);
}

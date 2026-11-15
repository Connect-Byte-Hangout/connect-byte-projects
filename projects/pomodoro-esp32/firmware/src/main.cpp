
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <esp_system.h>

// ==========================================
// POMODORO - ESP32-C3 SUPERMINI
// OLED SSD1306 128x32
// ==========================================

#define PIN_SDA 4
#define PIN_SCL 5
#define BTN_1 0
#define BTN_2 1
#define PIN_BUZZER 7

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_ADDRESS 0x3C

#define BUZZER_CHANNEL 0
#define BUZZER_RESOLUTION 8

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

// ==========================================
// CONFIGURACOES
// ==========================================

const uint8_t workChoices[] = {
  25, 30, 45, 50, 60, 1, 5, 10, 15, 20
};

const uint8_t breakChoices[] = {
  5, 10, 15, 1, 2, 3
};

const int WORK_COUNT =
  sizeof(workChoices) / sizeof(workChoices[0]);

const int BREAK_COUNT =
  sizeof(breakChoices) / sizeof(breakChoices[0]);

int workIndex = 0;
int breakIndex = 0;

uint32_t workSeconds = 25 * 60;
uint32_t breakSeconds = 5 * 60;

uint32_t remainingSeconds = 25 * 60;
uint32_t totalSeconds = 25 * 60;

int currentCycle = 1;
const int TOTAL_CYCLES = 4;

bool soundEnabled = true;
bool screenDirty = true;

unsigned long lastTick = 0;
unsigned long soundMessageUntil = 0;

// ==========================================
// ESTADOS
// ==========================================

enum State {
  IDLE,
  WORKING,
  BREAKING,
  PAUSED,
  CHOICE_WORK,
  CHOICE_BREAK,
  SET_WORK,
  SET_BREAK
};

State state = IDLE;
State pausedFrom = WORKING;

// ==========================================
// BOTOES
// ==========================================

const unsigned long DEBOUNCE_MS = 70;
const unsigned long MENU_PRESS_MS = 1000;
const unsigned long SOUND_PRESS_MS = 2000;

struct Button {
  uint8_t pin;
  bool stable;
  bool lastReading;
  bool handled;
  unsigned long changedAt;
  unsigned long pressedAt;
};

Button b1 = {BTN_1, HIGH, HIGH, false, 0, 0};
Button b2 = {BTN_2, HIGH, HIGH, false, 0, 0};

// ==========================================
// BUZZER - SOMENTE ledcWriteTone
// ==========================================

enum SoundType {
  SOUND_NONE,
  SOUND_CLICK,
  SOUND_PAUSE,
  SOUND_FINISH
};

SoundType currentSound = SOUND_NONE;

unsigned long soundTick = 0;
int soundStep = 0;

const uint16_t clickNotes[] = {
  2000
};

const uint16_t clickTimes[] = {
  180
};

const uint16_t pauseNotes[] = {
  2000, 0, 2000
};

const uint16_t pauseTimes[] = {
  200, 120, 200
};

const uint16_t finishNotes[] = {
  2000, 0,
  2400, 0,
  2800, 0,
  2000, 0,
  2400, 0,
  2800, 0,
  3000
};

const uint16_t finishTimes[] = {
  200, 60,
  200, 60,
  300, 60,
  200, 60,
  200, 60,
  300, 60,
  1100
};

const uint16_t* activeNotes = nullptr;
const uint16_t* activeTimes = nullptr;
int noteCount = 0;

// Unico metodo utilizado para controlar o buzzer
void buzzerTone(uint16_t frequency) {
  if (!soundEnabled || frequency == 0) {
    ledcWriteTone(BUZZER_CHANNEL, 0);
    return;
  }

  ledcWriteTone(BUZZER_CHANNEL, frequency);
}

void stopSound() {
  ledcWriteTone(BUZZER_CHANNEL, 0);

  currentSound = SOUND_NONE;
  soundStep = 0;
  noteCount = 0;
  activeNotes = nullptr;
  activeTimes = nullptr;
}

void startSound(SoundType type) {
  stopSound();

  if (!soundEnabled || type == SOUND_NONE) {
    return;
  }

  currentSound = type;

  switch (type) {
    case SOUND_CLICK:
      activeNotes = clickNotes;
      activeTimes = clickTimes;
      noteCount = 1;
      break;

    case SOUND_PAUSE:
      activeNotes = pauseNotes;
      activeTimes = pauseTimes;
      noteCount = 3;
      break;

    case SOUND_FINISH:
      activeNotes = finishNotes;
      activeTimes = finishTimes;
      noteCount =
        sizeof(finishNotes) / sizeof(finishNotes[0]);
      break;

    default:
      stopSound();
      return;
  }

  soundStep = 0;
  soundTick = millis();

  buzzerTone(activeNotes[0]);

  Serial.print("Som iniciado: ");
  Serial.println((int)type);
}

void updateSound() {
  if (currentSound == SOUND_NONE) return;

  unsigned long now = millis();

  if (now - soundTick <
      (unsigned long)activeTimes[soundStep]) {
    return;
  }

  soundStep++;

  if (soundStep >= noteCount) {
    stopSound();
    return;
  }

  soundTick = now;
  buzzerTone(activeNotes[soundStep]);
}

// ==========================================
// TESTE INICIAL IGUAL AO QUE FUNCIONOU
// ==========================================

void testBuzzer() {
  Serial.println("TESTE BUZZER: 2000 Hz");

  ledcWriteTone(BUZZER_CHANNEL, 2000);
  delay(2000);

  ledcWriteTone(BUZZER_CHANNEL, 0);
  delay(500);

  Serial.println("TESTE BUZZER FINALIZADO");
}

// ==========================================
// CRONOMETRO
// ==========================================

bool isRunning() {
  return state == WORKING || state == BREAKING;
}

void setState(State nextState) {
  state = nextState;
  screenDirty = true;

  Serial.print("Estado: ");
  Serial.println((int)state);
}

void resetTimer() {
  currentCycle = 1;
  remainingSeconds = workSeconds;
  totalSeconds = workSeconds;
  lastTick = millis();

  setState(IDLE);
}

void startWork() {
  remainingSeconds = workSeconds;
  totalSeconds = workSeconds;
  lastTick = millis();

  setState(WORKING);
}

void startBreak() {
  remainingSeconds = breakSeconds;
  totalSeconds = breakSeconds;
  lastTick = millis();

  setState(BREAKING);
}

void pauseTimer() {
  if (!isRunning()) return;

  pausedFrom = state;
  setState(PAUSED);

  startSound(SOUND_PAUSE);
}

void resumeTimer() {
  if (state != PAUSED) return;

  lastTick = millis();
  setState(pausedFrom);

  startSound(SOUND_CLICK);
}

void finishTimer() {
  bool wasWorking = state == WORKING;

  remainingSeconds = 0;

  setState(
    wasWorking ? CHOICE_WORK : CHOICE_BREAK
  );

  startSound(SOUND_FINISH);

  Serial.println("CRONOMETRO FINALIZADO");
}

// ==========================================
// DISPLAY
// ==========================================

void renderTimer() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);

  if (state == IDLE) {
    display.print("PRONTO");
  } else if (state == WORKING) {
    display.print("FOCO");
  } else if (state == BREAKING) {
    display.print("PAUSA");
  } else if (state == PAUSED) {
    display.print("PAUSADO");
  }

  display.setCursor(95, 0);
  display.print(currentCycle);
  display.print("/");
  display.print(TOTAL_CYCLES);

  char buffer[12];

  snprintf(
    buffer,
    sizeof(buffer),
    "%02lu:%02lu",
    (unsigned long)(remainingSeconds / 60),
    (unsigned long)(remainingSeconds % 60)
  );

  display.setTextSize(2);
  display.setCursor(34, 10);
  display.print(buffer);

  display.drawRect(0, 28, 128, 4, SSD1306_WHITE);

  if (totalSeconds > 0) {
    uint32_t elapsed =
      totalSeconds - remainingSeconds;

    int progress =
      (elapsed * 124UL) / totalSeconds;

    progress = constrain(progress, 0, 124);

    if (progress > 0) {
      display.fillRect(
        2, 30, progress, 1,
        SSD1306_WHITE
      );
    }
  }

  display.display();
}

void renderChoice() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  if (state == CHOICE_WORK) {
    display.setCursor(0, 0);
    display.print("FOCO CONCLUIDO!");

    display.setCursor(0, 12);
    display.print("B2: Fazer pausa");

    display.setCursor(0, 23);
    display.print("B1: Novo foco");
  } else {
    display.setCursor(0, 0);
    display.print("DESCANSO ACABOU!");

    display.setCursor(0, 12);
    display.print("B2: Novo foco");

    display.setCursor(0, 23);
    display.print("B1: Mais pausa");
  }

  display.display();
}

void renderSettings() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);

  int minutes;

  if (state == SET_WORK) {
    display.print("AJUSTAR FOCO");
    minutes = workChoices[workIndex];
  } else {
    display.print("AJUSTAR PAUSA");
    minutes = breakChoices[breakIndex];
  }

  display.setTextSize(2);
  display.setCursor(0, 12);
  display.print(minutes);
  display.print("m");

  display.setTextSize(1);
  display.setCursor(76, 12);
  display.print("B2:+");

  display.setCursor(76, 23);
  display.print("B1:OK");

  display.display();
}

void renderSoundStatus() {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);

  display.setCursor(18, 3);
  display.print("CONFIGURACAO");

  display.setCursor(18, 18);
  display.print(
    soundEnabled ? "SOM LIGADO" : "SOM DESLIGADO"
  );

  display.display();
}

void renderUI() {
  if (soundMessageUntil != 0 &&
      (long)(millis() - soundMessageUntil) < 0) {
    renderSoundStatus();
    return;
  }

  if (state == CHOICE_WORK ||
      state == CHOICE_BREAK) {
    renderChoice();
  } else if (state == SET_WORK ||
             state == SET_BREAK) {
    renderSettings();
  } else {
    renderTimer();
  }
}

// ==========================================
// CONTROLE DO SOM
// ==========================================

void toggleSound() {
  soundEnabled = !soundEnabled;

  stopSound();

  soundMessageUntil = millis() + 1200;
  screenDirty = true;

  Serial.println(
    soundEnabled ? "SOM ON" : "SOM OFF"
  );

  if (soundEnabled) {
    startSound(SOUND_CLICK);
  }
}

// ==========================================
// B1 - RESET / MENU / OPCAO 2
// ==========================================

void onButton1() {
  stopSound();

  Serial.println("ACAO B1");

  switch (state) {
    case CHOICE_WORK:
      startWork();
      break;

    case CHOICE_BREAK:
      startBreak();
      break;

    case SET_WORK:
      setState(SET_BREAK);
      break;

    case SET_BREAK:
      workSeconds = workChoices[workIndex] * 60UL;
      breakSeconds = breakChoices[breakIndex] * 60UL;
      resetTimer();
      break;

    default:
      resetTimer();
      break;
  }

  startSound(SOUND_CLICK);
  screenDirty = true;
}

// ==========================================
// B2 - PLAY / PAUSE / OPCAO 1
// ==========================================

void onButton2() {
  stopSound();

  Serial.println("ACAO B2");

  switch (state) {
    case CHOICE_WORK:
      startBreak();
      break;

    case CHOICE_BREAK:
      currentCycle++;

      if (currentCycle > TOTAL_CYCLES) {
        currentCycle = 1;
      }

      startWork();
      break;

    case SET_WORK:
      workIndex = (workIndex + 1) % WORK_COUNT;
      break;

    case SET_BREAK:
      breakIndex = (breakIndex + 1) % BREAK_COUNT;
      break;

    case IDLE:
      startWork();
      break;

    case WORKING:
    case BREAKING:
      pauseTimer();
      return;

    case PAUSED:
      resumeTimer();
      return;
  }

  startSound(SOUND_CLICK);
  screenDirty = true;
}

// ==========================================
// LEITURA DOS BOTOES
// ==========================================

void updateButton(Button &button, bool isB1) {
  unsigned long now = millis();
  bool reading = digitalRead(button.pin);

  if (reading != button.lastReading) {
    button.lastReading = reading;
    button.changedAt = now;
  }

  if (now - button.changedAt < DEBOUNCE_MS) {
    return;
  }

  // Mudanca estabilizada
  if (reading != button.stable) {
    button.stable = reading;

    if (reading == LOW) {
      button.pressedAt = now;
      button.handled = false;

      Serial.println(
        isB1 ? "B1 DOWN" : "B2 DOWN"
      );

      // Executa escolhas imediatamente
      if (state == CHOICE_WORK ||
          state == CHOICE_BREAK) {
        button.handled = true;

        if (isB1) {
          onButton1();
        } else {
          onButton2();
        }
      }

      return;
    }

    // Soltou o botao
    Serial.println(
      isB1 ? "B1 UP" : "B2 UP"
    );

    if (button.handled) {
      button.handled = false;
      return;
    }

    if (isB1) {
      onButton1();
    } else {
      onButton2();
    }

    return;
  }

  // Pressionamento longo
  if (button.stable == LOW &&
      !button.handled &&
      state == IDLE) {

    unsigned long duration = now - button.pressedAt;

    if (isB1 && duration >= MENU_PRESS_MS) {
      button.handled = true;
      setState(SET_WORK);
      startSound(SOUND_CLICK);
    } else if (!isB1 &&
               duration >= SOUND_PRESS_MS) {
      button.handled = true;
      toggleSound();
    }
  }
}

// ==========================================
// SETUP
// ==========================================

void setup() {
  Serial.begin(115200);
  delay(300);

  Serial.println("POMODORO - ESP32-C3");
  Serial.print("Reset reason: ");
  Serial.println((int)esp_reset_reason());

  // BUZZER PRIMEIRO
  // Mesmo procedimento do teste que tocou
  ledcSetup(BUZZER_CHANNEL, 2000, BUZZER_RESOLUTION);
  ledcAttachPin(PIN_BUZZER, BUZZER_CHANNEL);

  testBuzzer();

  // BOTOES
  pinMode(BTN_1, INPUT_PULLUP);
  pinMode(BTN_2, INPUT_PULLUP);

  b1.stable = digitalRead(BTN_1);
  b1.lastReading = b1.stable;
  b1.changedAt = millis();

  b2.stable = digitalRead(BTN_2);
  b2.lastReading = b2.stable;
  b2.changedAt = millis();

  // DISPLAY
  Wire.begin(PIN_SDA, PIN_SCL);
  Wire.setClock(100000);

  if (!display.begin(
    SSD1306_SWITCHCAPVCC,
    OLED_ADDRESS
  )) {
    Serial.println("ERRO OLED");

    while (true) {
      delay(1000);
    }
  }

  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(18, 8);
  display.print("SEU TEMPO");
  display.setCursor(18, 19);
  display.print("SEU RITMO!");
  display.display();

  delay(600);

  resetTimer();
  Serial.println("POMODORO PRONTO");
}

// ==========================================
// LOOP
// ==========================================

void loop() {
  unsigned long now = millis();

  updateButton(b1, true);
  updateButton(b2, false);
  updateSound();

  if (isRunning()) {
    unsigned long elapsed = now - lastTick;

    if (elapsed >= 1000) {
      uint32_t seconds = elapsed / 1000;
      lastTick += seconds * 1000;

      if (seconds >= remainingSeconds) {
        finishTimer();
      } else {
        remainingSeconds -= seconds;
        screenDirty = true;
      }
    }
  }

  if (soundMessageUntil != 0 &&
      (long)(now - soundMessageUntil) >= 0) {
    soundMessageUntil = 0;
    screenDirty = true;
  }

  if (screenDirty) {
    renderUI();
    screenDirty = false;
  }

  delay(5);
}

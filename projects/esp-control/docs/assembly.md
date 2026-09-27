# 🔌 Guia de Montagem - Controle Byte do Milhão🪙

### 🛠️ Antes de começar
- **Botões** têm 4 pinos, mas funcionam em pares: os pinos de um mesmo lado estão conectados internamente. Use uma perna de um lado para o sinal e a perna do lado oposto para o GND.
- **LED** tem lado: perna maior é **Positivo (+)**, perna menor é **Negativo (-)**.
- **Resistor** não tem lado, pode ser soldado em qualquer ponta.
- **Buzzer** tem polaridade: o pino marcado com **+** é o positivo.
- **Crimpagem**: usar alicate para prender o terminal metálico no fio e depois colocar a capinha plástica.

---

## Passo 1: Preparando os Botões 🎮

Repita o processo para cada um dos 4 botões.

1. Identifique os dois pinos que serão usados: um de um lado do botão, outro do lado oposto.
2. Solde um fio em um dos pinos (será o fio que conecta ao ESP32).
3. Solde um fio no pino do lado oposto (será o fio que conecta ao GND).
4. Crimpe um **terminal fêmea** na ponta livre de cada fio.

Referência de pinos por botão:

- Botão **Amarelo** → fio que conecta ao ESP32 no **GPIO 23**, fio que conecta ao **GND**
- Botão **Azul** → fio que conecta ao ESP32 no **GPIO 22**, fio que conecta ao **GND**
- Botão **Verde** → fio que conecta ao ESP32 no **GPIO 21**, fio que conecta ao **GND**
- Botão **Vermelho** → fio que conecta ao ESP32 no **GPIO 19**, fio que conecta ao **GND**

```
GPIO 23 ---- [ BOTÃO AMARELO ] ---- GND
GPIO 22 ---- [ BOTÃO AZUL    ] ---- GND
GPIO 21 ---- [ BOTÃO VERDE   ] ---- GND
GPIO 19 ---- [ BOTÃO VERMELHO] ---- GND
```

---

## Passo 2: Preparando o LED 💡

1. Identifique a **perna maior (Positiva)** do LED.
2. Solde o **resistor** na perna maior (+).
3. Na outra ponta do resistor, solde um fio (será o fio que conecta ao ESP32).
4. Solde um fio na perna menor (Negativo) do LED (será o fio que conecta ao GND).
5. Crimpe um **terminal fêmea** na ponta livre de cada fio.

---

## Passo 3: Preparando o Buzzer 🔊

1. Identifique o pino **positivo (+)** do buzzer (marcado na carcaça).
2. Solde um fio no pino positivo (+) (será o fio que conecta ao ESP32).
3. Solde um fio no pino negativo (-) (será o fio que conecta ao GND).
4. Crimpe um **terminal fêmea** na ponta livre de cada fio.

---

## Passo 4: Conectando no ESP32 🧠

Com todos os componentes preparados, plugue os terminais nos pinos correspondentes do ESP32:

- Fio do **LED** (+) → pino **13**
- Fio do **LED** (-) → **GND**
- Fio do **Buzzer** (+) → pino **2**
- Fio do **Buzzer** (-) → **GND**
- Fio do **Botão Amarelo** → pino **23**, outro fio → **GND**
- Fio do **Botão Azul** → pino **22**, outro fio → **GND**
- Fio do **Botão Verde** → pino **21**, outro fio → **GND**
- Fio do **Botão Vermelho** → pino **19**, outro fio → **GND**

---

## Passo 5: Alimentação ⚡

1. Conecte o ESP32 ao computador via **cabo USB**.
2. O LED interno do ESP32 deve acender, indicando que está energizado.

---

## Passo 6: Teste 🔧

1. Com o circuito montado e o código carregado, abra o **Serial Monitor** na IDE.

2. Pressione cada botão e verifique se a mensagem correspondente aparece no monitor:
   - Botão Amarelo → `Botão A pressionado!`
   - Botão Azul → `Botão B pressionado!`
   - Botão Verde → `Botão C pressionado!`
   - Botão Vermelho → `Botão D pressionado!`
3. A cada clique, o **LED deve piscar** e o **buzzer emitir um bipe curto**.

---

🎉 **Pronto! O controle está montado e funcionando.**

-------

# 🔌 Assembly Guide

### 🛠️ Before You Start
- **Buttons** have 4 pins, but work in pairs: pins on the same side are connected internally. Use one pin from one side for the connection to the ESP32, and the pin on the opposite side for GND.
- **LEDs** have polarity: the longer leg is **Positive (+)**, the shorter leg is **Negative (-)**.
- **Resistors** have no polarity — they can be soldered in either direction.
- **Buzzers** have polarity: the pin marked with **+** is positive.
- **Crimping**: use pliers to clamp the metal terminal onto the wire, then slide the plastic sleeve over it.

---

## Step 1: Preparing the Buttons 🎮

Repeat this process for each of the 4 buttons.

1. Identify the two pins you will use: one on each opposite side of the button.
2. Solder a wire to one of the pins (this wire connects to the ESP32).
3. Solder a wire to the pin on the opposite side (this wire connects to GND).
4. Crimp a **female terminal** onto the free end of each wire.

Pin reference per button:
- **Yellow** button → wire to ESP32 on **GPIO 23**, wire to **GND**
- **Blue** button → wire to ESP32 on **GPIO 22**, wire to **GND**
- **Green** button → wire to ESP32 on **GPIO 21**, wire to **GND**
- **Red** button → wire to ESP32 on **GPIO 19**, wire to **GND**

```
GPIO 23 ---- [ YELLOW BUTTON ] ---- GND
GPIO 22 ---- [  BLUE BUTTON  ] ---- GND
GPIO 21 ---- [ GREEN BUTTON  ] ---- GND
GPIO 19 ---- [  RED BUTTON   ] ---- GND
```

---

## Step 2: Preparing the LED 💡

1. Identify the **longer leg (Positive)** of the LED.
2. Solder the **resistor** to the longer leg (+).
3. On the other end of the resistor, solder a wire (this wire connects to the ESP32).
4. Solder a wire to the shorter leg (Negative) of the LED (this wire connects to GND).
5. Crimp a **female terminal** onto the free end of each wire.

---

## Step 3: Preparing the Buzzer 🔊

1. Identify the **positive (+)** pin of the buzzer (marked on the casing).
2. Solder a wire to the positive pin (+) (this wire connects to the ESP32).
3. Solder a wire to the negative pin (-) (this wire connects to GND).
4. Crimp a **female terminal** onto the free end of each wire.

---

## Step 4: Connecting to the ESP32 🧠

With all components ready, plug the terminals into the correct pins on the ESP32:

- **LED** wire (+) → pin **13**
- **LED** wire (-) → **GND**
- **Buzzer** wire (+) → pin **2**
- **Buzzer** wire (-) → **GND**
- **Yellow button** wire → pin **23**, other wire → **GND**
- **Blue button** wire → pin **22**, other wire → **GND**
- **Green button** wire → pin **21**, other wire → **GND**
- **Red button** wire → pin **19**, other wire → **GND**

---

## Step 5: Power ⚡

1. Connect the ESP32 to your computer using a **USB cable**.
2. The built-in LED on the ESP32 should light up, confirming it is powered on.

---

## Step 6: Testing 🔧

1. With the circuit assembled and the code uploaded, open the **Serial Monitor** in your IDE.
2. Press each button and check if the corresponding message appears in the monitor:
   - Yellow button → `Button A pressed!`
   - Blue button → `Button B pressed!`
   - Green button → `Button C pressed!`
   - Red button → `Button D pressed!`
3. With each press, the **LED should blink** and the **buzzer should emit a short beep**.

---

🎉 **All done! The controller is assembled and ready to go.**
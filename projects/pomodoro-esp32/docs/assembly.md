# 🔌 Assembly Guide

## Before you begin

Keep power disconnected while wiring. Verify the battery's positive and negative terminals before connecting it, and confirm every connection against the pin table below.

## Signal wiring

| Component | Connection |
| --- | --- |
| OLED SDA | GPIO 4 |
| OLED SCL | GPIO 5 |
| OLED VCC | Compatible supply |
| OLED GND | GND |
| Button B1 | GPIO 0 and GND |
| Button B2 | GPIO 1 and GND |
| Buzzer positive | GPIO 7 |
| Buzzer negative | GND |

The buttons use `INPUT_PULLUP`, so they are active-low and do not need external pull-up resistors.

## Power

Wire the battery, protected charger, and power switch as shown in the diagram while following the specifications of the components in your kit. Do not program or power the board until continuity, voltage, and polarity have been checked.

## Programming

1. Install VS Code and PlatformIO using the [English guide](../../../docs/platformio.en.md).
2. Open the `firmware/` folder as a PlatformIO project.
3. Connect the ESP32-C3 with a USB data cable.
4. Build and upload the firmware.
5. Open the serial monitor at `115200` to follow startup.

## Controls

| State | B1 | B2 |
| --- | --- | --- |
| Idle | Reset; hold 1 s for settings | Start; hold 2 s for sound |
| Running | Reset | Pause |
| Paused | Reset | Resume |
| Settings | Confirm | Next option |

# 🔌 Guia de Montagem

## Antes de começar

Mantenha a alimentação desligada durante as conexões. Confirme os terminais positivo e negativo da bateria antes de ligá-la e confira cada conexão na tabela de pinos abaixo.

## Ligações de sinal

| Componente | Ligação |
| --- | --- |
| OLED SDA | GPIO 4 |
| OLED SCL | GPIO 5 |
| OLED VCC | Alimentação compatível |
| OLED GND | GND |
| Botão B1 | GPIO 0 e GND |
| Botão B2 | GPIO 1 e GND |
| Positivo do buzzer | GPIO 7 |
| Negativo do buzzer | GND |

Os botões usam `INPUT_PULLUP`, portanto ficam ativos em nível baixo e não precisam de resistores pull-up externos.

## Alimentação

Monte a bateria, o carregador protegido e a chave liga/desliga conforme o diagrama, respeitando as especificações dos componentes usados no seu kit. Não programe nem energize a placa até revisar continuidade, tensão e polaridade.

## Programação

1. Instale o VS Code e o PlatformIO usando o [guia em português](../../../docs/platformio.md).
2. Abra a pasta `firmware/` como projeto no PlatformIO.
3. Conecte o ESP32-C3 por um cabo USB de dados.
4. Compile e envie o firmware.
5. Abra o monitor serial em `115200` para acompanhar a inicialização.

## Controles

| Estado | B1 | B2 |
| --- | --- | --- |
| Parado | Reinicia; segure 1 s para configurar | Inicia; segure 2 s para som |
| Em execução | Reinicia | Pausa |
| Pausado | Reinicia | Continua |
| Ajustes | Confirma | Próxima opção |

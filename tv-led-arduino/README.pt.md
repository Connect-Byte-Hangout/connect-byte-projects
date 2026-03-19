🇺🇸 [English](README.md) | 🇧🇷 Português

<p align="center">
  <img src="./assets/tv3.jpeg" width="100%">
</p>

# Televisão RGB com Arduino

Um projeto de eletrônica criativa onde as participantes constroem uma mini televisão de papelão com iluminação RGB interativa controlada por um Arduino e um botão.

Este projeto foi desenvolvido durante um encontro mensal da Connect Byte e introduz conceitos fundamentais de eletrônica, mistura de cores e programação embarcada.

---

## Visão geral

Neste projeto, as participantes constroem a carcaça de uma "TV" customizada e montam um circuito interativo.

Utilizando um Arduino, um LED RGB e um botão (push-button), o sistema simula a troca de canais da TV. Cada vez que o botão é pressionado, o Arduino atualiza uma máquina de estados para mudar a cor da tela (Vermelho, Verde, Azul, Modo Festa ou Desligado).

Este projeto apresenta conceitos fundamentais como:
- eletrônica básica (Tensão, Corrente e GND)
- a importância dos resistores para limitação de corrente
- como funcionam os LEDs RGB e a mistura de cores via PWM
- leitura de entradas digitais (botões) e debouncing
- máquinas de estado e lógica de `switch/case`

---

## Circuito

- **LED RGB** → Conecte cada perna de cor (R, G, B) a um resistor de 220Ω, e depois aos pinos PWM do Arduino (ex: 9, 10, 11). Conecte a perna comum ao GND ou 5V (dependendo do tipo do LED).
- **Botão (Push-button)** → Um lado no GND, o outro no pino digital 2 do Arduino (usando o `INPUT_PULLUP` interno).
- **Alimentação** → O sistema pode ser alimentado por um suporte de pilhas conectado aos pinos VIN e GND do Arduino.

---

## Código

O código de exemplo está disponível na pasta `code`.

O projeto pode ser aberto utilizando **PlatformIO no Visual Studio Code**.

Arquivo principal:
`code/led-tv/src/main.cpp`

Para entender a fundo a leitura de botões, o truque do `millis()` (debouncing) e a programação dos "canais" da TV, assista à [gravação do nosso encontro](https://www.youtube.com/watch?v=jdX4qP33tmc) com o passo a passo do código.

Veja mais também em nosso [workshop](https://www.canva.com/design/DAHD3Qv_aYI/iuNidV_qm2hbHpIOjla_cA/edit?utm_content=DAHD3Qv_aYI&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton).

---

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
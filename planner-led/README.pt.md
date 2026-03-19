🇺🇸 [English](README.md) | 🇧🇷 Português

<p align="center">
  <img src="./assets/planner2.jpg" width="100%">
</p>

# Planner Interativo com LEDs

Um projeto prático de eletrônica onde as participantes constroem um rastreador de hábitos ou planner diário interativo usando chaves gangorra e LEDs dentro de um porta-retrato.

Este projeto foi desenvolvido durante um encontro da Connect Byte e introduz interação física e lógica básica de circuitos.

---

## Visão geral

Neste projeto, as participantes utilizam um porta-retrato para criar um "quadro de missões" ou rastreador de hábitos visual. Cada tarefa está ligada a uma chave gangorra física e a um LED.

Quando uma tarefa é concluída, virar a chave acende o LED, proporcionando um feedback visual e físico satisfatório de realização.

Este projeto apresenta conceitos fundamentais como:
- leitura de entradas digitais (chaves/interruptores)
- controle de saídas digitais (LEDs)
- gerenciamento de múltiplas entradas e saídas simultaneamente
- integração de eletrônica em objetos decorativos do dia a dia

---

## Circuito

- **Chaves Gangorra** → Um lado no 5V, o outro em um pino de entrada digital (com resistor pull-down) ou usando `INPUT_PULLUP` para o GND.
- **LEDs** → Pino de saída digital → Resistor 220Ω → Ânodo do LED (+) → Cátodo do LED (-) → GND.

---

## Código

O código de exemplo está disponível na pasta `code`.

O projeto pode ser aberto utilizando **PlatformIO no Visual Studio Code**.

Arquivo principal:
`code/planner/src/main.cpp`

---

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
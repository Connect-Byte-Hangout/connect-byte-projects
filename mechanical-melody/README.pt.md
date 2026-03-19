🇺🇸 [English](README.md) | 🇧🇷 Português

<p align="center">
  <img src="./assets/soundbox2.png" width="100%">
</p>

# Melodia Mecânica

Um projeto de eletrônica criativa onde as participantes constroem uma caixa de som interativa usando um Arduino, um teclado de membrana e um buzzer.

Este projeto foi desenvolvido durante um encontro prático da Connect Byte e introduz os conceitos básicos de geração de som e leitura de matrizes.

---

## Visão geral

Neste projeto, as participantes transformam uma caixa de papelão em um instrumento musical customizado ou uma mesa de efeitos sonoros.

Utilizando um Arduino, um teclado de membrana 4x4 e um buzzer piezoelétrico, o sistema identifica qual tecla foi pressionada e gera uma nota musical ou frequência específica.

Este projeto apresenta conceitos fundamentais como:
- geração de frequências sonoras com microcontroladores
- como funcionam os teclados matriciais (linhas e colunas)
- mapeamento de entradas para saídas específicas (variáveis e arrays)
- montagem de circuitos básicos para componentes de áudio

---

## Circuito

- **Teclado de Membrana 4x4** → Conecte os 8 pinos aos pinos digitais do Arduino (ex: 2 ao 9)
- **Buzzer Piezoelétrico** → Pino positivo em um pino PWM do Arduino (ex: 10) e pino negativo no GND

---

## Código

O código de exemplo está disponível na pasta `code`.

O projeto pode ser aberto utilizando **PlatformIO no Visual Studio Code**.

Arquivo principal:
`code/melody/src/main.cpp`

---

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
🐰 Tamagotchi Físico de Páscoa — Connect Byte

Um projeto de eletrônica criativa onde as participantes constroem um objeto interativo com tema de Páscoa, misturando arte, narrativa e hardware de forma leve e divertida ✨

Este projeto foi desenvolvido para um workshop da Connect Byte e introduz conceitos fundamentais de eletrônica por meio de uma experiência acessível e prática.

________________________________________

Visão Geral

Neste projeto, as participantes irão criar e montar um pequeno artefato interativo utilizando materiais simples e componentes eletrônicos.

A experiência é dividida em dois momentos:

• uma fase criativa, focada em personalização e design visual 🎨
• uma fase de eletrônica, onde a interação é adicionada com luz e/ou som ⚡

Dependendo do nível escolhido, o projeto responde a toque (botão) ou a estímulos do ambiente (som), criando um comportamento interativo simples e envolvente.

Este projeto introduz conceitos como:

• eletrônica básica (Tensão, Corrente e GND)
• como LEDs funcionam e por que resistores são importantes
• circuitos simples com bateria e interruptores
• leitura de sinais do ambiente com sensores
• uso de Arduino para criar interações
• integração entre arte + hardware

________________________________________

Circuito

🌱 Nível 1 — Básico

Um circuito simples alimentado por bateria moeda:

• LED → conectado em série com um resistor
• Botão (push-button) → controla o fluxo de corrente
• Bateria (CR2032) → fornece energia

Fluxo básico da ligação:

Bateria (+) → Botão → Resistor → LED (+)
Bateria (–) → LED (–)

Comportamento:

• pressionou → acende 💡
• soltou → apaga

________________________________________

⚡ Nível 2 — Intermediário

Um circuito interativo com Arduino:

• LED → conectado a um pino digital (com resistor)
• Buzzer → conectado a um pino digital para som
• Sensor de som (KY-038) → conectado a uma entrada do Arduino
• Arduino (Nano ou Uno) → controla a lógica
• Alimentação → via USB

Comportamento:

• o sensor detecta um som forte
• o Arduino processa o sinal
• uma saída é ativada (luz + som)

________________________________________

Código

O código de exemplo está disponível na pasta code.

O projeto pode ser aberto usando PlatformIO no Visual Studio Code ou pela Arduino IDE.

Arquivo principal:

code/src/main.cpp

O código demonstra:

• leitura de sensor de som
• controle de LEDs e buzzer
• lógica condicional simples para interação

________________________________________

Experiência do Workshop

Este projeto foi pensado para ser:

• acessível para iniciantes
• criativo primeiro, técnico depois
• modular (cada participante escolhe seu nível)

Não é necessário ter experiência prévia com eletrônica.

________________________________________

Connect Byte

Website: https://connect-byte.org

LinkedIn: https://www.linkedin.com/company/connect-byte/

Instagram: @connectbyte_

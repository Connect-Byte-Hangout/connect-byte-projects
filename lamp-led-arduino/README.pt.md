🇺🇸 [English](README.md) | 🇧🇷 Português

# Luminária LED com Arduino

Um projeto simples de eletrônica criativa onde as participantes constroem uma pequena luminária utilizando Arduino.

Este projeto foi desenvolvido durante um encontro prático da Connect Byte e introduz conceitos básicos de circuitos eletrônicos e programação de microcontroladores.

---

## Visão geral

Neste projeto as participantes constroem uma pequena luminária baseada em LED utilizando um Arduino e componentes eletrônicos simples.

O LED pode ser controlado por código, permitindo experimentar diferentes comportamentos de iluminação.

Este projeto apresenta conceitos fundamentais como:

- circuitos eletrônicos básicos
- saídas digitais
- resistores e LEDs
- programação com Arduino

---

## Objetivos de aprendizado

Ao concluir este projeto, as participantes aprendem:

- como montar um circuito simples em uma protoboard
- como LEDs funcionam
- por que resistores são necessários
- como controlar componentes utilizando código no Arduino

---

## Circuito

Conecte os componentes conforme mostrado no diagrama.

![Circuito](circuit-diagram.png)

Ligação básica:

LED → resistor → pino 13 do Arduino

---

## Ambiente de desenvolvimento

Este projeto foi desenvolvido utilizando **Visual Studio Code** com a extensão **PlatformIO**.

O PlatformIO fornece um ambiente profissional para desenvolvimento de sistemas embarcados, incluindo gerenciamento de projetos, gerenciamento de dependências e ferramentas para envio de código para o dispositivo.

Ferramentas utilizadas:

- Visual Studio Code
- Extensão PlatformIO
- Arduino Framework

---

## Código

O código de exemplo está disponível na pasta `code`.

O projeto pode ser aberto utilizando **PlatformIO no Visual Studio Code**.

Arquivo principal:
```code/lamp/src/main.cpp```

---

## Como funciona

O Arduino envia um sinal **HIGH** para o pino do LED, permitindo que a corrente passe pelo LED e pelo resistor.

O resistor protege o LED limitando a corrente elétrica.

---

## Possíveis extensões

Depois que a luminária básica estiver funcionando, é possível experimentar:

- LEDs RGB
- controle de brilho utilizando PWM
- sensores para controlar a iluminação
- designs decorativos para a luminária
- conexão da luminária com sistemas IoT

---

## Connect Byte

Este projeto foi criado como parte de um encontro prático da comunidade Connect Byte.

Website: https://connect-byte.org  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
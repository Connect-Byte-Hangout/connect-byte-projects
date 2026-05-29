🇺🇸 [English](README.md) | 🇧🇷 Português

<p align="center">
  <img src="./assets/Pascoa1.JPG" width="100%">
</p>

# 🐰 Tamagotchi Físico de Páscoa

Um projeto de eletrônica criativa onde as participantes constroem um objeto interativo com tema de Páscoa, misturando arte, narrativa e hardware de forma leve e divertida ✨

Este projeto foi desenvolvido para um workshop da Connect Byte e introduz conceitos fundamentais de eletrônica por meio de uma experiência acessível e prática.

## 🎨 Visão Geral do Projeto

Neste projeto, as participantes irão criar e montar um pequeno artefato interativo utilizando materiais simples e componentes eletrônicos.

A experiência é dividida em dois momentos: uma fase criativa focada em personalização e design visual, e uma fase de eletrônica onde a interação é adicionada com luz e/ou som. Dependendo do nível escolhido, o projeto responde a toque (botão) ou a estímulos do ambiente (som), criando um comportamento interativo simples e envolvente.

## ✨ Como a "Mágica" Funciona 

Este projeto foi pensado para ser acessível para iniciantes, criativo e modular. Cada participante pode escolher o seu nível de complexidade:

**🌱 Nível 1 — Básico:** Um circuito simples alimentado por bateria moeda. Quando o botão (push-button) é pressionado, a corrente flui e a luz acende. Ao soltar, a luz apaga.

**⚡ Nível 2 — Intermediário:** Um circuito interativo com Arduino. Um sensor de som (KY-038) detecta um som forte no ambiente. O Arduino processa esse sinal e ativa uma saída, ligando simultaneamente uma luz (LED) e um som (Buzzer).

## 🧩 Como Vamos Integrar Arte e Eletrônica

Para garantir uma integração perfeita entre o objeto artesanal e o hardware, este projeto introduz conceitos chave como:

1. *Eletrônica Básica:* Compreender Tensão, Corrente, GND, como os LEDs funcionam e por que os resistores são importantes.
2. *Circuitos Simples:* Criação de interações independentes usando baterias CR2032 e botões para o Nível 1.
3. *Lógica de Microcontrolador:* Leitura de sinais do ambiente com sensores e uso de um Arduino (Nano ou Uno) para controlar o comportamento interativo no Nível 2.

## 🛠️ Resumo Técnico para a Montagem (Hardware)

Não é necessário ter experiência prévia com eletrônica. Pode optar por construir a versão Básica ou a Intermediária.

•   **Circuito Nível 1:** Bateria (+) → Botão → Resistor → LED (+) → LED (–) → Bateria (–). Confira o passo-a-passo da [montagem](assets/projeto_basico_pascoa.pdf).

•   **Circuito Nível 2:** Construído com Arduino (Nano ou Uno), sensor de som, buzzer e LED com resistor, com alimentação via USB. Confira o passo-a-passo da [montagem](assets/projeto_basico_pascoa.pdf).

•   **Código (Nível 2):** O código de exemplo está disponível na pasta `code`. Pode ser aberto usando PlatformIO no Visual Studio Code ou pela Arduino IDE. Confira o [código](code/projeto_intermediario.ino).

•   **Workshop:** Confira nosso encontro com a explicação do projeto no [youtube](https://youtu.be/r3VPI3xCQUY?si=Go0TAlsu_vlTtzGe).

---

<p align="center">
  <img src="./assets/Pascoa3.jpg" width="100%">
</p>

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
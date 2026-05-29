🇺🇸 English | 🇧🇷 [Português](README.pt.md)

<p align="center">
  <img src="./assets/Pascoa1.JPG" width="100%">
</p>

# 🐰 Easter Physical Tamagotchi

A creative electronics project where participants build an interactive Easter-themed object that blends crafting, storytelling, and hardware in a playful and hands-on way ✨

This project was developed for a Connect Byte workshop and introduces fundamental concepts of electronics through a creative and accessible experience.

## 🎨 Project Overview

In this project, participants will design and assemble a small interactive artifact using simple materials and electronic components.

The experience is divided into two moments: a creative phase focused on personalization and visual design, and an electronics phase where interaction is added through light and/or sound. Depending on the chosen level, the project reacts either to touch (button) or environmental input (sound), creating a simple but engaging interactive behavior.

## ✨ How the "Magic" Works

This project is designed to be beginner-friendly, creative-first, and modular. Participants can choose their level of complexity:

**🌱 Level 1 — Basic:** A simple circuit powered by a coin battery. When the button is pressed, the current flows and the light turns on. When released, the light turns off.

**⚡ Level 2 — Intermediate:** An Arduino-based interactive circuit. A sound sensor (KY-038) detects a strong sound input in the environment. The Arduino processes this signal and triggers an output, activating both a light (LED) and a sound (Buzzer).

## 🧩 How We'll Integrate Art and Electronics

To ensure a seamless integration between the handcrafted object and the hardware, this project introduces key concepts such as:

1. *Basic Electronics:* Understanding Voltage, Current, GND, how LEDs work, and why resistors are important.
2. *Simple Circuits:* Building standalone interactions using CR2032 batteries and push-buttons for Level 1.
3. *Microcontroller Logic:* Reading environmental input with sensors and using an Arduino (Nano or Uno) for interactive behaviors in Level 2.

## 🛠️ Technical Summary for Assembly (Hardware)

No prior experience with electronics is required. You can choose to build the Basic or the Intermediate version. 

•   **Level 1 Circuit:** Battery (CR2032) (+) → Push-button → Resistor → LED (+) → LED (–) → Battery (–).
Check the [assembly guide](assets/projeto_basico_pascoa.pdf).

•   **Level 2 Circuit:** Built with Arduino (Nano or Uno), a sound sensor, a buzzer, and an LED with a resistor powered via USB. Check the [assembly guide](assets/projeto_intermediario_pascoa.pdf).

•   **Code (Level 2):** Example code is available in the `code` folder. Open the project using PlatformIO in Visual Studio Code or the Arduino IDE. [Main file](code/projeto_intermediario.ino).

•   **Workshop:** Check our class on [youtube](https://youtu.be/r3VPI3xCQUY?si=Go0TAlsu_vlTtzGe).

---

<p align="center">
  <img src="./assets/Pascoa3.jpg" width="100%">
</p>

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
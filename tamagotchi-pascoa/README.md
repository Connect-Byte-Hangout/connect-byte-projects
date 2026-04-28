
🐰 Easter Physical Tamagotchi — Connect Byte

A creative electronics project where participants build an interactive Easter-themed object that blends crafting, storytelling, and hardware in a playful and hands-on way ✨

This project was developed for a Connect Byte workshop and introduces fundamental concepts of electronics through a creative and accessible experience.

________________________________________

Overview

In this project, participants will design and assemble a small interactive artifact using simple materials and electronic components.

The experience is divided into two moments:

• a creative phase, focused on personalization and visual design 🎨
• an electronics phase, where interaction is added through light and/or sound ⚡

Depending on the chosen level, the project reacts either to touch (button) or environmental input (sound), creating a simple but engaging interactive behavior.

This project introduces key concepts such as:

• basic electronics (Voltage, Current, and GND)
• how LEDs work and why resistors are important
• simple circuits using batteries and switches
• reading environmental input with sensors
• using Arduino for interactive behaviors
• combining art + hardware into a cohesive experience

________________________________________

Circuit

🌱 Level 1 — Basic

A simple circuit powered by a coin battery:

• LED → connected in series with a resistor
• Push-button → controls the flow of current
• Battery (CR2032) → provides power

Basic wiring flow:

Battery (+) → Button → Resistor → LED (+)
Battery (–) → LED (–)

Behavior:

• press → light turns on
• release → light turns off

________________________________________

⚡ Level 2 — Intermediate

An Arduino-based interactive circuit:

• LED → connected to a digital output pin (with resistor)
• Buzzer → connected to a digital pin for sound output
• Sound sensor (KY-038) → connected to an analog/digital input
• Arduino (Nano or Uno) → controls logic
• Power → via USB

Behavior:

• the sensor detects a strong sound input
• Arduino processes the signal
• output is triggered (light + sound)

________________________________________

Code

Example code is available in the code folder.

The project can be opened using PlatformIO in Visual Studio Code or the Arduino IDE.

Main file:

code/src/main.cpp

The code demonstrates:

• reading input from a sound sensor
• controlling LEDs and buzzers
• simple conditional logic for interaction

________________________________________

Workshop Experience

This project is designed to be:

• beginner-friendly
• creative-first, technical-second
• modular (participants can choose their level)

No prior experience with electronics is required.

________________________________________

Connect Byte

Website: https://connect-byte.org

LinkedIn: https://www.linkedin.com/company/connect-byte/

Instagram: @connectbyte_

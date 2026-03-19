🇺🇸 English | 🇧🇷 [Português](README.pt.md)

<p align="center">
  <img src="./assets/soundbox2.png" width="100%">
</p>

# Mechanical Melody

A creative electronics project where participants build an interactive sound box using an Arduino, a membrane keypad, and a buzzer.

This project was developed during a Connect Byte hands-on workshop and introduces the basics of sound generation and matrix inputs.

---

## Overview

In this project, participants transform a simple cardboard box into a custom musical instrument or sound effects board. 

Using an Arduino, a 4x4 membrane keypad, and a piezo buzzer, the system reads which key is pressed and generates a specific musical note or frequency.

This project introduces key concepts such as:
- generating sound frequencies with microcontrollers
- how matrix keypads work (rows and columns)
- mapping inputs to specific outputs (variables and arrays)
- basic circuit assembly for audio components

---

## Circuit

- **4x4 Membrane Keypad** → Connect the 8 pins to the Arduino digital pins (e.g., 2 to 9)
- **Piezo Buzzer** → Positive pin to an Arduino PWM pin (e.g., 10), negative pin to GND

---

## Code

The example code is available in the `code` folder.

The project can be opened using **PlatformIO in Visual Studio Code**.

Main file:
`code/melody/src/main.cpp`

---

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
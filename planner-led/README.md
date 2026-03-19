🇺🇸 English | 🇧🇷 [Português](README.pt.md)

<p align="center">
  <img src="./assets/planner2.jpg" width="100%">
</p>

# Interactive LED Planner

A hands-on electronics project where participants build an interactive habit tracker or daily planner using rocker switches and LEDs inside a picture frame.

This project was developed during a Connect Byte workshop and introduces physical interaction and basic circuit logic.

---

## Overview

In this project, participants use a picture frame to create a visual "quest board" or habit tracker. Each task is linked to a physical rocker switch and an LED. 

When a task is completed, flipping the switch turns on the LED, giving a satisfying visual and physical feedback of accomplishment.

This project introduces key concepts such as:
- reading digital inputs (switches)
- controlling digital outputs (LEDs)
- managing multiple inputs and outputs simultaneously
- integrating electronics into everyday decorative objects

---

## Circuit

- **Rocker Switches** → One side to 5V, the other to a digital input pin (with a pull-down resistor) or using `INPUT_PULLUP` to GND.
- **LEDs** → Digital output pin → 220Ω Resistor → LED Anode (+) → LED Cathode (-) → GND.

---

## Code

The example code is available in the `code` folder.

The project can be opened using **PlatformIO in Visual Studio Code**.

Main file:
`code/planner/src/main.cpp`

---

## Connect Byte
Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
🇺🇸 English | 🇧🇷 [Português](README.pt.md)

<p align="center">
  <img src="./assets/lamp3.JPG" width="100%">
</p>

# Arduino LED Lamp

A simple creative electronics project where participants build a small LED lamp using Arduino.

This project was developed during a Connect Byte hands-on workshop and introduces the basics of electronic circuits and microcontroller programming.

---

## Overview

In this project participants build a small LED-based lamp using an Arduino and simple electronic components.

The LED can be controlled through code, allowing experimentation with different lighting behaviors.

This project introduces key concepts such as:

- basic electronic circuits
- digital outputs
- resistors and LEDs
- Arduino programming

---

## Learning Goals

By completing this project participants will learn:

- how to assemble a simple circuit on a breadboard
- how LEDs work
- why resistors are necessary
- how to control components with Arduino code

---


## Circuit

Connect the components as shown in the diagram.

![Circuit](circuit-diagram.png)

Basic wiring:

LED → resistor → Arduino pin 13

## Development Environment

This project was developed using **Visual Studio Code** with the **PlatformIO extension**.

PlatformIO provides a professional development environment for embedded systems, including project management, dependency management and device upload tools.

Tools used:

- Visual Studio Code
- PlatformIO Extension
- Arduino Framework

---

## Code

The example code is available in the `code` folder.

The project can be opened using **PlatformIO in Visual Studio Code**.

Main file:

```code/lamp/src/main.cpp```

---

## How it works

The Arduino sends a HIGH signal to the LED pin, allowing current to flow through the LED and resistor.

The resistor protects the LED by limiting the current.

---

## Possible Extensions

Once the basic lamp works, participants can experiment with:

- RGB LEDs
- brightness control with PWM
- sensors to control the light
- decorative lamp designs
- connecting the lamp to IoT systems

---

## Connect Byte

This project was created as part of a Connect Byte hands-on workshop.

Website: https://connect-byte.org  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
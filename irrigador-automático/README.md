🇺🇸 English | 🇧🇷 [Português](README.pt.md)

# Automatic Plant Irrigator with Arduino

A practical home automation project where participants build a system that monitors soil moisture and irrigates plants automatically.

This project was developed during a **Connect Byte** hands-on workshop and introduces concepts of analog sensors and actuator control (water pumps) via relays.

---

## Overview

In this project, participants build an intelligent system that detects when a plant needs water using a soil moisture sensor.

The Arduino processes the sensor data and, if the soil is dry, activates a mini water pump through a relay module.

This project introduces fundamental concepts such as:
- Reading analog sensors
- Using relay modules for external load control
- Conditional structures (if/else) in programming
- Basic process automation

---

## Learning Objectives

Upon completing this project, participants learn:
- How to collect environmental data using sensors
- The difference between analog and digital signals
- How to isolate and control higher power circuits (pumps) using relays
- Sensor calibration logic within the code

---

## Circuit

Connect the components as shown in the diagram (available in the assets folder).



**Basic wiring:**
- Soil Moisture Sensor → Pin A0 (Analog)
- Relay Module → Pin 7 (Digital)
- Water Pump → Connected to the Relay output and external power source

---

## Development Environment

This project was developed using **Visual Studio Code**.

Tools used:
- Visual Studio Code
- Arduino / PlatformIO Extension
- Arduino Framework

---

## Code

The example code is available in the `code` folder.

Main file:
`code/irrigador.ino`

---

## How it works

The Arduino constantly reads the analog value from the moisture sensor. When the soil dries out, the resistance increases, and the read value exceeds the defined limit (setpoint).

Upon detecting dry soil, the Arduino sends a signal to the Relay, which "closes the switch" and turns on the water pump until the soil is moist again.

## Connect Byte

This project was created as part of a practical meeting of the Connect Byte community.

Website:

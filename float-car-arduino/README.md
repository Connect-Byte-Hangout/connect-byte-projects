🇺🇸 English | 🇧🇷 [Português](README.pt.md)

<p align="center">
  <img src="./assets/carnaval1.jpg" width="100%">
</p>

# Arduino Float Car Robot

A creative robotics project where participants build an autonomous float car robot using Arduino.

This project was developed during a Connect Byte hands-on workshop and introduces the basics of robotics, motor control, and programming logic.

---

## Overview

In this project participants build a small robotic float car (Robô Polvo) that executes a programmed choreography.

Using a motor driver, the Arduino controls two DC motors to move forward, stop, and turn exactly 90 degrees. At the same time, an LED blinks in a "samba rhythm".

This project introduces key concepts such as:

- basic robotics and kinematics
- DC motor control via H-bridge drivers (L9110S)
- movement sequences using state machines
- time-based multitasking (using `millis()`)

---

## Learning Goals

By completing this project participants will learn:

- how to wire a motor driver to an Arduino and DC motors
- how to control motor direction and speed through code
- how to calculate turning times based on wheel radius and distance
- how to run parallel tasks, like blinking an LED without interrupting the robot's movement

---

## Circuit

Connect the components taking care with the motor driver connections.

Basic wiring:

- Motor Right → L9110S Driver → Arduino pins 7 (A) and 8 (B)
- Motor Left → L9110S Driver → Arduino pins 4 (A) and 5 (B)
- "Octopus Eye" LED → resistor → Arduino pin 11

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

```code/car/src/main.cpp```


For a deeper dive into the logic and state machines, watch our [workshop recording](https://drive.google.com/file/d/1SJ_JABWWWgHsd38rvRdCPOPwIJ-EQPhp/view) where we explain the code step-by-step.

## How it works

The Arduino sends PWM (Pulse Width Modulation) and digital signals to the L9110S driver, which translates them into power to spin the motors forward or backward.

The movement is controlled by a state machine that dictates the car's choreography step-by-step. Simultaneously, the `millis()` function checks the time to blink the LED in a 2/4 samba rhythm without pausing the motors.

See more in our [workshop](https://www.canva.com/design/DAG_Xh8P50w/FBFa6IrBuQ4W8jjsY-pvWw/edit).


## Possible Extensions

Once the basic float car works, participants can experiment with:

- ultrasonic sensors to avoid obstacles
- line tracking modules
- bluetooth modules to control the car via smartphone
- new choreographies and LED rhythms

---

## Connect Byte

This project was created as part of a Connect Byte hands-on workshop.

Website: https://connect-byte.org    
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)

# Pomodoro Timer with ESP32-C3

A portable focus timer that combines an ESP32-C3 Super Mini, an OLED display, two buttons, and a buzzer to organize work and break cycles.

The project was developed for Connect Byte's November workshop and introduces state-based programming, button input, non-blocking timing, and visual and audible feedback.

## How it works

- The display shows the remaining time, current cycle, and a progress bar.
- B2 starts, pauses, and resumes the timer.
- B1 resets the cycle.
- While idle, hold B1 for 1 second to adjust work and break durations.
- While idle, hold B2 for 2 seconds to enable or disable sound.
- At the end of each stage, choose whether to start another focus session or a break.

## Materials and assembly

- [Bill of materials](docs/materials.md)
- [Assembly and usage guide](docs/assembly.md)

## Firmware

The firmware uses the Arduino Framework with PlatformIO and is available in [`firmware/`](firmware/). It targets the ESP32-C3 Super Mini and a 128 x 32 SSD1306 OLED display at I2C address `0x3C`.

Open the `firmware/` folder in VS Code with PlatformIO to build it. See the repository's [PlatformIO guide](../../docs/platformio.en.md) for setup instructions.

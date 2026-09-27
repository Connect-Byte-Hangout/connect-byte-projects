# Physical Financial Planner

A planner that connects financial organization on paper, data recognition on the Connect Byte website, and goal tracking on a physical device with an ESP32-C3 and OLED display.

Participants fill out the weekly sheet by hand, photograph the planner, and upload the image through the Connect Byte community area. After reviewing the recognized fields, the data becomes available to the device. Pressing the ESP32 **BOOT** button updates the display with the saved amount, the goal, and the progress reached.

> The digital step happens in the [Connect Byte community Planner](https://www.connect-byte.org/planner) and is available only to members who have access. This functionality is not part of this public repository.

## How it works

1. Fill out the [financial planner sheet](assets/financial-planner-sheet.pdf) by hand.
2. Take a photo of the completed sheet or enter the fields manually on the website.
3. Open the [Connect Byte community Planner](https://www.connect-byte.org/planner).
4. If you upload a photo, review the recognized fields and correct any information if necessary.
5. Save the updated goal and amounts.
6. Briefly press the ESP32 **BOOT** button to update the display.

[Holding the button for approximately five seconds](docs/assembly.md#wi-fi-configuration) opens the Wi-Fi configuration portal. Follow the guide to configure the network at home.

## Materials and assembly

- [Materials](docs/materials.md)
- [Assembly and setup guide](docs/assembly.md)
- [Printable planner sheet](assets/financial-planner-sheet.pdf)

## Firmware

The firmware uses PlatformIO and is available in [`firmware/`](firmware/). It is configured for the ESP32-C3 Super Mini and supports 128 x 32 or 128 x 64 OLED displays. The configuration portal creates the `ConnectByte-Planner` network with the password `12345678`, matching the units delivered at the event.

The device identifier and token are not included in the public source code. They link each Planner to the participant's Connect Byte account, are configured by administrators, and are stored in the ESP32 memory. Only administrators can access this device-linking step.

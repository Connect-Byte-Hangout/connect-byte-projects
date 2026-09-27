# How to use PlatformIO with VS Code

Projects with firmware in this repository use the same structure:

```text
firmware/
├── platformio.ini
└── src/
    └── main.cpp
```

The `platformio.ini` file identifies the board and framework. The main code is
located in `src/main.cpp`.

## 1. Install Visual Studio Code

1. Visit the [official VS Code download page](https://code.visualstudio.com/download).
2. Choose Windows, macOS, or Linux and complete the installation.
3. Open VS Code.

## 2. Install PlatformIO

1. In VS Code, open **Extensions** in the sidebar.
2. Search for **PlatformIO IDE**.
3. Install the official extension published by PlatformIO.
4. Wait for the installation to finish and restart VS Code if requested.

You do not need to install PlatformIO Core separately: it is included with the
extension. You can also read the [official PlatformIO documentation for VS Code](https://docs.platformio.org/en/stable/integration/ide/vscode.html).

## 3. Open a project from this repository

1. Open the project's folder inside `projects/`.
2. In VS Code, select **File > Open Folder**.
3. Open the project's `firmware/` folder specifically. It contains the
   `platformio.ini` file.
4. Wait while PlatformIO prepares the board tools the first time you open it.

Do not open only the `main.cpp` file: PlatformIO needs the folder containing
`platformio.ini` to be open.

## 4. Build and upload to the board

Use the PlatformIO buttons in the bottom bar of VS Code:

- **✓ Build**: checks and compiles the code;
- **→ Upload**: compiles and uploads the program to the board connected by USB;
- **Plug Monitor**: opens the serial monitor.

The same actions are available under **PlatformIO > Project Tasks**. The official
documentation explains the [Build, Upload, and Serial Monitor tools](https://docs.platformio.org/en/stable/integration/ide/vscode.html#platformio-toolbar).

If the project has more than one board configured, select the correct PlatformIO
environment. The Tamagotchi project, for example, has environments for Arduino
Uno and Arduino Nano.

## 5. Before uploading

1. Connect the board using a USB cable that also supports data transfer.
2. Check that the board model matches the environment in `platformio.ini`.
3. Close the serial monitor before uploading if the port is busy.
4. If there is more than one USB port, select the correct port in the PlatformIO tasks.

## Special setup for Byte do Milhão

The `esp-control` firmware uses Wi-Fi and server information. Inside
`firmware/include/`, copy `config.example.h` to `config.h` and replace all
`TODO` values. The real configuration file is ignored by Git to prevent Wi-Fi
passwords from being published.

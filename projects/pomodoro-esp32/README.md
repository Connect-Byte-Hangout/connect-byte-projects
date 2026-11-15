🇺🇸 [English](README.en.md) | 🇧🇷 Português

# Pomodoro com ESP32-C3

Um temporizador de foco portátil que combina um ESP32-C3 Super Mini, display OLED, dois botões e um buzzer para organizar ciclos de trabalho e descanso.

## Como funciona

- O display mostra o tempo restante, o ciclo atual e uma barra de progresso.
- O botão B2 inicia, pausa e retoma o cronômetro.
- O botão B1 reinicia o ciclo.
- Com o temporizador parado, segure B1 por 1 segundo para ajustar os tempos de foco e pausa.
- Com o temporizador parado, segure B2 por 2 segundos para ligar ou desligar o som.
- Ao final de cada etapa, escolha entre iniciar um novo foco ou uma pausa.

## Materiais e montagem

- [Lista de materiais](docs/materials.md)
- [Guia de montagem e uso](docs/assembly.md)

## Firmware

O firmware usa o Arduino Framework com PlatformIO e está em [`firmware/`](firmware/). Ele foi configurado para o ESP32-C3 Super Mini e um display OLED SSD1306 de 128 x 32 pixels no endereço I2C `0x3C`.

Para compilar, abra a pasta `firmware/` no VS Code com PlatformIO. Consulte também o [guia de PlatformIO do repositório](../../docs/platformio.md).

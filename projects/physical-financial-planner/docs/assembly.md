# 🔌 Assembly Guide

## Before you begin

The provided firmware is configured for an ESP32-C3 and an I2C OLED display at address `0x3C`, using a default resolution of 128 x 64 pixels. A 128 x 32 display can be selected through `OLED_128X32` in the code.

> Check the voltage, polarity, and model of every component before connecting the battery. The final circuit diagram used at the event still needs to be added.

## 1. Prepare the paper planner

1. Print the [planner sheet](../assets/financial-planner-sheet.pdf).
2. Fill in the week and the planned and actual amounts for each category.
3. Fill in the available weekly amount, the promised savings, and the amount actually saved.
4. Record the goal and the week's notes.

You can also enter every field manually in the [Connect Byte community Planner](https://www.connect-byte.org/planner) without taking or uploading a photo.

## 2. Assemble the device

Connect the OLED display to the ESP32-C3 through I2C. The provided firmware uses:

| Function | Configured pin |
| --- | ---: |
| Display SDA | GPIO 4 |
| Display SCL | GPIO 3 |
| BOOT button | GPIO 9 |
| Optional external status LED | GPIO 5 |

The participants did not install the status LED during the event. GPIO 5 support remains in the firmware as an optional improvement using a separate LED; it is not the board's built-in LED. Do not connect the battery holder before checking its polarity.

### Optional improvement challenge: status LED

As a next step, add a separate status LED with a suitable resistor to GPIO 5. The firmware already uses this output to indicate activity, success, and errors. This challenge was not part of the assembly completed at the event.

## 3. Prepare the firmware

1. Install VS Code and PlatformIO using the repository guide.
2. Open the `firmware/` folder in VS Code.
3. Build and upload the firmware.

## 4. Configure the device

On first startup, open the serial monitor at `115200`. The firmware asks for the device identifier and private device token. Administrators use these values to link the physical Planner to the participant's account on the Connect Byte website. Both values are stored in the ESP32 NVS memory, and the token is not printed again. Only administrators have access to this device-linking step.

> Obtain the identifier and token only through an authorized Connect Byte flow. Never share the token or add it to this repository.

## 5. Use the community area

1. Open the [Connect Byte community Planner](https://www.connect-byte.org/planner).
2. Sign in with an account that has access to the community area.
3. Open the financial planner feature.
4. Upload a clear photo of the completed sheet or fill out the form manually without uploading a photo.
5. If you upload a photo, review the recognized fields and correct any errors.
6. Save the data.

The recognition tool belongs to the Connect Byte website and is not included in this public repository. If the feature is unavailable to your account, request access from the community team.

<span id="wi-fi-configuration"></span>

## Wi-Fi configuration

The Connect Byte Planner can change or configure its Wi-Fi network without connecting the ESP32 to a computer.

1. Turn on the Planner normally.
2. Press and hold the ESP32-C3 Super Mini **BOOT** button for approximately five seconds.
3. The Planner enters Wi-Fi configuration mode.
4. The OLED displays `Configurar Wi-Fi` and `ConnectByte-Planner`.
5. The ESP32-C3 temporarily creates a Wi-Fi access point named `ConnectByte-Planner`.
6. On a phone or computer, connect to `ConnectByte-Planner` using the password `12345678`.
7. The WiFiManager configuration portal should appear after the connection is established.
8. Select **Configurar WiFi** and wait for the available networks to appear. This step can be slow, so allow the portal a little time to change screens and finish scanning.
9. Select the Wi-Fi network the Planner should use normally, enter that network's password, and confirm the configuration.
10. After a successful connection, the ESP32 saves the selected network credentials for future startups.
11. The OLED confirms that Wi-Fi is connected.
12. The Planner automatically contacts the backend and updates the financial progress shown on the display.

The configuration portal remains available for up to 300 seconds, or five minutes. If configuration is not completed during that period, the portal closes.

### BOOT button actions

- **Short press:** immediately requests updated Planner data through the API.
- **Long press, approximately five seconds:** opens the Wi-Fi configuration portal.

### ESP32-C3 Super Mini technical detail

The firmware sets the Wi-Fi transmission power before opening the access point:

```cpp
WiFi.setTxPower(WIFI_POWER_8_5dBm);
```

This setting is part of the project implementation used to keep the configuration access point visible and operational on the ESP32-C3 Super Mini. The firmware uses GPIO 9 for the BOOT button.

The serial monitor also supports `INFO`, `UPDATE`, and `RESET_DEVICE`.

# 🔌 Guia de Montagem

## Antes de começar

O firmware recebido está configurado para um ESP32-C3, display OLED I2C no endereço `0x3C` e resolução padrão de 128 x 64 pixels. Ele também oferece suporte a um display de 128 x 32 pixels por meio da configuração `OLED_128X32` no código.

> Confira a tensão, a polaridade e o modelo de cada componente antes de conectar a bateria.

## 1. Prepare o planner de papel

1. Imprima a [folha do planner](../assets/financial-planner-sheet.pdf).
2. Preencha a semana, os valores planejados e gastos por categoria.
3. Preencha quanto você tem para a semana, quanto prometeu guardar e quanto guardou de verdade.
4. Registre sua meta e as observações da semana.

Também é possível preencher todos os campos manualmente no [Planner da área da comunidade Connect Byte](https://www.connect-byte.org/planner), sem tirar ou enviar uma foto.

## 2. Monte o dispositivo

Conecte o display OLED ao ESP32-C3 usando a interface I2C. No firmware recebido, os pinos estão configurados desta forma:

| Função | Pino configurado |
| --- | ---: |
| SDA do display | GPIO 4 |
| SCL do display | GPIO 3 |
| Botão BOOT | Integrado na Placa |
| LED de status avulso e opcional | GPIO 5 |

As participantes não implementaram o LED de status durante o evento. Porém, o código está preparado para receber um LED de feedback no pino GPIO 5 como uma melhoria opcional. Confira a polaridade antes de conectar o suporte para quatro pilhas AA.

### Desafio de melhoria opcional: LED de status

Como próximo passo, adicione um LED com um resistor adequado no GPIO 5. O firmware já usa essa saída para indicar atividade, sucesso e erros. Esse desafio não fez parte da montagem realizada no evento.

## 3. Prepare o firmware

1. Instale o VS Code e o PlatformIO seguindo o [guia do repositório](../../../docs/platformio.md).
2. Abra a pasta `firmware/` no VS Code.
3. Compile e envie o firmware para a placa.

## 4. Configure o dispositivo

Na primeira inicialização, abra o monitor serial em `115200`. O firmware pedirá:

- o identificador do dispositivo;
- o token privado do dispositivo.

As administradoras usam esses dados para vincular o Planner físico à conta da participante no site da Connect Byte. Eles são armazenados na memória NVS do ESP32 e o token não é exibido novamente no monitor serial. Somente as administradoras têm acesso a essa etapa de vinculação.

> O identificador e o token devem ser obtidos somente pelo fluxo autorizado da Connect Byte. Não compartilhe o token nem o coloque em arquivos deste repositório.

## 5. Use a área da comunidade

1. Acesse o [Planner da área da comunidade Connect Byte](https://www.connect-byte.org/planner).
2. Entre com uma conta que tenha acesso à área da comunidade.
3. Abra a funcionalidade do planner financeiro.
4. Envie uma foto nítida da folha preenchida ou preencha o formulário manualmente, sem enviar uma foto.
5. Se enviar uma foto, revise os campos reconhecidos e corrija qualquer erro.
6. Salve os dados.

A ferramenta de reconhecimento pertence ao site da Connect Byte e não está incluída neste repositório público. Caso a funcionalidade não apareça para sua conta, solicite acesso à equipe da comunidade.

<span id="configuracao-do-wi-fi"></span>

## Configuração do Wi-Fi

O Connect Byte Planner permite trocar ou configurar a rede Wi-Fi sem precisar conectar o ESP32 ao computador.

1. Ligue o Planner normalmente.
2. Pressione e mantenha pressionado o botão **BOOT** do ESP32-C3 Super Mini por aproximadamente cinco segundos.
3. Após os cinco segundos, o Planner entra no modo de configuração de Wi-Fi.
4. O display OLED mostra `Configurar Wi-Fi` e `ConnectByte-Planner`.
5. O ESP32-C3 cria temporariamente um ponto de acesso Wi-Fi chamado `ConnectByte-Planner`.
6. No celular ou computador, abra as configurações de Wi-Fi e conecte-se à rede `ConnectByte-Planner` usando a senha `12345678`.
7. Após conectar-se à rede do Planner, o portal de configuração do WiFiManager deve ser apresentado.
8. No portal, selecione **Configurar WiFi** e aguarde as redes disponíveis aparecerem. Essa etapa é lenta mesmo: espere um pouco enquanto o portal muda de tela e conclui a busca.
9. Selecione a rede Wi-Fi que o Planner deverá utilizar normalmente, informe a senha dessa rede e confirme a configuração.
10. Após a conexão ser concluída com sucesso, o ESP32 salva as credenciais de Wi-Fi para as próximas inicializações.
11. O OLED informa que o Wi-Fi foi conectado.
12. Em seguida, o Planner consulta automaticamente o backend e atualiza no display os dados de progresso financeiro.

O portal de configuração permanece disponível por até 300 segundos, ou cinco minutos. Se a configuração não for concluída nesse período, o portal é encerrado.

### Usos do botão BOOT

- **Pressionamento curto:** solicita imediatamente uma atualização dos dados do Planner através da API.
- **Pressionamento longo, por aproximadamente cinco segundos:** abre o portal de configuração do Wi-Fi.

### Detalhe técnico do ESP32-C3 Super Mini

Antes de iniciar o ponto de acesso, o firmware configura a potência de transmissão Wi-Fi com:

```cpp
WiFi.setTxPower(WIFI_POWER_8_5dBm);
```

Essa configuração faz parte da implementação utilizada no projeto para garantir o funcionamento e a visibilidade do ponto de acesso no ESP32-C3 Super Mini. O botão BOOT utilizado pelo firmware está no GPIO 9.

Pelo monitor serial, também estão disponíveis os comandos `INFO`, `UPDATE` e `RESET_DEVICE`.

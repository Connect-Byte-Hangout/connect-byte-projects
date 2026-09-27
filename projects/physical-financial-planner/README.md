# Planner Financeiro Físico

Um planner que conecta organização financeira no papel, reconhecimento de dados no site da Connect Byte e acompanhamento da meta em um dispositivo físico com ESP32-C3 e display OLED.

As participantes preenchem manualmente a folha semanal, fotografam o planner e enviam a imagem pela área da comunidade no site da Connect Byte. Depois de revisar os campos reconhecidos, os dados ficam disponíveis para o dispositivo. Ao pressionar o botão **BOOT** do ESP32, o display mostra quanto já foi guardado, o valor da meta e o progresso alcançado.

> A etapa digital acontece no [Planner da área da comunidade Connect Byte](https://www.connect-byte.org/planner) e está disponível somente para integrantes que tenham acesso. Essa funcionalidade não faz parte deste repositório público.

## Como o projeto funciona

1. Preencha a [folha do planner financeiro](assets/financial-planner-sheet.pdf) à mão.
2. Tire uma foto da folha preenchida ou escolha preencher os campos manualmente no site.
3. Entre no [Planner da área da comunidade Connect Byte](https://www.connect-byte.org/planner).
4. Se enviar uma foto, confira os campos reconhecidos e corrija qualquer informação, se necessário.
5. Salve a meta e os valores atualizados.
6. Pressione rapidamente o botão **BOOT** no ESP32 para atualizar o display.

Um pressionamento longo de aproximadamente cinco segundos abre o portal de configuração do Wi-Fi. Consulte o [passo a passo para configurar a rede em casa.](docs/assembly.md#configuracao-do-wi-fi)

## Materiais e montagem

- [Lista de materiais](docs/materials.md)
- [Guia de montagem e configuração](docs/assembly.md)
- [Folha do planner para impressão](assets/financial-planner-sheet.pdf)

## Firmware

O firmware usa PlatformIO e está em [`firmware/`](firmware/). Ele está configurado para a placa ESP32-C3 Super Mini e aceita displays OLED de 128 x 32 ou 128 x 64 pixels. O portal de configuração cria a rede `ConnectByte-Planner` com a senha `12345678`, mantendo compatibilidade com as unidades entregues no evento.

O identificador e o token do dispositivo não ficam no código público. Eles vinculam cada Planner à conta da participante no site da Connect Byte, são configurados pelas administradoras e ficam armazenados na memória do ESP32. Somente as administradoras têm acesso a essa etapa de vinculação.

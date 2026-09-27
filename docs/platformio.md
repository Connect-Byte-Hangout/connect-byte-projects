# Como usar o PlatformIO com o VS Code

Os projetos com programação deste repositório usam o mesmo formato:

```text
firmware/
├── platformio.ini
└── src/
    └── main.cpp
```

O `platformio.ini` identifica a placa e o framework. O código principal fica em
`src/main.cpp`.

## 1. Instalar o Visual Studio Code

1. Acesse a [página oficial de download do VS Code](https://code.visualstudio.com/download).
2. Escolha Windows, macOS ou Linux e conclua a instalação.
3. Abra o VS Code.

## 2. Instalar o PlatformIO

1. No VS Code, abra **Extensions** na barra lateral.
2. Pesquise por **PlatformIO IDE**.
3. Instale a extensão oficial publicada pela PlatformIO.
4. Aguarde a instalação terminar e reinicie o VS Code se ele solicitar.

Não é necessário instalar o PlatformIO Core separadamente: ele já acompanha a
extensão. Consulte também a [documentação oficial do PlatformIO para VS Code](https://docs.platformio.org/en/stable/integration/ide/vscode.html).

## 3. Abrir um projeto deste repositório

1. Entre na pasta do projeto em `projects/`.
2. No VS Code, selecione **File > Open Folder**.
3. Abra especificamente a pasta `firmware/` do projeto. Ela é a pasta que contém
   o arquivo `platformio.ini`.
4. Aguarde o PlatformIO preparar as ferramentas da placa na primeira abertura.

Não abra somente o arquivo `main.cpp`: o PlatformIO precisa que a pasta com o
`platformio.ini` esteja aberta.

## 4. Compilar e enviar para a placa

Na barra inferior do VS Code, use os botões do PlatformIO:

- **✓ Build**: verifica e compila o código;
- **→ Upload**: compila e grava o programa na placa conectada por USB;
- **Plug Monitor**: abre o monitor serial.

As mesmas ações aparecem em **PlatformIO > Project Tasks**. A documentação
oficial descreve os comandos de [Build, Upload e Serial Monitor](https://docs.platformio.org/en/stable/integration/ide/vscode.html#platformio-toolbar).

Se o projeto tiver mais de uma placa configurada, escolha o ambiente correto no
seletor do PlatformIO. O Tamagotchi, por exemplo, possui ambientes para Arduino
Uno e Arduino Nano.

## 5. Antes de fazer Upload

1. Conecte a placa com um cabo USB que também transmita dados.
2. Confira se o modelo da placa corresponde ao ambiente do `platformio.ini`.
3. Feche o monitor serial antes do Upload caso a porta esteja ocupada.
4. Se houver mais de uma porta USB, selecione a porta correta nas tarefas do
   PlatformIO.

## Configuração especial do Byte do Milhão

O firmware do `esp-control` usa dados de Wi-Fi e do servidor. Dentro de
`firmware/include/`, copie `config.example.h` para `config.h` e substitua todos
os valores `TODO`. O arquivo real é ignorado pelo Git para evitar publicar senha
de Wi-Fi.

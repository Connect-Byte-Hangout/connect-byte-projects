🇺🇸 [English](README.md) | 🇧🇷 Português

<p align="center">
  <img src="./assets/carnaval1.jpg" width="100%">
</p>

# Carro Alegórico Robótico com Arduino

Um projeto criativo de robótica onde as participantes constroem um carro alegórico autônomo utilizando Arduino.

Este projeto foi desenvolvido durante um encontro prático da Connect Byte e introduz conceitos básicos de robótica, controle de motores e lógica de programação.

---

## Visão geral

Neste projeto as participantes constroem um pequeno carro alegórico robótico (Robô Polvo) que executa uma coreografia programada.

Utilizando um driver de motor, o Arduino controla dois motores DC para andar para frente, parar e girar exatamente 90 graus. Ao mesmo tempo, um LED pisca simulando um "ritmo de samba".

Este projeto apresenta conceitos fundamentais como:

- robótica básica e cinemática
- controle de motores DC via Ponte H (Driver L9110S)
- sequências de movimento usando máquinas de estado
- multitarefas baseadas em tempo (usando `millis()`)

---

## Objetivos de aprendizado

Ao concluir este projeto, as participantes aprendem:

- como conectar um driver de motor ao Arduino e aos motores DC
- como controlar a direção e velocidade dos motores através do código
- como calcular tempos de giro usando matemática básica (raio e distância da roda)
- como executar tarefas paralelas, como piscar um LED sem interromper o movimento do robô

---

## Circuito

Conecte os componentes tendo atenção às conexões do driver de motor.

Ligação básica:

- Motor Direito → Driver L9110S → Pinos 7 (A) e 8 (B) do Arduino
- Motor Esquerdo → Driver L9110S → Pinos 4 (A) e 5 (B) do Arduino
- LED "Olho do Polvo" → resistor → Pino 11 do Arduino

---

## Ambiente de desenvolvimento

Este projeto foi desenvolvido utilizando **Visual Studio Code** com a extensão **PlatformIO**.

O PlatformIO fornece um ambiente profissional para desenvolvimento de sistemas embarcados, incluindo gerenciamento de projetos, gerenciamento de dependências e ferramentas para envio de código para o dispositivo.

Ferramentas utilizadas:

- Visual Studio Code
- Extensão PlatformIO
- Arduino Framework

---

## Código

O código de exemplo está disponível na pasta `code`.

O projeto pode ser aberto utilizando **PlatformIO no Visual Studio Code**.

Arquivo principal:
```code/car/src/main.cpp```

Para entender a lógica e as máquinas de estado a fundo, assista à [gravação do nosso encontro](https://drive.google.com/file/d/1SJ_JABWWWgHsd38rvRdCPOPwIJ-EQPhp/view) com o passo a passo do código.

## Como funciona

O Arduino envia sinais digitais e PWM (Modulação por Largura de Pulso) para o driver L9110S, que os traduz em energia para girar os motores para frente ou para trás.

O movimento é controlado por uma máquina de estados que dita a coreografia do carro passo a passo. Simultaneamente, a função `millis()` verifica o tempo para piscar o LED em um ritmo de samba 2/4 sem pausar o funcionamento dos motores.

Veja mais em nosso [workshop](https://www.canva.com/design/DAG_Xh8P50w/FBFa6IrBuQ4W8jjsY-pvWw/edit).

## Possíveis extensões

Depois que o carro alegórico básico estiver funcionando, é possível experimentar:

- sensores ultrassônicos para desviar de obstáculos
- módulos seguidores de linha
- módulos bluetooth para controlar o carro pelo celular
- novas coreografias e ritmos de LED

---

## Connect Byte

Este projeto foi criado como parte de um encontro prático da comunidade Connect Byte.

Website: https://connect-byte.org  
Linkedin: https://www.linkedin.com/company/connect-byte/  
Instagram: [@connectbyte_](https://www.instagram.com/connectbyte_)
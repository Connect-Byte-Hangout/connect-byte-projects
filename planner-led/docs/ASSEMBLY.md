# 🔌 Guia de Montagem do Projeto


### 🛠️ Antes de começar
- **Resistor** não tem lado, pode ser soldado em qualquer ponta.  
- **LED** tem lado: perna maior é **Positivo (+)**, perna menor é **Negativo (-)**.  
- **Crimpagem**: usar alicate para prender o terminal metálico no fio e depois colocar a capinha plástica. 
- **Montagem**: confira o diagrama do projeto [aqui](docs/diagram.jpg).  

---

## Passo 1: Preparando o LED ✨
1. Identifique a **perna maior (Positiva)** do LED.  
2. Solde o **resistor** nessa perna maior.  
3. Na outra ponta do resistor, solde um fio **claro** (para identificar como positivo).  
4. Solde um fio **escuro** na perna menor (Negativo) do LED.  
5. Crimpe um **terminal fêmea** na ponta livre do fio claro.  
   - O fio escuro fica sem terminal por enquanto.  

---

## Passo 2: Ligação da Bateria 🔋
A bateria **CR2032** não pode ser soldada. Vamos usar o truque da fita isolante.  

1. Desencape cerca de **2 cm** das pontas de um fio claro (Positivo) e um fio escuro (Negativo).  
2. Achate as pontas dos fios de cobre, como uma “vassourinha”.  
3. Encoste o fio claro no **lado Positivo (+)** da bateria e prenda com fita isolante.  
4. Encoste o fio escuro no **lado Negativo (-)** e prenda também.  
5. Dê uma volta completa de fita isolante na bateria para firmar bem os fios.  
6. Crimpe um **terminal fêmea** na ponta livre do fio claro.  
   - O fio escuro continua solto.  

---

## Passo 3: Conectando no Módulo 🔵
1. Plugue o conector fêmea do **fio positivo da bateria** no pino **+5V (VCC)** do módulo azul.  
2. Plugue o conector fêmea do **fio positivo do LED (com resistor)** no pino **D0** do módulo.  

---

## Passo 4: Unindo os Negativos ⚡
Agora temos dois fios escuros soltos (LED e bateria).  

1. Junte as pontas desencapadas dos dois fios.  
2. Torça bem com os dedos, formando um fio único mais grosso.  
3. Crimpe essa ponta dupla em **um único terminal fêmea**.  
4. Plugue esse conector no pino **GND** do módulo azul.  

---

## Passo 5: Teste e Calibragem 🔧
1. Com tudo conectado, o circuito já funciona.  
2. Cubra o sensor do módulo com o dedo (simulando escuridão).  
3. Use uma chave de fenda pequena para girar o **trimpot laranja** no centro do módulo.  
4. Ajuste até o LED acender quando o sensor estiver tampado e apagar quando estiver descoberto.  

🌸 **Pronto! O circuito está calibrado e iluminado para o projeto especial.**




-------

# 🔌 Project Assembly Guide

### 🛠️ Before You Start
- **Resistors** have no polarity — they can be soldered in either direction.
- **LEDs** do have polarity: the longer leg is Positive (+), the shorter leg is Negative (−).
- **Crimping:** use pliers to clamp the metal terminal onto the wire, then slide the plastic sleeve over it.
- **Assembly:** check the project diagram [here](docs/diagram.jpg).
---

## Step 1: Preparing the LED ✨
1. Identify the longer (Positive) leg of the LED.
2. Solder the resistor to that longer leg.
3. On the other end of the resistor, solder a light-colored wire (to mark it as positive).
4. Solder a dark-colored wire to the shorter (Negative) leg of the LED.
5. Crimp a female terminal onto the free end of the light-colored wire.
   - Leave the dark wire without a terminal for now.

---

## Step 2: Battery Connection 🔋
The CR2032 battery cannot be soldered. We'll use the electrical tape trick instead.

1. Strip about 2 cm from the ends of a light-colored (Positive) and a dark-colored (Negative) wire.
2. Flatten the exposed copper ends into a small fan or brush shape.
3. Press the light wire against the Positive (+) side of the battery and secure it with electrical tape.
4. Press the dark wire against the Negative (−) side and tape it down as well.
5. Wrap a full loop of electrical tape around the battery to hold both wires firmly in place.
6. Crimp a female terminal onto the free end of the light-colored wire.
   - Leave the dark wire loose for now.

---

## Step 3: Connecting to the Module 🔵
1. Plug the female connector from the battery's positive wire into the +5V (VCC) pin on the blue module.
2. Plug the female connector from the LED's positive wire (with resistor) into the D0 pin on the module.

---

## Step 4: Joining the Negative Wires ⚡
At this point you should have two loose dark wires (one from the LED, one from the battery).

1. Hold the stripped ends of both wires together.
2. Twist them firmly with your fingers to form a single, thicker wire.
3. Crimp that doubled end into a single female terminal.
4. Plug that connector into the GND pin on the blue module.

---

## Step 5: Testing and Calibration 🔧
1. With everything connected, the circuit is already live.
2. Cover the module's sensor with your finger to simulate darkness.
3. Use a small flathead screwdriver to turn the orange trimmer potentiometer in the center of the module.
4. Adjust it until the LED turns on when the sensor is covered and turns off when it's uncovered.


🌸 All done! The circuit is calibrated and ready to light up your special project.

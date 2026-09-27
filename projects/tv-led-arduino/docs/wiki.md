***

# Wiki do Projeto – Televisão com Arduino

***

## 01. Introdução

Esta Wiki foi desenvolvida como guia completo do Projeto de Março da Connect Byte, cujo objetivo é construir uma “televisão” utilizando LED simples ou LED RGB, botão e Arduino Uno.

O conteúdo foi estruturado para conduzir o participante desde os conceitos fundamentais de eletrônica até a montagem e teste completo do circuito.

Ao final, espera‑se que o aprendiz compreenda:

*   O funcionamento básico de um circuito elétrico.
*   A importância de resistores.
*   O uso correto de LEDs simples e RGB.
*   O funcionamento de botões com Arduino.
*   Como alimentar a placa com bateria.
*   Como carregar um programa no Arduino.

Este material é recomendado para estudo individual, uso em oficinas e referência posterior.

***

## 02. Eletrônica Básica

### 2.1 Tensão, Corrente e Referência GND

Todo circuito elétrico depende de três elementos essenciais:

*   **Tensão (V):** força que empurra os elétrons.
*   **Corrente (A):** fluxo de elétrons pelo circuito.
*   **GND:** ponto de referência (0 V), completando o caminho da corrente.

No Arduino Uno:

*   5V é a tensão padrão fornecida aos componentes.
*   GND é o retorno obrigatório para fechar o circuito.

### 2.2 Resistores
> **TODO:** adicionar a imagem de resistores mencionada na documentação original.

Resistores limitam a corrente que flui por um componente sensível, como LEDs.

Exemplo simplificado:

*   LED típico: 2 V, 20 mA
*   Fonte: 5 V

Cálculo aproximado:  
**R = (5 V − 2 V) / 0,02 A = 150 Ω**

Para iniciantes, recomenda-se:

*   220 Ω
*   330 Ω

Esses valores garantem segurança e estabilidade no circuito.

### 2.3 Polaridade

Alguns componentes possuem orientação correta:

*   LEDs possuem ânodo (+) e cátodo (−).
*   Baterias possuem positivo e negativo.
*   LEDs RGB possuem terminal comum e terminais individuais para cada cor.

Conectar fora da polaridade pode impedir o funcionamento ou causar danos.

***

## 03. Componentes do Projeto

### 3.1 LED Simples
> **TODO:** adicionar a imagem de LEDs simples mencionada na documentação original.

*   Possui duas pernas.
*   Emite luz de uma única cor.
*   Necessita resistor obrigatoriamente.

Identificação:

*   Perna maior: ânodo (+)
*   Perna menor: cátodo (−)
*   Lado achatado na base: cátodo (−)

### 3.2 LED RGB
> **TODO:** adicionar a imagem do LED RGB mencionada na documentação original.

*   Possui quatro pernas.
*   Cada perna corresponde a uma cor: R, G e B.
*   A perna restante é a comum: ânodo comum ou cátodo comum.

Cada cor deve utilizar um resistor exclusivo.

### 3.3 Botão (Push-button)
> **TODO:** adicionar a imagem do botão mencionada na documentação original.

*   Utilizado para interação do usuário com o sistema.
*   Funciona como um interruptor temporário.
*   Requer normalmente resistor pull‑down ou pull‑up.

### 3.4 Suporte de Pilha e Bateria
> **TODO:** adicionar a imagem do suporte de pilhas mencionada na documentação original.

*   Fio vermelho: positivo
*   Fio preto: negativo
*   No Arduino:
    *   VIN ou 5V → positivo
    *   GND → negativo

### 3.5 Arduino Uno
> **TODO:** adicionar a imagem do Arduino Uno mencionada na documentação original.

*   Placa microcontrolada usada para controlar LEDs, botões e leituras.
*   Alimentada por USB ou bateria.
*   Possui pinos digitais, portas de alimentação e interface de programação.

***

## 04. Montagem do Circuito

### 4.1 Teste do LED Simples com Bateria

1.  Conectar a bateria ao LED utilizando um resistor de 220 Ω.
2.  Verificar polaridade.
3.  Confirmar que o LED acende levemente.

### 4.2 Montagem do LED Simples no Arduino

Pino digital → resistor → ânodo  
Cátodo → GND

### 4.3 Montagem do LED RGB

*   Conectar cada cor a um pino digital do Arduino.
*   Usar resistores individuais para cada cor.
*   Conectar perna comum ao 5V (ânodo comum) ou GND (cátodo comum), conforme o modelo.

### 4.4 Conexão do Botão

Configuração típica com pull‑down:

*   Um lado do botão → 5V
*   Outro lado → pino digital do Arduino
*   Pino digital também conectado a um resistor para GND (10 kΩ geralmente)

### 4.5 Alimentação com Bateria

*   Conectar fio vermelho do suporte de pilhas ao VIN ou 5V.
*   Conectar fio preto ao GND.
*   Garantir que a polaridade esteja correta.

***

## 05. Programação do Arduino

### 5.1 Ambiente de Desenvolvimento

*   Instalar Arduino IDE.
*   Selecionar a placa "Arduino Uno".
*   Selecionar a porta COM correta.

### 5.2 Upload do Código

1.  Conectar o Arduino via cabo USB.
2.  Abrir o arquivo-fonte do projeto.
3.  Verificar a seleção da placa.
4.  Carregar o código utilizando o botão "Upload".

### 5.3 Boas Práticas no Código

*   Declarar pinos claramente.
*   Incluir comentários explicativos.
*   Testar individualmente LED simples, RGB e botão antes de integração final.

***

## 06. Testes

### 6.1 Teste do LED Simples

*   Validar se acende quando programado.
*   Verificar brilho consistente.

### 6.2 Teste do LED RGB

*   Testar separadamente vermelho, verde e azul.
*   Confirmar funcionamento adequado da perna comum.

### 6.3 Teste do Botão

*   Confirmar leitura digital no monitor serial.
*   Testar comportamento com pull-down ou pull-up.

### 6.4 Teste de Alimentação

*   Verificar estabilidade quando alimentado por bateria.
*   Confirmar ausência de aquecimento dos componentes.

***

## 07. Solução de Problemas

### 7.1 LED não acende

*   Verificar polaridade.
*   Confirmar resistor.
*   Checar se está no pino correto.

### 7.2 LED RGB com cor incorreta

*   Comum conectado de forma errada.
*   Resistores ausentes ou incorretos.
*   Código configurado para modelo oposto (ânodo/cátodo).

### 7.3 Botão não funciona

*   Falta de resistor pull-down.
*   Fiação incorreta.
*   Mau contato na protoboard.

### 7.4 Arduino reinicia

*   Curto-circuito.
*   Sobrecarga nos pinos.
*   Fonte insuficiente.

***

## 08. Boas Práticas

*   Testar individualmente cada componente.
*   Evitar soldagem desnecessária se iniciante.
*   Manter organização dos fios.
*   Registrar alterações no código.
*   Não energizar simultaneamente USB e bateria sem conhecer a topologia elétrica.

***

## 09. Considerações Finais

O Projeto de Março da Connect Byte foi desenvolvido para introduzir de forma prática e segura os conceitos essenciais de eletrônica e programação embarcada.

Recomenda-se aos participantes:

*   Repetir os experimentos.
*   Testar variações de código.
*   Explorar novas combinações de LEDs e botões.
*   Estudar novos sensores e atuadores.

Este projeto serve como base sólida para aprofundamento em circuitos mais complexos e sistemas embarcados.

***

Feito com 💙 para quem quer/tem um hobby no mundo da tecnologia.
Connect Byte • Março 2026

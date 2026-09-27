#include <Arduino.h>
#include <Wire.h>

// =========================
// CONFIGURAÇÕES DE GIRO
// =========================

// CALCULADO matematicamente (exemplo do protótipo):
// - Distância entre rodas: 20 cm 
// - Raio da roda: 3 cm (diâmetro 6 cm)
// - Motor: 208 RPM a velocidade máxima (255)

// =========================
// CÁCULO MATEMÁTICO 
// =========================

// 1️⃣ Diâmetro = 3 × 2 = 6 cm
// 2️⃣ Perímetro = 3.14159 × 6 = 18.85 cm
// 3️⃣ Velocidade = (208 × 18.85) ÷ 60 = 65.35 cm/s
// 4️⃣ Raio_giro = 20 ÷ 2 = 10 cm
// 5️⃣ Arco = 0.25 × 6.28318 × 10 = 15.71 cm
// 6️⃣ Tempo = 15.71 ÷ 65.35 = 0.240 s
// 7️⃣ Tempo_ms = 0.240 × 1000 = 240 ms 

// Resultado: ~240ms para girar 90° (um quarto de volta)
// AJUSTE se necessário (variações por atrito, deslizamento, etc)

#define TEMPO_GIRO_90_GRAUS 240      // Tempo para girar 90° (faça testes empíricos aqui) - POLVO -> 400

// ========================================================================
// 🔧 MODO DE CALIBRAÇÃO
// ========================================================================
// Se MODO_CALIBRAR_GIRO = true:
//   O robô vai girar 90° repetidamente para você testar
//   e ajustar o TEMPO_GIRO_90_GRAUS até ficar perfeito!
//
// Se MODO_NORMAL = true:
//   O robô executa a sequência completa
// ========================================================================

#define MODO_CALIBRAR_GIRO false  // true = testa o giro | false = desligado
#define MODO_NORMAL true          // true = executa sequência | false = desligado

// ========================================================================
// 📍 PINAGEM - CONEXÕES DOS MOTORES (Driver L9110S)
// ========================================================================
// Conecte os fios do Arduino no driver de motores L9110S:
//
//   Arduino → L9110S
//   Pino 7  → M1_A (Motor Direito - Entrada A)
//   Pino 8  → M1_B (Motor Direito - Entrada B)
//   Pino 4  → M2_A (Motor Esquerdo - Entrada A)
//   Pino 5  → M2_B (Motor Esquerdo - Entrada B)
//
// ========================================================================

#define M1_A 7  // Motor DIREITO - Entrada A
#define M1_B 8  // Motor DIREITO - Entrada B
#define M2_A 4  // Motor ESQUERDO - Entrada A
#define M2_B 5  // Motor ESQUERDO - Entrada B

// ========================================================================
// 💡 LED DO OLHO DO POLVO
// ========================================================================
// Conecte um LED no pino 11 (com resistor de 220Ω):
//   Arduino Pino 11 → Resistor 220Ω → LED (+) → GND
//
// Este LED vai piscar no ritmo de samba durante toda a sequência! 🎵
// ========================================================================

#define LED_OLHO_POLVO 11  // Pino do LED que pisca

// =========================
// CONFIGURAÇÕES DE VELOCIDADE
// =========================
#define VELOCIDADE_FRENTE 200    // 255 é a MÁXIMA velocidade (não coloque mais que esse valor)
#define VELOCIDADE_CURVA 200     // 255 é a MÁXIMA velocidade nas curvas

// ========================================================================
// 🎵 LED OLHO DO POLVO - RITMO DE SAMBA
// ========================================================================
// Esta parte faz o LED piscar no ritmo de samba (2/4)
// Padrão: TUM-tum-TUM (pausa) - repete!
// ========================================================================

unsigned long ultimaPiscadaOlho = 0;  // Guarda quando foi a última piscada
int passoSamba = 0;                    // Qual passo do ritmo estamos
int ritmoSamba[] = {200, 100, 150, 100, 200, 250};  // Tempos de cada batida

// Função que faz o LED piscar no ritmo de samba
void piscarOlhoSamba() {
  unsigned long tempoAtual = millis();  // Pega o tempo atual
  
  // Verifica se já passou o tempo da batida atual
  if (tempoAtual - ultimaPiscadaOlho >= ritmoSamba[passoSamba]) {
    ultimaPiscadaOlho = tempoAtual;
    
    // Passos pares: LIGA o LED (TUM!)
    // Passos ímpares: DESLIGA o LED (pausa)
    if (passoSamba % 2 == 0) {
      digitalWrite(LED_OLHO_POLVO, HIGH);  // Liga LED
    } else {
      digitalWrite(LED_OLHO_POLVO, LOW);   // Desliga LED
    }
    
    // Avança para o próximo passo do ritmo
    passoSamba++;
    if (passoSamba >= 6) {
      passoSamba = 0;  // Volta para o começo (loop infinito)
    }
  }
}

// ========================================================================
// 🎮 FUNÇÕES DE CONTROLE DOS MOTORES
// ========================================================================
// Estas funções controlam cada motor individualmente.
// ========================================================================

// --- MOTOR ESQUERDO ---

void motorEsqFrente(int velocidade) {
  analogWrite(M2_A, 0);           // Entrada A desligada
  analogWrite(M2_B, velocidade);  // Entrada B ligada = motor gira para frente
}

void motorEsqTras(int velocidade) {
  analogWrite(M2_A, velocidade);  // Entrada A ligada = motor gira para trás
  analogWrite(M2_B, 0);           // Entrada B desligada
}

void motorEsqParar() {
  analogWrite(M2_A, 0);  // Ambas entradas desligadas = motor parado
  analogWrite(M2_B, 0);
}

// --- MOTOR DIREITO ---

void motorDirFrente(int velocidade) {
  analogWrite(M1_A, 0);           // Entrada A desligada
  analogWrite(M1_B, velocidade);  // Entrada B ligada = motor gira para frente
}

void motorDirTras(int velocidade) {
  analogWrite(M1_A, velocidade);  // Entrada A ligada = motor gira para trás
  analogWrite(M1_B, 0);           // Entrada B desligada
}

void motorDirParar() {
  analogWrite(M1_A, 0);  // Ambas entradas desligadas = motor parado
  analogWrite(M1_B, 0);
}

// =========================
// MOVIMENTOS
// =========================

void frente() {
  motorEsqFrente(VELOCIDADE_FRENTE);
  motorDirFrente(VELOCIDADE_FRENTE);
}

void parar() {
  motorEsqParar();
  motorDirParar();
}

void girarDireita() {
  motorEsqFrente(VELOCIDADE_CURVA);
  motorDirTras(VELOCIDADE_CURVA);
}

void girarEsquerda() {
  motorEsqTras(VELOCIDADE_CURVA);
  motorDirFrente(VELOCIDADE_CURVA);
}

// ========================================================================
// 🔄 FUNÇÕES DE GIRO DE 90 GRAUS
// ========================================================================
// Estas funções fazem o robô girar exatamente 90° (um quarto de volta)
// ========================================================================

// Gira 90° para a DIREITA
void girar90Direita() {
  girarDireita();                  // Começa a girar
  delay(TEMPO_GIRO_90_GRAUS);      // Espera o tempo calculado
  parar();                         // Para de girar
}

// Gira 90° para a ESQUERDA
void girar90Esquerda() {
  girarEsquerda();                 // Começa a girar
  delay(TEMPO_GIRO_90_GRAUS);      // Espera o tempo calculado
  parar();                         // Para de girar
}

// ========================================================================
// 🧪 MODO CALIBRAÇÃO DE GIRO
// ========================================================================
// Esta função é usada para testar e calibrar o giro de 90°
// Ative MODO_CALIBRAR_GIRO = true no início do código para usar
// ========================================================================

void calibrarGiro() {
  Serial.println("\n=== MODO CALIBRACAO DE GIRO ===");
  Serial.print("Tempo atual: ");
  Serial.print(TEMPO_GIRO_90_GRAUS);
  Serial.println(" ms");
  Serial.println("Testando giro 90° DIREITA...\n");
  
  delay(2000);  // Espera 2 segundos
  
  Serial.println(">>> GIRANDO AGORA! <<<");
  girar90Direita();  // Executa o giro
  
  Serial.println("\nVerifique se girou exatamente 90°");
  Serial.println("- Se girou MENOS: AUMENTE o TEMPO_GIRO_90_GRAUS");
  Serial.println("- Se girou MAIS: DIMINUA o TEMPO_GIRO_90_GRAUS");
  Serial.println("\nAguardando 5 segundos para repetir...\n");
  
  delay(5000);  // Espera 5 segundos antes de repetir
}


// =========================
// ESTADOS DA SEQUÊNCIA
// =========================
enum Estado {
  ANDANDO_1,           // Andando 1 segundo (início)
  PARANDO_1,           // Primeira parada
  GIRANDO_DIR,         // Girando 90° direita
  ESPERANDO_DIR,       // Esperando 10s virado direita
  VOLTANDO_CENTRO_1,   // Voltando ao centro
  PARANDO_2,           // Para para começar a andar para frente
  ANDANDO_2,           // Andando 1 segundo (final)
  PARADO_FINAL         // Parado definitivamente
};

Estado estadoAtual = ANDANDO_1;
unsigned long tempoInicio = 0;

// =========================
// SEQUÊNCIA COMPLETA
// =========================

void executarSequencia() {
  switch (estadoAtual) {
    
    // ===== 1. ANDAR FRENTE POR 1 SEGUNDO =====
    case ANDANDO_1:
      if (tempoInicio == 0) {
        tempoInicio = millis();
        frente();
      }
      
      if (millis() - tempoInicio >= 1000) {  // 1 segundo
        estadoAtual = PARANDO_1;
        tempoInicio = 0;
      }
      break;
    
    // ===== 2. PARAR =====
    case PARANDO_1:
      parar();
      delay(500);  // Pausa breve
      estadoAtual = GIRANDO_DIR;
      break;
    
    // ===== 3. GIRAR 90° DIREITA =====
    case GIRANDO_DIR:
      girar90Direita();
      tempoInicio = millis();
      estadoAtual = ESPERANDO_DIR;
      break;
    
    // ===== 4. ESPERAR 10 SEGUNDOS (DIREITA) =====
    case ESPERANDO_DIR:
      if (millis() - tempoInicio >= 10000) {  // 10 segundos
        estadoAtual = VOLTANDO_CENTRO_1;
        tempoInicio = 0;
      }
      break;
    
    // ===== 5. VOLTAR AO CENTRO =====
    case VOLTANDO_CENTRO_1:
      girar90Esquerda();  // Cancela o giro de 90° direita
      estadoAtual = PARANDO_2;
      break;

    // ===== 6. PARAR =====
    case PARANDO_2:
      parar();
      delay(1000);  // Pausa breve
      estadoAtual = ANDANDO_2;
      tempoInicio = 0;
      break;
    
    // ===== 9. ANDAR FRENTE POR 1 SEGUNDO (FINAL) =====
    case ANDANDO_2:
      if (tempoInicio == 0) {
        tempoInicio = millis();
        frente();
      }
      
      if (millis() - tempoInicio >= 1000) {  // 1 segundo
        estadoAtual = PARADO_FINAL;
        tempoInicio = 0;
      }
      break;
    
    // ===== 10. PARAR DEFINITIVAMENTE =====
    case PARADO_FINAL:
      parar();
      // Fica parado para sempre
      break;
  }
}

// =========================
// SETUP
// =========================

void setup() {
  pinMode(M1_A, OUTPUT);
  pinMode(M1_B, OUTPUT);
  pinMode(M2_A, OUTPUT);
  pinMode(M2_B, OUTPUT);
  
  pinMode(LED_OLHO_POLVO, OUTPUT);
  digitalWrite(LED_OLHO_POLVO, LOW);
  
  Serial.begin(9600);
  delay(500);
  
  Serial.println("\n=======================================");
  Serial.println("   🐙 ROBO POLVO - SEQUENCIA SAMBA 🎵");
  Serial.println("=======================================");
  Serial.println();
  
  if (MODO_CALIBRAR_GIRO) {
    Serial.println(">>> MODO: CALIBRACAO DE GIRO <<<");
    Serial.println("O robo vai girar 90° repetidamente");
    Serial.println("Ajuste TEMPO_GIRO_90_GRAUS ate ficar perfeito!");
  } else {
    Serial.println(">>> MODO: SEQUENCIA NORMAL <<<");
    Serial.print("Tempo de giro: ");
    Serial.print(TEMPO_GIRO_90_GRAUS);
    Serial.println(" ms");
  }
  
  Serial.println("🐙 Olho piscando no ritmo de SAMBA!");
  Serial.println();
  Serial.println("Iniciando em 3 segundos...");
  delay(3000);
  Serial.println("\n>>> INICIANDO! <<<\n");
  
  parar();
  tempoInicio = 0;
}

// ========================================================================
// 🔄 LOOP PRINCIPAL
// ========================================================================
// Esta função roda REPETIDAMENTE, para sempre, depois do setup().
// É aqui que o robô executa suas ações continuamente!
// ========================================================================

void loop() {
  // SEMPRE pisca o olho do polvo no ritmo de samba! 🎵
  piscarOlhoSamba();
  
  // Verifica qual modo está ativo e executa a função correspondente
  if (MODO_CALIBRAR_GIRO) {
    // Modo calibração: gira repetidamente para testar o tempo
    calibrarGiro();
  } else {
    // Modo normal: executa a sequência completa
    executarSequencia();
    delay(50);  // Pequena pausa (50 milissegundos)
  }
}
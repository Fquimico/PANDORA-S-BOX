// Define os pinos dos LEDs
int led1 = 8; // Define o pino digital 8 como o pino do LED1
int led2 = 9; // Define o pino digital 9 como o pino do LED2

void setup() {
  // Inicializa os pinos como saída
  pinMode(led1, OUTPUT); // Configura o pino do LED1 como saída
  pinMode(led2, OUTPUT); // Configura o pino do LED2 como saída

  // Inicializa a comunicação serial para o módulo HC-06
  Serial.begin(9600); // Inicia a comunicação serial com a velocidade de transmissão de 9600 bps
}

void loop() {
  if (Serial.available() > 0) { // Verifica se há dados disponíveis para leitura na porta serial
    char comando = Serial.read(); // Lê o caractere recebido pela porta serial

    if (comando == '8') { // Se o comando recebido for '8'
      digitalWrite(led1, HIGH); // Acende o LED1
      digitalWrite(led2, LOW); // Apaga o LED2
    } else if (comando == '9') { // Se o comando recebido for '9'
      digitalWrite(led1, LOW); // Apaga o LED1
      digitalWrite(led2, HIGH); // Acende o LED2
    } else if (comando == '0') { // Se o comando recebido for '0'
      digitalWrite(led1, LOW); // Apaga o LED1
      digitalWrite(led2, LOW); // Apaga o LED2
    } else if (comando == '2') { // Se o comando recebido for '2'
      digitalWrite(led1, HIGH); // Acende o LED1
      digitalWrite(led2, HIGH); // Acende o LED2
    }
  }
}

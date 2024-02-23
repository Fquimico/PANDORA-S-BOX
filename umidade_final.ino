// Define os pinos dos LEDs
int ledVermelho = 8; // LED vermelho indicando solo seco
int ledAmarelo = 9; // LED amarelo indicando solo moderadamente úmido
int ledVerde = 10; // LED verde indicando solo úmido

// Define o pino do sensor de umidade do solo
int sensorUmidadeSolo = A0;

void setup() {
  // Inicializa os pinos dos LEDs como saída
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  Serial.begin(9600); // Inicializa a comunicação serial
}

void loop() {
  // Lê o valor do sensor de umidade do solo
  int valorUmidade = analogRead(sensorUmidadeSolo);

  // Converte o valor lido para percentual de umidade (0-100%)
  float percentualUmidade = map(valorUmidade, 1023, 0, 0, 100);

  // Ativa os LEDs e imprime o estado do solo de acordo com o percentual de umidade
  if (percentualUmidade < 30) {
    digitalWrite(ledVermelho, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, LOW);
    Serial.println("Estado do solo: Seco");
    Serial.print("Percentual de umidade: ");
    Serial.print(percentualUmidade);
    Serial.println("%");
    Serial.println(valorUmidade);

  } else if (percentualUmidade >= 30 && percentualUmidade < 50) {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVerde, LOW);
    Serial.println("Estado do solo: Moderado");
    Serial.print("Percentual de umidade: ");
    Serial.print(percentualUmidade);
    Serial.println("%");
     Serial.println(valorUmidade);
  } else {
    digitalWrite(ledVermelho, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVerde, HIGH);
    Serial.println("Estado do solo: Úmido");
    Serial.print("Percentual de umidade: ");
    Serial.print(percentualUmidade);
    Serial.println("%");
     Serial.println(valorUmidade);
  }

  delay(1000); // Aguarda 1 segundo antes da próxima leitura
}

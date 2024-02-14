// Definir os pinos do buzzer e do sensor LDR
int buzzerPin = 2;
int ldrPin = A0;

// Definir o valor limite para o sensor LDR
int limiteLDR = 150;

void setup() {
  // Inicializar o monitor serial
  Serial.begin(9600);

  // Configurar o pino do buzzer como saída
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // Ler o valor do sensor LDR
  int valorLDR = analogRead(ldrPin);

  // Verificar se o laser foi interrompido
  if (valorLDR > limiteLDR) {
    // Emitir um sinal de alerta no buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(1000);
    digitalWrite(buzzerPin, LOW);

    // Imprimir a mensagem de alerta no monitor serial
    Serial.println("ALERTA DE INTRUSO, PERIGO!!!!");
  } else {
    // Imprimir a mensagem de perímetro seguro no monitor serial
    Serial.println("PERIMETRO SEGURO !!!");
  }

  // Aguardar um segundo antes de repetir o loop
  delay(1000);
}

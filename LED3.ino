// Define os pinos dos LEDs
int led1 = 8;
int led2 = 9;

void setup() {
  // Inicializa os pinos como saída
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  // Inicializa a comunicação serial para o módulo HC-06
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char comando = Serial.read(); 

    if (comando == '8') {
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, LOW); 
    } else if (comando == '9') {
      digitalWrite(led1, LOW); 
      digitalWrite(led2, HIGH); 
    } else if (comando == '0') {
      digitalWrite(led1, LOW); 
      digitalWrite(led2, LOW); 
    } else if (comando == '2') {
      digitalWrite(led1, HIGH); 
      digitalWrite(led2, HIGH); 
    }
  }
}

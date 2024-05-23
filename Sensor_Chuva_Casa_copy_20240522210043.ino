// Programa : Teste sensor de chuva
// Autor : Arduino e Cia

int pino_d = 52; //Pino ligado ao D0 do sensor
int pino_a = A0; //Pino ligado ao A0 do sensor
int val_d = 0; //Armazena o valor lido do pino digital
int val_a = 0; //Armazena o valor lido do pino analogico

void setup()
{
  // Define os pinos do sensor como entrada
  pinMode(pino_d, INPUT);
  pinMode(pino_a, INPUT);
  Serial.begin(9600);
}
void loop()
{
  //Le e arnazena o valor do pino digital
  val_d = digitalRead(pino_d);
  //Le e armazena o valor do pino analogico
  val_a = analogRead(pino_a);
  //Envia as informacoes para o serial monitor
  Serial.print("Valor digital : ");
  Serial.print(val_d);
  Serial.print(" - Valor analogico : ");
  Serial.print(val_a);
 
  // Acende o led de acordo com a intensidade 
  if (val_a >900 && val_a <1024)
  {
    Serial.println(" - intensidade baixa");
  }
  if (val_a >400 && val_a <900)
  {
    Serial.println(" - intensidade média");
  }
  if (val_a > 0 && val_a <400)
  {
    Serial.println(" - intensidade alta");
  }
  delay(1000);
}
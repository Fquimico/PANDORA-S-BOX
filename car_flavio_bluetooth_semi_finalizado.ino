//Engine
#define ENA 7
#define N1 6
#define N2 5
#define N3 4
#define N4 3
#define ENB 2

void setup() {
  /*Define Type Engine Pins */
  pinMode(ENA, OUTPUT);
  pinMode(N1, OUTPUT);
  pinMode(N2, OUTPUT);
  pinMode(N3, OUTPUT);
  pinMode(N4, OUTPUT);
  pinMode(ENB, OUTPUT);

  /*Inicialize Serial Comunication*/
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char comand = Serial.read();
    Serial.println(comand);
    if (comand == 'F') {
      forwardEngine();
    }
    else if (comand == 'S') {
      stopEngine();
    }
    else if (comand == 'L') {
      leftEngine();
    }
    else if (comand == 'R') {
      rightEngine();
    }
    else if (comand == 'B') {
      backEngine();
    }
  }
}

void forwardEngine() {
  analogWrite(ENA, 255);
  digitalWrite(N1, HIGH);
  digitalWrite(N2, LOW);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, LOW);
  analogWrite(ENB, 200);
}

void backEngine() {
  analogWrite(ENA, 255);
  digitalWrite(N1, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
  analogWrite(ENB, 255);
}

void stopEngine() {
  analogWrite(ENA, 0);
  digitalWrite(N1, HIGH);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, HIGH);
  analogWrite(ENB, 0);
}

void rightEngine() {
  analogWrite(ENA, 255);
  digitalWrite(N1, LOW);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, HIGH);
  digitalWrite(N4, HIGH);
  analogWrite(ENB, 0);
}

void leftEngine() {
  analogWrite(ENA, 0);
  digitalWrite(N1, HIGH);
  digitalWrite(N2, HIGH);
  digitalWrite(N3, LOW);
  digitalWrite(N4, HIGH);
  analogWrite(ENB, 135);
}

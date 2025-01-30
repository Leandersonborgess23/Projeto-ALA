const int analogPin = A0;
const int ledPin = 13;
const int threshold = 900;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valores[500];

  for (int i = 0; i < 500; i++) {
    valores[i] = analogRead(analogPin);
    delayMicroseconds(250);
  }

  for (int i = 0; i < 500; i++) {
    Serial.print(valores[i]);  // Imprime valor real lido
    Serial.print(", ");  

    if (valores[i] >= threshold) {
      Serial.println(1000);  // Nível lógico alto
    } else {
      Serial.println(500);   // Nível lógico baixo
    }
  }

  delay(1000);
}



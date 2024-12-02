const int analogPin = A0;
const int ledPin = 13;
const int threshold = 900;
const unsigned long waveTime = 1000 ; // Tempo em milissegundos

unsigned long startTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int analogValue = analogRead(analogPin);
  Serial.println(analogValue);

  if (analogValue > threshold) {
    if (millis() - startTime >= waveTime) {
      digitalWrite(ledPin, HIGH); // Acende o LED
    }
  } else {
    startTime = millis();         // Reseta o tempo
    digitalWrite(ledPin, LOW);    // Apaga o LED
  }
}
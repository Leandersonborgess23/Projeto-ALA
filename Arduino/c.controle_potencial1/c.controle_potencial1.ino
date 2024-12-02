#define optoPin 4           // Pino que controla o PC817
const int analogPin = A0;   // Entrada analógica (sensor ou potenciômetro)
const int threshold = 900;  // Limite para acionar a carga
volatile int power = 100;   // Potência inicial (0 a 256)
int analogValue = 0;        // Valor lido do sensor

void setup() {
  Serial.begin(9600);
  pinMode(optoPin, OUTPUT);
  digitalWrite(optoPin, LOW); // Garante que a carga começa desligada
}

void loop() {
  analogValue = analogRead(analogPin); // Lê o sensor
  Serial.println(analogValue);

  if (analogValue > threshold) {
    // Ajusta a potência com base no sensor
    power = map(analogValue, threshold, 1023, 0, 256);

    // Calcula o tempo de condução em microssegundos
    int conductionTime = map(power, 0, 256, 0, 8333); // Até 8.33ms (meio ciclo AC)
    digitalWrite(optoPin, HIGH);                      // Liga a carga
    delayMicroseconds(conductionTime);                // Tempo proporcional à potência
    digitalWrite(optoPin, LOW);                       // Desliga a carga
  } else {
    digitalWrite(optoPin, LOW); // Mantém a carga desligada
  }

  delay(10); // Atraso para estabilidade
}

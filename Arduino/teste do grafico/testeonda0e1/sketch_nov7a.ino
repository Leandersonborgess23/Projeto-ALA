//teste da onda retificada

const int analogPin = A0;
const int ledPin = 13;
const int threshold = 900;

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  int valores[100];

  int analogValue = analogRead(analogPin);
  for (int i=0; i<99; i++){
    analogValue = analogRead(analogPin);
    valores[i] = analogValue;
    //delayMicroseconds(250);
  }

  for (int i=0; i<99; i++){
    Serial.println(valores[i]);
    delay(500);
  }

  delay(1000);
  /*
   if (analogValue <= threshold) {
   digitalWrite(ledPin, LOW);  // desliga o LED
  } else {
    digitalWrite(ledPin, HIGH);  // liga o LED
  }
  *

}

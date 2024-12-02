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

  //valores[i] = analogValue;
    //delayMicroseconds(250);
 
  if (analogValue <= threshold) {
   digitalWrite(ledPin, LOW);  // desliga o LED
  }
  else {
    digitalWrite(ledPin, HIGH);  // liga o LED
  }
 

}

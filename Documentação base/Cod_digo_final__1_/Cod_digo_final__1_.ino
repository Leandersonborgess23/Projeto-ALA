int loadR = 3;
volatile int power = 100;

void zero_crosss_int() {
  //Cálculo do ângulo de disparo: 60Hz -> 8.33ms (1/2 ciclo)
  //(8333us - 8.33us) / 128 = 65 (aprox)
 int powertime = (65*power);
 //Matém o circuito desligado por powertime microssegundos
 delayMicroseconds (powertime);
 //Envia sinal ao TRIAC para que ele passe a conduzir
 digitalWrite(loadR, HIGH);
 //Espera alguns microssegundos para que o TRIAC receba o pulso 
 delayMicroseconds(8.33);
 //Desliga o pulso
 digitalWrite(loadR, LOW);
}

void setup() {
  pinMode(loadR, OUTPUT);
  //Inicializa interrupção. O número zero indica o pino 2 do Arduino,
  //zer_crosss_int é a função que será chamada toda vez que o pino 2 
  //subir (RISING) de valor 0 para 1
  attachInterrupt(0, zero_crosss_int, RISING);
}
  

void loop() {
  //Seta de potência para diferentes níveis. Se for uma lâmpada
  //2esta vai variar o brilho.
  power = 10;
  delay(1000);
  power = 60;
  delay(1000);
  power = 120;
  delay(1000);
  power = 180;
  delay(1000); 
  power = 240;
  delay(1000);
}			


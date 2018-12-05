#include <Ultrasonic.h>

//Define os pinos de utilizaçao de controle para o motor
int motorA1 = 4; //esquerda
int motorA2 = 5;
int motorB1 = 6;//direita
int motorB2 = 7;
int buzina = 8;
int enviaPino = 10;  //envia - trig
int recebePino = 11; //recebe - 00ho
int velocidade = 5; //0 < X < 255

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(enviaPino, recebePino);

void setup() {
  // Inicializa as portas como entrada e saída.
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzina, OUTPUT);
  // Inicializa a comunicação serial em 9600 bits.
  Serial.begin(9600);
}

void frente() {
  digitalWrite(motorA1, LOW); //motor a
  digitalWrite(motorA2, 150); //motor a
//  analogWrite(motorA2, 150);
  digitalWrite(motorB1,LOW); //motor b
 // analogWrite(motorB2, 150);
 digitalWrite(motorB2, 150);//motor b
}

void tras() {
  digitalWrite(motorA1, velocidade); //motor a
  digitalWrite(motorA2, LOW); //motor a
  digitalWrite(motorB1, velocidade); //motor b
  digitalWrite(motorB2, LOW); //motor b
  delay(1000);
  parado();
}

void esquerda() {
  digitalWrite(motorA1, velocidade); //ESQUERDA
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);//DIREITA
  digitalWrite(motorB2, LOW);
  //delay(500);
  //delay(1000);
  delay(900);
  parado();
}
void esquerda_volta() {
  digitalWrite(motorA1, LOW); //ESQUERDA
  digitalWrite(motorA2, velocidade);
  digitalWrite(motorB1, LOW);//DIREITA
  digitalWrite(motorB2, LOW);
  //delay(500);
  //delay(1000);
  delay(900);
  parado();
}

void direita() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, velocidade);
  digitalWrite(motorB2, LOW);
  delay(900); //anda bem
  parado();
}
void direita_volta() {
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, velocidade);
  delay(900); //anda bem
  parado();
}

void parado() {
  //o carro permanece parado.
  digitalWrite(motorA1, LOW);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(200);
}

void ligaBuzina() {
  //aciona a buzina.
  tone(buzina, 1500);
}
void desligaBuzina() {
  noTone(buzina);
}

float distancia, distD, distE;//em cm
long contador ;//contador em seg
int cont = 0;
void loop() {
  contador =  ultrasonic.timing(); //contador em seg
  //Le as informacoes do sensor, em cm
  distancia = ultrasonic.convert(contador, Ultrasonic::CM);
  frente();
 // if (distancia < 15 ) {
  if(distancia < 10){ 
   direita();  //vai girar para a direita e analisar
    contador = ultrasonic.timing(); //contador em seg
    distD = ultrasonic.convert(contador, Ultrasonic::CM);
    //if (distD < 15) {
      if(distD<10){
      direita_volta();
      esquerda(); //vai girar para a esquerda e analisar
      contador = ultrasonic.timing(); //contador em seg
      distE = ultrasonic.convert(contador, Ultrasonic::CM);
    //  if (distE > 15)
     if (distE >= 10)
      {
        frente();
      } else {
        esquerda_volta();
        direita();
        frente();
      }

    }

  }
}

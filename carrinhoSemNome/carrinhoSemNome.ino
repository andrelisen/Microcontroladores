#include <Ultrasonic.h>

//Define os pinos de utilizaçao de controle para o motor 
int motorA1 = 4;
int motorA2 = 5;
int motorB1 = 6;
int motorB2 = 7;

int buzina = 8;

int trigPin = 10;
int echoPin = 11;

int velocidade = 75; //0 < X < 255

void setup() {
  // Inicializa as portas como entrada e saída.
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(buzina, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // Inicializa a comunicação serial em 9600 bits.
  Serial.begin(9600);
}

void frente()
{
  digitalWrite(motorA1, velocidade); //motor a
  digitalWrite(motorA2, LOW); //motor a
  digitalWrite(motorB1, LOW); //motor b
  digitalWrite(motorB2, velocidade); //motor b
 //  delay(2000);
}

void tras()
{
  digitalWrite(motorA1, LOW); //motor a
  digitalWrite(motorA2, velocidade); //motor a
  digitalWrite(motorB1, velocidade); //motor b
  digitalWrite(motorB2, LOW); //motor b
//   delay(2000);
}

void direita()
{
  parado();
  delay(1000);
  digitalWrite(motorA1, velocidade);
  digitalWrite(motorA2, velocidade);
  digitalWrite(motorB1, velocidade);
  digitalWrite(motorB2,LOW);
  delay(500);
}

void esquerda()
{
  parado();
  delay(1000);
  digitalWrite(motorA1, velocidade);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, velocidade);
  digitalWrite(motorB2,velocidade);
  delay(500);
}


//void caminhoFrente()
//{
//  //O carro se movimenta para frente.
//    analogWrite(motorB1, 0);
//    analogWrite(motorA1, vSpeed);
//    analogWrite(motorA2, 0);
//    analogWrite(motorB2, vSpeed);
//}

//void caminhoRe()
//{
//   // o carro se movimenta para trás.
//    analogWrite(motorA1, 0);
//    analogWrite(motorB1, vSpeed);
//    analogWrite(motorB2, 0);
//    analogWrite(motorA2, vSpeed);
//}

//void caminhoFrenteEsquerda()
//{
//  // o carro se movimenta para Frente Esquerda.
//    analogWrite(motorA1, vSpeed); 
//    analogWrite(motorA2, 0);
//    analogWrite(motorB1, 100);    
//    analogWrite(motorB2, 0);
//}
//
//void caminhoFrenteDireita()
//{
//    // o carro se movimenta para Frente Direita.
//    analogWrite(motorA1, 100); 
//    analogWrite(motorA2, 0);
//    analogWrite(motorB1, vSpeed);      
//    analogWrite(motorB2, 0);
//}
//
//
//void caminhoReEsquerda()
//{
//    // o carro se movimenta para Trás Esquerda.
//    analogWrite(motorA1, 0);   
//    analogWrite(motorA2, vSpeed);
//    analogWrite(motorB1, 0); 
//    analogWrite(motorB2, 100);
//}
//
//void caminhoReDireita()
//{
//  // o carro se movimenta para Trás Direita.
//    analogWrite(motorA1, 0);   
//    analogWrite(motorA2, 0);
//    analogWrite(motorB1, 0);   
//    analogWrite(motorB2, vSpeed);
//}
// 
//void esquerda()
//{
//  //o carro se movimenta para esquerda.
//    analogWrite(motorA1, 0);
//    analogWrite(motorA2, vSpeed);
//    analogWrite(motorB1, vSpeed);
//    analogWrite(motorB2, 0);
//}

//void direita()
//{
//  //o carro se movimenta para direita.
//    analogWrite(motorA1, vSpeed);
//    analogWrite(motorA2, 0);
//    analogWrite(motorB1, 0);
//    analogWrite(motorB2, vSpeed);
//}

void parado()
{
  //o carro permanece parado.
    analogWrite(motorA1, 0);
    analogWrite(motorA2, 0);
    analogWrite(motorB1, 0);
    analogWrite(motorB2, 0);
}

void ligaBuzina()
{
  //aciona a buzina.
    tone(buzina,1500);   
}
void desligaBuzina()
{
    noTone(buzina);   
}

void controleUltrassonico()
{
    long duration, distance;
    digitalWrite(trigPin, LOW); 
    delay(2);
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    Serial.println(distance);
     if(distance > 20 ){
     // caminhoFrente();
     frente();  
     }
   else{
    direita(); 
     //  tras();
   //  caminhoRe();  
    // caminhoReDireita();
   }
   
//    if (distance <= 30) {
//    caminhoRe();
//    }
//    else {
//      
//    }
//    if (distance < 25) {
//      caminhoFrenteDireita();
//    }
//    else {
//    caminhoFrenteEsquerda();
//  }
//  if (distance < 20) {
//      caminhoReDireita();
//} 
 // else {
    //digitalWrite(led3, LOW);
 // }
 // if (distance < 15) {
   // digitalWrite(led4, HIGH);
//    sound = 950;
//}
 // else {
   // digitalWrite(led4,LOW);
 // }
  //if (distance < 10) {
   // digitalWrite(led5, HIGH);
  //  sound = 1000;
//}
 // else {
   // digitalWrite(led5,LOW);
 // }
 // if (distance < 5) {
   // digitalWrite(led6, HIGH);
 //   sound = 1050;
 // }
 // else {
    //digitalWrite(led6,LOW);
 // }
 
//  if (distance > 30 || distance <= 0){
//    Serial.println("Out of range");
//    desligaBuzina();
//  }
//  else {
//    Serial.print(distance);
//    Serial.println(" cm");
//    ligaBuzina();
//   
//  }
//  delay(500);
}
void loop()
{
   controleUltrassonico(); 
}

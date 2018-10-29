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
 // parado();
//  delay(1000);
  digitalWrite(motorA1, velocidade);
  digitalWrite(motorA2, velocidade);
  digitalWrite(motorB1, velocidade);
  digitalWrite(motorB2,LOW);
//  delay(500);
}

void esquerda()
{
 // parado();
 // delay(1000);
  digitalWrite(motorA1, velocidade);
  digitalWrite(motorA2, LOW);
  digitalWrite(motorB1, velocidade);
  digitalWrite(motorB2,velocidade);
//  delay(500);
}

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
    long duration, distance, distanceEsq, distanceDir;
    digitalWrite(trigPin, LOW); 
    delay(2);
    digitalWrite(trigPin, HIGH);
    delay(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
   
    Serial.println(distance);
     if(distance > 20 )
     {
     frente();  
     }
     else{
    parado();
    delay(125);
    direita();
    delay(125);
    duration = pulseIn(echoPin, HIGH);
    //distanceEsq = (duration/2) / 29.1;
    distanceDir = (duration/2) / 29.1;
    parado();
    esquerda();
    parado();
    delay(125);
    esquerda();
    delay(125);
    duration = pulseIn(echoPin, HIGH);
    distanceEsq = (duration/2) / 29.1;
    parado();
    direita();
    parado();  
    delay(125);
        if(distanceDir > distanceEsq)
        {
        direita();
        delay(125);
        frente();  
      }
      else{
      esquerda();
      delay(125);
      frente();
      }
 }
     //     else{
//      direita(); 
//        if(distance <20 && distance != 0)
//        {
//        esquerda();
//        }
//        else{
//          frente();
//        }
//     }
//     if(distance == 0)
//     {
//     tras();
//     }
}
void loop()
{
   controleUltrassonico(); 
}

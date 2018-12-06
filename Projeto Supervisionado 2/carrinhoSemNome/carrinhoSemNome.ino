#include <Ultrasonic.h>

  //Define os pinos de utilizaçao de controle para o motor 
  int motorA1 = 4; //esquerda
  int motorA2 = 5;
  int motorB1 = 6;//direita
  int motorB2 = 7;
  int buzina = 8;
  int enviaPino = 10;  //envia - trig
  int recebePino = 11; //recebe - echo



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
  
  void frente()
  {
    digitalWrite(motorA1, LOW); //motor a
//    digitalWrite(motorA2, velocidade); //motor a
    digitalWrite(motorA2, HIGH);
    digitalWrite(motorB1,LOW); //motor b
  //  digitalWrite(motorB2, velocidade);//motor b
  digitalWrite(motorB2, HIGH);
  }
  
  void esquerda()
  {
    digitalWrite(motorA1, HIGH); //ESQUERDA
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);//DIREITA
    digitalWrite(motorB2,LOW);
  }
  
  void direita()
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, HIGH);
    digitalWrite(motorB2,LOW);
   // delay(800); //anda bem
  //  parado();
  }
  
  void parado()
  {
    //o carro permanece parado.
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
  }
    int verificacao = 0;
    float distancia;//em cm
    long contador ;//contador em seg
   void loop()
  {
    contador =  ultrasonic.timing(); //contador em seg
    //Le as informacoes do sensor, em cm
    distancia = ultrasonic.convert(contador, Ultrasonic::CM);
        if(distancia > 20 ){
        frente();  
        }
        else{
          parado();
          delay(1000);
          direita();
          delay(580); //dobra 90 graus
        }
          contador = ultrasonic.timing(); //contador em seg
          distancia = ultrasonic.convert(contador, Ultrasonic::CM);
            if(distancia > 20){
              frente();  
              }
              else{
               parado();
               delay(1000);
               esquerda();
               delay(610);
               frente();
              }
   }

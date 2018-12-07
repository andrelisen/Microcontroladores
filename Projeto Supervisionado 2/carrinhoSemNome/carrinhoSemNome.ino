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
  delay(500);
  arrumar();
  }

  void arrumar(){
  digitalWrite(motorB1, LOW);
  digitalWrite(motorB2, LOW);
  delay(75);
  digitalWrite(motorB1, HIGH);
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
    float distancia;//EM CM
    long contador = 0;//CONTADOR EM SEG
void loop()
        {
        contador =  ultrasonic.timing(); //CONTADOR EM SEG
       //LÊ AS INFORMAÇÕES DO SENSOR, EM CM
      distancia = ultrasonic.convert(contador, Ultrasonic::CM);  
 if(distancia > 30 )
           {
               frente();  
               
           }
else{
        if(verificacao == 0){
          parado();
          delay(1000);
          direita();
          delay(580); //DOBRA 90 GRAUS
        }else{ //VIU QUE MESMO DOBRANDO P/ ESQUERDA NÃO TERIA COMO ANDAR NOVAMENTE JÁ QUE VOLTAVA PARA O LOCAL AONDE ESTAVA
              parado();
              delay(1000);
              esquerda();
              delay(610);
               frente();
               verificacao = 0;
        }
       }
  contador = ultrasonic.timing(); 
  distancia = ultrasonic.convert(contador, Ultrasonic::CM);
            if(distancia > 30){
      frente();        
            }
  else{
    parado();
    delay(1000);
    esquerda();
    delay(610);
    frente();
    verificacao ++;
       }
}

#include <Ultrasonic.h>

  //Define os pinos de utilizaçao de controle para o motor 
  int motorA1 = 4; //esquerda
  int motorA2 = 5;
  int motorB1 = 6;//direita
  int motorB2 = 7;
  int buzina = 8;
  int enviaPino = 10;  //envia - trig
  int recebePino = 11; //recebe - echo
  int velocidade = 254; //0 < X < 255
  
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
    digitalWrite(motorA2, velocidade); //motor a
    digitalWrite(motorB1,LOW); //motor b
    digitalWrite(motorB2, velocidade);//motor b
  }
  
  void tras()
  {
    digitalWrite(motorA1, velocidade); //motor a
    digitalWrite(motorA2, LOW); //motor a
    digitalWrite(motorB1, velocidade); //motor b
    digitalWrite(motorB2, LOW); //motor b
    delay(800);
  }
  
  void esquerda()
  {
    digitalWrite(motorA1, velocidade); //ESQUERDA
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);//DIREITA
    digitalWrite(motorB2,LOW);
    delay(800);
  }
  
  void direita()
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, velocidade);
    digitalWrite(motorB2,LOW);
    delay(800); //anda bem
  }
  
  void parado()
  {
    //o carro permanece parado.
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
      delay(800);
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
    float distancia=0;//em cm
    long contador=0;//contador em seg
   
  void loop()
  {
    contador =  ultrasonic.timing(); //contador em seg
    //Le as informacoes do sensor, em cm
    distancia = ultrasonic.convert(contador, Ultrasonic::CM);
        if(distancia > 15){
          frente();  
        }else{
          parado();
          direita();
          parado();
          contador = ultrasonic.timing(); //contador em seg
          distancia = ultrasonic.convert(contador, Ultrasonic::CM);
            if(distancia > 15){
              frente();
            }
            else{
             parado();
             esquerda();
             parado();
             contador = ultrasonic.timing(); //contador em seg
             distancia = ultrasonic.convert(contador, Ultrasonic::CM);
              if(distancia > 15){
                frente();
                }else{
                parado();
                direita();
                parado();
              }
          }
        }
  }

#include <Ultrasonic.h>

  //Define os pinos de utilizaçao de controle para o motor 
  int motorA1 = 4; //esquerda
  int motorA2 = 5;
  int motorB1 = 6;//direita
  int motorB2 = 7;
  int buzina = 8;
  int enviaPino = 10;  //envia - trig
  int recebePino = 11; //recebe - echo
  int velocidade = 150; //0 < X < 255
  
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
    delay(2000);
  }
  
  void esquerda()
  {
    digitalWrite(motorA1, velocidade); //ESQUERDA
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, LOW);//DIREITA
    digitalWrite(motorB2,LOW);
    delay(500);
    parado();
  }
  
  void direita()
  {
    digitalWrite(motorA1, LOW);
    digitalWrite(motorA2, LOW);
    digitalWrite(motorB1, velocidade);
    digitalWrite(motorB2,LOW);
    delay(1000);
    parado();
  }
  
  void parado()
  {
    //o carro permanece parado.
      digitalWrite(motorA1, LOW);
      digitalWrite(motorA2, LOW);
      digitalWrite(motorB1, LOW);
      digitalWrite(motorB2, LOW);
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
    //Le as informacoes do sensor, em cm
    float distancia;//em cm
    long contador = ultrasonic.timing(); //contador em seg
    distancia = ultrasonic.convert(contador, Ultrasonic::CM);
    //inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
    //Exibe informacoes no serial monitor
    Serial.print("Distancia em cm: ");
    Serial.print(distancia);
   // Serial.print(" - Distancia em polegadas: ");
  //  Serial.println(inMsec);
    //delay(1000);
      
  //    long duration, distance, distanceEsq, distanceDir;
  //   // digitalWrite(trigPin, LOW); 
  //   // delay(2);
  //    digitalWrite(trigPin, HIGH); //echo recebe trig manda
  //    delay(100);
  //    //digitalWrite(trigPin, LOW);
  //    duration = pulseIn(echoPin, HIGH);
  //    distance = (duration/2) / 29.1;
  //   
  //    Serial.println(distance);
        if(distancia > 15 ){
         frente();  
        }
        
        if(distancia <= 5){
          tras();
        }
  
        if(distancia < 15){
          direita();  
          contador = ultrasonic.timing(); //contador em seg
          distancia = ultrasonic.convert(contador, Ultrasonic::CM);
            if(distancia > 15){
              frente();
            }else{
              esquerda();
              esquerda();
              contador = ultrasonic.timing(); //contador em seg
              distancia = ultrasonic.convert(contador, Ultrasonic::CM);
              if(distancia > 15){
                frente();
              }else{
               direita();   
              }
            }
        }
  //       else
  //     {
  //       ligaBuzina();
  //       delay(15);
  //       desligaBuzina();
  //        parado();
  //          direita();
  //        delay(90);
  //        parado();
  //        duration = pulseIn(echoPin, HIGH);
  //        distanceDir = (duration/2) / 29.1;
  //        delay(10);
  //        esquerda();
  //        delay(10);
  //        parado();
  //        esquerda();
  //        delay(90);
  //        parado();        
  //        duration = pulseIn(echoPin, HIGH);
  //        distanceEsq = (duration/2) / 29.1;
  //        delay(10);
  //        direita();
  //        delay(90);
  //        parado();  
  //          if(distanceDir > distanceEsq)
  //          {
  //            direita();
  //            delay(90);
  //            frente();  
  //          }
  //          else
  //          {
  //          esquerda();
  //          delay(90);
  //          frente();
  //          }
  //     }
  //     if(distance == 0 || distanceDir == 0 || distanceEsq == 0)
  //     {
  //     tras();
  //     delay(30);
  //     direita();
  //     delay(180);
  //     frente();  
  //     }
  }
  void loop()
  {
     controleUltrassonico(); 
  }

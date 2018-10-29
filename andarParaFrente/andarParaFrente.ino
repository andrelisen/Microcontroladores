//Programa : Controle 2 motores DC usando Ponte H L298N
//Autor : FILIPEFLOP
 
//Definicoes pinos Arduino ligados a entrada da Ponte H
int IN1 = 4;
int IN2 = 5;
int IN3 = 6;
int IN4 = 7;
  
void setup()
{
  //Define os pinos como saida
 pinMode(IN1, OUTPUT);
 pinMode(IN2, OUTPUT);
 pinMode(IN3, OUTPUT);
 pinMode(IN4, OUTPUT);
}
  
void loop()
{
  digitalWrite(IN1, HIGH); //motor a
  digitalWrite(IN2, LOW); //motor a
  digitalWrite(IN3, LOW); //motor b
  digitalWrite(IN4, HIGH); //motor b
   delay(2000);
}


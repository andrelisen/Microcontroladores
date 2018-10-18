                                // A B C D E F G   
byte seven_seg_digits[11][7] = {  {0,1,1,0,1,1,1},//H
                                  {1,0,0,1,1,1,1},//E
                                  {0,0,0,1,1,1,0},//L
                                  {0,0,0,1,1,1,0},//L
                                  {1,1,1,1,1,1,0},//O
                                  {1,1,1,0,1,1,1},//A
                                  {1,1,1,0,0,0,0},//T
                                  {1,1,1,1,0,0,1},//3
                                  {1,1,0,1,1,0,1},//2
                                  {1,1,1,1,1,1,1},//8
                                  {1,1,0,0,1,1,1},//P
                                 };
byte count = 0;
int botao = 2;
int estadoBotao;

/*
Faça com que as transições das letras sejam feitas com interrupções,
das seguintes formas:
• Nos pinos INT0 e INT1;
• Com Pin Change;
• Usando Timer.*/

void setup() 
{
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
  writePonto(0);  //inicializa ponto decimal como desligado
  pinMode(2, INPUT);//Esta inicializando o botao que esta na posicao 20
 attachInterrupt(0, reset, CHANGE);//digitalPinToInterrupt(20)
 Serial.begin(9600);
}
  
void writePonto(byte modo)   //Funcao que aciona o ponto no display
{  
  digitalWrite(10, modo);
}

void sevenSegWrite(byte digit)  //Funcao que aciona o display
{
  byte pin = 3;

  //Percorre o array ligando os segmentos correspondentes ao digito
  for (byte segCount = 0; segCount < 7; ++segCount)  
  { 
    digitalWrite(pin, seven_seg_digits[digit][segCount]);
    ++pin;
  }
    writePonto(1);  //Liga o ponto
    delay(100);   //Aguarda 100 milisegundos
    writePonto(0);  //Desliga o ponto
}

void loop() 
{
   if(count ==11)
   {
     count = 0;
   }
   else{
     sevenSegWrite(count);
     count++;
    delay(1000); 
   }
}     

void reset()
  {
    count = 0;
    delay(1000);
    digitalWrite(13,LOW);
    delay(1000);
    digitalWrite(13,HIGH);
  }

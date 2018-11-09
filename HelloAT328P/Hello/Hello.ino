                                   // A B C D E F G   
byte matrizModo[11][7] = {        {0,1,1,0,1,1,1},//H
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

/*
Faça com que as transições das letras sejam feitas com interrupções,
das seguintes formas:
• Nos pinos INT0 e INT1;
• Com Pin Change;
• Usando Timer.*/
//LOW = 1 HIGH = 0

void setup() 
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(13, OUTPUT);
  writePonto(0);  //inicializa ponto decimal como desligado
  pinMode(2, INPUT);//Esta inicializando o botao 
  pinMode(3, INPUT);
  attachInterrupt(0, interrupt0, RISING); // de alto para baixo
  attachInterrupt(1, interrupt1, RISING);
}
  
void writePonto(byte modo)   //Funcao que aciona o ponto no display
{  
  digitalWrite(11, modo);
}

void escreveDisplay(byte numero)  //Funcao que aciona o display
{
  byte pin = 4;

  //Percorre o array ligando os segmentos correspondentes ao digito
  for (byte letra = 0; letra < 7; ++letra)  
  { 
    digitalWrite(pin, matrizModo[numero][letra]);
    ++pin;
  }
    writePonto(1);  //Liga o ponto
    delay(100);   //Aguarda 100 milisegundos
    writePonto(0);  //Desliga o ponto
}

void loop() 
{

}

void interrupt0() //transcorrer as palavras de tras para frente
{
  if(count == 0) //significa que ainda nao foi digitado nada
  {
     delay(10000);
     count = 10;
     escreveDisplay(count);
     delay(10000);
  }
  else{
         delay(10000);
         count = count - 1;
         escreveDisplay(count);
         delay(10000);
  }
}

void interrupt1() // transcorrer as palavras de frente para tras
{
  if(count == 0 || count == 11) //significa que ainda nao foi digitado nada
  {
     delay(10000);
     count = 0;
     escreveDisplay(count);
     delay(10000);    
     count = count + 1;
  }
  else{
         delay(10000);
         escreveDisplay(count);
          count = count + 1;
         delay(10000);  
  }
}


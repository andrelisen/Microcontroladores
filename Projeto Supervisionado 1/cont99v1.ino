                                // A B C D E F G   
byte matrizDireita[10][7] =      { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                 { 0,1,1,0,0,1,1 },  // = Digito 4
                                 { 1,0,1,1,0,1,1 },  // = Digito 5
                                 { 1,0,1,1,1,1,1 },  // = Digito 6
                                 { 1,1,1,0,0,0,0 },  // = Digito 7
                                 { 1,1,1,1,1,1,1 },  // = Digito 8
                                 { 1,1,1,0,0,1,1 },  // = Digito 9
                                 };
                                // A B C D E F G   
byte matrizEsquerda[10][7] =     { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                 { 0,1,1,0,0,1,1 },  // = Digito 4
                                 { 1,0,1,1,0,1,1 },  // = Digito 5
                                 { 1,0,1,1,1,1,1 },  // = Digito 6
                                 { 1,1,1,0,0,0,0 },  // = Digito 7
                                 { 1,1,1,1,1,1,1 },  // = Digito 8
                                 { 1,1,1,0,0,1,1 },  // = Digito 9
                                 };                                 

byte countDireita = 0;
byte countEsquerda = 0;

/*
--Utilize o timer 1 para controlar a periodicidade de atualização do
display 7 segmentos (valor que será apresentado). EU SOU O CONTADOR 
--Utilize o timer 2 para controlar a periodicidade que o LED pisca
(apresentação da informação no display). EU SOU O DELAY
*/

void setup() 
{
  byte i;
  for(i = 0; i<14;++i)
  {
    pinMode(i, OUTPUT);//SETANDO LEDS DO DISPLAY DE 7 SEGMENTOS 
  }  
}
  

void escreveDisplayDireita(byte numero)  //Funcao que aciona o display
{
  byte pino = 0;
  //Percorre o array ligando os segmentos correspondentes ao digito
  //for(byte letra = 0; letra <7; ++letra)
  //{
    for (byte letra = 0; letra < 7; ++letra)  
    { 
    digitalWrite(pino, matrizDireita[numero][letra]);
    ++pino;
    }
  //}
}

void escreveDisplayEsquerda(byte numero)  //Funcao que aciona o display
{
  byte pino2 = 7;
  //Percorre o array ligando os segmentos correspondentes ao digito
    for (byte letra = 0; letra < 7; ++letra)  
    { 
    digitalWrite(pino2, matrizEsquerda[numero][letra]);
    ++pino2;
    }
}

void loop() 
{
    if(countDireita == 9)//quando termina unidade
    {
       countEsquerda++;
      escreveDisplayEsquerda(countEsquerda);
      countDireita = 0;
      escreveDisplayDireita(countDireita);
      delay(500);
}else
    { 
      countDireita++;
      escreveDisplayDireita(countDireita);
      delay(500);
    }
    if(countDireita == 9 && countEsquerda == 9){
        countDireita  = 0;
        countEsquerda = 0;
      escreveDisplayEsquerda(countEsquerda);
      escreveDisplayDireita(countDireita);
        delay(500);
  }
}

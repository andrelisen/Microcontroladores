<<<<<<< HEAD
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
=======
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
int controleTimer1=0;
int controleTimer2=0;
int controleDisplay = 0; //se 1=ligaEsquerda, se 0=ligaDireita
>>>>>>> bc63ba1f5f26983aa1d733cd3ab13d6f36a93899

/* 
--Utilize o timer 1 para controlar a periodicidade de atualização do 
display 7 segmentos (valor que será apresentado). EU SOU O CONTADOR  
--Utilize o timer 2 para controlar a periodicidade que o LED pisca 
(apresentação da informação no display). EU SOU O DELAY 
*/ 


ISR(TIMER2_OVF_vect) //timer2 por overflow --> controla tela
{
<<<<<<< HEAD
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
=======
    TCNT2 = 0; //reinicializa registrador      
    controleTimer2 = controleTimer2 + 1;
    if(controleTimer2 == 63){//era 63
     escreveDisplayDireita(countDireita);
     escreveDisplayEsquerda(countEsquerda);   
      controleTimer2=0;  
  }
}

ISR(TIMER1_OVF_vect) //interrupção do TIMER1
{
   controleTimer1 = controleTimer1 + 1;
    if(controleTimer1 == 245) //1segundo
       {
         countDireita = countDireita + 1;
         if(countDireita == 10)
        {
          countEsquerda ++; 
          countDireita = 0;
        } 
        if(countDireita == 10 && countEsquerda == 10)
        {
        countDireita = 0;
        countEsquerda = 0;
        }
      controleTimer1 = 0;
      }
     TCNT1 = 0;
}


void setup()  
{ 
  byte i; 
  for(i = 2; i<9;++i) //matriz esquerda
  { 
    pinMode(i, OUTPUT);//SETANDO LEDS DO DISPLAY DE 7 SEGMENTOS  
  }   
  for(i = 22; i<29;++i) //matrizdireita
  { 
    pinMode(i, OUTPUT);//SETANDO LEDS DO DISPLAY DE 7 SEGMENTOS  
  }
  //CONFIGURACAO TIMER 1 
   TCCR1A = 0; //confira timer para operação normal
    //pinos OC1A e OC1B desconectados
   TCCR1B = 0; //limpa registrador
   TIMSK1 |= (1 << TOIE1); // habilita a interrupção do TIMER1
//---------------SEM PRESCALER------------------------------------
   TCCR1B = 1; // modo normal sem prescaler
   TCNT1 = 0;
   pinMode(13, OUTPUT);
   //CONFIGURACAO TIMER 2
     TCCR2A = 0; //timer operando em modo normal, registrador de
     TCCR2B = 7; 
     TCNT2 = 0; //registrador de contagem
     TIMSK2 = 1;//habilita interrupçao do timer2
} 
   

void escreveDisplayDireita(byte numero)  //Funcao que aciona o display 
{ 
  byte pino = 22; 
    for (byte letra = 0; letra < 7; ++letra)   
    {  
    digitalWrite(pino, matrizDireita[numero][letra]); 
    ++pino; 
    } 
} 
 
void escreveDisplayEsquerda(byte numero)  //Funcao que aciona o display 
{ 
  byte pino2 = 2; 
  //Percorre o array ligando os segmentos correspondentes ao digito 
    for (byte letra = 0; letra < 7; ++letra)   
    {  
    digitalWrite(pino2, matrizEsquerda[numero][letra]); 
    ++pino2; 
    } 
} 

void loop()  
{ 
 
} 

>>>>>>> bc63ba1f5f26983aa1d733cd3ab13d6f36a93899

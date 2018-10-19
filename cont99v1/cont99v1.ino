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

/* 
--Utilize o timer 1 para controlar a periodicidade de atualização do 
display 7 segmentos (valor que será apresentado). EU SOU O CONTADOR  
--Utilize o timer 2 para controlar a periodicidade que o LED pisca 
(apresentação da informação no display). EU SOU O DELAY 
*/ 

ISR(TIMER1_OVF_vect) //interrupção do TIMER1
{
    if(controleTimer1 == 385)
    {
     if(countDireita != 9)
     {
     countDireita = countDireita + 1;
     escreveDisplayDireita(countDireita);
     }
     else{
       countEsquerda = countEsquerda + 1;
       countDireita = 0;
        escreveDisplayDireita(countDireita);
        escreveDisplayEsquerda(countEsquerda);
       // digitalWrite(13, LOW);
       //  delay(500);
       //  digitalWrite(13, HIGH);
     }
     if(countEsquerda == 9 && countDireita == 9)
     {
     countEsquerda = 0;
     countDireita = 0;
      escreveDisplayDireita(countDireita);
      escreveDisplayEsquerda(countEsquerda);
     }
     controleTimer1 = 0 ;
    }
     TCNT1 = 0;
     controleTimer1 = controleTimer1 + 1;
}

ISR(TIMER2_OVF_vect) //timer2 por overflow --> controla tela
{
    TCNT2 = 0; //reinicializa registrador      
    //de contagem do timer2 (8 bits)
    controleTimer2 ++;
    if(controleTimer2 == 100){
      if(countDireita != 9)
     {
     //countDireita = countDireita + 1;
     escreveDisplayDireita(countDireita);
     }
     else{
     //  countEsquerda = countEsquerda + 1;
      // countDireita = 0;
        escreveDisplayDireita(countDireita);
        escreveDisplayEsquerda(countEsquerda);
       // digitalWrite(13, LOW);
       //  delay(500);
       //  digitalWrite(13, HIGH);
     }
     if(countEsquerda == 9 && countDireita == 9)
     {
     //countEsquerda = 0;
    // countDireita = 0;
      escreveDisplayDireita(countDireita);
      escreveDisplayEsquerda(countEsquerda);
     }
     controleTimer2 = 0 ;
    }

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
     TCCR1B = 0; //limpa registrador
     TIMSK1 |= (1 << TOIE1); // habilita a interrupção doTIMER1
     TCCR1B = 1; // modo normal SEM PRESCALER
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


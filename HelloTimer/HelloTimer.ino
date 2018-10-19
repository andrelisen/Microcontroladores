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
//int contagem = 0;
/*
Faça com que as transições das letras sejam feitas com interrupções,
das seguintes formas:
• Nos pinos INT0 e INT1;
• Com Pin Change;
• Usando Timer.*/
//LOW = 1 HIGH = 0


//rotina de interrupçao do avr
ISR(TIMER2_OVF_vect) //timer2 por overflow
{
  TCNT2 = 0; //reinicializa registrador de contagem do timer2 (8 bits)
  contagem++;
    if(contagem == 100){
       if (count == 11)
        {
        count = 0; //zera a contagem
        }  
        escreveDisplay(count);
        count = count + 1;
        contagem = 0;
    }
}

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
  TCCR2A = 0; //timer operando em modo normal, registrador de controle do timer2 (8 bits em zero)
  TCCR2B = 7; //prescaler 1:1024, divisor permite contar tempos maiores com o timer (3 bits menos significativos) multiplica o ciclo de maquina por 1024
  TCNT2 = 0; //registrador de contagem
  TIMSK2 = 1;//habilita interrupçao do timer2
    //como calcular o tempo??
     /*
      overflow = timer2_cont * prescaler * ciclo de maquina
      ciclo de maquina = 16mhz = 1/16000000 = 62,5ns
      overflow = 256 * 1024 * 62,5E-9 = 16,38ms
      A cada 16,5ms ocorre uma interrupçao do timer2
    */
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



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

void InitialiseInterrupt(){
  cli();		        // Desabilita interrupcoes  
 // PCICR =2;    //ou 0x02;       // Enable PCINT1 interrupt PINOS de [28:23] ou PCINT[14:8] (Analogicos A0-A5) 
  PCICR = 0x02;
 // PCMSK1 = 7; //ou 0b00000111;  // Seta a mascara para PCINT1 (PCINT0|PCINT1|PCINT2)
  PCMSK1 = 0b00000111;
  sei();		        // Habilita interrupcoes
}

void InitialiseIO(){
  pinMode(A0, INPUT);
  digitalWrite(A0,HIGH);
  pinMode(A1, INPUT_PULLUP);	   
  pinMode(A2, INPUT_PULLUP);	   
}


ISR(PCINT1_vect) {    // Interrupt service routine. Every single PCINT8..14 (=ADC0..5) change
            // will generate an interrupt: but this will always be the same interrupt routine
  Serial.println("ENTREI");
  if(count = 0 || count == 11) //primeira vez
  {
    delay(500);
    count = 0;
    escreveDisplay(count);
    count = count + 1;  
  }
  else{
    delay(500);
    escreveDisplay(count);
    count = count + 1;  
  }
//  if (digitalRead(A0)==0)  Serial.println("A0");
 //  if (digitalRead(A1)==0)  Serial.println("A1");
 // if (digitalRead(A2)==0)  Serial.println("A2");
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
  pinMode(13, OUTPUT); //led da placa
  writePonto(0);  //inicializa ponto decimal como desligado
  pinMode(2, INPUT);//Esta inicializando o botao 
  pinMode(3, INPUT);
  Serial.begin(9600);
  Serial.println("Iniciando Configuracoes");
  InitialiseIO();
  InitialiseInterrupt();
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
   // zeraDisplay(letra, pin);
  }
    writePonto(1);  //Liga o ponto
    delay(100);   //Aguarda 100 milisegundos
    writePonto(0);  //Desliga o ponto
}

void loop() 
{
 
}



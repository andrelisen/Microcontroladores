                                // A B C D E F G   
byte matrizModo[10][7] =         { { 1,1,1,1,1,1,0 },  // = Digito 0
                                 { 0,1,1,0,0,0,0 },  // = Digito 1
                                 { 1,1,0,1,1,0,1 },  // = Digito 2
                                 { 1,1,1,1,0,0,1 },  // = Digito 3
                                 { 0,1,1,0,0,1,1 },  // = Digito 4
                                 { 1,0,1,1,0,1,1 },  // = Digito 5
                                 { 1,0,1,1,1,1,1 },  // = Digito 6
                                 { 1,1,1,0,0,0,0 },  // = Digito 7
                                 { 1,1,1,1,1,1,1 },  // = Digito 8
                                 { 1,1,1,0,0,1,1 },  // = Digito 9
                                 }; //1 liga led; 0 desliga led
byte count = 0;

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
  pinMode(13, OUTPUT);//led da placa
  writePonto(0);  //inicializa ponto decimal como desligado
  pinMode(2, INPUT);//Esta inicializando o botao que esta na posicao 20
 attachInterrupt(0, reset, RISING);//modo RISING para que qualquer modificaçao no botao gere a interrupcao
}
  
void writePonto(byte modo)   //Funcao que aciona o ponto no display
{  
  digitalWrite(10, modo);
}

void escreveDisplay(byte numero)  //Funcao que aciona o display
{
  byte pino = 3;

  //Percorre o array ligando os segmentos correspondentes ao digito
  for (byte letra = 0; letra < 7; ++letra)  //0=A,1=B,2=C,3=D,4=E,5=F,6=G
  { //onde letra e a letra de cada segmento do display
    digitalWrite(pino, matrizModo[numero][letra]);
    ++pino;
  }
    writePonto(1);  //Liga o ponto
    delay(100);   //Aguarda 100 milisegundos
    writePonto(0);  //Desliga o ponto
}

void loop() 
{
   if(count >9)
   {
     count = 0;
   }
     escreveDisplay(count);
     count++;
    delay(500); 
}     

void reset()
  {
    count = 0;
    digitalWrite(13, LOW);
    delay(1000);
    digitalWrite(13,HIGH);
  }


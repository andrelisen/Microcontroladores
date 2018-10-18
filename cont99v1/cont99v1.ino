                                // A B C D E F G   
byte matrizDireita[10][7] =            { { 1,1,1,1,1,1,0 },  // = Digito 0
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
byte count1 = 0;
byte count2 = 0;


/*
--Utilize o timer 1 para controlar a periodicidade de atualização do
display 7 segmentos (valor que será apresentado). EU SOU O CONTADOR 
--Utilize o timer 2 para controlar a periodicidade que o LED pisca
(apresentação da informação no display). EU SOU O DELAY
*/

void setup() 
{
  pinMode(3, OUTPUT);// matriz direita
  pinMode(4, OUTPUT);// matriz direita
  pinMode(5, OUTPUT);// matriz direita
  pinMode(6, OUTPUT);// matriz direita
  pinMode(7, OUTPUT);// matriz direita
  pinMode(8, OUTPUT);// matriz direita
  pinMode(9, OUTPUT);// matriz direita
  pinMode(10, OUTPUT);// matriz direita
  pinMode(30, OUTPUT);// matriz esquerda
  pinMode(32, OUTPUT);// matriz esquerda
  pinMode(34, OUTPUT);// matriz esquerda
  pinMode(36, OUTPUT);// matriz esquerda
  pinMode(38, OUTPUT);// matriz esquerda
  pinMode(40, OUTPUT);// matriz esquerda
  pinMode(42, OUTPUT);// matriz esquerda
  pinMode(44, OUTPUT);// matriz esquerda
  pinMode(13, OUTPUT); //led da placa
  writePonto(0);  //inicializa ponto decimal como desligado
  pinMode(2, INPUT);//Esta inicializando o botao que esta na posicao 20
  attachInterrupt(0, reset, RISING);//digitalPinToInterrupt(20)
}
  
void writePonto(byte modo)   //Funcao que aciona o ponto no display
{  
  digitalWrite(10, modo);
}

void escreveDisplay(byte numero)  //Funcao que aciona o display
{
  byte pino = 3;

  //Percorre o array ligando os segmentos correspondentes ao digito
  for (byte letra = 0; letra < 7; ++letra)  
  { 
    digitalWrite(pino, seven_seg_digits[numero][letra]);
    ++pino;
  }
    writePonto(1);  //Liga o ponto
    delay(100);   //Aguarda 100 milisegundos
    writePonto(0);  //Desliga o ponto
}

void loop() 
{
  for(count = 0;count<9)
  if(count >9)
   {
     count = 0;
   }
     sevenSegWrite(count);
     count++;
    delay(500); 
}     


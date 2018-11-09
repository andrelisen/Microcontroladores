void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando Configuracoes");
  InitialiseIO();
  InitialiseInterrupt();
}

void loop() {
  Serial.println("LOOP");
  delay(500);
}  

void InitialiseInterrupt(){
  cli();		        // Desabilita interrupcoes  
  PCICR =2;    //ou 0x02;       // Enable PCINT1 interrupt PINOS de [28:23] ou PCINT[14:8] (Analogicos A0-A5) 
  PCMSK1 = 7; //ou 0b00000111;  // Seta a mascara para PCINT1 (PCINT0|PCINT1|PCINT2)
  sei();		        // Habilita interrupcoes
}

void InitialiseIO(){
  pinMode(0, INPUT);
  //pinMode(A1, INPUT_PULLUP);	   
  //pinMode(A2, INPUT_PULLUP);	   
}


ISR(PCINT1_vect) {    // Interrupt service routine. Every single PCINT8..14 (=ADC0..5) change
            // will generate an interrupt: but this will always be the same interrupt routine
  Serial.println("Interrupcao entrou");
}

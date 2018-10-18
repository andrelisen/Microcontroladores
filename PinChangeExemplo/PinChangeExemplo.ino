
ISR (PCINT1_vect) // handle pin change interrupt for A0 to A5 here
 {
   //  digitalWrite(13,digitalRead(A0));
    // delay(50000);
    // digitalWrite(13, HIGH);
    // delay(50000);
  Serial.println("INTERRUPÇAO ACEITA");
  delay(500);

 }  

void setup()
{
  Serial.begin(9600);
  Serial.println("Iniciando Configuracoes");
   pinMode(A3, INPUT);
   cli();		        // Desabilita interrupcoes  
   PCICR =2;    //ou 0x02;       // Habilita PCINT1 interrupçao PINOS de [28:23] ou PCINT[14:8] (Analogicos A0-A5) 
   PCMSK1 = 7; //ou 0b00000111;  // Seta a mascara para PCINT1 (PCINT0|PCINT1|PCINT2)
   sei();	
}


void loop() {
  Serial.println("LOOP");
  delay(500);
}  


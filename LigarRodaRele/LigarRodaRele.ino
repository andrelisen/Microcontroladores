int rodaDireita 5; 
int rodaEsquerda 6;
void setup(){
 pinMode(rodaDireita,OUTPUT); 
 pinMode(rodaEsquerda,OUTPUT);
}
void loop() {
 digitalWrite(rodaDireita, HIGH);
 digitalWrite(rodaEsquerda, LOW);
 delay(2000);
 digitalWrite(rodaDireita,LOW);
 digitalWrite(rodaEsquerda, HIGH);
 delay(2000);
}


// Declaração de variaveis
String senha = "123ab";

int led = 8;


void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  Serial.begin(9600); //inicia a comunicacao serial (valor entre parenteses velocidade da comunicacao de 300 ate 115200)
  Serial.println("Insira sua senha:");  
}
String leSenha(){
  char c; 
  String entrada = "";
  //Serial.println("Insira sua senha:");  
  while(Serial.available() > 0){ //retorna o numero de bytes disponivel para leitura
    c = Serial.read(); //le um byte, por isso tem q ser char
    if(c != '\n'){
       entrada.concat(c);
    }
    delay(10);
  }
  Serial.print("Recebi:");
  Serial.println(entrada);
  return entrada;
}


void loop() {
  // put your main code here, to run repeatedly:
  String entrada = "";
  if(Serial.available() > 0){
      entrada = leSenha();
      if(entrada == senha){
        digitalWrite(led, HIGH);
        Serial.println("Certa");
      }else{
        Serial.println("Errada");
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
        delay(1000);
        digitalWrite(led, HIGH);
        delay(1000);
        digitalWrite(led, LOW);
      }
   }
}

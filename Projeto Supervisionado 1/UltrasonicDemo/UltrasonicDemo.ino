/*
 * HCSR04Ultrasonic/examples/UltrasonicDemo/UltrasonicDemo.pde
 *
 * SVN Keywords
 * ----------------------------------
 * $Author: cnobile $
 * $Date: 2011-09-17 02:43:12 -0400 (Sat, 17 Sep 2011) $
 * $Revision: 29 $
 * ----------------------------------
 */

#include <Ultrasonic.h>

#define trigPin 10
#define echoPin 11
#define buzzer 3

int sound = 250;


void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(buzzer, OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
 

  if (distance <= 30) {
   // digitalWrite(led, HIGH);
    sound = 800;
}
  else {
    //digitalWrite(led,LOW);
  }
  if (distance < 25) {
      //digitalWrite(led2, HIGH);
      sound = 850;
}
  else {
     // digitalWrite(led2, LOW);
  }
  if (distance < 20) {
      //digitalWrite(led3, HIGH);
      sound = 900;
} 
  else {
    //digitalWrite(led3, LOW);
  }
  if (distance < 15) {
   // digitalWrite(led4, HIGH);
    sound = 950;
}
  else {
   // digitalWrite(led4,LOW);
  }
  if (distance < 10) {
   // digitalWrite(led5, HIGH);
    sound = 1000;
}
  else {
   // digitalWrite(led5,LOW);
  }
  if (distance < 5) {
   // digitalWrite(led6, HIGH);
    sound = 1050;
}
  else {
    //digitalWrite(led6,LOW);
  }
 
  if (distance > 30 || distance <= 0){
    Serial.println("Out of range");
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
    tone(buzzer, sound);
   
  }
  delay(500);
}

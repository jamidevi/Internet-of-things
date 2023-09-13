#include <Servo.h>
Servo servo_motor;
void setup() {
  // put your setup code here, to run once:
pinMode(9,OUTPUT);
pinMode(10,INPUT);
servo_motor.attach(2);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,LOW);
delayMicroseconds(2);
digitalWrite(9,HIGH);
delayMicroseconds(10);
digitalWrite(9,LOW);
long int duration=pulseIn(10,HIGH);
float dist= duration*0.034/2;
Serial.println(dist);
 if(dist<10)
  {
  servo_motor.write(360);
}
else
{
   
  servo_motor.write(160);
}
}

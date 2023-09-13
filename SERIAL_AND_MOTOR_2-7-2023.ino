#include<Servo.h>
Servo servo_motor;
void setup() {
  // put your setup code here, to run once:
servo_motor.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int x=Serial.read();
Serial.println(x);
if(x=='A')
{
 servo_motor.write(180);
  //delay(1000); 
}
else if(x=='B')
{
  servo_motor.write(90);
}
else if(x=='C')
{
  servo_motor.write(120);
  //delay(1000);
}
  
}
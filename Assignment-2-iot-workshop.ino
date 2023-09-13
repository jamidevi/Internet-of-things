#include <Servo.h>
Servo servo_motor;

void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT);
  servo_motor.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
int x=digitalRead(3);
if(x==HIGH)
{
servo_motor.write(360);
delay(100);
}
else
{
  servo_motor.write(0);
  delay(100);
}
}
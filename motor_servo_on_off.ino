#include <Servo.h>
Servo servo_motor;
void setup() {
  // put your setup code here, to run once:
servo_motor.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(Serial.available()>0)
  {
  String data1=Serial.readString();
  data1.trim();
  {
if(data1=="start")
{
  servo_motor.write(180);
  Serial.println("servo motro is on");
}
else if(data1=="stop")
{
  servo_motor.write(360);
  Serial.println("servo motor is off");
}
}
  }
}

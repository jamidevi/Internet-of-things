#include <Servo.h>
Servo servo_motor;
void setup() {
  // put your setup code here, to run once:
servo_motor.attach(9);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
 int sensor_data=analogRead(A2);
 Serial.println(sensor_data);
  if(sensor_data<800)
  {
  servo_motor.write(0);
  delay(1000);
  }
  else
  {
  servo_motor.write(100);
  delay(1000);
  }
}

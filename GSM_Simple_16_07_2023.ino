#include <SoftwareSerial.h>
SoftwareSerial SIM900A(10,11);
char c = ' ';

void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
Serial.println("Arduino with SIM900A is ready");
SIM900A.begin(9600);
Serial.println("SIM900A started at 9600");
}

void loop() {
  // put your main code here, to run repeatedly:
if(SIM900A.available())
{
  c = SIM900A.read();
  Serial.write(c);
}
if(Serial.available())
{
  c=Serial.read();
  SIM900A.write(c);
}
}

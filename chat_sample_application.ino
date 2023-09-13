#include <SoftwareSerial.h>
SoftwareSerial bluetooth_conn(10, 11);
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
bluetooth_conn.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
if(Serial.available()>0)
{
bluetooth_conn.println(Serial.readString());
}
if(bluetooth_conn.available()>0)
{
Serial.println(bluetooth_conn.readString());

}
}

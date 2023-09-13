#include <DHT11.h>
#include <Servo.h>
Servo servo_motor;
DHT11 dht11_sensor(2);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
servo_motor.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
float temperature= dht11_sensor.readTemperature();
if(temperature!=-1)
{
servo_motor.write(360);
Serial.println("H");
}
else
{
  servo_motor.write(160);
  Serial.println("C");
}
float humidity=dht11_sensor.readHumidity();
{
  if(humidity!=-1)
  {
   Serial.println("High");
  }
  else
  {
  Serial.println("LOW");
  }
}
delay(1000);
}

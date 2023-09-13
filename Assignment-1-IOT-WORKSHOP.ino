void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(7,OUTPUT);
pinMode(9,OUTPUT);
pinMode(4,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
int sensor_data=analogRead(A2);
  Serial.println(sensor_data);
  if(sensor_data<700)
  {
  digitalWrite(7,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(4,LOW);
  }
  else if((sensor_data>700 )&& (sensor_data<900))
  {
    digitalWrite(7,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(4,LOW);
  }
else
{
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(4,HIGH);
}
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13,OUTPUT);
}

void loop() {
  // put your main code here, to run repeate
  if(Serial.available()>0)
  {
  String data1=Serial.readString();
  data1.trim();
  {
if(data1=="start")
{
  digitalWrite(13,HIGH);
  Serial.println("LED is ON");
}
else if(data1=="stop")
  {
    digitalWrite(13,LOW);
Serial.println("LED is off");
  }
}
  }
}

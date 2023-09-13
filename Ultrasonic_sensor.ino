void setup() {
  // put your setup code here, to run once:
pinMode(D5,INPUT);//echo
pinMode(D6,OUTPUT);//trigger
pinMode(D7,OUTPUT);
pinMode(D8,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(D6,LOW);
delayMicroseconds(2);
digitalWrite(D6,HIGH);
delayMicroseconds(10);
digitalWrite(D6,LOW);
int duration=pulseIn(D5,HIGH);
float dist= duration*0.034/2;
Serial.println(dist);
if(dist<200)
{
  digitalWrite(D7,HIGH);
  digitalWrite(D8,LOW);
}
else if (dist>250)
{
  digitalWrite(D8,HIGH);
  digitalWrite(D7,LOW);
}
}
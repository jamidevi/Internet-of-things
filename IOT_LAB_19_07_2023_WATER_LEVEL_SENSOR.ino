void setup() {
  // put your setup code here, to run once:
pinMode(4,OUTPUT);
pinMode(7,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int data = analogRead(A3);
Serial.println(data);
delay(2000);
if(data<=950)
{
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
}
else 
{
digitalWrite(4,LOW);
digitalWrite(7,HIGH);
}
}

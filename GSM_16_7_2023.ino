#include <SoftwareSerial.h>   
  SoftwareSerial SIM900A(10,11); // SoftSerial( RX , TX );   
  // 10 pin connect to TX of GSM SIM 900 Module   
  // 11 pin connect to RX of GSM SIM 900 Module   
  void setup()   
  {   
  SIM900A.begin(9600); // Setting the baud rate of GSM Module    
  Serial.begin(9600); // Setting the baud rate of Serial Monitor (Arduino)   
  Serial.println ("SIM900A Ready");   
  delay(100);   
  Serial.println ("Type s to send message ");   
  pinMode(13,OUTPUT);
  }   
  void loop()   
  {   
  if (Serial.available()>0)   
   switch(Serial.read())   
  {   
   case 's':   
   SendMessage();   
   break;   
  }   
  if (SIM900A.available()>0)   
   Serial.println(SIM900A.read()); 
    String s = SIM900A.readString();
    s.trim();
    String s1 = s.substring(10,20);
    String message = s.substring(49,s.length());
    Serial.println(s.length());
    Serial.println(s);
    Serial.println(s1);
    Serial.println(message);
    if(s1=="6281641798"  && message =="ON")
    {
      digitalWrite(13,HIGH);
    }
    if(s1=="6281641798"  && message =="OFF")
    {
      digitalWrite(13,LOW);
    } 
    delay(10000);
   
  }   
  void SendMessage()   
  {   
  Serial.println ("Sending Message");   
  SIM900A.println("AT+CMGF=1"); //Sets the GSM Module in Text Mode   
  delay(1000);   
  Serial.println ("Set SMS Number");   
  SIM900A.println("AT+CMGS=\"6281641798\"\r"); //Write Mobile number to send message   
  delay(1000);   
  Serial.println ("Set SMS Content");   
  SIM900A.println("SVECW IOT WORKSHOP");// Messsage content   
  delay(100);   
  Serial.println ("Finish");   
  SIM900A.println((char)26);// ASCII code of CTRL+Z   
  delay(1000);   
  Serial.println ("Message has been sent");   
  }
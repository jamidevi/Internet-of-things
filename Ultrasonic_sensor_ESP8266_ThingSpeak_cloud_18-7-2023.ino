#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include "ThingSpeak.h"
char* ssid= "Galaxy A52s 5G9BA2";
char* password= "fish4523";
WiFiServer server(80);
WiFiClient client;
unsigned long myChannelNumber=1;
const char* myWriteAPIKey="BYBJ7ZB60291VFY3";
unsigned long lastTime=0;
unsigned long timerDelay=1000;
const int trigPin=D5;
const int echoPin=D6;
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCM;
float distanceINCH;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
Serial.print("connecting to");
Serial.println(ssid);
WiFi.begin(ssid,password);
while(WiFi.status()!=WL_CONNECTED)
{
  delay(500);
  Serial.print(".");
}
Serial.println("WIFI Connected");
Serial.println("IP Address:");
Serial.println(WiFi.localIP());
server.begin();
ThingSpeak.begin(client);
pinMode(trigPin,OUTPUT);
pinMode(echoPin,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin,LOW);
delay(1000);//delay microseconds(2)
digitalWrite(trigPin,HIGH);
delay(1000);
digitalWrite(trigPin,LOW);
duration=pulseIn(echoPin,HIGH);
distanceCM=((duration*SOUND_SPEED)/2);
distanceINCH=distanceCM*CM_TO_INCH;
Serial.print("Distance in CM :");
Serial.println(distanceCM);
Serial.print("Distance in INCH:");
Serial.println(distanceINCH);
delay(1000);
ThingSpeak.setField(1,distanceCM);
ThingSpeak.setField(2,distanceINCH);
ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
}

#include <IFTTTMaker.h>

/*******************************************************************
 *  Trigger event at end of the setup                              *
 *                                                                 *
 *  adapted by Brian Lough                                         *
 *******************************************************************/


#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>

//------- Replace the following! ------
char ssid[] = "Galaxy A52s 5G9BA2";       // your network SSID (name)
char password[] = "fish4523";  // your network key
#define KEY "aio_EgNA93PD35scFV4I50xyL1aqdrdg"  // Get it from this page https://ifttt.com/services/maker/settings
#define EVENT_NAME "LED_ON" // Name of your event name, set when you are creating the applet
#define EVENT_NAME "LED_OFF"


WiFiClientSecure client;
IFTTTMaker ifttt(KEY, client);

void setup() {

  Serial.begin(115200);
  pinMode(D2,OUTPUT);
  pinMode(D7,OUTPUT);
  pinMode(D8,OUTPUT);
  // Set WiFi to station mode and disconnect from an AP if it was Previously
  // connected
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);

  // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  IPAddress ip = WiFi.localIP();
  Serial.println(ip);


  //triggerEvent takes an Event Name and then you can optional pass in up to 3 extra Strings
  if(ifttt.triggerEvent(EVENT_NAME, ssid, ip.toString())){
    Serial.println("Successfully sent");
  } else
  {
    Serial.println("Failed!");
  }

}

void loop() {
  if(x==1)
      {
        digitalWrite(D2,HIGH);
        delay(1000);
        digitalWrite(D7,HIGH);
        delay(1000);
        digitalWrite(D8,HIGH);
        delay(1000);
      }
      else if(x==0)
      {
        digitalWrite(D2,LOW);
        delay(1000);
        digitalWrite(D7,LOW);
        delay(1000);
        digitalWrite(D8,LOW);
        delay(1000);
      }

}

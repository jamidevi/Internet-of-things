/*
  ReadMultipleFields
  
  Description: Demonstates reading from a public channel which requires no API key (reading from a private channel requires a read API key).
               The values read from the public channel is the current wind direction, wind speed, humidity, outside temperature, rain, pressure, 
               power level, and light intensity  at MathWorks headquaters in Natick, MA.The functionality also provides us to read the 
               status message, location coordinates, and created-at timestamp associated with the latest feed.
  
  Hardware: ESP8266 based boards
  
  !!! IMPORTANT - Modify the secrets.h file for this project with your network connection and ThingSpeak channel details. !!!
  
  Note:
  - Requires ESP8266WiFi library and ESP8622 board add-on. See https://github.com/esp8266/Arduino for details.
  - Select the target hardware from the Tools->Board menu
  - This example is written for a network using WPA encryption. For WEP or WPA, change the WiFi.begin() call accordingly.  
  
  ThingSpeak ( https://www.thingspeak.com ) is an analytic IoT platform service that allows you to aggregate, visualize, and 
  analyze live data streams in the cloud. Visit https://www.thingspeak.com to sign up for a free account and create a channel.  
  
  Documentation for the ThingSpeak Communication Library for Arduino is in the README.md folder where the library was installed.
  See https://www.mathworks.com/help/thingspeak/index.html for the full ThingSpeak documentation.
  
  For licensing information, see the accompanying license file.
  
  Copyright 2020, The MathWorks, Inc.
*/

#include <ESP8266WiFi.h>
#include "secrets.h"
#include "ThingSpeak.h" // always include thingspeak header file after other header files and custom macros

char ssid[] = "Galaxy A52s 5G9BA2";   // your network SSID (name) 
char pass[] ="fish4523";   // your network password
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;

const char * MyChannelReadAPIKey="MRFHFCH33HSSH3V1";
//
int statusCode = 0;
int field[8] = {1,2,3,4,5,6,7,8};

void setup() {
  Serial.begin(115200);      // Initialize serial 
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA);
  
  ThingSpeak.begin(client);  // Initialize ThingSpeak

  // Connect or reconnect to WiFi
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass); // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected");
  }
}

void loop() {
    
    // Read and store all the latest field values, location coordinates, status message, and created-at timestamp
    // use ThingSpeak.readMultipleFields(channelNumber, readAPIKey) for private channels
    statusCode = ThingSpeak.readMultipleFields( 2220445,MyChannelReadAPIKey);
    
    if(statusCode == 200)
    {
      // Fetch the stored data

      int x = ThingSpeak.getFieldAsInt(field[1]); // Field 1
      int y = ThingSpeak.getFieldAsFloat(field[2]); // Field 2
      
      
      
      Serial.println("the value of filed 1 is : " + String(x));
      Serial.println("the value of field 2 is : " + String(y));
      
    }
    else{
      Serial.println("Problem reading channel. HTTP error code " + String(statusCode)); 
    }

    Serial.println();
    delay(5000); // no need to fetch too often
       
}

#include <DHT11.h>
#include<ESP8266WiFi.h>
#include "ThingSpeak.h"
// Create an instance of the DHT11 class and set the digital I/O pin.
DHT11 dht11(D2);
char ssid[] = "Galaxy A52s 5G9BA2";   // your network SSID (name) 
char pass[] = "fish4523"; 
int keyIndex = 0;            // your network key Index number (needed only for WEP)
WiFiClient  client;
String myStatus = "";
unsigned long myChannelNumber =2220445 ;
const char * myWriteAPIKey = "MRFHFCH33HSSH3V1";
void setup()
{
    // Initialize serial communication at 115200 baud.
    Serial.begin(115200);
    while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo native USB port only
  }
  
  WiFi.mode(WIFI_STA); 
  ThingSpeak.begin(client);
}

void loop()
{
  if(WiFi.status() != WL_CONNECTED){
    Serial.print("Attempting to connect to SSID: ");
    //Serial.println(SECRET_SSID);
    while(WiFi.status() != WL_CONNECTED){
      WiFi.begin(ssid, pass);  // Connect to WPA/WPA2 network. Change this line if using open or WEP network
      Serial.print(".");
      delay(5000);     
    } 
    Serial.println("\nConnected.");
  }
    // Read the humidity from the sensor.
    float humidity = dht11.readHumidity();

    // Read the temperature from the sensor.
    float temperature = dht11.readTemperature();
   ThingSpeak.setField(1, humidity);
  ThingSpeak.setField(2, temperature);
    // If the temperature and humidity readings were successful, print them to the serial monitor.
    if (temperature != -1 && humidity != -1)
    {
        Serial.print("Temperature: ");
        Serial.print(temperature);
        Serial.println(" C");

        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println(" %");
    }
    else
    {
        // If the temperature or humidity reading failed, print an error message.
        Serial.println("Error reading data");
    }

    // Wait for 2 seconds before the next reading.
    delay(2000);

    ThingSpeak.setStatus(myStatus);
  
  // write to the ThingSpeak channel
  int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
  if(x == 200){
    Serial.println("Channel update successful.");
  }
  else{
    Serial.println("Problem updating channel. HTTP error code " + String(x));
  }
}

#include <Arduino.h>
#if defined(ESP32)
   #include <WiFi.h>
#elif defined(ESP8266)
   #include <ESP8266WiFi.h>
#endif
#include <ESP_Mail_Client.h>
#define WIFI_SSID "Galaxy A52s 5G9BA2"
#define WIFI_PASSWORD "fish4523" 
 
#define SMTP_HOST "smtp.gmail.com"
#define SMTP_PORT 465

#define AUTHOR_EMAIL "jamid8297@gmail.com"
#define AUTHOR_PASSWORD "treebfmblsbqmfte"

#define RECIPIENT_EMAIL "jamidevi6279@gmail.com"

SMTPSession smtp;

void smtpCallback(SMTP_Status status);

void setup() {
  Serial.begin(115200);
  Serial.println();
  Serial.print("Connecting to AP");
  WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
  while(WiFi.status() !=WL_CONNECTED)
  {
    Serial.print(".");
    delay(200);
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address:");
  Serial.println(WiFi.localIP());
  Serial.println();
  smtp.debug(1);
  smtp.callback(smtpCallback);
  ESP_Mail_Session session;
  session.server.host_name=SMTP_HOST;
  session.server.port=SMTP_PORT;
  session.login.email=AUTHOR_EMAIL;
  session.login.password=AUTHOR_PASSWORD;
  session.login.user_domain="";
  
  SMTP_Message message;
  message.sender.name="ESP8266";
  message.sender.email=AUTHOR_EMAIL;
  message.subject="ESP TEST EMAIL";
  message.addRecipient("Devi",RECIPIENT_EMAIL);

  //send HTML message
  String htmlMsg = "<div style=\"color:#2f4468;\"><h1>HEllo world!<p>- sent from Esp board </p></div>";
  message.html.content=htmlMsg.c_str();
  message.html.content=htmlMsg.c_str();
  message.text.charSet="us-ascii";
  message.html.transfer_encoding=Content_Transfer_Encoding::enc_7bit;

  message.priority=esp_mail_smtp_priority::esp_mail_smtp_priority_low;
  message.response.notify=esp_mail_smtp_notify_success | esp_mail_smtp_notify_failure | esp_mail_smtp_notify_delay;
  
  if(!smtp.connect(&session))
    return;

  if(!MailClient.sendMail(&smtp,&message))
    Serial.println("Error sending Email," + smtp.errorReason());
}

void loop()
{

}

void smtpCallback(SMTP_Status status)
{
  Serial.println(status.info());
  if(status.success())
  {
    Serial.println("---------------");
    ESP_MAIL_PRINTF("Message sent sucess : %d\n", status.completedCount());
    ESP_MAIL_PRINTF("Message sent sucess : %d\n", status.failedCount());
    Serial.println("-------------\n");
    struct tm dt;
    for(size_t i=0; i<smtp.sendingResult.size(); i++)
    {
      SMTP_Result result=smtp.sendingResult.getItem(i);
      time_t ts = (time_t)result.timestamp;
      localtime_r(&ts,&dt);

      ESP_MAIL_PRINTF("Message No: %d\n",i+1);
      ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
      ESP_MAIL_PRINTF("Date/Time:%d/%d/%d %d:%d:%d\n", dt.tm_year + 1900 , dt.tm_mon + 1, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
      ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients.c_str());
      ESP_MAIL_PRINTF("Subject:%s\n",result.subject.c_str());
    }
    Serial.println("-----------\n");
  }

}














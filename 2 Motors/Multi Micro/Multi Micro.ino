#define BLYNK_TEMPLATE_ID "TMPL-TWxDqC-"
#define BLYNK_DEVICE_NAME "2 Motors"
#define BLYNK_AUTH_TOKEN "xzsSJW-fpRiYEGWCgSQsLKsv5Kgr250L"
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

Servo servo1;
Servo servo2;



char auth[] = "xzsSJW-fpRiYEGWCgSQsLKsv5Kgr250L";
char ssid[] = "MSN";                    
char pass[] = "tala1964";                    

void setup()

{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo1.attach(13);// D7 pin
  servo2.attach(12);//D6 pin
   
 }


void loop()

{
  Blynk.run();
}

BLYNK_WRITE(V1)

{
   servo1.write(param.asInt());
}
BLYNK_WRITE(V2)

{
   servo2.write(param.asInt());
}

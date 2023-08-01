#define BLYNK_TEMPLATE_ID "TMPLIGqK_Fnw"
#define BLYNK_DEVICE_NAME "2 Motors and Temp"
#define BLYNK_AUTH_TOKEN "TQDd_1ZNscE2d0BWNVwKkMkQttWEbmdi"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#include <SimpleTimer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define BLYNK_PRINT Serial    

#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board "D4 pin on the ndoemcu Module"
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;
SimpleTimer timer;
Servo servo1;
Servo servo2;
char auth[] = "TQDd_1ZNscE2d0BWNVwKkMkQttWEbmdi";
char ssid[] = "MSN";                    
char pass[] = "tala1964";                    

void setup()

{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  servo1.attach(13);// D7 pin
  servo2.attach(12);//D6 pin
  DS18B20.begin();
  timer.setInterval(1000L, getSendData);
 }

void loop()

{
  Blynk.run();
  timer.run();
}

BLYNK_WRITE(V1)

{
   servo1.write(param.asInt());
}
BLYNK_WRITE(V2)

{
   servo2.write(param.asInt());
}
void getSendData()
{
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Serial.println(temp);
  Blynk.virtualWrite(V3, temp); //virtual pin V3

}

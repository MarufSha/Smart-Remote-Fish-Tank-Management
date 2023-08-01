#define BLYNK_TEMPLATE_ID "TMPLZV1YoU1n"
#define BLYNK_DEVICE_NAME "Water Temperature"
#define BLYNK_AUTH_TOKEN "qBIPUevBn-Xh2Io4ZngWje1uScO63m6p"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <SimpleTimer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define BLYNK_PRINT Serial    
char auth[] = "qBIPUevBn-Xh2Io4ZngWje1uScO63m6p";

/* WiFi credentials */
char ssid[] = "MSN";
char pass[] = "tala1964";

SimpleTimer timer;



#define ONE_WIRE_BUS 2 // DS18B20 on arduino pin2 corresponds to D4 on physical board "D4 pin on the ndoemcu Module"
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;
void setup() 
{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  DS18B20.begin();
  timer.setInterval(1000L, getSendData);
}

void loop() 
{
  timer.run(); // Initiates SimpleTimer
  Blynk.run();
}

/***************************************************
 * Send Sensor data to Blynk
 **************************************************/
void getSendData()
{
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Serial.println(temp);
  Blynk.virtualWrite(V3, temp); //virtual pin V3

}
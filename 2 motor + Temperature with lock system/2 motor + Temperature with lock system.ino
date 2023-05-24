#define BLYNK_TEMPLATE_ID "TMPLT24n6rpr"
#define BLYNK_DEVICE_NAME "2 Motors and Temperate with Lock System"
#define BLYNK_AUTH_TOKEN "gZSIaUjF7ruOJtUAWh5xDuwIIJ8TcUSE"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

#include <SimpleTimer.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#define BLYNK_PRINT Serial    

#define ONE_WIRE_BUS 2 // D4 pin
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature DS18B20(&oneWire);
float temp;
SimpleTimer timer;
Servo servo1;
Servo servo2;
char auth[] = "gZSIaUjF7ruOJtUAWh5xDuwIIJ8TcUSE";
char ssid[] = "MSN";                    
char pass[] = "tala1964";  
int digitalPin = D0;                  

void setup()

{
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode(digitalPin, OUTPUT);
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

BLYNK_WRITE(V4) {
  digitalWrite(digitalPin, param.asInt());
}

void getSendData()
{
  DS18B20.requestTemperatures(); 
  temp = DS18B20.getTempCByIndex(0); // Celcius
  Serial.println(temp);
  Blynk.virtualWrite(V3, temp); //virtual pin V3

}
// And gate input 1 = Light + node
// And gate input 2 = D6 from NodeMCU
// And gate output 2 = Servo motor data


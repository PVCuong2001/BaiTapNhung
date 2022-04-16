#include "DHT.h"
#include <Adafruit_Sensor.h>
#include <Arduino.h>
#define DHTPIN 9 // what digital pin we're connected to

// Chọn loại cảm biến cho phù hợp ---------------------------------------------------------------------------------------
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
 


  dht.begin();
}

void loop()
{

  delay(2000);

  float h = dht.readHumidity();

  float t = dht.readTemperature();
  Serial.println(h);
  Serial.println(t);
}

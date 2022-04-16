#include "DHT.h"
#include <Adafruit_Sensor.h>
#include <Wire.h>
#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 9 // what digital pin we're connected to

// Chọn loại cảm biến cho phù hợp ---------------------------------------------------------------------------------------
#define DHTTYPE DHT11 // DHT 11
//#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);
int button = 2;
bool isC = true;


float tmp = 0.0;
bool oldStatus =true;
int timer =0;
bool check=true;
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 6, d5 = 5, d6 = 4, d7 = 3;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup()
{
  Serial.begin(9600);
  Serial.println("DHTxx test!");
  pinMode(button, INPUT_PULLUP);
  pinMode(13 ,OUTPUT);
   lcd.begin(16, 2);
  Serial.begin(9600);
  lcd.setCursor(0,0) ;
  digitalWrite(13,HIGH);
}

void loop()
{
    delay(100);


  float tmp = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

   Serial.println(tmp);

//  float tmp = 30;
//  // Read temperature as Fahrenheit (isFahrenheit = true)
//  float f = 40;
  lcd.clear();

  if (digitalRead(button) ==LOW){
    oldStatus = !oldStatus;
    if(millis() -timer <=500){
      check =!check;
      if(check==false){
        lcd.noDisplay();
        digitalWrite(13,LOW);
      Serial.println("No Display");
      }else{
      
        lcd.begin(16, 2);
      Serial.println("Display");
      }
      
    }else{
      timer = millis();
    }
     delay(100);
  }
  if(oldStatus ==true){
    lcd.setCursor(0,1);
  lcd.print("Nhiet do :"+String(tmp));
  }else{
    lcd.setCursor(0,1);
  lcd.print("Nhiet do :"+String(f));
  }

}

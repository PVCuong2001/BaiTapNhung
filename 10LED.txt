#include <Arduino.h>

int LED_INDEX[] = {3, 5, 6, 9, 10, 11, 7, 8, 12, 13};
int numLed = 10;

void setup()
{
  // put your setup code here, to run once:
  for (int i = 0; i < 10; i++)
  {
    pinMode(LED_INDEX[i], OUTPUT);
  }
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

void cau1(int timedelay){
   // put your main code here, to run repeatedly:
  delay(timedelay);
  for(int i = 0 ; i < numLed ; i++){
    digitalWrite(LED_INDEX[i], HIGH);
    delay(timedelay);
  }
  delay(timedelay);
  for(int i = numLed ; i > 0 ; i--){
    digitalWrite(LED_INDEX[i-1], LOW);
    delay(timedelay);
  }
}

void cau2(int timedelay){
   // put your main code here, to run repeatedly:
  delay(timedelay);
  for (int i = 0; i <=(numLed - 1) / 2 ; i++)
  {
    digitalWrite(LED_INDEX[i], HIGH);
    digitalWrite(LED_INDEX[numLed - 1 - i], HIGH);
    delay(timedelay);
  }
  delay(timedelay);
  for (int i = (numLed - 1) / 2; i >=0  ; i--)
  {
    digitalWrite(LED_INDEX[i], LOW);
    digitalWrite(LED_INDEX[numLed - 1 - i], LOW);
    delay(timedelay);
  }
}

void cau3(int timedelay){
    // put your main code here, to run repeatedly:
  delay(timedelay);
  for (int i = 0 ; i < numLed ; i+=2)
  {
    digitalWrite(LED_INDEX[i], HIGH);
    delay(timedelay);
    digitalWrite(LED_INDEX[i], LOW);
    delay(timedelay);
  }
  for (int i = numLed - 1 ; i >= 1 ; i-=2)
  {
    digitalWrite(LED_INDEX[i], HIGH);
    delay(timedelay);
    digitalWrite(LED_INDEX[i], LOW);
    delay(timedelay);
  }
}

void cau4_backup(){
   // put your main code here, to run repeatedly:
  delay(200);
  int sensorValue = analogRead(A5);
    Serial.println(sensorValue);
    int time_delay = sensorValue*3;
    cau3(time_delay);
}

void cau4(){
  // put your main code here, to run repeatedly:
  delay(200);
  for (int i = 0 ; i < numLed ; i+=2)
  {
    int sensorValue = analogRead(A5);
    Serial.println(sensorValue);
    int time_delay = sensorValue*3;
    digitalWrite(LED_INDEX[i], HIGH);
    delay(time_delay);
    digitalWrite(LED_INDEX[i], LOW);
    delay(time_delay);
  }
  for (int i = numLed - 1 ; i >= 1 ; i-=2)
  {
    int sensorValue = analogRead(A5);
    Serial.println(sensorValue);
    int time_delay = sensorValue*3;
    digitalWrite(LED_INDEX[i], HIGH);
    delay(time_delay);
    digitalWrite(LED_INDEX[i], LOW);
    delay(time_delay);
  }
}

//nho rut bot day 4 chan A0->A3
void cau5(){
   for (int i = 0; i <= 255; i += 5)
  {
    int sensorValue = analogRead(A5);
      Serial.println(sensorValue);
    int time_delay = sensorValue * 3;
    for (int j = 0; j < 6; j++)
    {
      analogWrite(LED_INDEX[j], i);
    }
    delay(time_delay);
  }
}
void loop()
{
  cau5();
}

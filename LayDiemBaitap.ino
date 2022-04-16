#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9
#define LED 3
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.
int check = 0;
int isturnoff =0;
unsigned long timer,timer2=0;
void setup()
{
    Serial.begin(9600); // Initiate a serial communication
    SPI.begin();        // Initiate  SPI bus
    mfrc522.PCD_Init(); // Initiate MFRC522
    Serial.println("Approximate your card to the reader...");
    Serial.println();
    pinMode(LED,OUTPUT);
   // digitalWrite(LED, LOW);
}
void loop()
{
  
     if(isturnoff==1){
      digitalWrite(LED, LOW);
      delay(2000);
      isturnoff=0;
      check =0;
    }
    else if(check==1){
        Serial.println("High");
        digitalWrite(LED, HIGH);
        delay(300);
        
    }else if(check==2){
      Serial.println("Low-low");
        digitalWrite(LED, LOW);
        delay(300);
        Serial.println("Low-high");
        digitalWrite(LED, HIGH);
        delay(300);
        
    }
    // Look for new cards
    if (!mfrc522.PICC_IsNewCardPresent())
    {
        
        return;
    }
    // Select one of the cards
    if (!mfrc522.PICC_ReadCardSerial())
    {
        return;
    }
    // Show UID on serial monitor
    Serial.print("UID tag :");
    String content = "";
    byte letter;
    for (byte i = 0; i < mfrc522.uid.size; i++)
    {
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
        content.concat(String(mfrc522.uid.uidByte[i], HEX));
    }
    Serial.println();
    Serial.print("Message : ");
    content.toUpperCase();
        if (content.substring(1) == "E1 71 88 20") // change here the UID of the card/cards that you want to give access
        {
             Serial.println("Authorized access");
             if (check==1){
                if (millis()-timer<1000){
                  isturnoff=1;
                }
                
            }
            timer=millis();
            check = 1;
            //isturnoff +=1;
            Serial.println(isturnoff);
        }

        else
        {
          Serial.println("Authorized denied");
            check = 2;
            isturnoff=0;
        }   
}

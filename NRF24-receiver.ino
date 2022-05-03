#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

RF24 radio(7,8);

const byte address[6] = "00001";
//int LED = 2;

void setup() {
 
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0,address);
  radio.setPALevel(RF24_PA_MAX);
  radio.setDataRate(RF24_250KBPS);
  radio.startListening();
}

void loop() {

float text1;
  if (radio.available()) {

    radio.read(&text1,sizeof(text1));
    
    if (text1 > 25 && text1 < 50) {
        //Serial.println("SEÑAL BUENA");
        //digitalWrite(LED,HIGH);;
        //delay(25);
        //digitalWrite(LED,LOW);
        //delay(25);
        Serial.print("T");
        Serial.print(text1);
        Serial.print("\t");
        Serial.println("\t");
        delay(200);
      }
       
      }else{
        Serial.println("SIN SEÑAL");
        delay(1000);
    }
  }

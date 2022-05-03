//TRASMISOR TX
#include <SPI.h>
#include <nRF24L01.h>
#include <printf.h>
#include <RF24.h>
#include <RF24_config.h>
#include <DHT.h>

#define DHTPIN 2 //PIN DONDE CONECTAR LA SEÑAL DEL SENSOR
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

RF24 radio(7,8);    //pines del radio

const byte address[6] = "00001";       //Direccion solo se necesita 1

void setup() {
  Serial.begin(9600);
  dht.begin();
  radio.begin(); //Se inicia radio
  radio.openWritingPipe(address);     //Se envia la direccion al receptor
  radio.setPALevel(RF24_PA_MAX);     //Potencia de radio al maximo
  radio.setDataRate(RF24_250KBPS);  //Velocidad de datos
  radio.stopListening();           //Dejar de escuchar 
}

void loop() {                         //Envio de mensaje (Trasmisor)

  float t = dht.readTemperature();
  //int h = dht.readHumidity();
  //int tf = dht.readTemperature(true);

  Serial.print("T");
  Serial.print(t);
  Serial.println("\t");
  delay(50);

  //int text1 = 30;
  float text1 = t;     //envia mensaje
 
  radio.write(&text1, sizeof(text1)); //trasforma el mensaje en texto radio
  Serial.print("Señal enviada c: ");
  Serial.print(text1);
  Serial.println("C");
  delay(100);
}

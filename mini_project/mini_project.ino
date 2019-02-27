#include <DHT.h>
#define DHTPIN D5
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
uint8_t temperature, humidity;

void setup() {
 pinMode(D2,OUTPUT);
 pinMode(D3,OUTPUT);
 Serial.begin(115200);
dht.begin();
delay(10);
Serial.println();
Serial.println();

}

void loop() {

  temperature = dht.readTemperature();
humidity = dht.readHumidity();
delay(500);
Serial.print("Temperature Value is :");
Serial.print(temperature);
Serial.print("C");
Serial.print("  Humidity Value is :");
Serial.print(humidity);
Serial.println("%");
delay(100);
  
  if(digitalRead(D1)==LOW || temperature<=30)
  {
    Serial.println("Bright");
    digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  delay(2000);
  }
  else
  {
    Serial.println("Dark");
    digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  delay(500);
  }
}



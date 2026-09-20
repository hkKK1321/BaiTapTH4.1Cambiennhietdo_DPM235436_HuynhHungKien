#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("=== BAI 4.1: DO NHIET DO & DO AM (DHT22) ===");
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Loi: Khong doc duoc du lieu tu DHT22!");
  } else {
    Serial.print("Nhiet do T: ");
    Serial.print(t);
    Serial.print(" *C  |  Do am H: ");
    Serial.print(h);
    Serial.println(" %");
  }
  delay(1000);
}

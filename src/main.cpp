#include <Arduino.h>
#include <DHTesp.h>
#include "devices.h"

DHTesp dht;

void setup() {
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_YELLOW, OUTPUT);
  dht.setup(DHT_PIN, DHTesp::DHT11);
}

void loop() {
  Serial.println("Hello World!");
  digitalWrite(LED_BUILTIN, HIGH);
  digitalWrite(LED_RED, HIGH);
  digitalWrite(LED_GREEN, HIGH);
  digitalWrite(LED_YELLOW, HIGH);
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(LED_RED, LOW);
  digitalWrite(LED_GREEN, LOW);
  digitalWrite(LED_YELLOW, LOW);
  delay(3000);

  float fHumidity = dht.getHumidity();
  float fTemperature = dht.getTemperature();
  Serial.printf("Humidity: %.2f, Temperature: %.2f\n",
       fHumidity, fTemperature);
}


#include <WiFi.h>
#include "DHT.h"
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define DHTPIN 4
#define DHTTYPE DHT22

const char* ssid = "sanju";
const char* password = "";

DHT dht(DHTPIN, DHTTYPE);
Adafruit_SSD1306 display(128, 64, &Wire, -1);

float temp;
float hum;

void setup() {
  Serial.begin(115200);
  dht.begin();

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }

  Serial.println("Connected!");
}

void loop() {
  temp = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print(temp);
  Serial.print(",");
  Serial.println(hum);

  display.clearDisplay();
  display.setTextSize(1);

  display.setCursor(0, 10);
  display.print("Temperature:");
  display.print(temp);

  display.setCursor(0, 30);
  display.print("Humidity:");
  display.print(hum);

  display.display();

  if (temp > 35) {
    Serial.println("Warning: High Temperature!");
  }

  delay(2000);
}

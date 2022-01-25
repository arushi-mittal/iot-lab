#include "WiFi.h"
#include "ThingSpeak.h"
#include <DHT.h>

const char * ssid = "SSID";
const char * password = "******";
const char * writeAPIKey = "*******";
const int TLEDPIN = 22;
const int HLEDPIN = 13;
unsigned long channelID = XXXXXX;

#define DHTPIN 27
#define DHTTYPE DHT22

float tempThreshold = 30, humThreshold = 86;

DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

//unsigned long lastTime = 0;
//unsigned long timerDelay = 30000;

String getTemp () {
  float t = dht.readTemperature();
  if (isnan(t)) {
    Serial.println("No output");
    return "N/A";
  }
  else {
    char buffer[200];
    sprintf(buffer, "Temperature: %f", t);
    Serial.println(buffer);
    return String(t);
  }
}

String getHumidity () {
  float h = dht.readHumidity();
  if (isnan(h)) {
    Serial.println("No output");
    return "N/A";    
  }
  char buffer[200];
  sprintf(buffer, "Humidity: %f \%", h);
  Serial.println(buffer);
  return String(h);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  WiFi.mode(WIFI_STA);
  ThingSpeak.begin(client);
  pinMode(TLEDPIN, OUTPUT);
  pinMode(HLEDPIN, OUTPUT);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting...");
  }
  Serial.println("Connected");
}

void loop() {
  // put your main code here, to run repeatedly:
  String temp = getTemp();
  String hum = getHumidity();

  int tempResponse = ThingSpeak.writeField(channelID, 1, temp, writeAPIKey);
  int humResponse = ThingSpeak.writeField(channelID, 2, hum, writeAPIKey);

  if (tempResponse == 200 && humResponse == 200) {
    char buffer[200];
    sprintf(buffer, "Temperature: %s and Humidity: %s \%", temp, hum);
    Serial.println(buffer);
  }

    float tVal = dht.readTemperature();
    float hVal = dht.readHumidity();
    if (tVal >= tempThreshold) {
      digitalWrite(TLEDPIN, HIGH);
    }
    else {
      digitalWrite(TLEDPIN, LOW);
    }
    if (hVal >= humThreshold) {
      digitalWrite(HLEDPIN, HIGH);
    }
    else {
      digitalWrite(HLEDPIN, LOW);
    }
  delay(1000);
}

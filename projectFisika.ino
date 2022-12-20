#define BLYNK_TEMPLATE_ID           "TMPL3FBKDL8v"
#define BLYNK_DEVICE_NAME           "Quickstart Device"
#define BLYNK_AUTH_TOKEN            "vTngXsPUUHmxagyW-4z6ub527-d5kHzU"
#define BLYNK_PRINT Serial
#define DHTTYPE DHT11
#define DHTPIN D3

#include <DHT.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

DHT dht(DHTPIN, DHTTYPE);

char auth[]= "vTngXsPUUHmxagyW-4z6ub527-d5kHzU";
char ssid[]="Fk";
char pass[]="12345678g";

void setup(){
  Serial.begin(9600);
  dht.begin();
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  int h = dht.readHumidity();
  int s = dht.readTemperature();

  Serial.print("kelembapan: ");
  Serial.print(h);
  Serial.print("%");  
  Serial.print("\n");
  Serial.print("Suhu: ");
  Serial.print(s);
  Serial.print("^C");  
  Serial.print("\n");

  Blynk.virtualWrite(V0, s);
  Blynk.virtualWrite(V1, h);    
  delay(500);
}

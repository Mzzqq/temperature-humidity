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
  float c, r, k, f;
  c = dht.readTemperature();
  k = c + 273.15;
  r = c * (4.0/5.0);
  f = (9.0/5.0)*c + 32;

  Serial.print("Celcius: ");
  Serial.print(c);
  Serial.print(" °C");  
  Serial.print("\n");
  Serial.print("Kelvin: ");
  Serial.print(k);
  Serial.print(" °K");  
  Serial.print("\n");
  Serial.print("Reamur: ");
  Serial.print(r);
  Serial.print(" °R");  
  Serial.print("\n");
  Serial.print("fahrenheit: ");
  Serial.print(f);
  Serial.print(" °F");  
  Serial.print("\n");
  Serial.print("\n");

  Blynk.virtualWrite(V0, c);
  Blynk.virtualWrite(V1, k);
  Blynk.virtualWrite(V2, r);
  Blynk.virtualWrite(V3, f); 

  delay(1000);
}

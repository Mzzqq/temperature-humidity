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
  float c, hum;
  c = dht.readTemperature();
  hum = dht.readHumidity();

  Serial.print("Celcius: ");
  Serial.print(c);
  Serial.print(" °C");  
  Serial.print("\n");
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print("%");  
  Serial.print("\n\n");
  

  Blynk.virtualWrite(V0, c);
  Blynk.virtualWrite(V1, hum);

  if(c > 25){
    Blynk.logEvent("temp_up","Temperature above 25°C");
  } else if (c < 22){
    Blynk.logEvent("temp_down","Temperature below 22°C");
  }

  if(hum > 60){
    Blynk.logEvent("hum_up","Humidity above 60%");
  } else if (hum < 40){
    Blynk.logEvent("hum_down","Humidity below 40%");
  }  

  delay(1000);
}

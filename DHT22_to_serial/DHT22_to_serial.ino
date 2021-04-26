//Include
#include "DHT.h"

//Pins
#define DHTPIN 7


//Define
#define DHTTYPE DHT22

//Initialization
DHT dht(DHTPIN, DHTTYPE);

//Variables



void setup() {
  Serial.begin(9600);
  Serial.println(F("Arduino.Connected"));
  dht.begin();
}


void loop() {
  // Wait a few seconds between measurements.
    delay(2000);
  //Running temperature function
    Temp_measurement_DHT22();
  
}

  void Temp_measurement_DHT22()
  {
     // Reading temperature or humidity takes about 250 milliseconds!
   // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
    // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
    // Check if any reads failed and exit early (to try again) for DHT22.
    if (isnan(h) || isnan(t)) {
            Serial.println(F("Error.For_temperature_measurement")); }
    else {
            Serial.print(F(" Humidity: "));
            Serial.print(h);
            Serial.print(F("%  Temperature: "));
            Serial.print(t);
      }
    return;    
    }
  

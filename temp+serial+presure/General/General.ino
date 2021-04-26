//Include
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include "DHT.h"
#include <Adafruit_GFX.h>    // Core graphics library
#include <TftSpfd5408.h> // Hardware-specific library

//Pins
#define DHTPIN 31
#define SEALEVELPRESSURE_HPA (1013.25)
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0
#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

//Define
#define DHTTYPE DHT22
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

//Initialization
Adafruit_BME280 bme; //Init BME280
DHT dht(DHTPIN, DHTTYPE); //Init DHT
TftSpfd5408 tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET); //Init disp

//Variables



void setup() {
  Serial.begin(9600);
  Serial.println(F("Arduino.Connected"));
  dht.begin();
  tft.reset();
  tft.begin(0x9341);
  tft.setRotation(0);
  tft.fillScreen(BLACK);
}


void loop() {
  // Wait a few seconds between measurements.
    delay(2000);
  //Running temperature function
    Temp_measurement_DHT22();
  //Running presure function
    Preuser_measerment();
  //Running TFT func
    TFT_screen();
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
            Serial.println();
            Serial.print(F(" Humidity: "));
            Serial.print(h);
            Serial.print(F("%  Temperature: "));
            Serial.print(t);
      }
    return;    
    }

  void Preuser_measerment()
  {
      if (!bme.begin(0x76)) {
          Serial.println("Could not find a valid BME280 sensor, check wiring!");
           while (1);
      }
      else {
           Serial.println();
           Serial.print(F(" Preasure: "));
           Serial.print(bme.readPressure() / 100.0F);
           Serial.println(" hPA");
           Serial.print(F(" Preasure: "));
           Serial.print((bme.readPressure() / 100.0F)*0.75);
           Serial.println(F(" Millimetre"));  
           Serial.println(bme.readPressure());
      }
   }

  void TFT_screen() {
    tft.setCursor(0, 0);
    tft.setTextColor(WHITE);  tft.setTextSize(2);
    tft.print("Humidity: ");
    tft.print(dht.readHumidity());
    tft.println(" %");
    tft.print("Temp.: ");
    tft.print(dht.readTemperature());
    tft.println(" C");
    tft.print("Pressure.: ");
    tft.print((bme.readPressure() / 100.0F)*0.75);
    tft.println(" mm");
     }
    

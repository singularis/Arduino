# Arduino Sensor Monitoring & Display Systems

A comprehensive collection of Arduino projects focused on environmental sensor monitoring, data visualization, and PC-Arduino communication systems. This workspace contains various projects ranging from simple sensor readings to advanced TFT display interfaces with real-time data visualization.

## 🎯 Project Overview

This repository contains multiple Arduino sketches designed for:
- **Environmental Monitoring**: Temperature, humidity, and pressure sensing
- **Data Visualization**: TFT display interfaces with custom graphics and meters
- **PC-Arduino Communication**: Serial communication for real-time data exchange
- **System Monitoring**: CPU load and RAM usage display from connected PC

## 📁 Project Structure

### 🌡️ **Environmental Sensor Projects**

#### `DHT22_to_serial/`
- **Purpose**: Basic temperature and humidity monitoring using DHT22 sensor
- **Features**: Serial output of humidity and temperature readings
- **Hardware**: DHT22 sensor, Arduino
- **Data Output**: Formatted serial data every 2 seconds

#### `Preasure/`
- **Purpose**: Atmospheric pressure monitoring using BME280 sensor
- **Features**: 
  - Pressure readings in hPa and mmHg
  - Temperature and humidity monitoring
  - Altitude calculation
- **Hardware**: BME280 sensor, Arduino
- **Communication**: I2C protocol

#### `temp+serial+presure/General/`
- **Purpose**: Combined environmental monitoring with TFT display
- **Features**:
  - DHT22 temperature/humidity monitoring
  - BME280 pressure sensing
  - TFT display output
  - Real-time data visualization
- **Hardware**: DHT22, BME280, TFT display, Arduino

### 📊 **Advanced Display Systems**

#### `cpu_shows/`
- **Purpose**: Advanced PC monitoring dashboard with TFT display
- **Features**:
  - Real-time CPU load visualization with analog meter
  - RAM usage display
  - Environmental sensors integration
  - Custom ring meter graphics
  - Rainbow color schemes
  - Relay control for power management
- **Hardware**: Arduino Mega, TFT display, DHT22, BME280, relay module
- **Author**: Danny van den Brande (ArduinoSensors.nl, Bluecore Tech)

#### `temp_running_interface/`
- **Purpose**: Temperature monitoring interface with serial communication
- **Features**:
  - Professional TFT interface
  - Real-time temperature gauge
  - Serial data reception
  - Heat index calculations
  - Touch screen capabilities
- **Hardware**: TFT touchscreen, DHT22, BME280, Arduino Mega

#### `data_excanhge_included/`
- **Purpose**: Comprehensive data exchange system
- **Features**:
  - Multi-sensor data collection
  - TFT display with custom UI
  - Serial communication protocol
  - Real-time data visualization
  - Touch screen interface

### 🔌 **Communication Projects**

#### `Serial sender/`
- **Purpose**: Python script for PC-Arduino communication
- **Features**:
  - CPU usage monitoring (using psutil)
  - Memory usage tracking
  - Serial communication with Arduino
  - Real-time system statistics
- **Language**: Python 3
- **Dependencies**: `psutil`, `pyserial`

#### `Serial_test/`
- **Purpose**: Basic serial communication testing
- **Features**: Simple Arduino-PC communication verification
- **Usage**: Testing serial connections and data transmission

#### `test_serial/`
- **Purpose**: Enhanced serial communication testing
- **Features**: Advanced serial protocol testing and debugging

### 🎮 **Control & Interface Projects**

#### `cpu_shows_on_off/`
- **Purpose**: CPU monitoring with power control features
- **Features**: System monitoring with automated power management

#### `from_pc_to_arduinot_test/`
- **Purpose**: PC to Arduino data transmission testing
- **Features**: Bidirectional communication testing

#### `sketch_oct03a/`
- **Purpose**: Development/testing sketch
- **Features**: Various experimental features and testing code

### 📱 **Display Resources**

#### `TFT-Shield-Example-Code-master5/`
- **Purpose**: TFT display example code and resources
- **Features**:
  - Graphics testing examples
  - Bitmap display functionality
  - Paint application
  - Rotation testing
- **Resources**: Sample bitmaps, shield configurations

## 🛠️ Hardware Requirements

### Core Components
- **Arduino Mega 2560** (recommended for most projects)
- **TFT Display** (SPFD5408 chipset, 320x240 resolution)
- **DHT22 Sensor** (Temperature & Humidity)
- **BME280 Sensor** (Pressure, Temperature, Humidity)
- **Relay Module** (for power control)
- **Breadboard & Jumper Wires**

### Optional Components
- **Touch Screen** (for interactive projects)
- **SD Card Module** (for data logging)
- **Real-time Clock Module** (for timestamp features)

## 📚 Library Dependencies

### Core Libraries (Included in `libraries/` folder)
- `Adafruit_BME280_Library` - BME280 sensor support
- `Adafruit_GFX` - Graphics library foundation
- `Adafruit_ILI9341` - TFT display driver
- `Adafruit_TouchScreen` - Touch screen functionality
- `DHT_sensor_library` - DHT22/DHT11 sensor support
- `SPFD5408_TFT_Library` - TFT display specific library
- `RTClib` - Real-time clock functionality
- `Servo` - Servo motor control

### Python Dependencies (for PC scripts)
```bash
pip install psutil pyserial
```

## 🚀 Quick Start Guide

### 1. Hardware Setup
1. Connect DHT22 sensor to pin 31
2. Connect BME280 sensor via I2C (SDA/SCL)
3. Connect TFT display to specified analog pins
4. Connect relay module to pin 35 (if using power control)

### 2. Software Setup
1. Install Arduino IDE
2. Copy libraries from `libraries/` folder to your Arduino libraries directory
3. Open desired project from the project folders
4. Select Arduino Mega as target board
5. Upload sketch to Arduino

### 3. PC Communication Setup
1. Install Python dependencies: `pip install psutil pyserial`
2. Update COM port in Python script
3. Run Python script for PC monitoring features

## 📊 Pin Configurations

### Standard Pin Layout
- **DHT22**: Pin 31
- **BME280**: I2C (SDA: Pin 20, SCL: Pin 21)
- **TFT Display**: 
  - CS: A3, CD: A2, WR: A1, RD: A0, RESET: A4
- **Touch Screen**: 
  - XP: Pin 8, XM: A2, YP: A3, YM: Pin 9
- **Relay**: Pin 35
- **Sensor Pin**: Pin 33

## 🎨 Features

### Visual Elements
- **Custom Ring Meters**: Analog-style gauges with color coding
- **Rainbow Color Schemes**: Dynamic color transitions
- **Professional UI**: Clean, organized display layouts
- **Real-time Updates**: Live data refresh (500ms intervals)

### Data Processing
- **Heat Index Calculations**: Comfort level indicators
- **Pressure Conversion**: Multiple units (hPa, mmHg)
- **Serial Protocol**: Robust PC-Arduino communication
- **Error Handling**: Sensor failure detection and reporting

## 📈 Usage Examples

### Environmental Monitoring
```cpp
// Basic temperature reading
float temperature = dht.readTemperature();
float humidity = dht.readHumidity();
float pressure = bme.readPressure() / 100.0F;
```

### Display Output
```cpp
// Custom ring meter display
ringMeter(cpu_load, 0, 100, x, y, radius, "CPU", GREEN2RED);
```

### Serial Communication
```cpp
// Receiving data from PC
if (Serial.available() > 0) {
    incomingByte = Serial.parseInt();
    // Process received data
}
```

## 🔧 Troubleshooting

### Common Issues
- **Sensor Not Found**: Check I2C connections and addresses
- **Display Not Working**: Verify pin connections and power supply
- **Serial Communication Failed**: Check baud rate and COM port settings
- **Library Errors**: Ensure all required libraries are installed

### Debug Tips
- Use `Serial.println()` for debugging
- Check sensor connections with multimeter
- Verify library versions compatibility
- Monitor serial output for error messages

## 🤝 Contributing

Feel free to contribute to this project by:
- Adding new sensor integrations
- Improving display interfaces
- Enhancing communication protocols
- Adding documentation and examples

## 📝 License

This project contains work by Danny van den Brande (ArduinoSensors.nl, Bluecore Tech) and various open-source contributors. Please respect individual library licenses.

## 🔗 Related Resources

- [Arduino Official Documentation](https://www.arduino.cc/reference/)
- [Adafruit Learning System](https://learn.adafruit.com/)
- [Arduino Sensors Website](http://ArduinoSensors.nl)

---

**Note**: This is a comprehensive sensor monitoring system designed for educational and practical applications. Always ensure proper electrical connections and safety measures when working with electronics. 
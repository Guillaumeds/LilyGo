# T-SIM7070G Available GPIO Pins Guide

## 🔍 **IMPORTANT CORRECTION**
The original GPIO mapping document showed many pins as "conditionally used for LoRa" - but this is **INCORRECT** for the T-SIM7070G. The LoRa examples in the codebase are for **external LoRa shields**, not built-in functionality. Your T-SIM7070G does **NOT** have integrated LoRa, so all those pins are actually **AVAILABLE** for your use!

## ✅ **Available Pins Summary for T-SIM7070G**

### **Fully Available Pins (13 pins)**
| GPIO | Capabilities | Best Use Cases |
|------|-------------|----------------|
| **5** | Strapping pin (must be HIGH at boot) | Digital I/O, SPI CS |
| **16** | General purpose | Digital I/O, PWM, Interrupts |
| **17** | General purpose | Digital I/O, PWM, Interrupts |
| **18** | General purpose | SPI Clock, Digital I/O |
| **19** | General purpose | SPI MISO, Digital I/O |
| **23** | General purpose | SPI MOSI, Digital I/O |
| **32** | ADC1, Touch, RTC | Analog input, Touch sensor, Wake-up |
| **33** | ADC1, Touch, RTC | Analog input, Touch sensor, Wake-up |
| **34** | Input-only, ADC1, RTC | Analog input only, Wake-up |
| **39** | Input-only, ADC1, RTC | Analog input only, Wake-up |

### **Conditionally Available Pins (3 pins)**
| GPIO | Condition | Capabilities | Notes |
|------|-----------|-------------|-------|
| **0** | If boot considerations handled | Strapping, ADC2, Touch, RTC | Has pull-up, affects boot mode |
| **1** | If Serial debug not needed | UART0 TX | Usually used for Serial.print() |
| **3** | If Serial debug not needed | UART0 RX | Usually used for Serial input |

## 🛠️ **What You Can Do With These Pins**

### **Digital I/O Applications**
- **GPIO 5, 16, 17, 18, 19, 23**: Perfect for:
  - LED control
  - Button inputs
  - Relay control
  - Digital sensors (temperature, humidity, motion)
  - PWM outputs (servo control, LED dimming)
  - Interrupt inputs

### **Analog Input Applications**
- **GPIO 32, 33**: ADC1 channels (work with WiFi active)
  - Voltage monitoring
  - Analog sensors (light, pressure, etc.)
  - Battery level monitoring (additional to built-in)
  - Touch sensors

- **GPIO 34, 39**: Input-only ADC1 channels
  - Voltage monitoring only
  - Analog sensors (read-only)

### **Communication Interfaces**

#### **Additional SPI Bus**
Use the "former LoRa pins" for a second SPI bus:
```cpp
// HSPI configuration using available pins
#define HSPI_MISO  19
#define HSPI_MOSI  23  
#define HSPI_SCLK  18
#define HSPI_SS    5

SPIClass hspi(HSPI);
hspi.begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);
```

#### **Additional I2C Bus**
Create a second I2C bus using available pins:
```cpp
#define I2C2_SDA  16
#define I2C2_SCL  17

TwoWire I2C2 = TwoWire(1);
I2C2.begin(I2C2_SDA, I2C2_SCL);
```

#### **Additional UART**
Use available pins for extra serial communication:
```cpp
#define UART2_RX  16
#define UART2_TX  17

HardwareSerial Serial2(2);
Serial2.begin(9600, SERIAL_8N1, UART2_RX, UART2_TX);
```

### **Deep Sleep Wake-up Sources**
RTC domain pins can wake ESP32 from deep sleep:
- **GPIO 32, 33, 34, 39**: Perfect for wake-up buttons or sensors
- **GPIO 0**: Boot button (already has pull-up)

## 📋 **Pin Assignment Recommendations**

### **For Sensor Projects**
```cpp
// Recommended pin assignments
#define TEMP_SENSOR_PIN    16    // Digital temperature sensor
#define MOTION_SENSOR_PIN  17    // PIR motion sensor  
#define LIGHT_SENSOR_PIN   32    // Analog light sensor (ADC1)
#define BUTTON_PIN         33    // User button with touch
#define LED_STATUS_PIN     18    // Status LED
#define RELAY_PIN          19    // Relay control
```

### **For Display Projects**
```cpp
// SPI display on available pins
#define TFT_CS    5
#define TFT_DC    16
#define TFT_RST   17
#define TFT_MOSI  23
#define TFT_SCLK  18
#define TFT_MISO  19  // If needed
```

### **For Multiple Sensors**
```cpp
// I2C sensors on default bus (GPIO 21/22)
// Additional I2C sensors on second bus
#define I2C2_SDA  16
#define I2C2_SCL  17

// Analog sensors
#define PRESSURE_SENSOR   32  // ADC1
#define VOLTAGE_MONITOR   33  // ADC1
#define CURRENT_SENSOR    34  // ADC1 (input-only)

// Digital I/O
#define PUMP_CONTROL      18
#define VALVE_CONTROL     19
#define ALARM_OUTPUT      23
#define STATUS_LED        5
```

## ⚠️ **Important Considerations**

### **Strapping Pin (GPIO 5)**
- Must be HIGH during boot for normal operation
- Safe to use after boot for any digital I/O
- Avoid pulling LOW during boot/reset

### **ADC Limitations**
- **ADC1** (GPIO 32, 33, 34, 39): Can be used with WiFi active ✅
- **ADC2** (GPIO 0): Cannot be used when WiFi is active ❌
- Input-only pins (34, 39) cannot drive outputs

### **Boot Considerations**
- **GPIO 0**: Has pull-up, used for boot mode selection
- **GPIO 1, 3**: Used for Serial communication by default
- Safe to use after proper configuration

### **Power Consumption**
- Configure unused pins as INPUT with pull-up/down
- RTC pins (32, 33, 34, 39) can wake from deep sleep
- Input-only pins (34, 39) have no internal pull resistors

## 🔧 **Example Configurations**

### **Basic Sensor Setup**
```cpp
void setup() {
    // Digital outputs
    pinMode(18, OUTPUT);  // LED
    pinMode(19, OUTPUT);  // Relay
    
    // Digital inputs  
    pinMode(16, INPUT_PULLUP);  // Button
    pinMode(17, INPUT);         // Sensor
    
    // Analog inputs
    pinMode(32, INPUT);  // ADC1
    pinMode(33, INPUT);  // ADC1
    pinMode(34, INPUT);  // Input-only
    pinMode(39, INPUT);  // Input-only
}
```

### **Advanced Multi-Interface Setup**
```cpp
#include <Wire.h>
#include <SPI.h>

// Second I2C bus
TwoWire I2C2 = TwoWire(1);

// Second SPI bus  
SPIClass HSPI(HSPI);

void setup() {
    // Initialize second I2C on GPIO 16/17
    I2C2.begin(16, 17);
    
    // Initialize second SPI on GPIO 18/19/23/5
    HSPI.begin(18, 19, 23, 5);
    
    // Configure remaining pins
    pinMode(32, INPUT);   // Analog sensor
    pinMode(33, INPUT);   // Touch button
}
```

## 🎯 **Summary**

Your T-SIM7070G gives you **13 fully available GPIO pins** plus 3 conditional ones - much more than initially thought! The key insight is that LoRa is **NOT built-in**, so all those pins are yours to use.

**Best pins for different uses:**
- **General digital I/O**: GPIO 16, 17, 18, 19, 23
- **Analog inputs**: GPIO 32, 33 (with WiFi), GPIO 34, 39 (input-only)
- **SPI devices**: Use GPIO 5, 18, 19, 23 for second SPI bus
- **I2C devices**: Use GPIO 16, 17 for second I2C bus  
- **Wake-up sources**: GPIO 32, 33, 34, 39 (RTC domain)
- **Boot-safe**: GPIO 16, 17, 18, 19, 23, 32, 33, 34, 39

This gives you plenty of flexibility for complex IoT projects!

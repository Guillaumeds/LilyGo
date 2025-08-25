# LilyGO-T-SIM7000G Complete GPIO Mapping

## Overview
This document provides a comprehensive mapping of all ESP32 GPIO pins (0-39) for the LilyGO-T-SIM7000G board, including their functions, capabilities, and usage status.

## Pin Status Legend
- ✅ **USED**: Pin is used by onboard hardware
- 🔶 **CONDITIONAL**: Pin used when optional shields are attached
- 🟢 **AVAILABLE**: Pin available for user applications
- ❌ **NOT AVAILABLE**: Pin not accessible or reserved
- ⚠️ **RESTRICTED**: Pin available but with limitations

## Complete GPIO Mapping (0-39)

| GPIO | Function | Status | ESP32 Capabilities | Notes |
|------|----------|--------|-------------------|-------|
| 0 | Boot Button | ⚠️ | Strapping, ADC2, Touch, RTC | Pulled up, affects boot mode |
| 1 | UART0 TX | ⚠️ | Serial TX | Used for Serial communication |
| 2 | SD_MISO | ✅ | Strapping, ADC2, Touch, RTC | Must be LOW at boot |
| 3 | UART0 RX | ⚠️ | Serial RX | Used for Serial communication |
| 4 | PWR_PIN | ✅ | Strapping, ADC2, Touch, RTC | SIM7000 power control |
| 5 | LORA_SS | 🔶 | Strapping | LoRa SPI CS, must be HIGH at boot |
| 6 | - | ❌ | Internal Flash | Connected to SPI flash |
| 7 | - | ❌ | Internal Flash | Connected to SPI flash |
| 8 | - | ❌ | Internal Flash | Connected to SPI flash |
| 9 | - | ❌ | Internal Flash | Connected to SPI flash |
| 10 | - | ❌ | Internal Flash | Connected to SPI flash |
| 11 | - | ❌ | Internal Flash | Connected to SPI flash |
| 12 | LED_PIN / LORA_RST | ✅/🔶 | Strapping, ADC2, Touch, RTC | Blue LED, LoRa reset (conflict!) |
| 13 | SD_CS | ✅ | ADC2, Touch, RTC | SD card chip select |
| 14 | SD_SCLK | ✅ | ADC2, Touch, RTC | SD card SPI clock |
| 15 | SD_MOSI | ✅ | Strapping, ADC2, Touch, RTC | SD card SPI MOSI |
| 16 | - | 🟢 | - | Available for user applications |
| 17 | - | 🟢 | - | Available for user applications |
| 18 | LORA_SCK | 🔶 | - | LoRa SPI clock |
| 19 | LORA_MISO | 🔶 | - | LoRa SPI MISO |
| 20 | - | ❌ | Not exposed | Not available on most modules |
| 21 | I2C_SDA | ✅ | - | Default I2C data line |
| 22 | I2C_SCL | ✅ | - | Default I2C clock line |
| 23 | LORA_MOSI | 🔶 | - | LoRa SPI MOSI |
| 24 | - | ❌ | Not exposed | Not available on most modules |
| 25 | PIN_DTR | ✅ | ADC2, DAC1, RTC | SIM7000 Data Terminal Ready |
| 26 | PIN_RX | ✅ | ADC2, DAC2, RTC | UART RX from SIM7000 |
| 27 | PIN_TX | ✅ | ADC2, Touch, RTC | UART TX to SIM7000 |
| 28 | - | ❌ | Not exposed | Not available on most modules |
| 29 | - | ❌ | Not exposed | Not available on most modules |
| 30 | - | ❌ | Not exposed | Not available on most modules |
| 31 | - | ❌ | Not exposed | Not available on most modules |
| 32 | LORA_DI0 | 🔶 | ADC1, Touch, RTC | LoRa digital I/O 0 |
| 33 | RADIO_DIO_1 | 🔶 | ADC1, Touch, RTC | LoRa digital I/O 1 |
| 34 | RADIO_DIO_2 | 🔶 | Input-only, ADC1, RTC | LoRa digital I/O 2 |
| 35 | BATTERY_ADC | ✅ | Input-only, ADC1, RTC | Battery voltage divider |
| 36 | SOLAR_ADC | ✅ | Input-only, ADC1, RTC | Solar panel voltage |
| 37 | - | ❌ | Not exposed | Not available on most modules |
| 38 | - | ❌ | Not exposed | Not available on most modules |
| 39 | - | 🟢 | Input-only, ADC1, RTC | Available (input only) |

## Detailed Pin Functions

### SIM7000 Module Interface
| Pin | Function | Direction | Description |
|-----|----------|-----------|-------------|
| GPIO 4 | PWR_PIN | Output | Power control for SIM7000 module |
| GPIO 25 | DTR | Output | Data Terminal Ready signal |
| GPIO 26 | RX | Input | UART receive from SIM7000 |
| GPIO 27 | TX | Output | UART transmit to SIM7000 |

### SD Card Interface (SPI)
| Pin | Function | Direction | Description |
|-----|----------|-----------|-------------|
| GPIO 2 | MISO | Input | SPI Master In Slave Out |
| GPIO 13 | CS | Output | SPI Chip Select |
| GPIO 14 | SCLK | Output | SPI Clock |
| GPIO 15 | MOSI | Output | SPI Master Out Slave In |

### Analog Inputs
| Pin | Function | Range | Description |
|-----|----------|-------|-------------|
| GPIO 35 | Battery ADC | 0-3.3V | Battery voltage through divider |
| GPIO 36 | Solar ADC | 0-3.3V | Solar panel voltage |

### I2C Interface
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO 21 | SDA | I2C Data line (default ESP32 pin) |
| GPIO 22 | SCL | I2C Clock line (default ESP32 pin) |

### Onboard LED
| Pin | Function | Description |
|-----|----------|-------------|
| GPIO 12 | Blue LED | Onboard status LED (active LOW) |

### LoRa Shield Interface (Optional)
| Pin | Function | Direction | Description |
|-----|----------|-----------|-------------|
| GPIO 5 | SS | Output | LoRa SPI Chip Select |
| GPIO 12 | RST | Output | LoRa Reset (conflicts with LED!) |
| GPIO 18 | SCK | Output | LoRa SPI Clock |
| GPIO 19 | MISO | Input | LoRa SPI MISO |
| GPIO 23 | MOSI | Output | LoRa SPI MOSI |
| GPIO 32 | DIO0 | Input | LoRa Digital I/O 0 |
| GPIO 33 | DIO1 | Input | LoRa Digital I/O 1 |
| GPIO 34 | DIO2 | Input | LoRa Digital I/O 2 |

## Available Pins for User Applications

### Fully Available Pins
- **GPIO 16**: General purpose I/O
- **GPIO 17**: General purpose I/O  
- **GPIO 39**: Input-only, ADC1 capable, RTC domain

### Conditionally Available Pins
- **GPIO 0**: Available but affects boot mode (has pull-up)
- **GPIO 1**: Available if not using Serial for debugging
- **GPIO 3**: Available if not using Serial for debugging
- **GPIO 5**: Available if not using LoRa shield
- **GPIO 18**: Available if not using LoRa shield
- **GPIO 19**: Available if not using LoRa shield
- **GPIO 23**: Available if not using LoRa shield
- **GPIO 32**: Available if not using LoRa shield (ADC1, Touch)
- **GPIO 33**: Available if not using LoRa shield (ADC1, Touch)
- **GPIO 34**: Available if not using LoRa shield (Input-only, ADC1)

## ESP32 Pin Capabilities Reference

### ADC (Analog-to-Digital Converter)
- **ADC1** (GPIO 32-39): Can be used with WiFi active
- **ADC2** (GPIO 0, 2, 4, 12-15, 25-27): Cannot be used when WiFi is active

### DAC (Digital-to-Analog Converter)
- **DAC1**: GPIO 25 (8-bit)
- **DAC2**: GPIO 26 (8-bit)

### Touch Sensors
- GPIO 0, 2, 4, 12-15, 27, 32, 33

### RTC Domain (Deep Sleep Wake-up)
- GPIO 0, 2, 4, 12-15, 25-27, 32-39

### Strapping Pins (Boot Configuration)
- **GPIO 0**: Boot mode selection
- **GPIO 2**: Must be LOW for normal boot
- **GPIO 5**: Must be HIGH for normal boot
- **GPIO 12**: Flash voltage selection (should be LOW for 3.3V)
- **GPIO 15**: Timing configuration

## Important Notes and Restrictions

### ⚠️ Critical Warnings
1. **GPIO 12 Conflict**: Used for both LED and LoRa reset - cannot use LoRa shield with LED
2. **Strapping Pins**: GPIO 0, 2, 5, 12, 15 affect boot behavior
3. **Input-Only**: GPIO 34, 35, 36, 39 cannot be used as outputs
4. **ADC2 + WiFi**: ADC2 pins cannot be used for analog reading when WiFi is active
5. **Flash Pins**: GPIO 6-11 are connected to internal flash - never use these

### 💡 Recommendations
1. **For sensors**: Use GPIO 16, 17 for digital sensors
2. **For analog inputs**: Use GPIO 39 (ADC1) or GPIO 32-34 if LoRa not used
3. **For interrupts**: Any available GPIO except input-only pins
4. **For PWM**: Any available output-capable GPIO
5. **For additional I2C**: Use software I2C on GPIO 16, 17
6. **For additional SPI**: Use HSPI on available pins

## Power Consumption Notes
- Unused pins should be configured as inputs with pull-up/pull-down to minimize current
- RTC domain pins (GPIO 0, 2, 4, 12-15, 25-27, 32-39) can wake ESP32 from deep sleep
- Input-only pins (34, 35, 36, 39) have no internal pull resistors

## Pin Configuration Examples

### Basic GPIO Setup
```cpp
// Available pins for user applications
#define USER_PIN_1    16    // General purpose I/O
#define USER_PIN_2    17    // General purpose I/O
#define USER_ANALOG   39    // Input-only, ADC1

void setup() {
    pinMode(USER_PIN_1, OUTPUT);
    pinMode(USER_PIN_2, INPUT_PULLUP);
    pinMode(USER_ANALOG, INPUT);
}
```

### Additional I2C Bus
```cpp
#include <Wire.h>

// Use software I2C on available pins
#define I2C2_SDA  16
#define I2C2_SCL  17

TwoWire I2C2 = TwoWire(1);

void setup() {
    I2C2.begin(I2C2_SDA, I2C2_SCL);
}
```

### Additional SPI Bus (if LoRa not used)
```cpp
#include <SPI.h>

// Use HSPI on LoRa pins when LoRa shield not attached
#define HSPI_MISO  19
#define HSPI_MOSI  23
#define HSPI_SCLK  18
#define HSPI_SS    5

SPIClass hspi(HSPI);

void setup() {
    hspi.begin(HSPI_SCLK, HSPI_MISO, HSPI_MOSI, HSPI_SS);
}
```

## Troubleshooting Common Issues

### Boot Problems
- **Symptom**: ESP32 won't boot or enters download mode
- **Cause**: Strapping pins in wrong state
- **Solution**: Check GPIO 0, 2, 5, 12, 15 connections

### ADC Reading Issues
- **Symptom**: ADC2 pins return 0 when WiFi is active
- **Cause**: ADC2 shares hardware with WiFi
- **Solution**: Use ADC1 pins (32-39) or disable WiFi during ADC reading

### LoRa + LED Conflict
- **Symptom**: Cannot use both LoRa shield and onboard LED
- **Cause**: Both use GPIO 12
- **Solution**: Choose one or modify hardware/software

### I2C Device Not Found
- **Symptom**: I2C scanner doesn't find devices
- **Cause**: Wrong pins or pull-up resistors missing
- **Solution**: Verify GPIO 21/22 connections and add pull-ups if needed

## Hardware Modifications

### Adding External Pull-ups
For reliable I2C operation, add 4.7kΩ pull-up resistors:
- GPIO 21 (SDA) to 3.3V
- GPIO 22 (SCL) to 3.3V

### Disabling Onboard LED
To free GPIO 12 for other uses:
- Desolder LED or cut trace
- Remove current limiting resistor

### Additional ADC Inputs
Use voltage dividers for higher voltage inputs:
- Max input: 3.3V
- For 5V: Use 1:1 voltage divider
- For 12V: Use 1:3 voltage divider

## Board Variants and Differences

### LilyGO-T-SIM7000G Versions
- **20191227**: Original version
- **20200415**: Added GPS power control (AT+CGPIO=0,48,1,1)

### Pin Differences
All versions use the same GPIO mapping for ESP32 connections.

## Related Documentation
- [ESP32 Datasheet](https://www.espressif.com/sites/default/files/documentation/esp32_datasheet_en.pdf)
- [ESP32 Technical Reference](https://www.espressif.com/sites/default/files/documentation/esp32_technical_reference_manual_en.pdf)
- [SIM7000 AT Command Manual](SIM7000_AT_Commands.md)
- [LilyGO GitHub Repository](https://github.com/Xinyuan-LilyGO/LilyGo-Modem-Series)

## Revision History
- **v1.0**: Initial comprehensive GPIO mapping based on codebase analysis
- **Source**: LilyGO-T-SIM7000G repository analysis and ESP32 datasheet

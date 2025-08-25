# Soil Sensor Monitoring System

## Overview
This implementation extends the existing ESP32 deep sleep + SIM7000 system to include:
- **Modbus RS485 soil sensor communication** via GPIO 32/33
- **Backup battery monitoring** via GPIO 34 with voltage divider
- **Sensor power control** via GPIO 35 with MOSFET switching
- **Enhanced ThingSpeak data logging** with 8 fields of data

## Hardware Configuration

### Pin Assignments
```
GPIO 32 -> TTL to MODBUS485 board TXD pin
GPIO 33 -> TTL to MODBUS485 board RXD pin  
GPIO 34 -> Backup battery voltage (via voltage divider)
GPIO 35 -> MOSFET trigger for sensor power control
```

### Backup Battery Voltage Divider
- **Ratio**: 2.024 (when backup battery = 3.850V, ESP32 pin = 1.902V)
- **Calculation**: `actual_voltage = adc_voltage * 2.024`

### MOSFET Power Control
- **Device**: B83111 MOSFET module (from Temu link provided)
- **Control Logic**: GPIO 35 HIGH = sensors ON, LOW = sensors OFF
- **Test Cycle**: 4s ON, 5s OFF during startup for verification

## ThingSpeak Data Fields

| Field | Data | Unit | Description |
|-------|------|------|-------------|
| Field 1 | Main Battery Voltage | V | Primary battery voltage |
| Field 2 | Backup Battery Voltage | V | Backup battery voltage |
| Field 3 | Soil Moisture | % | Soil moisture percentage |
| Field 4 | Soil Temperature | °C | Soil temperature |
| Field 5 | Soil pH | pH | Soil pH level |
| Field 6 | Main Battery % | % | Main battery percentage |
| Field 7 | Backup Battery % | % | Backup battery percentage |
| Field 8 | Cycle Counter | count | Boot/cycle counter |

## Modbus Communication

### Configuration
- **Baud Rate**: 9600
- **Protocol**: Modbus RTU
- **Function Code**: 0x03 (Read Holding Registers)
- **Slave Address**: 1 (configurable)
- **Registers**: 3 (moisture, temperature, pH)

### Example Modbus Request
```
Slave Addr: 0x01
Function:   0x03 (Read Holding Registers)
Start Addr: 0x0000
Num Regs:   0x0003
CRC:        Calculated automatically
```

### Data Parsing
Raw sensor values are converted using scaling factors:
- **Moisture**: `raw_value / 10.0` (adjust as needed)
- **Temperature**: `raw_value / 10.0` (adjust as needed)  
- **pH**: `raw_value / 100.0` (adjust as needed)

## Power Management

### Sensor Power Cycle
1. **Startup**: Test cycle (4s ON, 5s OFF) to verify MOSFET operation
2. **Measurement**: Power ON → 2s stabilization → Read sensors → Power OFF
3. **Sleep**: All sensors powered OFF during ESP32 deep sleep

### Battery Monitoring
Both main and backup batteries use advanced sampling:
- **15 sample sets** of **15 readings each** (225 total samples)
- **Median filtering** per sample set
- **Statistical averaging** of all medians
- **Percentage calculation** based on voltage range

## Operation Sequence

### Boot/Wake Cycle
1. **Initialize** pins and communication
2. **Test** sensor power cycle (first boot only)
3. **Measure** main battery (advanced sampling)
4. **Measure** backup battery (advanced sampling)  
5. **Power ON** sensors and stabilize (2s)
6. **Read** soil sensor data via Modbus
7. **Power OFF** sensors
8. **Connect** to cellular network
9. **Send** all data to ThingSpeak
10. **Sleep** ESP32 and SIM7000 for 5 minutes

### Error Handling
- **Sensor read failure**: Send -1.0 values to indicate error
- **Network failure**: Retry with progressive timeouts
- **MOSFET test**: Visual verification during startup

## Customization

### Sensor-Specific Modifications
You'll need to adjust these parameters based on your specific soil sensor:

```cpp
// Modbus parameters (in read_soil_sensors())
uint8_t slave_addr = 1;           // Your sensor's slave address
uint16_t start_addr = 0x0000;     // Starting register address
uint16_t num_registers = 3;       // Number of registers to read

// Data scaling (in read_soil_sensors())
soilMoisture = moisture_raw / 10.0;     // Adjust divisor
soilTemperature = temp_raw / 10.0;      // Adjust divisor
soilPH = ph_raw / 100.0;                // Adjust divisor
```

### MOSFET Logic
If the MOSFET behavior is inverted, swap the logic in:
```cpp
void sensor_power_on() {
    digitalWrite(SENSOR_POWER_PIN, LOW);   // Change to LOW if inverted
}

void sensor_power_off() {
    digitalWrite(SENSOR_POWER_PIN, HIGH);  // Change to HIGH if inverted
}
```

### Backup Battery Ratio
If your voltage divider ratio is different, update:
```cpp
#define BACKUP_BATTERY_RATIO   2.024   // Change to your actual ratio
```

## Troubleshooting

### MOSFET Not Switching
- Check the test cycle output during startup
- Verify GPIO 35 connections
- Try inverting the HIGH/LOW logic

### No Modbus Response
- Verify GPIO 32/33 connections to RS485 board
- Check baud rate and slave address
- Use oscilloscope to verify signal transmission

### Incorrect Battery Readings
- Verify voltage divider connections
- Check the backup battery ratio calculation
- Ensure proper ADC configuration

### ThingSpeak Upload Issues
- Verify API key and field mappings
- Check cellular network connectivity
- Monitor serial output for HTTP responses

## Next Steps

1. **Test** the MOSFET power cycle during first boot
2. **Verify** Modbus communication with your specific sensor
3. **Adjust** scaling factors based on sensor documentation
4. **Monitor** ThingSpeak data for accuracy
5. **Optimize** power consumption if needed

The system is designed to be robust with comprehensive error handling and detailed logging for debugging.

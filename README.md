# 🛰️ LilyGO T-SIM7000G IoT Tracker

A complete IoT solution for the LilyGO T-SIM7000G board featuring GPS tracking, battery monitoring, and dual connectivity (WiFi + Cellular) with wireless OTA programming.

## 🌟 **Features**

- 📡 **Dual Connectivity**: WiFi (OTA programming) + Cellular (IoT data)
- 🛰️ **GPS Tracking**: Real-time location with satellite count
- 🔋 **Battery Monitoring**: Voltage and percentage with solar panel support
- 📊 **ThingSpeak Integration**: Automatic data upload every 2 minutes
- 🔄 **WiFi OTA Programming**: Wireless code updates via VSCode/PlatformIO
- 🤖 **Automatic APN Detection**: No manual carrier configuration needed
- 📱 **Mobile Hotspot Support**: Works with phone hotspots for remote programming

## 🎯 **Based on Original LilyGO Examples**

This project combines and enhances multiple official LilyGO examples:
- `HttpsBuiltlnGet.ino` - HTTPS communication
- `GPS_BuiltIn.ino` - GPS functionality
- `ReadBattery.ino` - Battery monitoring
- Uses **LilyGO's forked TinyGSM library** with enhanced features

## 🚀 Quick Start

### 1. Hardware Setup
- Insert a SIM card with data plan into your LilyGO T-SIM7000G
- Connect GPS and cellular antennas
- Connect 18650 battery (optional)
- Connect USB cable for programming

### 2. Software Setup

#### Install PlatformIO in VS Code:
1. Open VS Code
2. Go to Extensions (Ctrl+Shift+X)
3. Search for "PlatformIO IDE"
4. Install the extension
5. Restart VS Code

#### Open this project:
1. Open VS Code
2. File → Open Folder
3. Select this project folder
4. PlatformIO will automatically detect the project

### 3. Find Your APN (Automatic Detection)

**Don't know your APN?** No problem! Run the automatic APN detector:

#### Step 1: Run APN Auto-Detection
1. Make sure `default_envs = T-SIM7000G-APN-Detect` in `platformio.ini`
2. Insert your SIM card and connect antennas
3. Upload and run: **PlatformIO → Upload**
4. Open **Serial Monitor** to see results

#### Expected Output:
```
=== LilyGO T-SIM7000G APN Auto-Detection ===
📱 IMSI: 310410123456789
🌍 MCC (Country): 310
📡 MNC (Network): 410
📡 Likely Carrier: AT&T
💡 Suggested APNs: phone, broadband, m2m.com.attz

🧪 Testing Common APNs...
[1/35] Testing: AT&T (USA) - phone
   Connecting... Connected! IP: 10.123.45.67
✅ SUCCESS! This APN works!
📝 Use this configuration:
   Carrier: AT&T
   APN: phone
```

#### Step 2: Update Configuration (Optional)
**Good news!** The main program now uses **automatic APN detection** just like the original LilyGO examples.

If automatic detection fails, you can manually set the APN in `src/main.cpp`:
```cpp
// Uncomment and set your carrier's APN:
#define NETWORK_APN     "phone"              // AT&T
// #define NETWORK_APN     "vzwinternet"        // Verizon
// #define NETWORK_APN     "fast.t-mobile.com"  // T-Mobile
```

#### Step 3: Run Main Program
The project is already configured for the main program:
```ini
default_envs = T-SIM7000G  ; Main GPS & Battery program
```

#### ThingSpeak Configuration:
The project is pre-configured for your ThingSpeak channel:
- Channel ID: 2976042
- Write API Key: RWE803O3NIOLIUQS

**Field Mapping:**
- Field 1: Battery Percentage (%)
- Field 2: GPS Latitude
- Field 3: GPS Longitude
- Field 4: GPS Altitude (m)
- Field 5: Number of Satellites
- Field 6: Battery Voltage (V)
- Field 7: Cellular Signal Strength

### 4. Build and Upload

#### Using PlatformIO:
1. Open VS Code with this project
2. Click the PlatformIO icon in the sidebar
3. Under "PROJECT TASKS" → "T-SIM7000G":
   - Click "Build" to compile
   - Click "Upload" to flash to board
   - Click "Monitor" to view serial output

#### Using Command Line:
```bash
# Build the project
pio run

# Upload to board
pio run --target upload

# Monitor serial output
pio device monitor
```

## 📊 ThingSpeak Channel Modification

Your current ThingSpeak channel is configured for soil monitoring. You have two options:

### Option 1: Use Existing Channel (Recommended)
The code is configured to use your existing channel fields:
- Field 1: Battery Percentage (instead of Soil Moisture)
- Field 2: GPS Latitude (instead of Soil Temperature)
- Field 3: GPS Longitude (instead of Electrical Conductivity)
- Field 4: GPS Altitude (instead of pH Level)

### Option 2: Create New Channel
1. Go to ThingSpeak.com
2. Create a new channel with fields:
   - Field 1: Battery Percentage (%)
   - Field 2: Latitude
   - Field 3: Longitude
   - Field 4: Altitude (m)
   - Field 5: Satellites
   - Field 6: Battery Voltage (V)
   - Field 7: Signal Strength
3. Update the channel ID and API key in `include/config.h`

## 🔧 Customization

### Change Data Transmission Interval:
Edit `include/config.h`:
```cpp
#define DATA_SEND_INTERVAL_MS       120000    // 2 minutes
```

### Enable Debug Output:
All debug options are enabled by default in `include/config.h`:
```cpp
#define DEBUG_SERIAL                true
#define DEBUG_GPS                   true
#define DEBUG_CELLULAR              true
```

### Battery Voltage Calibration:
If battery readings are inaccurate, adjust the voltage divider ratio:
```cpp
#define BATTERY_VOLTAGE_DIVIDER     2.0       // Adjust this value
```

## 📱 Monitoring

### Serial Monitor Output:
```
=== LilyGO T-SIM7000G GPS & Battery Monitor ===
Initializing...
Powering on modem...
Modem powered on
Initializing modem...
Modem responded to AT commands
Modem Info: SIM7000G
Connecting to cellular network...
Waiting for network registration... Connected!
Connecting to GPRS... Connected!
Local IP: 10.x.x.x
Enabling GPS...
GPS enabled
Setup complete! Starting data collection...

=== Data Collection Cycle ===
--- Current Data ---
Battery: 3.85V (70.8%)
GPS: Lat=40.123456, Lon=-74.123456, Alt=45.2m
Satellites: 8
Sending data to ThingSpeak...
Data sent to ThingSpeak!
```

### LED Status Indicators:
- **Slow blink**: Starting up
- **Fast blink**: Searching for GPS/connecting to cellular
- **Solid on**: Ready and operating normally
- **Very fast blink**: Error condition

## 🛠️ Troubleshooting

### Modem Not Responding:
1. Check SIM card is properly inserted
2. Verify antennas are connected
3. Check power supply (USB or battery)
4. Try different APN settings

### GPS Not Getting Fix:
1. Ensure GPS antenna is connected
2. Move to location with clear sky view
3. Wait up to 5 minutes for initial fix
4. Check GPS is enabled in code

### ThingSpeak Upload Fails:
1. Verify internet connection (cellular)
2. Check API key and channel ID
3. Ensure ThingSpeak rate limits (15 seconds between updates)

### Battery Reading Incorrect:
1. Calibrate voltage divider ratio in config.h
2. Check battery is properly connected
3. Verify ADC pin connections

### APN Detection Issues:
1. **No APNs work**: Check SIM card has data plan activated
2. **Modem not responding**: Verify antennas connected, try hardware test first
3. **Network registration fails**: Check cellular coverage in your area
4. **Manual APN needed**: Contact your carrier for correct APN settings

### Common APN by Carrier:
- **Hologram**: `hologram`
- **AT&T**: `phone`, `broadband`, `m2m.com.attz`
- **Verizon**: `vzwinternet`, `verizon`
- **T-Mobile**: `fast.t-mobile.com`, `epc.tmobile.com`
- **Vodafone**: `internet`, `pp.vodafone.co.uk`
- **Rogers**: `internet.com`
- **Bell**: `inet.bell.ca`

## 📋 Dependencies

The project automatically downloads these libraries:
- TinyGSM (cellular modem communication)
- TinyGPS++ (GPS parsing)
- PubSubClient (MQTT, if needed later)
- ArduinoJson (JSON handling)

## 🔗 Useful Links

- [LilyGO T-SIM7000G Documentation](https://github.com/Xinyuan-LilyGO/LilyGo-Modem-Series)
- [ThingSpeak Channel](https://thingspeak.com/channels/2976042)
- [PlatformIO Documentation](https://docs.platformio.org/)
- [TinyGSM Library](https://github.com/vshymanskyy/TinyGSM)

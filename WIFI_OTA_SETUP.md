# 📶 WiFi OTA Setup Guide - LilyGO T-SIM7000G

This guide shows you how to program your LilyGO T-SIM7000G wirelessly using WiFi OTA (Over-The-Air) updates with VSCode and PlatformIO.

## 🎯 **What You'll Achieve:**
- ✅ **Wireless programming** from VSCode without USB cable
- ✅ **Remote updates** to deployed devices
- ✅ **Dual connectivity** - WiFi for programming + Cellular for IoT data
- ✅ **Professional OTA** with password protection and progress monitoring

## 🔧 **Setup Steps:**

### **Step 1: Configure WiFi Credentials**

Edit `include/wifi_config.h`:
```cpp
// Replace with your WiFi network
#define WIFI_SSID           "Your_WiFi_Network"
#define WIFI_PASSWORD       "Your_WiFi_Password"

// OTA settings (optional to change)
#define OTA_HOSTNAME        "lilygo-sim7000g"
#define OTA_PASSWORD        "lilygo123"
```

### **Step 2: First Upload via USB**

**IMPORTANT:** You must upload the OTA-enabled firmware via USB first:

```bash
# Build and upload via USB (one time only)
pio run -e T-SIM7000G -t upload
```

### **Step 3: Find Device IP Address**

After USB upload, check the serial monitor:
```
📶 Step 11: Setup WiFi OTA
   ✅ WiFi connected! IP: 192.168.1.100
   ✅ mDNS started: lilygo-sim7000g.local
   ✅ WiFi OTA ready for wireless programming!
   📡 Use: pio run -e T-SIM7000G-OTA -t upload
   🔑 Password: lilygo123
```

### **Step 4: Wireless Programming**

Now you can program wirelessly from VSCode:

```bash
# Upload new code wirelessly
pio run -e T-SIM7000G-OTA -t upload
```

## 📋 **PlatformIO Configuration**

Your `platformio.ini` includes two environments:

### **USB Programming (First time):**
```ini
[env:T-SIM7000G]
platform = espressif32@6.11.0
board = esp32dev
framework = arduino
# Uses USB connection
```

### **WiFi OTA Programming (After first upload):**
```ini
[env:T-SIM7000G-OTA]
platform = espressif32@6.11.0
board = esp32dev
framework = arduino
upload_protocol = espota
upload_port = lilygo-sim7000g.local  ; mDNS name
upload_flags = --auth=lilygo123      ; OTA password
```

## 🌐 **Network Requirements:**

### **WiFi Network:**
- **Same network** - Your computer and ESP32 must be on the same WiFi network
- **Firewall** - Allow port 3232 (OTA port)
- **Router** - Must support mDNS/Bonjour (most modern routers do)

### **Alternative IP-Based Upload:**
If mDNS doesn't work, use IP address:
```ini
upload_port = 192.168.1.100  ; Replace with actual IP
```

## 🔄 **OTA Upload Process:**

### **What Happens During OTA:**
1. **PlatformIO** builds your code
2. **Connects** to ESP32 via WiFi (port 3232)
3. **Authenticates** with password
4. **Uploads** firmware wirelessly
5. **ESP32 reboots** with new code

### **Expected Output:**
```bash
$ pio run -e T-SIM7000G-OTA -t upload
Processing T-SIM7000G-OTA (platform: espressif32@6.11.0; board: esp32dev; framework: arduino)
--------------------------------------------------------------------------------
Uploading .pio\build\T-SIM7000G-OTA\firmware.bin
Uploading: [============      ] 75% Done...
Uploading: [==================] 100% Done...

SUCCESS
```

## 🛠️ **Troubleshooting:**

### **Problem: "Could not resolve host"**
```bash
Error: Could not resolve host lilygo-sim7000g.local
```
**Solutions:**
1. Use IP address instead of mDNS name
2. Check if device and computer are on same network
3. Try: `ping lilygo-sim7000g.local`

### **Problem: "Authentication failed"**
```bash
Error: Authentication failed
```
**Solutions:**
1. Check OTA password in `wifi_config.h`
2. Verify `upload_flags = --auth=lilygo123` in platformio.ini
3. Make sure passwords match exactly

### **Problem: "Connection timeout"**
```bash
Error: Connection timeout
```
**Solutions:**
1. Check WiFi connection on ESP32
2. Verify firewall allows port 3232
3. Try different WiFi network
4. Check router settings

### **Problem: "Device not found"**
**Solutions:**
1. Check serial monitor for IP address
2. Use IP instead of mDNS: `upload_port = 192.168.1.100`
3. Restart ESP32 and check WiFi connection

## 📱 **Monitoring OTA Updates:**

### **Serial Monitor During OTA:**
```
🔄 OTA Update starting: sketch
📥 OTA Progress: 25% (65536/262144)
📥 OTA Progress: 50% (131072/262144)
📥 OTA Progress: 75% (196608/262144)
📥 OTA Progress: 100% (262144/262144)
✅ OTA Update completed!
```

### **VSCode Terminal:**
```bash
Uploading: [==================] 100% Done...
SUCCESS
```

## 🔐 **Security Features:**

### **Password Protection:**
- **OTA password** required for uploads
- **Configurable** in `wifi_config.h`
- **Prevents unauthorized** firmware updates

### **Network Security:**
- **WiFi encryption** (WPA2/WPA3)
- **Local network only** (not internet accessible)
- **Temporary connection** (only during upload)

## 🎯 **Best Practices:**

### **Development Workflow:**
1. **Develop** code in VSCode
2. **Test** via USB first (if major changes)
3. **Deploy** via WiFi OTA to remote devices
4. **Monitor** via serial or WiFi

### **Remote Deployment:**
1. **Initial setup** via USB at your location
2. **Ship device** to remote location
3. **Update remotely** via WiFi OTA
4. **No physical access** needed for updates

### **Backup Strategy:**
1. **Keep working firmware** version
2. **Test updates** on development device first
3. **Have recovery plan** (physical access for USB)

## 📊 **Dual Connectivity Benefits:**

Your device now has **two communication channels:**

### **WiFi (for programming):**
- ✅ **OTA updates**
- ✅ **Fast data transfer**
- ✅ **Local network access**
- ✅ **Development/debugging**

### **Cellular (for IoT data):**
- ✅ **ThingSpeak uploads**
- ✅ **GPS tracking**
- ✅ **Remote monitoring**
- ✅ **Works anywhere with cell coverage**

## 🚀 **Ready to Use!**

You now have a **professional IoT device** with:
- 📡 **Cellular connectivity** for data
- 📶 **WiFi connectivity** for programming
- 🔄 **Wireless OTA updates**
- 🛰️ **GPS tracking**
- 🔋 **Battery monitoring**

**No more USB cables needed for programming!** 🎉

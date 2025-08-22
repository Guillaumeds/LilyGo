# 🚀 Quick Start Guide - LilyGO T-SIM7000G

## 📋 What You Need
- ✅ LilyGO T-SIM7000G board
- ✅ SIM card with data plan
- ✅ 2x antennas (GPS + Cellular)
- ✅ USB cable
- ✅ VS Code with PlatformIO

## 🔧 Hardware Setup (5 minutes)

### 1. Insert SIM Card
- Power off the board
- Insert SIM card (check orientation)
- Power on

### 2. Connect Antennas
- **GPS antenna** → smaller connector (usually labeled "GPS")
- **Cellular antenna** → larger connector (usually labeled "MAIN" or "LTE")

### 3. Connect USB
- Connect USB cable to computer
- Board should power on (LED may blink)

## 💻 Software Setup (10 minutes)

### 1. Open Project in VS Code
```bash
# Open VS Code
# File → Open Folder → Select your project folder
```

### 2. Install PlatformIO (if needed)
- Extensions → Search "PlatformIO IDE" → Install
- Restart VS Code

### 3. Find Your APN (Automatic)
```bash
# The project is already configured for APN detection
# Just upload and run!
```

## 🎯 Step-by-Step Process

### Step 1: Auto-Detect APN
1. **Upload APN Detector**:
   - PlatformIO → Upload (or Ctrl+Alt+U)
   - Wait for upload to complete

2. **Open Serial Monitor**:
   - PlatformIO → Monitor (or Ctrl+Alt+S)
   - Watch for APN detection results

3. **Expected Output**:
   ```
   📱 IMSI: 310410123456789
   📡 Likely Carrier: AT&T
   💡 Suggested APNs: phone, broadband
   
   ✅ SUCCESS! This APN works!
   📝 Use this configuration:
      APN: phone
   ```

### Step 2: Configure Main Program
1. **Edit config.h**:
   ```cpp
   // Update this line with your working APN
   #define CELLULAR_APN    "phone"  // Use detected APN
   ```

2. **Switch to main program**:
   - Edit `platformio.ini`
   - Change: `default_envs = T-SIM7000G`

### Step 3: Run GPS & Battery Monitor
1. **Upload main program**:
   - PlatformIO → Upload

2. **Monitor output**:
   ```
   === LilyGO T-SIM7000G GPS & Battery Monitor ===
   Connecting to cellular... Connected!
   GPS enabled
   
   === Data Collection Cycle ===
   Battery: 3.85V (70.8%)
   GPS: Lat=40.123456, Lon=-74.123456
   Sending to ThingSpeak... Success!
   ```

3. **Check ThingSpeak**:
   - Visit: https://thingspeak.com/channels/2976042
   - See your GPS and battery data!

## 🚨 Troubleshooting

### Problem: Modem not responding
**Solution**: Run hardware test first
```ini
# Change platformio.ini to:
default_envs = T-SIM7000G-Hardware-Test
```

### Problem: No APN works
**Solutions**:
1. Check SIM card has active data plan
2. Verify antennas are connected
3. Try manual APN from carrier

### Problem: GPS no fix
**Solutions**:
1. Move to location with clear sky view
2. Wait 5+ minutes for initial fix
3. Check GPS antenna connection

### Problem: ThingSpeak upload fails
**Solutions**:
1. Verify cellular internet works
2. Check API key in config.h
3. Ensure 15+ second intervals between uploads

## 📊 Data Fields

Your ThingSpeak channel will show:
- **Field 1**: Battery Percentage (%)
- **Field 2**: GPS Latitude
- **Field 3**: GPS Longitude
- **Field 4**: GPS Altitude (m)
- **Field 5**: Number of Satellites
- **Field 6**: Battery Voltage (V)
- **Field 7**: Signal Strength

## ⏰ Timing

- **Data collection**: Every 2 minutes
- **GPS reading**: Continuous
- **Battery monitoring**: Every 10 seconds
- **ThingSpeak upload**: Every 2 minutes (when GPS has fix)

## 🔋 Power Options

- **USB powered**: Always on, good for testing
- **Battery powered**: Add 18650 battery for portable operation
- **Solar powered**: Connect solar panel for outdoor deployment

## 📱 LED Status

- **Slow blink**: Starting up
- **Fast blink**: Connecting to network/GPS
- **Solid on**: Ready and operating
- **Very fast blink**: Error condition

## 🎉 Success!

When everything works, you'll see:
1. ✅ Cellular connection established
2. ✅ GPS getting satellite fix
3. ✅ Battery voltage reading correctly
4. ✅ Data appearing on ThingSpeak every 2 minutes

**Total setup time: ~15 minutes**

Need help? Check the full README.md for detailed troubleshooting!

/**
 * @file      wifi_config.h
 * @author    WiFi Configuration for LilyGO T-SIM7000G OTA
 * @license   MIT
 * @date      2025-01-21
 * @brief     WiFi credentials and OTA settings
 */

#pragma once

// ========================================
// 📶 WIFI CONFIGURATION
// ========================================

// Replace these with your WiFi network credentials
#define WIFI_SSID           "Guillaume Phone"     // Your WiFi network name
#define WIFI_PASSWORD       "0840866917"   // Your WiFi password

// ========================================
// 🔄 OTA CONFIGURATION
// ========================================

// OTA Settings
#define OTA_HOSTNAME        "lilygo-sim7000g"      // mDNS hostname (device.local)
#define OTA_PASSWORD        "lilygo123"            // OTA upload password
#define OTA_PORT            3232                   // OTA port (default: 3232)

// Firmware version
#define FIRMWARE_VERSION    "1.0.0"               // Current firmware version

// ========================================
// 🌐 NETWORK SETTINGS
// ========================================

// WiFi connection settings
#define WIFI_CONNECT_TIMEOUT    20                 // WiFi connection timeout (seconds)
#define WIFI_RECONNECT_INTERVAL 30                 // WiFi reconnection interval (seconds)

// mDNS settings
#define MDNS_ENABLED        true                   // Enable mDNS discovery
#define MDNS_SERVICE        "_arduino"             // mDNS service type
#define MDNS_PROTOCOL       "_tcp"                 // mDNS protocol

// ========================================
// 🔧 ADVANCED OTA SETTINGS
// ========================================

// OTA update behavior
#define OTA_REBOOT_DELAY    3000                   // Delay before reboot after OTA (ms)
#define OTA_PROGRESS_INTERVAL 1000                 // Progress update interval (ms)

// OTA security
#define OTA_AUTH_REQUIRED   true                   // Require password for OTA
#define OTA_HASH_CHECK      true                   // Verify firmware hash

// ========================================
// 📋 USAGE INSTRUCTIONS
// ========================================

/*
SETUP INSTRUCTIONS:

1. UPDATE WIFI CREDENTIALS:
   - Change WIFI_SSID to your network name
   - Change WIFI_PASSWORD to your network password

2. FIRST UPLOAD (USB):
   pio run -e T-SIM7000G -t upload

3. WIRELESS UPLOADS (OTA):
   pio run -e T-SIM7000G-OTA -t upload

4. FIND DEVICE IP:
   - Check serial monitor for IP address
   - Or use: ping lilygo-sim7000g.local

5. TROUBLESHOOTING:
   - Ensure device and computer are on same WiFi network
   - Check firewall settings (allow port 3232)
   - Verify OTA password matches

PLATFORMIO.INI CONFIGURATION:

[env:T-SIM7000G-OTA]
upload_protocol = espota
upload_port = lilygo-sim7000g.local
upload_flags = --auth=lilygo123

ALTERNATIVE IP-BASED UPLOAD:
upload_port = 192.168.1.100  ; Use actual IP address

COMMAND LINE USAGE:
pio run -e T-SIM7000G-OTA -t upload
*/

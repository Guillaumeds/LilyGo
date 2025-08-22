/**
 * @file      config.h
 * @author    Configuration for LilyGO T-SIM7000G
 * @license   MIT
 * @date      2025-01-21
 * @brief     Configuration settings for ThingSpeak and cellular connection
 */

#pragma once

// ========================================
// 🌐 THINGSPEAK CONFIGURATION
// ========================================

// ThingSpeak Channel Information
#define THINGSPEAK_CHANNEL_ID       2976042
#define THINGSPEAK_WRITE_API_KEY    "RWE803O3NIOLIUQS"
#define THINGSPEAK_READ_API_KEY     "R7AY7KIC6W4M6Y3I"

// ThingSpeak Server
#define THINGSPEAK_SERVER           "api.thingspeak.com"
#define THINGSPEAK_PORT             80

// Field Mapping for GPS & Battery Data
// Note: Your current channel has soil monitoring fields
// We'll repurpose some fields for GPS/battery data:
#define FIELD_BATTERY_PERCENT       1  // Field 1: Battery Percentage (%)
#define FIELD_LATITUDE              2  // Field 2: GPS Latitude
#define FIELD_LONGITUDE             3  // Field 3: GPS Longitude  
#define FIELD_ALTITUDE              4  // Field 4: GPS Altitude (m)
#define FIELD_SATELLITES            5  // Field 5: Number of Satellites
#define FIELD_BATTERY_VOLTAGE       6  // Field 6: Battery Voltage (V)
#define FIELD_SIGNAL_STRENGTH       7  // Field 7: Cellular Signal Strength

// ========================================
// 📱 CELLULAR CONFIGURATION
// ========================================

// APN Settings - Update these for your carrier
// Common APNs:
// - Hologram: "hologram"
// - AT&T: "phone" or "broadband"
// - Verizon: "vzwinternet"
// - T-Mobile: "fast.t-mobile.com"
// - Vodafone: "internet"
#define CELLULAR_APN                "hologram"
#define CELLULAR_USER               ""
#define CELLULAR_PASS               ""

// ========================================
// ⏰ TIMING CONFIGURATION
// ========================================

// Data collection and transmission intervals
#define DATA_SEND_INTERVAL_MS       120000    // 2 minutes (120,000 ms)
#define GPS_READ_INTERVAL_MS        1000      // Read GPS every 1 second
#define BATTERY_READ_INTERVAL_MS    10000     // Read battery every 10 seconds

// Timeout settings
#define NETWORK_CONNECT_TIMEOUT_MS  60000     // 1 minute
#define THINGSPEAK_TIMEOUT_MS       10000     // 10 seconds
#define GPS_FIX_TIMEOUT_MS          300000    // 5 minutes

// ========================================
// 🔋 BATTERY CONFIGURATION
// ========================================

// Battery voltage calculation
#define BATTERY_VOLTAGE_DIVIDER     2.0       // Voltage divider ratio
#define BATTERY_ADC_REFERENCE       3.3       // ESP32 ADC reference voltage
#define BATTERY_ADC_RESOLUTION      4095.0    // 12-bit ADC resolution

// Li-ion battery voltage levels
#define BATTERY_VOLTAGE_MAX         4.2       // 100% charge
#define BATTERY_VOLTAGE_MIN         3.0       // 0% charge

// ========================================
// 🛰️ GPS CONFIGURATION
// ========================================

// GPS accuracy requirements
#define GPS_MIN_SATELLITES          4         // Minimum satellites for valid fix
#define GPS_MAX_AGE_MS              5000      // Maximum age of GPS data (5 seconds)

// GPS coordinate precision
#define GPS_COORDINATE_PRECISION    6         // Decimal places for lat/lon

// ========================================
// 🚨 DEBUG CONFIGURATION
// ========================================

// Debug output settings
#define DEBUG_SERIAL                true      // Enable serial debug output
#define DEBUG_GPS                   true      // Enable GPS debug info
#define DEBUG_CELLULAR              true      // Enable cellular debug info
#define DEBUG_THINGSPEAK            true      // Enable ThingSpeak debug info
#define DEBUG_BATTERY               true      // Enable battery debug info

// Serial baud rate
#define DEBUG_BAUD_RATE             115200

// ========================================
// 💡 LED INDICATOR CONFIGURATION
// ========================================

// LED status patterns
#define LED_PATTERN_STARTUP         500       // Slow blink during startup
#define LED_PATTERN_GPS_SEARCH      200       // Fast blink when searching for GPS
#define LED_PATTERN_CELLULAR_CONNECT 100      // Very fast blink when connecting
#define LED_PATTERN_READY           0         // Solid on when ready
#define LED_PATTERN_ERROR           50        // Very fast blink for errors

// ========================================
// 🔧 ADVANCED SETTINGS
// ========================================

// Retry settings
#define MAX_CELLULAR_RETRIES        3         // Max retries for cellular connection
#define MAX_THINGSPEAK_RETRIES      3         // Max retries for ThingSpeak upload
#define RETRY_DELAY_MS              5000      // Delay between retries

// Power management
#define ENABLE_DEEP_SLEEP           false     // Enable deep sleep between readings
#define DEEP_SLEEP_DURATION_MS      60000     // Deep sleep duration (1 minute)

// Data validation
#define VALIDATE_GPS_COORDINATES    true      // Validate GPS coordinates before sending
#define MIN_LATITUDE                -90.0     // Valid latitude range
#define MAX_LATITUDE                90.0
#define MIN_LONGITUDE               -180.0    // Valid longitude range  
#define MAX_LONGITUDE               180.0

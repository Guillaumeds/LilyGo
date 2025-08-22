/**
 * @file      main.cpp
 * @author    LilyGO T-SIM7000G GPS & Battery Monitor (Based on LilyGO Examples)
 * @license   MIT
 * @date      2025-01-21
 * @brief     Reads GPS location and battery percentage every 2 minutes
 *            and sends data to ThingSpeak via cellular connection
 *            Based on original LilyGO examples: HttpsBuiltlnGet, GPS_BuiltIn, ReadBattery
 */

#define TINY_GSM_RX_BUFFER          1024 // Set RX buffer to 1Kb

// See all AT commands, if wanted
// #define DUMP_AT_COMMANDS

#include "utilities.h"
#include "wifi_config.h"
#include <TinyGsmClient.h>
#include <Update.h>
#include <WiFi.h>
#include <ArduinoOTA.h>
#include <ESPmDNS.h>

#ifdef DUMP_AT_COMMANDS  // if enabled it requires the streamDebugger lib
#include <StreamDebugger.h>
StreamDebugger debugger(SerialAT, Serial);
TinyGsm modem(debugger);
#else
TinyGsm modem(SerialAT);
#endif

// ThingSpeak Configuration
const char* thingspeakServer = "api.thingspeak.com";
const char* writeAPIKey = "RWE803O3NIOLIUQS";  // Your write API key
const int channelID = 2976042;                  // Your channel ID

// WiFi Configuration for OTA (from wifi_config.h)
const char* wifi_ssid = WIFI_SSID;
const char* wifi_password = WIFI_PASSWORD;

// OTA Configuration (from wifi_config.h)
const char* ota_hostname = OTA_HOSTNAME;
const char* ota_password = OTA_PASSWORD;
const char* currentVersion = FIRMWARE_VERSION;

// APN Configuration - Leave empty for automatic detection
// If automatic detection fails, uncomment and set your carrier's APN:
// #define NETWORK_APN     "hologram"           // Hologram IoT
// #define NETWORK_APN     "phone"              // AT&T
// #define NETWORK_APN     "vzwinternet"        // Verizon
// #define NETWORK_APN     "fast.t-mobile.com"  // T-Mobile

// Global objects
TinyGsmClient client(modem);

// Timing variables
unsigned long lastSendTime = 0;
const unsigned long sendInterval = 120000; // 2 minutes in milliseconds

// Data variables
float batteryVoltage = 0.0;
float batteryPercentage = 0.0;
float lat = 0.0;
float lon = 0.0;
float speed = 0.0;
float alt = 0.0;
int vsat = 0;
int usat = 0;
float accuracy = 0.0;
uint8_t fixMode = 0;

// Function declarations
void initializeCellular();
void enableGPS();
void readBatteryData();
void readGPSData();
void printCurrentData();
void sendToThingSpeak();
void setupWiFiOTA();
void handleOTA();

void setup() {
    Serial.begin(115200); // Set console baud rate
    delay(2000); // Give time for serial monitor to connect

    Serial.println("=== LilyGO T-SIM7000G GPS & Battery Monitor ===");
    Serial.println("Based on original LilyGO examples");
    Serial.println("Starting detailed debugging...");
    Serial.println();

    Serial.println("📶 Step 1: Setup WiFi OTA (Priority)");
    setupWiFiOTA();

    Serial.println();
    Serial.println("🔧 Step 2: Initialize Serial Communication");
    Serial.printf("   - Main Serial: 115200 baud ✓\n");
    SerialAT.begin(115200, SERIAL_8N1, MODEM_RX_PIN, MODEM_TX_PIN);
    Serial.printf("   - Modem Serial: RX=%d, TX=%d, 115200 baud ✓\n", MODEM_RX_PIN, MODEM_TX_PIN);

    Serial.println();
    Serial.println("🔌 Step 3: Configure Power Control");
#ifdef BOARD_POWERON_PIN
    Serial.printf("   - Setting BOARD_POWERON_PIN (%d) to HIGH\n", BOARD_POWERON_PIN);
    pinMode(BOARD_POWERON_PIN, OUTPUT);
    digitalWrite(BOARD_POWERON_PIN, HIGH);
    Serial.println("   - Board power control enabled ✓");
#else
    Serial.println("   - No BOARD_POWERON_PIN defined for this board");
#endif

    Serial.println();
    Serial.println("🔄 Step 4: Reset Modem (if available)");
#ifdef MODEM_RESET_PIN
    Serial.printf("   - Resetting modem via pin %d\n", MODEM_RESET_PIN);
    pinMode(MODEM_RESET_PIN, OUTPUT);
    digitalWrite(MODEM_RESET_PIN, !MODEM_RESET_LEVEL); delay(100);
    digitalWrite(MODEM_RESET_PIN, MODEM_RESET_LEVEL); delay(2600);
    digitalWrite(MODEM_RESET_PIN, !MODEM_RESET_LEVEL);
    Serial.println("   - Modem reset sequence completed ✓");
#else
    Serial.println("   - No MODEM_RESET_PIN defined for this board");
#endif

    Serial.println();
    Serial.println("✈️ Step 5: Configure Flight Mode (if available)");
#ifdef MODEM_FLIGHT_PIN
    Serial.printf("   - Disabling airplane mode via pin %d\n", MODEM_FLIGHT_PIN);
    pinMode(MODEM_FLIGHT_PIN, OUTPUT);
    digitalWrite(MODEM_FLIGHT_PIN, HIGH);
    Serial.println("   - Airplane mode disabled ✓");
#else
    Serial.println("   - No MODEM_FLIGHT_PIN defined for this board");
#endif

    Serial.println();
    Serial.println("💤 Step 6: Configure DTR (Wake up modem)");
    Serial.printf("   - Setting DTR pin (%d) to LOW to wake modem\n", MODEM_DTR_PIN);
    pinMode(MODEM_DTR_PIN, OUTPUT);
    digitalWrite(MODEM_DTR_PIN, LOW);
    Serial.println("   - DTR configured ✓");

    Serial.println();
    Serial.println("🔋 Step 7: Power On Modem");
    Serial.printf("   - Using PWRKEY pin (%d)\n", BOARD_PWRKEY_PIN);
    Serial.printf("   - Power pulse width: %d ms\n", MODEM_POWERON_PULSE_WIDTH_MS);
    pinMode(BOARD_PWRKEY_PIN, OUTPUT);
    digitalWrite(BOARD_PWRKEY_PIN, LOW);
    delay(100);
    Serial.println("   - Sending power-on pulse...");
    digitalWrite(BOARD_PWRKEY_PIN, HIGH);
    delay(MODEM_POWERON_PULSE_WIDTH_MS);
    digitalWrite(BOARD_PWRKEY_PIN, LOW);
    Serial.println("   - Power-on sequence completed ✓");

    Serial.println();
    Serial.println("📞 Step 8: Test Modem Communication");
    Serial.println("   - Sending AT commands to test modem response...");

    int retry = 0;
    while (!modem.testAT(1000)) {
        Serial.printf("   - Attempt %d: No response from modem\n", retry + 1);
        if (retry++ > 30) {
            Serial.println("   - Modem not responding, trying power cycle...");
            digitalWrite(BOARD_PWRKEY_PIN, LOW);
            delay(100);
            digitalWrite(BOARD_PWRKEY_PIN, HIGH);
            delay(MODEM_POWERON_PULSE_WIDTH_MS);
            digitalWrite(BOARD_PWRKEY_PIN, LOW);
            Serial.println("   - Power cycle completed, retrying...");
            retry = 0;
        }
        delay(1000);
    }
    Serial.println("   - Modem responding to AT commands ✓");

    Serial.println();
    Serial.println("📱 Step 9: Check SIM Card Status");
    SimStatus sim = SIM_ERROR;
    int simRetry = 0;
    while (sim != SIM_READY) {
        sim = modem.getSimStatus();
        switch (sim) {
        case SIM_READY:
            Serial.println("   - SIM card online and ready ✓");
            break;
        case SIM_LOCKED:
            Serial.println("   - ⚠️ SIM card is locked. Please unlock the SIM card first.");
            Serial.println("   - You may need to enter PIN code");
            break;
        case SIM_ANTITHEFT_LOCKED:
            Serial.println("   - ⚠️ SIM card anti-theft is active");
            break;
        case SIM_ERROR:
            Serial.printf("   - ❌ SIM card error (attempt %d)\n", ++simRetry);
            if (simRetry > 10) {
                Serial.println("   - ❌ SIM card not detected after 10 attempts");
                Serial.println("   - Please check SIM card insertion");
            }
            break;
        default:
            Serial.printf("   - SIM status: %d (checking...)\n", sim);
            break;
        }
        if (sim != SIM_READY) delay(1000);
    }

    Serial.println();
    Serial.println("🌐 Step 10: Initialize Cellular Connection");
    initializeCellular();

    Serial.println();
    Serial.println("🛰️ Step 11: Enable GPS");
    enableGPS();

    Serial.println();
    Serial.println("🎉 Setup Complete!");
    Serial.println("� WiFi OTA ready for wireless programming");
    Serial.println("�📊 Starting data collection every 2 minutes...");
    Serial.println("📡 Waiting for GPS fix and then sending to ThingSpeak");
    Serial.println("============================================================");
}

void loop() {
    // Handle OTA updates
    handleOTA();

    // Check if it's time to send data
    if (millis() - lastSendTime >= sendInterval) {
        Serial.println("\n=== Data Collection Cycle ===");

        // Read battery voltage
        readBatteryData();

        // Read GPS data
        readGPSData();

        // Print current data
        printCurrentData();

        // Send data to ThingSpeak if GPS has valid fix
        if (fixMode > 0 && lat != 0.0 && lon != 0.0) {
            sendToThingSpeak();
        } else {
            Serial.println("Waiting for GPS fix...");
        }

        lastSendTime = millis();
    }

    delay(1000); // Check every second
}

void initializeCellular() {
    Serial.println("   🔧 Configuring network mode...");
#ifdef TINY_GSM_MODEM_HAS_NETWORK_MODE
    if (!modem.setNetworkMode(MODEM_NETWORK_AUTO)) {
        Serial.println("   ❌ Set network mode failed!");
    } else {
        Serial.println("   ✓ Network mode set to AUTO");
    }
    String mode = modem.getNetworkModeString();
    Serial.printf("   📡 Current network mode: %s\n", mode.c_str());
#else
    Serial.println("   ℹ️ Network mode configuration not available");
#endif

    Serial.println("   🔧 Configuring preferred mode...");
#ifdef TINY_GSM_MODEM_HAS_PREFERRED_MODE
    if (!modem.setPreferredMode(MODEM_PREFERRED_CATM_NBIOT)) {
        Serial.println("   ❌ Set network preferred mode failed!");
    } else {
        Serial.println("   ✓ Preferred mode set to CAT-M/NB-IoT");
    }
    String prefMode = modem.getPreferredModeString();
    Serial.printf("   📡 Current preferred mode: %s\n", prefMode.c_str());
#else
    Serial.println("   ℹ️ Preferred mode configuration not available");
#endif

    Serial.println("   🔧 Configuring APN...");
#ifdef NETWORK_APN
    Serial.printf("   📡 Setting manual APN: %s\n", NETWORK_APN);
    if (!modem.setNetworkAPN(NETWORK_APN)) {
        Serial.println("   ❌ Set network APN error!");
    } else {
        Serial.println("   ✓ Manual APN configured");
    }
#else
    Serial.println("   🤖 Using automatic APN detection");
    Serial.println("   📡 Modem will negotiate APN with carrier");
#endif

    // Check network registration status and network signal status
    int16_t sq;
    Serial.print("Wait for the modem to register with the network.");
    RegStatus status = REG_NO_RESULT;
    while (status == REG_NO_RESULT || status == REG_SEARCHING || status == REG_UNREGISTERED) {
        status = modem.getRegistrationStatus();
        switch (status) {
        case REG_UNREGISTERED:
        case REG_SEARCHING:
            sq = modem.getSignalQuality();
            Serial.printf("[%lu] Signal Quality:%d\n", millis() / 1000, sq);
            delay(1000);
            break;
        case REG_DENIED:
            Serial.println("Network registration was rejected, please check if the APN is correct");
            return;
        case REG_OK_HOME:
            Serial.println("Online registration successful");
            break;
        case REG_OK_ROAMING:
            Serial.println("Network registration successful, currently in roaming mode");
            break;
        default:
            Serial.printf("Registration Status:%d\n", status);
            delay(1000);
            break;
        }
    }
    Serial.println();

#ifdef MODEM_REG_SMS_ONLY
    while (status == REG_SMS_ONLY) {
        Serial.println("Registered for \"SMS only\", home network (applicable only when E-UTRAN), this type of registration cannot access the network. Please check the APN settings and ask the operator for the correct APN information and the balance and package of the SIM card. If you still cannot connect, please replace the SIM card and test again.");
        delay(5000);
    }
#endif

    Serial.printf("Registration Status:%d\n", status);
    delay(1000);

    String ueInfo;
    if (modem.getSystemInformation(ueInfo)) {
        Serial.print("Inquiring UE system information:");
        Serial.println(ueInfo);
    }

    if (!modem.setNetworkActive()) {
        Serial.println("Enable network failed!");
    }

    delay(5000);

    String ipAddress = modem.getLocalIP();
    Serial.print("Network IP:"); Serial.println(ipAddress);

    // Print modem software version
    String res;
    modem.sendAT("+SIMCOMATI");
    modem.waitResponse(10000UL, res);
    Serial.println(res);
}

void enableGPS() {
    Serial.println("Enabling GPS/GNSS/GLONASS");
    while (!modem.enableGPS(MODEM_GPS_ENABLE_GPIO, MODEM_GPS_ENABLE_LEVEL)) {
        Serial.print(".");
    }
    Serial.println();
    Serial.println("GPS Enabled");

    // Set GPS Baud to 115200
    modem.setGPSBaud(115200);
}

void readGPSData() {
    Serial.println("Requesting current GPS/GNSS/GLONASS location");

    // Reset GPS variables
    int year, month, day, hour, min, sec;

    if (modem.getGPS(&fixMode, &lat, &lon, &speed, &alt, &vsat, &usat, &accuracy,
                     &year, &month, &day, &hour, &min, &sec)) {
        Serial.println("GPS data received successfully");
    } else {
        Serial.println("Couldn't get GPS/GNSS/GLONASS location");
        fixMode = 0; // No fix
    }
}

void readBatteryData() {
#ifdef BOARD_BAT_ADC_PIN
    // Read battery voltage from ADC (based on ReadBattery example)
    uint32_t battery_voltage_mv = analogReadMilliVolts(BOARD_BAT_ADC_PIN);
    battery_voltage_mv *= 2;   // The hardware voltage divider resistor is half of the actual voltage

    batteryVoltage = battery_voltage_mv / 1000.0; // Convert to volts

    // Convert voltage to percentage (for Li-ion battery)
    // 4.2V = 100%, 3.0V = 0%
    batteryPercentage = ((batteryVoltage - 3.0) / (4.2 - 3.0)) * 100.0;
    if (batteryPercentage > 100.0) batteryPercentage = 100.0;
    if (batteryPercentage < 0.0) batteryPercentage = 0.0;
#else
    Serial.println("Battery ADC not available on this board");
    batteryVoltage = 0.0;
    batteryPercentage = 0.0;
#endif
}

void printCurrentData() {
    Serial.println("--- Current Data ---");
    Serial.printf("Battery: %.2fV (%.1f%%)\n", batteryVoltage, batteryPercentage);

    if (fixMode > 0) {
        Serial.printf("FixMode: %d\n", fixMode);
        Serial.printf("Latitude: %.6f\tLongitude: %.6f\n", lat, lon);
        Serial.printf("Speed: %.2f\tAltitude: %.1f\n", speed, alt);
        Serial.printf("Visible Satellites: %d\tUsed Satellites: %d\n", vsat, usat);
        Serial.printf("Accuracy: %.2f\n", accuracy);
    } else {
        Serial.println("GPS: No fix available");
    }
}

void sendToThingSpeak() {
    Serial.println("Sending data to ThingSpeak...");

    // Initialize HTTPS (based on HttpsBuiltlnGet example)
    modem.https_begin();

    // Prepare ThingSpeak URL
    String url = "https://";
    url += thingspeakServer;
    url += "/update?api_key=";
    url += writeAPIKey;
    url += "&field1=" + String(batteryPercentage, 1);  // Battery percentage
    url += "&field2=" + String(lat, 6);                // Latitude
    url += "&field3=" + String(lon, 6);                // Longitude
    url += "&field4=" + String(alt, 1);                // Altitude
    url += "&field5=" + String(vsat);                  // Visible satellites
    url += "&field6=" + String(batteryVoltage, 2);     // Battery voltage

    Serial.print("Request URL: ");
    Serial.println(url);

    // Set GET URL
    if (!modem.https_set_url(url.c_str())) {
        Serial.println("Failed to set ThingSpeak URL");
        modem.https_end();
        return;
    }

    // Send GET request
    int httpCode = modem.https_get();
    if (httpCode != 200) {
        Serial.print("HTTP get failed! Error code = ");
        Serial.println(httpCode);
        modem.https_end();
        return;
    }

    // Get response
    String response = modem.https_body();
    Serial.print("ThingSpeak Response: ");
    Serial.println(response);

    // Disconnect
    modem.https_end();

    Serial.println("Data sent to ThingSpeak successfully!");
}

void setupWiFiOTA() {
    Serial.println("   � Connecting to WiFi for OTA...");

    // Connect to WiFi
    WiFi.mode(WIFI_STA);
    WiFi.begin(wifi_ssid, wifi_password);

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < 20) {
        delay(500);
        Serial.print(".");
        attempts++;
    }

    if (WiFi.status() == WL_CONNECTED) {
        Serial.println();
        Serial.printf("   ✅ WiFi connected! IP: %s\n", WiFi.localIP().toString().c_str());

        // Start mDNS
        if (MDNS.begin(ota_hostname)) {
            Serial.printf("   ✅ mDNS started: %s.local\n", ota_hostname);
        } else {
            Serial.println("   ⚠️ mDNS failed to start");
        }

        // Configure ArduinoOTA
        ArduinoOTA.setHostname(ota_hostname);
        ArduinoOTA.setPassword(ota_password);

        ArduinoOTA.onStart([]() {
            String type;
            if (ArduinoOTA.getCommand() == U_FLASH) {
                type = "sketch";
            } else { // U_SPIFFS
                type = "filesystem";
            }
            Serial.println("🔄 OTA Update starting: " + type);
        });

        ArduinoOTA.onEnd([]() {
            Serial.println("\n✅ OTA Update completed!");
        });

        ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
            static unsigned long lastPrint = 0;
            if (millis() - lastPrint > 1000) { // Print every second
                Serial.printf("📥 OTA Progress: %u%% (%u/%u)\n",
                             (progress / (total / 100)), progress, total);
                lastPrint = millis();
            }
        });

        ArduinoOTA.onError([](ota_error_t error) {
            Serial.printf("❌ OTA Error[%u]: ", error);
            if (error == OTA_AUTH_ERROR) {
                Serial.println("Auth Failed");
            } else if (error == OTA_BEGIN_ERROR) {
                Serial.println("Begin Failed");
            } else if (error == OTA_CONNECT_ERROR) {
                Serial.println("Connect Failed");
            } else if (error == OTA_RECEIVE_ERROR) {
                Serial.println("Receive Failed");
            } else if (error == OTA_END_ERROR) {
                Serial.println("End Failed");
            }
        });

        ArduinoOTA.begin();
        Serial.println("   ✅ WiFi OTA ready for wireless programming!");
        Serial.printf("   📡 Use: pio run -e T-SIM7000G-OTA -t upload\n");
        Serial.printf("   � Password: %s\n", ota_password);

    } else {
        Serial.println();
        Serial.println("   ❌ WiFi connection failed - OTA not available");
        Serial.println("   ℹ️ Check WiFi credentials in code");
    }
}

void handleOTA() {
    // Handle ArduinoOTA
    ArduinoOTA.handle();

    // Keep WiFi alive
    if (WiFi.status() != WL_CONNECTED) {
        static unsigned long lastReconnect = 0;
        if (millis() - lastReconnect > 30000) { // Try reconnect every 30 seconds
            Serial.println("📶 WiFi disconnected, attempting reconnect...");
            WiFi.reconnect();
            lastReconnect = millis();
        }
    }
}

#ifndef TINY_GSM_FORK_LIBRARY
#error "No correct definition detected, Please copy all the [lib directories](https://github.com/Xinyuan-LilyGO/LilyGO-T-A76XX/tree/main/lib) to the arduino libraries directory , See README"
#endif

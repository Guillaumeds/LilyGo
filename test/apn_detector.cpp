/**
 * @file      apn_detector.cpp
 * @author    APN Auto-Detection for LilyGO T-SIM7000G
 * @license   MIT
 * @date      2025-01-21
 * @brief     Automatically detect APN settings and test common APNs
 */

#include <Arduino.h>
#include "../include/utilities.h"

#define TINY_GSM_MODEM_SIM7000SSL
#include <TinyGsmClient.h>

TinyGsm modem(SerialAT);

// Common APN database
struct APNConfig {
    const char* carrier;
    const char* country;
    const char* apn;
    const char* user;
    const char* pass;
};

// Comprehensive APN database
APNConfig commonAPNs[] = {
    // Global/Multi-carrier
    {"Hologram", "Global", "hologram", "", ""},
    {"1NCE", "Global", "iot.1nce.net", "", ""},
    
    // United States
    {"AT&T", "USA", "phone", "", ""},
    {"AT&T", "USA", "broadband", "", ""},
    {"AT&T", "USA", "m2m.com.attz", "", ""},
    {"Verizon", "USA", "vzwinternet", "", ""},
    {"Verizon", "USA", "verizon", "", ""},
    {"T-Mobile", "USA", "fast.t-mobile.com", "", ""},
    {"T-Mobile", "USA", "epc.tmobile.com", "", ""},
    {"Sprint", "USA", "cinet.spcs", "", ""},
    
    // Canada
    {"Rogers", "Canada", "internet.com", "", ""},
    {"Bell", "Canada", "inet.bell.ca", "", ""},
    {"Telus", "Canada", "sp.telus.com", "", ""},
    
    // United Kingdom
    {"Vodafone", "UK", "internet", "", ""},
    {"Vodafone", "UK", "pp.vodafone.co.uk", "", ""},
    {"EE", "UK", "everywhere", "", ""},
    {"O2", "UK", "mobile.o2.co.uk", "", ""},
    {"Three", "UK", "3internet", "", ""},
    
    // Germany
    {"Vodafone", "Germany", "web.vodafone.de", "", ""},
    {"T-Mobile", "Germany", "internet.t-mobile", "", ""},
    {"O2", "Germany", "internet", "", ""},
    
    // France
    {"Orange", "France", "orange", "", ""},
    {"SFR", "France", "websfr", "", ""},
    {"Bouygues", "France", "mmsbouygtel.com", "", ""},
    
    // Australia
    {"Telstra", "Australia", "telstra.internet", "", ""},
    {"Optus", "Australia", "internet", "", ""},
    {"Vodafone", "Australia", "vfinternet.au", "", ""},
    
    // IoT/M2M specific
    {"Twilio", "Global", "super", "", ""},
    {"Soracom", "Global", "soracom.io", "", ""},
    {"Particle", "Global", "particle", "", ""},
};

const int numAPNs = sizeof(commonAPNs) / sizeof(commonAPNs[0]);

void setup() {
    Serial.begin(115200);
    delay(2000);
    
    Serial.println("=== LilyGO T-SIM7000G APN Auto-Detection ===");
    Serial.println();
    
    // Initialize LED
    pinMode(BOARD_LED_PIN, OUTPUT);
    digitalWrite(BOARD_LED_PIN, LED_ON);
    
    // Initialize modem
    SerialAT.begin(MODEM_BAUDRATE, SERIAL_8N1, MODEM_RX_PIN, MODEM_TX_PIN);
    
    // Power on modem
    powerOnModem();
    
    // Initialize modem communication
    if (!initializeModem()) {
        Serial.println("❌ Failed to initialize modem!");
        while (true) {
            digitalWrite(BOARD_LED_PIN, LED_ON);
            delay(200);
            digitalWrite(BOARD_LED_PIN, !LED_ON);
            delay(200);
        }
    }
    
    // Get SIM card information
    getSIMInfo();
    
    // Try to detect APN automatically
    detectAPN();
    
    // Test common APNs
    testCommonAPNs();
    
    Serial.println("\n=== APN Detection Complete ===");
    Serial.println("Use the working APN in your main program!");
    digitalWrite(BOARD_LED_PIN, LED_ON);
}

void loop() {
    // Keep LED on to indicate completion
    delay(1000);
}

void powerOnModem() {
    Serial.println("🔌 Powering on modem...");
    
    pinMode(BOARD_PWRKEY_PIN, OUTPUT);
    digitalWrite(BOARD_PWRKEY_PIN, LOW);
    delay(100);
    digitalWrite(BOARD_PWRKEY_PIN, HIGH);
    delay(MODEM_POWERON_PULSE_WIDTH_MS);
    digitalWrite(BOARD_PWRKEY_PIN, LOW);
    
    delay(MODEM_START_WAIT_MS);
    Serial.println("✅ Modem powered on");
}

bool initializeModem() {
    Serial.println("🔧 Initializing modem...");
    
    // Test modem communication
    for (int i = 0; i < 10; i++) {
        if (modem.testAT()) {
            Serial.println("✅ Modem responding to AT commands");
            break;
        }
        delay(1000);
        if (i == 9) return false;
    }
    
    // Get modem information
    String modemInfo = modem.getModemInfo();
    Serial.println("📱 Modem Info: " + modemInfo);
    
    return true;
}

void getSIMInfo() {
    Serial.println("\n📋 Getting SIM Card Information...");
    
    // Check SIM card status
    modem.sendAT("+CPIN?");
    String response = "";
    if (modem.waitResponse(5000, response)) {
        Serial.println("SIM Status: " + response);
    }
    
    // Get IMSI (International Mobile Subscriber Identity)
    String imsi = modem.getIMSI();
    if (imsi.length() > 0) {
        Serial.println("📱 IMSI: " + imsi);
        
        // Extract MCC (Mobile Country Code) and MNC (Mobile Network Code)
        if (imsi.length() >= 5) {
            String mcc = imsi.substring(0, 3);
            String mnc = imsi.substring(3, 5);
            Serial.println("🌍 MCC (Country): " + mcc);
            Serial.println("📡 MNC (Network): " + mnc);
            
            // Try to identify carrier from MCC/MNC
            identifyCarrier(mcc, mnc);
        }
    }
    
    // Get ICCID (SIM card serial number)
    modem.sendAT("+CCID");
    if (modem.waitResponse(5000, response)) {
        Serial.println("🆔 ICCID: " + response);
    }
    
    // Get network operator
    modem.sendAT("+COPS?");
    if (modem.waitResponse(5000, response)) {
        Serial.println("🏢 Network Operator: " + response);
    }
}

void identifyCarrier(String mcc, String mnc) {
    Serial.println("\n🔍 Identifying Carrier from MCC/MNC...");
    
    // Common MCC/MNC combinations
    String mccmnc = mcc + mnc;
    
    if (mcc == "310" || mcc == "311" || mcc == "312" || mcc == "313" || mcc == "314" || mcc == "315" || mcc == "316") {
        Serial.println("🇺🇸 Country: United States");
        if (mnc == "410" || mnc == "411" || mnc == "560" || mnc == "680") {
            Serial.println("📡 Likely Carrier: AT&T");
            Serial.println("💡 Suggested APNs: phone, broadband, m2m.com.attz");
        } else if (mnc == "004" || mnc == "012" || mnc == "013") {
            Serial.println("📡 Likely Carrier: Verizon");
            Serial.println("💡 Suggested APNs: vzwinternet, verizon");
        } else if (mnc == "260" || mnc == "026" || mnc == "160" || mnc == "200" || mnc == "210" || mnc == "220" || mnc == "230" || mnc == "240" || mnc == "250" || mnc == "270" || mnc == "310" || mnc == "660" || mnc == "800") {
            Serial.println("📡 Likely Carrier: T-Mobile");
            Serial.println("💡 Suggested APNs: fast.t-mobile.com, epc.tmobile.com");
        }
    } else if (mcc == "302") {
        Serial.println("🇨🇦 Country: Canada");
        if (mnc == "720") {
            Serial.println("📡 Likely Carrier: Rogers");
            Serial.println("💡 Suggested APN: internet.com");
        } else if (mnc == "610") {
            Serial.println("📡 Likely Carrier: Bell");
            Serial.println("💡 Suggested APN: inet.bell.ca");
        }
    } else if (mcc == "234") {
        Serial.println("🇬🇧 Country: United Kingdom");
        if (mnc == "15") {
            Serial.println("📡 Likely Carrier: Vodafone");
            Serial.println("💡 Suggested APNs: internet, pp.vodafone.co.uk");
        } else if (mnc == "30" || mnc == "31" || mnc == "32" || mnc == "33" || mnc == "34") {
            Serial.println("📡 Likely Carrier: EE");
            Serial.println("💡 Suggested APN: everywhere");
        }
    } else if (mcc == "262") {
        Serial.println("🇩🇪 Country: Germany");
        if (mnc == "02") {
            Serial.println("📡 Likely Carrier: Vodafone");
            Serial.println("💡 Suggested APN: web.vodafone.de");
        } else if (mnc == "01") {
            Serial.println("📡 Likely Carrier: T-Mobile");
            Serial.println("💡 Suggested APN: internet.t-mobile");
        }
    }
}

void detectAPN() {
    Serial.println("\n🔍 Attempting Automatic APN Detection...");
    
    // Wait for network registration
    Serial.print("📡 Waiting for network registration...");
    if (modem.waitForNetwork(60000)) {
        Serial.println(" ✅ Registered!");
        
        // Try to get APN from network
        modem.sendAT("+CGDCONT?");
        String response = "";
        if (modem.waitResponse(5000, response)) {
            Serial.println("📋 Current PDP Context: " + response);
            
            // Parse APN from response
            int apnStart = response.indexOf("\"", response.indexOf("IP"));
            if (apnStart > 0) {
                apnStart++;
                int apnEnd = response.indexOf("\"", apnStart);
                if (apnEnd > apnStart) {
                    String detectedAPN = response.substring(apnStart, apnEnd);
                    Serial.println("🎯 Detected APN: " + detectedAPN);
                    
                    // Test the detected APN
                    if (testAPN(detectedAPN.c_str(), "", "")) {
                        Serial.println("✅ Detected APN works!");
                        return;
                    }
                }
            }
        }
    } else {
        Serial.println(" ❌ Failed!");
    }
}

void testCommonAPNs() {
    Serial.println("\n🧪 Testing Common APNs...");
    
    int successCount = 0;
    
    for (int i = 0; i < numAPNs; i++) {
        Serial.printf("\n[%d/%d] Testing: %s (%s) - %s\n", 
                     i + 1, numAPNs, 
                     commonAPNs[i].carrier, 
                     commonAPNs[i].country, 
                     commonAPNs[i].apn);
        
        if (testAPN(commonAPNs[i].apn, commonAPNs[i].user, commonAPNs[i].pass)) {
            Serial.println("✅ SUCCESS! This APN works!");
            successCount++;
            
            // Print configuration for user
            Serial.println("📝 Use this configuration:");
            Serial.println("   Carrier: " + String(commonAPNs[i].carrier));
            Serial.println("   APN: " + String(commonAPNs[i].apn));
            Serial.println("   User: " + String(commonAPNs[i].user));
            Serial.println("   Pass: " + String(commonAPNs[i].pass));
            Serial.println();
        } else {
            Serial.println("❌ Failed");
        }
        
        // Disconnect for next test
        modem.gprsDisconnect();
        delay(2000);
    }
    
    Serial.printf("\n📊 Summary: %d working APNs found out of %d tested\n", successCount, numAPNs);
}

bool testAPN(const char* apn, const char* user, const char* pass) {
    Serial.print("   Connecting...");
    
    // Try to connect with this APN
    if (modem.gprsConnect(apn, user, pass)) {
        Serial.print(" Connected! ");
        
        // Test internet connectivity
        if (modem.isGprsConnected()) {
            IPAddress local = modem.localIP();
            if (local != IPAddress(0, 0, 0, 0)) {
                Serial.print("IP: " + local.toString());
                return true;
            }
        }
    }
    
    return false;
}

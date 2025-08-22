/**
 * @file      hardware_test.cpp
 * @author    Hardware Test for LilyGO T-SIM7000G
 * @license   MIT
 * @date      2025-01-21
 * @brief     Simple hardware test to verify board functionality
 */

#include <Arduino.h>
#include "../include/utilities.h"

void setup() {
    Serial.begin(115200);
    delay(2000);
    
    Serial.println("=== LilyGO T-SIM7000G Hardware Test ===");
    Serial.println();
    
    // Test LED
    Serial.println("Testing LED...");
    pinMode(BOARD_LED_PIN, OUTPUT);
    for (int i = 0; i < 5; i++) {
        digitalWrite(BOARD_LED_PIN, LED_ON);
        delay(200);
        digitalWrite(BOARD_LED_PIN, !LED_ON);
        delay(200);
    }
    Serial.println("LED test complete");
    
    // Test battery ADC
    Serial.println("Testing battery ADC...");
    int batteryADC = analogRead(BOARD_BAT_ADC_PIN);
    float batteryVoltage = (batteryADC * 3.3 * 2.0) / 4095.0;
    Serial.printf("Battery ADC: %d\n", batteryADC);
    Serial.printf("Battery Voltage: %.2fV\n", batteryVoltage);
    
    // Test solar ADC
    Serial.println("Testing solar ADC...");
    int solarADC = analogRead(BOARD_SOLAR_ADC_PIN);
    float solarVoltage = (solarADC * 3.3 * 2.0) / 4095.0;
    Serial.printf("Solar ADC: %d\n", solarADC);
    Serial.printf("Solar Voltage: %.2fV\n", solarVoltage);
    
    // Test modem serial
    Serial.println("Testing modem serial...");
    SerialAT.begin(MODEM_BAUDRATE, SERIAL_8N1, MODEM_RX_PIN, MODEM_TX_PIN);
    
    // Power on modem
    Serial.println("Powering on modem...");
    pinMode(BOARD_PWRKEY_PIN, OUTPUT);
    digitalWrite(BOARD_PWRKEY_PIN, LOW);
    delay(100);
    digitalWrite(BOARD_PWRKEY_PIN, HIGH);
    delay(1000);
    digitalWrite(BOARD_PWRKEY_PIN, LOW);
    delay(3000);
    
    // Test AT command
    Serial.println("Testing AT command...");
    SerialAT.println("AT");
    delay(1000);
    
    if (SerialAT.available()) {
        String response = SerialAT.readString();
        Serial.println("Modem response: " + response);
        if (response.indexOf("OK") >= 0) {
            Serial.println("✓ Modem is responding!");
        } else {
            Serial.println("✗ Modem response unexpected");
        }
    } else {
        Serial.println("✗ No response from modem");
    }
    
    Serial.println();
    Serial.println("=== Hardware Test Complete ===");
    Serial.println("If all tests passed, you can proceed with the main program.");
}

void loop() {
    // Continuous monitoring
    static unsigned long lastPrint = 0;
    
    if (millis() - lastPrint > 5000) {
        Serial.println("--- Status Update ---");
        
        // Battery status
        int batteryADC = analogRead(BOARD_BAT_ADC_PIN);
        float batteryVoltage = (batteryADC * 3.3 * 2.0) / 4095.0;
        float batteryPercent = ((batteryVoltage - 3.0) / (4.2 - 3.0)) * 100.0;
        if (batteryPercent > 100.0) batteryPercent = 100.0;
        if (batteryPercent < 0.0) batteryPercent = 0.0;
        
        Serial.printf("Battery: %.2fV (%.1f%%)\n", batteryVoltage, batteryPercent);
        
        // Solar status
        int solarADC = analogRead(BOARD_SOLAR_ADC_PIN);
        float solarVoltage = (solarADC * 3.3 * 2.0) / 4095.0;
        Serial.printf("Solar: %.2fV\n", solarVoltage);
        
        // Modem communication test
        SerialAT.println("AT");
        delay(100);
        if (SerialAT.available()) {
            String response = SerialAT.readString();
            if (response.indexOf("OK") >= 0) {
                Serial.println("Modem: ✓ OK");
            } else {
                Serial.println("Modem: ✗ No response");
            }
        } else {
            Serial.println("Modem: ✗ No response");
        }
        
        Serial.println();
        lastPrint = millis();
    }
    
    // Blink LED to show activity
    static unsigned long lastBlink = 0;
    if (millis() - lastBlink > 1000) {
        digitalWrite(BOARD_LED_PIN, !digitalRead(BOARD_LED_PIN));
        lastBlink = millis();
    }
}

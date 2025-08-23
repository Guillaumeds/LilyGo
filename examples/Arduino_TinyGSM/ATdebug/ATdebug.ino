/*
  FILE: ATdebug.ino - ESP32 Deep Sleep + SIM7000 CSCLK Sleep Implementation
  AUTHOR: Based on ATdebug.ino by Koby Hale
  PURPOSE: Ultra-low power SIM7070G ThingSpeak integration with ESP32 deep sleep
  DESCRIPTION: Sends data to ThingSpeak every 5 minutes with ESP32 deep sleep + SIM7000 CSCLK sleep
               Uses direct AT commands without TinyGSM library
*/
#include <Arduino.h>
#include <driver/gpio.h>

#define SerialAT Serial1

#define PIN_DTR     25
#define PIN_TX      27
#define PIN_RX      26
#define PWR_PIN     4
#define GPS_POWER_PIN 12  // GPIO 12 controls GPS antenna power

// Deep sleep configuration
#define uS_TO_S_FACTOR      1000000ULL  // Conversion factor for micro seconds to seconds
#define TIME_TO_SLEEP       300         // Time ESP32 will go to sleep (5 minutes = 300 seconds)

// Timing constants (milliseconds)
#define MODEM_STARTUP_DELAY     20000   // 20 seconds for modem startup
#define AT_RESPONSE_TIMEOUT     15000   // 15 seconds for AT responses
#define NETWORK_REG_TIMEOUT     90000   // 90 seconds for network registration
#define HTTP_TIMEOUT           45000   // 45 seconds for HTTP operations

// Retry constants
#define MAX_AT_RETRIES         5
#define MAX_NETWORK_RETRIES    3
#define MAX_HTTP_RETRIES       3
#define MAX_SLEEP_RETRIES      3
#define MAX_WAKE_RETRIES       3

// Sleep verification delays
#define SLEEP_VERIFY_DELAY_1   5000    // 5 seconds
#define SLEEP_VERIFY_DELAY_2   10000   // 10 seconds
#define SLEEP_VERIFY_DELAY_3   15000   // 15 seconds
#define WAKE_VERIFY_DELAY_1    2000    // 2 seconds
#define WAKE_VERIFY_DELAY_2    5000    // 5 seconds
#define WAKE_VERIFY_DELAY_3    10000   // 10 seconds

// Battery reading
#define BATTERY_ADC_PIN        35      // Battery voltage divider pin
#define BATTERY_SAMPLES        15      // Number of readings for median filtering (keep odd)
#define BATTERY_MIN_VOLTAGE    2.5     // Empty battery voltage
#define BATTERY_MAX_VOLTAGE    4.2     // Full battery voltage

// Battery measurement variables
float batteryVoltage = 0.0;
int batteryPercentage = 0;

// ThingSpeak configuration
const char* THINGSPEAK_API_KEY = "RWE803O3NIOLIUQS";
const char* APN = "internet";

// Global variables
unsigned long lastCycleTime = 0;
bool modemPowered = false;
int cycleCount = 0;

bool reply = false;

// Function declarations
String sendATCommand(String command, unsigned long timeout = AT_RESPONSE_TIMEOUT);
String sendHTTPRequest(String command, unsigned long timeout = HTTP_TIMEOUT);
bool waitForResponse(String expectedResponse, unsigned long timeout = AT_RESPONSE_TIMEOUT);
bool performThingSpeakCycle();
bool establishNetworkConnection();
bool sendThingSpeakData();
void modem_sleep();
void modem_wake();
void gps_power_off();
void gps_power_on();
void esp32_deep_sleep();
void wake_from_deep_sleep();
bool robust_modem_sleep();
bool robust_modem_wake();
bool verify_modem_sleeping();
bool verify_modem_awake();
void modem_power_off();
void modem_power_on();
float read_battery_voltage();
void read_battery_advanced();
void sortBatteryData(float data[], int8_t size);
float mapBatteryVoltage(float voltage, float in_min, float in_max, float out_min, float out_max);
int calculate_battery_percentage(float voltage);

uint32_t dectModemBaud()
{
    static uint32_t rates[] = {115200, 57600,  38400, 19200, 9600,  74400, 74880,
                               230400, 460800, 2400,  4800,  14400, 28800
                              };

    for (uint8_t i = 0; i < sizeof(rates) / sizeof(rates[0]); i++) {
        uint32_t rate = rates[i];
        Serial.printf("[INFO]:Trying baud rate:%d\n", rate);
        SerialAT.updateBaudRate(rate);
        delay(100);
        for (int j = 0; j < 15; j++) {  // Increased attempts
            SerialAT.print("AT\r\n");
            delay(500);  // Longer delay
            String input = SerialAT.readString();
            if (input.indexOf("OK") >= 0) {
                Serial.printf("[INFO]:Modem responded at rate:%d\n", rate);
                SerialAT.println("AT+IPREX=115200");
                return rate;
            }
        }
    }
    SerialAT.updateBaudRate(115200);
    Serial.println("[ERROR]:Modem is not online!!!");
    return 0;
}


void modem_on()
{
    Serial.println("\nStarting Up Modem...");

    // Initialize serial communication
    SerialAT.begin(115200, SERIAL_8N1, PIN_RX, PIN_TX);
    delay(1000);

    // Try to communicate first - modem might already be on
    Serial.println("Testing if modem is already on...");
    for (int i = 0; i < 3; i++) {
        SerialAT.println("AT");
        delay(1000);
        if (SerialAT.available()) {
            String response = SerialAT.readString();
            if (response.indexOf("OK") >= 0) {
                Serial.println("Modem already powered on and responding");
                reply = true;
                modemPowered = true;
                return;
            }
        }
    }

    // If no response, power on the modem
    Serial.println("Powering on modem...");
    pinMode(PWR_PIN, OUTPUT);
    digitalWrite(PWR_PIN, LOW);   // Ensure it's off first
    delay(2000);
    digitalWrite(PWR_PIN, HIGH);  // Power pulse
    delay(1000);
    digitalWrite(PWR_PIN, LOW);   // Release power button
    // Perform advanced battery reading during modem startup delay
    Serial.println("Performing advanced battery measurement during modem startup...");
    read_battery_advanced();

    // Complete remaining startup delay if needed
    delay(2000);  // Small additional delay to ensure modem is ready

    int i = 15;  // More attempts

    if(dectModemBaud() == 0){
        Serial.println("Unable to communicate with modem.");
        return;
    }

    Serial.println("\nTesting Modem Response...\n");
    Serial.println("****");
    while (i) {
        SerialAT.println("AT");
        delay(1000);  // Longer delay
        if (SerialAT.available()) {
            String r = SerialAT.readString();
            Serial.println(r);
            if ( r.indexOf("OK") >= 0 ) {
                reply = true;
                break;
            }
        }
        delay(1000);
        i--;
    }
    Serial.println("****\n");
    modemPowered = reply;
}

void modem_sleep()
{
    if (!modemPowered) return;

    Serial.println("Putting SIM7000 to sleep for ESP32 deep sleep...");

    // Step 1: Disconnect any active connections gracefully
    sendATCommand("AT+SHDISC", 3000);
    delay(1000);

    // Step 2: Deactivate PDP context
    sendATCommand("AT+CNACT=1,0", 5000);
    delay(2000);

    // Step 3: Set DTR HIGH to prepare for sleep mode
    pinMode(PIN_DTR, OUTPUT);
    digitalWrite(PIN_DTR, HIGH);
    delay(1000);

    // Step 4: Enable sleep mode (AT+CSCLK=1)
    sendATCommand("AT+CSCLK=1", 5000);
    delay(2000);

    // Step 5: Hold DTR state during ESP32 deep sleep
    gpio_hold_en((gpio_num_t)PIN_DTR);
    gpio_deep_sleep_hold_en();

    Serial.println("SIM7000 sleep mode enabled with GPIO hold for ESP32 deep sleep");
}

void modem_wake()
{
    // This function is deprecated in deep sleep architecture
    // Wake-up is handled by wake_from_deep_sleep() function
    Serial.println("Note: modem_wake() deprecated - use wake_from_deep_sleep()");
}

String sendATCommand(String command, unsigned long timeout) {
    Serial.print("Sending: ");
    Serial.println(command);

    SerialAT.println(command);

    unsigned long startTime = millis();
    String response = "";

    while (millis() - startTime < timeout) {
        if (SerialAT.available()) {
            response += SerialAT.readString();
            if (response.indexOf("OK") >= 0 || response.indexOf("ERROR") >= 0) {
                break;
            }
        }
        delay(100);
    }

    Serial.print("Response: ");
    Serial.println(response);
    return response;
}

String sendHTTPRequest(String command, unsigned long timeout) {
    Serial.print("Sending HTTP: ");
    Serial.println(command);

    SerialAT.println(command);

    unsigned long startTime = millis();
    String response = "";
    bool gotOK = false;
    bool gotSHREQ = false;

    while (millis() - startTime < timeout) {
        if (SerialAT.available()) {
            String newData = SerialAT.readString();
            response += newData;

            if (response.indexOf("OK") >= 0) {
                gotOK = true;
            }
            if (response.indexOf("+SHREQ:") >= 0) {
                gotSHREQ = true;
            }

            // For SHREQ, we need both OK and +SHREQ response
            if (command.indexOf("SHREQ") >= 0) {
                if (gotOK && gotSHREQ) {
                    break;
                }
            } else {
                if (response.indexOf("OK") >= 0 || response.indexOf("ERROR") >= 0) {
                    break;
                }
            }
        }
        delay(100);
    }

    Serial.print("HTTP Response: ");
    Serial.println(response);
    return response;
}

bool waitForResponse(String expectedResponse, unsigned long timeout) {
    unsigned long startTime = millis();
    String response = "";

    while (millis() - startTime < timeout) {
        if (SerialAT.available()) {
            response += SerialAT.readString();
            if (response.indexOf(expectedResponse) >= 0) {
                Serial.print("Got expected response: ");
                Serial.println(response);
                return true;
            }
            if (response.indexOf("ERROR") >= 0) {
                Serial.print("Got error response: ");
                Serial.println(response);
                return false;
            }
        }
        delay(100);
    }

    Serial.println("Timeout waiting for response");
    return false;
}

void setup()
{
    Serial.begin(115200);
    delay(1000);

    // Check wake-up cause
    esp_sleep_wakeup_cause_t wakeup_reason = esp_sleep_get_wakeup_cause();

    if (wakeup_reason == ESP_SLEEP_WAKEUP_TIMER) {
        Serial.println("\n=== ESP32 Woke from Deep Sleep (Timer) ===");
        wake_from_deep_sleep();
    } else {
        Serial.println("\n=== ESP32 First Boot / Power On ===");
        cycleCount = 0;

        // Initialize GPS power control
        pinMode(GPS_POWER_PIN, OUTPUT);
        gps_power_off(); // Start with GPS off to save power

        // Initialize DTR pin for sleep/wake control
        pinMode(PIN_DTR, OUTPUT);
        digitalWrite(PIN_DTR, LOW); // Start with DTR LOW (awake state)

        // First boot - power on SIM7000
        modem_on();
        if (!reply) {
            Serial.println("ERROR: Failed to power on modem on first boot");
            esp32_deep_sleep(); // Sleep and retry
            return;
        }
    }

    cycleCount++;
    Serial.printf("\n=== Starting Cycle #%d ===\n", cycleCount);

    // Perform the data transmission cycle
    bool success = performThingSpeakCycle();

    if (success) {
        Serial.println("=== Cycle Completed Successfully ===");
    } else {
        Serial.println("=== Cycle Failed ===");
    }

    // Robust sleep sequence
    Serial.println("Preparing for robust deep sleep...");
    gps_power_off(); // Ensure GPS is off during sleep

    if (robust_modem_sleep()) {
        Serial.println("SIM7000 sleep verified - ESP32 entering deep sleep");
        esp32_deep_sleep();
    } else {
        Serial.println("SIM7000 sleep failed - forcing power off and deep sleep");
        modem_power_off();
        esp32_deep_sleep();
    }
}

void loop()
{
    // Should never reach here due to deep sleep
    Serial.println("ERROR: Reached loop() - this should not happen with deep sleep");
    delay(1000);
}

bool performThingSpeakCycle() {
    // Step 1: Wake up modem or power on if first time
    if (cycleCount == 1) {
        Serial.println("Step 1: Initial modem power on...");
        modem_on();
        if (!reply) {
            Serial.println("ERROR: Failed to power on modem");
            return false;
        }
    } else {
        Serial.println("Step 1: Waking up modem...");
        modem_wake();
    }

    // Step 2: Establish network connection
    Serial.println("Step 2: Establishing network connection...");
    if (!establishNetworkConnection()) {
        Serial.println("ERROR: Failed to establish network connection");
        return false;
    }

    // Step 3: Send data to ThingSpeak
    Serial.println("Step 3: Sending data to ThingSpeak...");
    if (!sendThingSpeakData()) {
        Serial.println("ERROR: Failed to send ThingSpeak data");
        return false;
    }

    return true;
}

bool establishNetworkConnection() {
    // Phase 1: Network Setup and Registration with retries
    for (int networkRetry = 0; networkRetry < MAX_NETWORK_RETRIES; networkRetry++) {
        Serial.printf("Network connection attempt %d/%d\n", networkRetry + 1, MAX_NETWORK_RETRIES);

        // 1. Check Signal Quality
        Serial.println("Checking signal quality...");
        String response = sendATCommand("AT+CSQ", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("+CSQ:") >= 0) {
            int rssiStart = response.indexOf(":") + 1;
            int rssiEnd = response.indexOf(",", rssiStart);
            if (rssiEnd > rssiStart) {
                int rssi = response.substring(rssiStart, rssiEnd).toInt();
                Serial.printf("Signal strength: %d\n", rssi);
                if (rssi < 10) {
                    Serial.println("WARNING: Poor signal quality");
                }
            }
        }
        delay(2000);

        // 2. Force GPRS Mode (Critical for TCP/HTTP)
        Serial.println("Setting GPRS mode...");
        response = sendATCommand("AT+CNMP=13", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to set GPRS mode");
            continue;
        }
        delay(3000);

        // 3. Check Network Registration (with extended timeout)
        Serial.println("Checking network registration...");
        bool registered = false;
        unsigned long regStartTime = millis();
        while (millis() - regStartTime < NETWORK_REG_TIMEOUT) {
            response = sendATCommand("AT+CREG?", 10000);
            if (response.indexOf("+CREG:") >= 0) {
                if (response.indexOf(",1") > 0 || response.indexOf(",5") > 0) {
                    Serial.println("Network registered successfully");
                    registered = true;
                    break;
                }
            }
            delay(5000); // Wait 5 seconds between checks
        }

        if (!registered) {
            Serial.println("Network registration failed");
            continue;
        }

        // 4. Set APN for network
        Serial.println("Setting APN...");
        String apnCommand = "AT+CGDCONT=1,\"IP\",\"" + String(APN) + "\"";
        response = sendATCommand(apnCommand, AT_RESPONSE_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to set APN");
            continue;
        }
        delay(2000);

        // 5. Activate Data Connection
        Serial.println("Activating data connection...");
        response = sendATCommand("AT+CNACT=1,1", 30000); // Extended timeout
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to activate data connection");
            continue;
        }
        delay(5000);

        // 6. Verify IP Address Assignment
        Serial.println("Verifying IP address...");
        response = sendATCommand("AT+CNACT?", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("+CNACT:") >= 0 && response.indexOf("1,1,\"") > 0) {
            Serial.println("IP address assigned successfully");

            // 7. Test DNS Resolution
            Serial.println("Testing DNS resolution...");
            response = sendATCommand("AT+CDNSGIP=\"api.thingspeak.com\"", 20000);
            if (response.indexOf("+CDNSGIP:") >= 0) {
                Serial.println("DNS resolution successful");
                return true;
            } else {
                Serial.println("DNS resolution failed, but continuing...");
                return true; // Continue even if DNS test fails
            }
        } else {
            Serial.println("No IP address assigned");
        }

        // Recovery sequence if this attempt failed
        Serial.println("Network setup failed, attempting recovery...");
        sendATCommand("AT+CNACT=1,0", 10000); // Deactivate context 1
        delay(5000);
    }

    Serial.println("All network connection attempts failed");
    return false;
}

bool sendThingSpeakData() {
    // Phase 2: HTTP Connection and Data Transmission with retries
    for (int httpRetry = 0; httpRetry < MAX_HTTP_RETRIES; httpRetry++) {
        Serial.printf("HTTP transmission attempt %d/%d\n", httpRetry + 1, MAX_HTTP_RETRIES);

        // 1. Configure HTTP Client
        Serial.println("Configuring HTTP client...");

        String response = sendATCommand("AT+SHCONF=\"URL\",\"http://api.thingspeak.com\"", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to set HTTP URL");
            continue;
        }
        delay(1000);

        response = sendATCommand("AT+SHCONF=\"BODYLEN\",1024", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to set body length");
            continue;
        }
        delay(1000);

        response = sendATCommand("AT+SHCONF=\"HEADERLEN\",350", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to set header length");
            continue;
        }
        delay(2000);

        // 2. Establish HTTP Connection
        Serial.println("Establishing HTTP connection...");
        response = sendATCommand("AT+SHCONN", HTTP_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to establish HTTP connection");
            // Try to disconnect and retry
            sendATCommand("AT+SHDISC", 5000);
            delay(3000);
            continue;
        }
        delay(3000);

        // 3. Send Data to ThingSpeak
        Serial.println("Sending data to ThingSpeak...");

        // Use advanced battery reading results (already measured during startup)
        Serial.printf("Using advanced battery measurement: %.3fV (%d%%)\n",
                      batteryVoltage, batteryPercentage);

        // Generate sample data for other fields
        float field2 = 60.2 + (cycleCount % 5);  // Sample humidity

        String dataRequest = "AT+SHREQ=\"/update?api_key=" + String(THINGSPEAK_API_KEY) +
                           "&field1=" + String(batteryVoltage, 3) +
                           "&field2=" + String(field2, 1) +
                           "&field3=" + String(batteryPercentage) + "\",1";

        response = sendHTTPRequest(dataRequest, HTTP_TIMEOUT);

        // 4. Parse response and read data
        if (response.indexOf("+SHREQ:") >= 0) {
            // Parse the response: +SHREQ: "GET",200,2
            // Find the line with +SHREQ:
            int shreqStart = response.indexOf("+SHREQ:");
            int lineEnd = response.indexOf("\n", shreqStart);
            String shreqLine = response.substring(shreqStart, lineEnd);

            Serial.printf("Parsing SHREQ line: %s\n", shreqLine.c_str());

            // Find the second comma (after "GET",)
            int firstComma = shreqLine.indexOf(",");
            int secondComma = shreqLine.indexOf(",", firstComma + 1);

            if (firstComma > 0 && secondComma > firstComma) {
                String statusCode = shreqLine.substring(firstComma + 1, secondComma);
                String byteCountStr = shreqLine.substring(secondComma + 1);

                statusCode.trim();
                byteCountStr.trim();

                Serial.printf("HTTP Status: %s, Byte Count: %s\n", statusCode.c_str(), byteCountStr.c_str());

                if (statusCode == "200") {
                    // 5. Read Response
                    int byteCount = byteCountStr.toInt();
                    if (byteCount > 0) {
                        String readCommand = "AT+SHREAD=0," + String(byteCount);
                        response = sendATCommand(readCommand, AT_RESPONSE_TIMEOUT);

                        if (response.indexOf("+SHREAD:") >= 0) {
                            Serial.println("Data sent successfully to ThingSpeak!");

                            // 6. Close HTTP Connection
                            Serial.println("Closing HTTP connection...");
                            sendATCommand("AT+SHDISC", 10000);
                            delay(2000);

                            return true;
                        }
                    }
                } else {
                    Serial.printf("HTTP request failed with status: %s\n", statusCode.c_str());
                }
            }
        } else {
            Serial.println("No valid HTTP response received");
        }

        // Cleanup for retry
        Serial.println("HTTP transmission failed, cleaning up...");
        sendATCommand("AT+SHDISC", 5000);
        delay(3000);

        // Recovery sequence
        if (httpRetry < MAX_HTTP_RETRIES - 1) {
            Serial.println("Attempting HTTP recovery...");
            sendATCommand("AT+CNACT=1,0", 10000); // Deactivate PDP context 1
            delay(3000);
            sendATCommand("AT+CNACT=1,1", 20000); // Reactivate PDP context 1
            delay(5000);
        }
    }

    Serial.println("All HTTP transmission attempts failed");
    return false;
}

// GPS Power Control Functions
void gps_power_off() {
    Serial.println("Turning GPS antenna power OFF");
    digitalWrite(GPS_POWER_PIN, LOW);

    // Also disable GPS via AT command if modem is powered
    if (modemPowered) {
        sendATCommand("AT+CGNSPWR=0", 5000); // Turn off GPS power
        sendATCommand("AT+CGPIO=0,48,1,0", 5000); // Set GPS power control pin LOW
    }
}

void gps_power_on() {
    Serial.println("Turning GPS antenna power ON");
    digitalWrite(GPS_POWER_PIN, HIGH);

    // Also enable GPS via AT command if modem is powered
    if (modemPowered) {
        sendATCommand("AT+CGPIO=0,48,1,1", 5000); // Set GPS power control pin HIGH
        sendATCommand("AT+CGNSPWR=1", 5000); // Turn on GPS power
    }
}

// ESP32 Deep Sleep Functions
void esp32_deep_sleep() {
    Serial.printf("ESP32 entering deep sleep for %d minutes\n", TIME_TO_SLEEP / 60);

    // Configure timer wake-up for 5 minutes
    esp_sleep_enable_timer_wakeup(TIME_TO_SLEEP * uS_TO_S_FACTOR);

    Serial.println("Going to sleep now...");
    Serial.flush(); // Ensure all serial output is sent
    delay(100);

    // Enter deep sleep
    esp_deep_sleep_start();

    // This line should never be reached
    Serial.println("ERROR: Failed to enter deep sleep");
}

void wake_from_deep_sleep() {
    Serial.println("Attempting robust SIM7000 wake-up...");

    // Cancel GPIO hold from previous sleep
    gpio_hold_dis((gpio_num_t)PIN_DTR);

    // Initialize pins after wake-up
    pinMode(PIN_DTR, OUTPUT);
    pinMode(GPS_POWER_PIN, OUTPUT);

    // Initialize serial communication
    SerialAT.begin(115200, SERIAL_8N1, PIN_RX, PIN_TX);
    delay(1000);

    if (robust_modem_wake()) {
        Serial.println("SIM7000 robust wake-up successful");
    } else {
        Serial.println("SIM7000 wake-up failed - performing power cycle");
        modem_power_off();
        delay(2000);
        modem_power_on();

        // Give modem time to initialize
        delay(15000);

        // Try AT communication again
        for (int i = 0; i < 3; i++) {
            if (verify_modem_awake()) {
                Serial.println("SIM7000 power cycle successful");
                return;
            }
            delay(5000);
        }

        Serial.println("SIM7000 power cycle failed - entering emergency sleep");
        esp32_deep_sleep();
    }
}

// Robust Sleep Functions
bool robust_modem_sleep() {
    Serial.println("Starting robust modem sleep sequence...");

    for (int attempt = 1; attempt <= MAX_SLEEP_RETRIES; attempt++) {
        Serial.printf("Sleep attempt %d/%d\n", attempt, MAX_SLEEP_RETRIES);

        // Step 1: Graceful disconnection
        sendATCommand("AT+SHDISC", 3000);
        delay(1000);
        sendATCommand("AT+CNACT=1,0", 5000);
        delay(2000);

        // Step 2: Set DTR HIGH and enable sleep
        pinMode(PIN_DTR, OUTPUT);
        digitalWrite(PIN_DTR, HIGH);
        delay(1000);
        sendATCommand("AT+CSCLK=1", 5000);
        delay(2000);

        // Step 3: Hold DTR state for ESP32 deep sleep
        gpio_hold_en((gpio_num_t)PIN_DTR);
        gpio_deep_sleep_hold_en();

        // Step 4: Wait and verify sleep
        unsigned long sleepDelay;
        switch(attempt) {
            case 1: sleepDelay = SLEEP_VERIFY_DELAY_1; break;
            case 2: sleepDelay = SLEEP_VERIFY_DELAY_2; break;
            default: sleepDelay = SLEEP_VERIFY_DELAY_3; break;
        }

        Serial.printf("Waiting %lu ms to verify sleep...\n", sleepDelay);
        delay(sleepDelay);

        if (verify_modem_sleeping()) {
            Serial.println("SIM7000 sleep verified successfully");
            return true;
        }

        Serial.printf("Sleep attempt %d failed, retrying...\n", attempt);

        // Reset for next attempt
        gpio_hold_dis((gpio_num_t)PIN_DTR);
        digitalWrite(PIN_DTR, LOW);
        delay(2000);
        sendATCommand("AT+CSCLK=0", 5000);
        delay(2000);
    }

    Serial.println("All sleep attempts failed");
    return false;
}

bool robust_modem_wake() {
    Serial.println("Starting robust modem wake sequence...");

    for (int attempt = 1; attempt <= MAX_WAKE_RETRIES; attempt++) {
        Serial.printf("Wake attempt %d/%d\n", attempt, MAX_WAKE_RETRIES);

        // Step 1: Release DTR hold and set LOW
        gpio_hold_dis((gpio_num_t)PIN_DTR);
        digitalWrite(PIN_DTR, LOW);

        // Step 2: Wait for wake-up
        unsigned long wakeDelay;
        switch(attempt) {
            case 1: wakeDelay = WAKE_VERIFY_DELAY_1; break;
            case 2: wakeDelay = WAKE_VERIFY_DELAY_2; break;
            default: wakeDelay = WAKE_VERIFY_DELAY_3; break;
        }

        Serial.printf("Waiting %lu ms for wake-up...\n", wakeDelay);
        delay(wakeDelay);

        // Step 3: Disable sleep mode
        sendATCommand("AT+CSCLK=0", 5000);
        delay(1000);

        // Step 4: Verify modem is awake
        if (verify_modem_awake()) {
            Serial.println("SIM7000 wake verified successfully");
            return true;
        }

        Serial.printf("Wake attempt %d failed, retrying...\n", attempt);
        delay(2000);
    }

    Serial.println("All wake attempts failed");
    return false;
}

bool verify_modem_sleeping() {
    Serial.println("Verifying modem sleep state...");

    // Try to send AT command - should get no response if sleeping
    SerialAT.println("AT");
    delay(2000);

    String response = "";
    unsigned long startTime = millis();
    while (millis() - startTime < 3000) {
        if (SerialAT.available()) {
            response += SerialAT.readString();
        }
        delay(100);
    }

    // Clear any remaining data
    while (SerialAT.available()) {
        SerialAT.read();
    }

    bool isSleeping = (response.length() == 0 || !response.indexOf("OK"));
    Serial.printf("Sleep verification: %s (response: '%s')\n",
                  isSleeping ? "SLEEPING" : "AWAKE", response.c_str());

    return isSleeping;
}

bool verify_modem_awake() {
    Serial.println("Verifying modem awake state...");

    for (int i = 0; i < 3; i++) {
        String response = sendATCommand("AT", 3000);
        if (response.indexOf("OK") >= 0) {
            Serial.println("Modem is awake and responding");
            return true;
        }
        delay(1000);
    }

    Serial.println("Modem is not responding");
    return false;
}

void modem_power_off() {
    Serial.println("Powering off SIM7000...");

    // Try graceful shutdown first
    sendATCommand("AT+CPOWD=1", 10000);
    delay(5000);

    // Force power off via PWR_PIN
    pinMode(PWR_PIN, OUTPUT);
    digitalWrite(PWR_PIN, HIGH);
    delay(1500);  // Hold for 1.5 seconds to force power off
    digitalWrite(PWR_PIN, LOW);

    modemPowered = false;
    Serial.println("SIM7000 powered off");
}

void modem_power_on() {
    Serial.println("Powering on SIM7000...");

    pinMode(PWR_PIN, OUTPUT);
    digitalWrite(PWR_PIN, HIGH);
    delay(1000);  // Hold for 1 second to power on
    digitalWrite(PWR_PIN, LOW);

    // Wait for modem to initialize
    delay(MODEM_STARTUP_DELAY);

    modemPowered = true;
    Serial.println("SIM7000 powered on");
}

float read_battery_voltage() {
    Serial.println("Reading battery voltage...");

    // Configure ADC for battery reading
    analogSetAttenuation(ADC_11db);  // For 0-3.3V range
    analogSetWidth(12);              // 12-bit resolution (0-4095)

    // Take multiple readings for accuracy
    int readings = 0;
    for (int i = 0; i < 10; i++) {
        readings += analogRead(BATTERY_ADC_PIN);
        delay(10);
    }

    int avgReading = readings / 10;

    // Convert to voltage
    // The board has a voltage divider (typically 2:1 ratio)
    // ADC reading -> voltage -> actual battery voltage
    float adcVoltage = (avgReading * 3.3) / 4095.0;
    float batteryVoltage = adcVoltage * 2.0;  // Compensate for voltage divider

    Serial.printf("ADC reading: %d, ADC voltage: %.3fV, Battery voltage: %.3fV\n",
                  avgReading, adcVoltage, batteryVoltage);

    // Check if we're on USB power (battery reading near 0V)
    if (batteryVoltage < 0.5) {
        Serial.println("USB power detected - battery voltage not available");
        return -1.0;  // Return -1 to indicate USB power
    }

    // Validate battery voltage range (typical Li-ion: 3.0V - 4.2V)
    if (batteryVoltage < 2.5 || batteryVoltage > 4.5) {
        Serial.printf("Warning: Battery voltage %.2fV outside normal range (3.0V-4.2V)\n", batteryVoltage);
    }

    return batteryVoltage;
}

// Advanced Battery Reading Functions
void read_battery_advanced() {
    Serial.println("=== Advanced Battery Measurement Started ===");
    unsigned long startTime = millis();

    // Configure ADC for battery reading
    analogSetAttenuation(ADC_11db);  // For 0-3.3V range
    analogSetWidth(12);              // 12-bit resolution (0-4095)

    float voltageBuffer[BATTERY_SAMPLES];
    uint32_t readBuffer = 0;

    Serial.printf("Taking %d sets of %d readings each (%d total samples)...\n",
                  BATTERY_SAMPLES, BATTERY_SAMPLES, BATTERY_SAMPLES * BATTERY_SAMPLES);

    // Outer loop: Take BATTERY_SAMPLES sets of readings
    for (int x = 0; x < BATTERY_SAMPLES; x++) {
        Serial.printf("Sample set %d/%d: ", x + 1, BATTERY_SAMPLES);

        // Inner loop: Take BATTERY_SAMPLES readings for this set
        for (int i = 0; i < BATTERY_SAMPLES; i++) {
            voltageBuffer[i] = (float)analogRead(BATTERY_ADC_PIN);
            delayMicroseconds(100);  // Small delay between readings
        }

        // Sort the readings and get median
        sortBatteryData(voltageBuffer, BATTERY_SAMPLES);
        uint32_t medianReading = (uint32_t)voltageBuffer[(BATTERY_SAMPLES - 1) / 2];
        readBuffer += medianReading;

        Serial.printf("Median ADC: %d\n", medianReading);
        delay(50);  // Small delay between sets
    }

    // Calculate average of all median readings
    float avgMedianReading = (float)readBuffer / BATTERY_SAMPLES;

    // Convert to voltage using the same formula as community solution
    // Formula: (((ADC_reading / 4096) * 3600 * 2) / 1000)
    batteryVoltage = (((avgMedianReading / 4096.0) * 3600.0 * 2.0) / 1000.0);

    // Calculate battery percentage
    batteryPercentage = calculate_battery_percentage(batteryVoltage);

    unsigned long duration = millis() - startTime;

    Serial.printf("=== Advanced Battery Measurement Complete ===\n");
    Serial.printf("Total samples: %d\n", BATTERY_SAMPLES * BATTERY_SAMPLES);
    Serial.printf("Average median ADC: %.1f\n", avgMedianReading);
    Serial.printf("Battery voltage: %.3fV\n", batteryVoltage);
    Serial.printf("Battery percentage: %d%%\n", batteryPercentage);
    Serial.printf("Measurement time: %lu ms\n", duration);
    Serial.println("===============================================");
}

void sortBatteryData(float data[], int8_t size) {
    // Bubble sort algorithm - sorts data from smallest to largest
    float swapper;
    for (int8_t i = 0; i < (size - 1); i++) {
        for (int8_t o = 0; o < (size - (i + 1)); o++) {
            if (data[o] > data[o + 1]) {
                swapper = data[o];
                data[o] = data[o + 1];
                data[o + 1] = swapper;
            }
        }
    }
}

float mapBatteryVoltage(float voltage, float in_min, float in_max, float out_min, float out_max) {
    // Linear mapping function (like Arduino map() but for floats)
    return (voltage - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int calculate_battery_percentage(float voltage) {
    // Check if we're on USB power (battery reading near 0V)
    if (voltage < 0.5) {
        Serial.println("USB power detected - battery percentage not available");
        return -1;  // Return -1 to indicate USB power
    }

    // Use the community-recommended voltage range
    float percentage = mapBatteryVoltage(voltage, BATTERY_MIN_VOLTAGE, BATTERY_MAX_VOLTAGE, 0.0, 100.0);

    // Clamp to valid range
    if (percentage < 0) percentage = 0;
    if (percentage > 100) percentage = 100;

    // Validate battery voltage range
    if (voltage < BATTERY_MIN_VOLTAGE || voltage > BATTERY_MAX_VOLTAGE) {
        Serial.printf("Warning: Battery voltage %.3fV outside normal range (%.1fV-%.1fV)\n",
                      voltage, BATTERY_MIN_VOLTAGE, BATTERY_MAX_VOLTAGE);
    }

    return (int)percentage;
}



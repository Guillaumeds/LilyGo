/*
  FILE: LilySoilWorking.ino - ESP32 Deep Sleep + SIM7000 CSCLK Sleep + Soil Sensors
  AUTHOR: Based on ATdebug.ino by Koby Hale
  PURPOSE: Ultra-low power SIM7070G ThingSpeak integration with ESP32 deep sleep + soil sensors
  DESCRIPTION: Sends battery and soil sensor data to ThingSpeak every 5 minutes 
               with ESP32 deep sleep + SIM7000 CSCLK sleep. Uses working Halisense soil sensors.
*/
#include <Arduino.h>
#include <driver/gpio.h>

#define SerialAT Serial1
#define ModbusSerial Serial2

#define PIN_DTR     25
#define PIN_TX      27
#define PIN_RX      26
#define PWR_PIN     4
#define GPS_POWER_PIN 12  // GPIO 12 controls GPS antenna power

// Modbus RS485 pins (confirmed working)
#define MODBUS_TX_PIN    32    // GPIO 32 - TTL485 TX
#define MODBUS_RX_PIN    33    // GPIO 33 - TTL485 RX

// Deep sleep configuration
#define uS_TO_S_FACTOR      1000000ULL  // Conversion factor for micro seconds to seconds
#define TIME_TO_SLEEP       900         // Time ESP32 will go to sleep (15 minutes = 900 seconds)

// Timing constants (milliseconds)
#define MODEM_STARTUP_DELAY     20000   // 20 seconds for modem startup
#define AT_RESPONSE_TIMEOUT     15000   // 15 seconds for AT responses
#define NETWORK_REG_TIMEOUT     90000   // 90 seconds for network registration
#define HTTP_TIMEOUT           60000   // 90 seconds for HTTP operations

// Retry constants
#define MAX_AT_RETRIES         5
#define MAX_NETWORK_RETRIES    3
#define MAX_HTTP_RETRIES       3
#define MAX_SLEEP_RETRIES      3
#define MAX_WAKE_RETRIES       3

// Sleep verification delays
#define SLEEP_VERIFY_DELAY_1   2000    // 2 seconds
#define SLEEP_VERIFY_DELAY_2   5000    // 5 seconds
#define SLEEP_VERIFY_DELAY_3   10000   // 10 seconds
#define WAKE_VERIFY_DELAY_1    200     // 200ms
#define WAKE_VERIFY_DELAY_2    500     // 500ms
#define WAKE_VERIFY_DELAY_3    1000    // 1 second

// Battery reading
#define BATTERY_ADC_PIN        35      // Main battery voltage divider pin
#define BACKUP_BATTERY_ADC_PIN 34      // Backup battery voltage divider pin
#define BATTERY_SAMPLES        15      // Number of readings for median filtering (keep odd)
#define BATTERY_MIN_VOLTAGE    2.5     // Empty battery voltage
#define BATTERY_MAX_VOLTAGE    4.2     // Full battery voltage

// Backup battery configuration (from your measurement: 4.226V -> 2.091V)
#define BACKUP_BATTERY_RATIO   2.021   // Ratio: 4.226V / 2.091V = 2.021

// Halisense soil sensor configuration (confirmed working)
#define MODBUS_BAUD      4800
#define TIMEOUT_MS       2000

// Halisense soil sensor data structure (working implementation)
struct SensorData {
    float temperature = 0.0;
    float humidity = 0.0;
    float ec = 0.0;
    float ph = 0.0;
    float nitrogen = 0.0;
    float phosphorus = 0.0;
    float potassium = 0.0;
    bool valid = false;
};

// Simple sensor data structure for temp/moisture only sensors
struct SimpleSensorData {
    float temperature = 0.0;
    float humidity = 0.0;
    bool valid = false;
};

// Sensor addresses
#define FULL_SENSOR_ADDR     2   // Address 2: Full 7-parameter sensor
#define SIMPLE_SENSOR_1_ADDR 13  // Address 13: Temp/Moisture only
#define SIMPLE_SENSOR_2_ADDR 10  // Address 10: Temp/Moisture only

// Official Halisense command template (confirmed working) - CRC calculated dynamically
const byte READ_ALL_REG_TEMPLATE[6] = {0x00, 0x03, 0x00, 0x00, 0x00, 0x07};  // Address filled dynamically
const byte READ_TEMP_HUMID_TEMPLATE[6] = {0x00, 0x03, 0x00, 0x00, 0x00, 0x02}; // Address filled dynamically

// Battery measurement variables
float batteryVoltage = 0.0;
int batteryPercentage = 0;
float backupBatteryVoltage = 0.0;
int backupBatteryPercentage = 0;

// Soil sensor data - 3 sensors total
SensorData fullSensorData;        // Address 2: Full 7-parameter sensor
SimpleSensorData simpleSensor1;   // Address 13: Temp/Moisture only
SimpleSensorData simpleSensor2;   // Address 10: Temp/Moisture only

// ThingSpeak configuration - TWO CHANNEL GROUPS
const char* THINGSPEAK_API_KEY_GROUP1 = "RWE803O3NIOLIUQS";  // Group 1: Voltages + Simple sensors (addr 13,10)
const char* THINGSPEAK_API_KEY_GROUP2 = "D89K8U1LXN43JG8K";  // Group 2: Full soil sensor data (addr 2)
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
bool sendThingSpeakGroup1();  // Voltages
bool sendThingSpeakGroup2();  // Soil data
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
void read_backup_battery_advanced();
void sortBatteryData(float data[], int8_t size);
float mapBatteryVoltage(float voltage, float in_min, float in_max, float out_min, float out_max);
int calculate_battery_percentage(float voltage);

// Soil sensor functions (working implementation)
SensorData readFullSensorData();
SimpleSensorData readSimpleSensorData(uint8_t address);
int sendHalisenseCommand(const byte* command, int cmdLength, byte* response, int maxResponse);
uint16_t calculateCRC(byte *data, uint8_t length);

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
    delay(MODEM_STARTUP_DELAY);   // Wait for modem to start

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

    // Perform advanced battery measurements early in cycle
    // This gives SIM module time to stabilize while we measure batteries
    Serial.println("\n=== Advanced Battery Measurements ===");
    read_battery_advanced();
    read_backup_battery_advanced();

    // Initialize Modbus for soil sensors (sensors permanently powered)
    Serial.println("\n=== Multi-Sensor Reading ===");
    Serial.println("🚀 Reading from 3 sensors: Full(addr 2) + Simple(addr 13,10)");

    // Initialize Modbus with confirmed working settings
    ModbusSerial.begin(MODBUS_BAUD, SERIAL_8N1, MODBUS_RX_PIN, MODBUS_TX_PIN);
    delay(1000); // Allow sensors to stabilize

    // Read all 3 soil sensors
    Serial.println("📡 Reading from 3 soil sensors...");

    // Read full sensor (address 2)
    Serial.println("Reading full sensor (address 2)...");
    fullSensorData = readFullSensorData();

    // Read simple sensor 1 (address 13)
    Serial.println("Reading simple sensor 1 (address 13)...");
    simpleSensor1 = readSimpleSensorData(SIMPLE_SENSOR_1_ADDR);

    // Read simple sensor 2 (address 10)
    Serial.println("Reading simple sensor 2 (address 10)...");
    simpleSensor2 = readSimpleSensorData(SIMPLE_SENSOR_2_ADDR);

    // Display results
    if (fullSensorData.valid) {
        Serial.println("✅ Full sensor data obtained successfully");
        Serial.printf("  Temperature: %.1f°C\n", fullSensorData.temperature);
        Serial.printf("  Humidity: %.1f%%\n", fullSensorData.humidity);
        Serial.printf("  EC: %.0f µS/cm\n", fullSensorData.ec);
        Serial.printf("  pH: %.1f\n", fullSensorData.ph);
        Serial.printf("  Nitrogen: %.0f mg/kg\n", fullSensorData.nitrogen);
        Serial.printf("  Phosphorus: %.0f mg/kg\n", fullSensorData.phosphorus);
        Serial.printf("  Potassium: %.0f mg/kg\n", fullSensorData.potassium);
    } else {
        Serial.println("❌ Failed to read full sensor - using default values");
        fullSensorData.temperature = -999.0;
        fullSensorData.humidity = -999.0;
        fullSensorData.ec = -999.0;
        fullSensorData.ph = -999.0;
        fullSensorData.nitrogen = -999.0;
        fullSensorData.phosphorus = -999.0;
        fullSensorData.potassium = -999.0;
    }

    if (simpleSensor1.valid) {
        Serial.printf("✅ Simple sensor 1 (addr 13): Temp=%.1f°C, Humidity=%.1f%%\n",
                      simpleSensor1.temperature, simpleSensor1.humidity);
    } else {
        Serial.println("❌ Failed to read simple sensor 1 - using default values");
        simpleSensor1.temperature = -999.0;
        simpleSensor1.humidity = -999.0;
    }

    if (simpleSensor2.valid) {
        Serial.printf("✅ Simple sensor 2 (addr 10): Temp=%.1f°C, Humidity=%.1f%%\n",
                      simpleSensor2.temperature, simpleSensor2.humidity);
    } else {
        Serial.println("❌ Failed to read simple sensor 2 - using default values");
        simpleSensor2.temperature = -999.0;
        simpleSensor2.humidity = -999.0;
    }

    // Additional stabilization time for SIM module after measurements
    Serial.println("Allowing SIM module additional stabilization time...");
    delay(2000);

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

// ===== SOIL SENSOR FUNCTIONS (Working Implementation) =====

SensorData readFullSensorData() {
    SensorData data;

    Serial.println("📡 BULK READ: Getting all 7 sensor values from address 2...");

    // Build command dynamically with correct address and CRC (original working method)
    byte command[8];
    memcpy(command, READ_ALL_REG_TEMPLATE, 6);
    command[0] = FULL_SENSOR_ADDR;  // Set address to 2

    // Calculate CRC dynamically (original working method)
    uint16_t crc = calculateCRC(command, 6);
    command[6] = crc & 0xFF;        // CRC low byte
    command[7] = (crc >> 8) & 0xFF; // CRC high byte

    // Send command (reads 7 registers at once)
    byte response[25];
    int responseLength = sendHalisenseCommand(command, 8, response, 25);

    if (responseLength == 19) {  // Expected: 3 header + 14 data + 2 CRC
        Serial.printf("✓ Perfect response length: %d bytes\n", responseLength);

        // Validate response header
        if (response[0] == FULL_SENSOR_ADDR && response[1] == 0x03 && response[2] == 0x0E) {
            Serial.println("✓ Valid response header");

            // Parse all 7 sensor values (official Halisense protocol)
            data.humidity = (((response[3] << 8) | response[4]) & 0xFFF) / 10.0;
            data.temperature = (((response[5] << 8) | response[6]) & 0xFFF) / 10.0;
            data.ec = (((response[7] << 8) | response[8]) & 0xFFF);
            data.ph = (((response[9] << 8) | response[10]) & 0xFFF) / 10.0;
            data.nitrogen = (((response[11] << 8) | response[12]) & 0xFFF);
            data.phosphorus = (((response[13] << 8) | response[14]) & 0xFFF);
            data.potassium = (((response[15] << 8) | response[16]) & 0xFFF);

            data.valid = true;
            Serial.println("✅ BULK READ SUCCESSFUL - All 7 values obtained!");

        } else {
            Serial.printf("✗ Invalid header: %02X %02X %02X\n", response[0], response[1], response[2]);
        }
    } else {
        Serial.printf("✗ Wrong response length: %d bytes (expected: 19)\n", responseLength);
    }

    return data;
}

SimpleSensorData readSimpleSensorData(uint8_t address) {
    SimpleSensorData data;

    Serial.printf("📡 Reading temp/humidity from address %d...\n", address);

    // Build command dynamically with correct address and CRC (original working method)
    byte command[8];
    memcpy(command, READ_TEMP_HUMID_TEMPLATE, 6);
    command[0] = address;  // Set the specific address

    // Calculate CRC dynamically (original working method)
    uint16_t crc = calculateCRC(command, 6);
    command[6] = crc & 0xFF;        // CRC low byte
    command[7] = (crc >> 8) & 0xFF; // CRC high byte

    // Send command (reads 2 registers: temp and humidity)
    byte response[9]; // Expected: 3 header + 4 data + 2 CRC
    int responseLength = sendHalisenseCommand(command, 8, response, 9);

    if (responseLength == 9) {  // Expected: 3 header + 4 data + 2 CRC
        Serial.printf("✓ Perfect response length: %d bytes\n", responseLength);

        // Validate response header
        if (response[0] == address && response[1] == 0x03 && response[2] == 0x04) {
            Serial.println("✓ Valid response header");

            // Parse temperature and humidity (same format as full sensor)
            data.humidity = (((response[3] << 8) | response[4]) & 0xFFF) / 10.0;
            data.temperature = (((response[5] << 8) | response[6]) & 0xFFF) / 10.0;

            data.valid = true;
            Serial.printf("✅ Simple sensor read successful: Temp=%.1f°C, Humidity=%.1f%%\n",
                         data.temperature, data.humidity);

        } else {
            Serial.printf("✗ Invalid header: %02X %02X %02X\n", response[0], response[1], response[2]);
        }
    } else {
        Serial.printf("✗ Wrong response length: %d bytes (expected: 9)\n", responseLength);
    }

    return data;
}

int sendHalisenseCommand(const byte* command, int cmdLength, byte* response, int maxResponse) {
    // Clear receive buffer
    while (ModbusSerial.available()) {
        ModbusSerial.read();
    }

    // Send command as fast continuous stream (TTL485 requirement)
    Serial.print("TX: ");
    for (int i = 0; i < cmdLength; i++) {
        Serial.printf("%02X ", command[i]);
        ModbusSerial.write(command[i]);
        // NO DELAYS between bytes - critical for TTL485 auto-direction
    }
    ModbusSerial.flush();
    Serial.print("→ ");

    // Wait for response
    unsigned long start = millis();
    int bytes = 0;

    while (millis() - start < TIMEOUT_MS && bytes < maxResponse) {
        if (ModbusSerial.available()) {
            response[bytes] = ModbusSerial.read();
            bytes++;
        }
        delay(1);
    }

    if (bytes > 0) {
        Serial.printf("RX (%d bytes): ", bytes);
        for (int i = 0; i < bytes; i++) {
            Serial.printf("%02X ", response[i]);
        }
        Serial.println();
    } else {
        Serial.println("✗ Timeout");
    }

    return bytes;
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

    // Step 3: Send data to both ThingSpeak groups
    Serial.println("Step 3: Sending data to ThingSpeak groups...");

    // Configure HTTP client
    sendATCommand("AT+SHCONF=\"URL\",\"http://api.thingspeak.com\"", AT_RESPONSE_TIMEOUT);
    sendATCommand("AT+SHCONF=\"BODYLEN\",1024", AT_RESPONSE_TIMEOUT);
    sendATCommand("AT+SHCONF=\"HEADERLEN\",350", AT_RESPONSE_TIMEOUT);

    // Connect to ThingSpeak
    String response = sendATCommand("AT+SHCONN", 15000);
    if (response.indexOf("OK") < 0) {
        Serial.println("❌ Failed to connect to ThingSpeak");
        return false;
    }

    // Send both groups (continue even if one fails)
    bool group1Success = sendThingSpeakGroup1();
    delay(200); // Delay between uploads
    bool group2Success = sendThingSpeakGroup2();

    // Disconnect HTTP
    sendATCommand("AT+SHDISC");

    // Report results
    if (group1Success && group2Success) {
        Serial.println("✅ Both ThingSpeak groups uploaded successfully");
        return true;
    } else if (group1Success || group2Success) {
        Serial.println("⚠️ Partial success - one group uploaded");
        return true; // Consider partial success as success
    } else {
        Serial.println("❌ Both ThingSpeak uploads failed");
        return false;
    }
}

bool sendThingSpeakGroup1() {
    Serial.println("📡 Sending Group 1 data (Voltages + Simple Sensors) to ThingSpeak...");

    // Build ThingSpeak URL for Group 1: Voltages + Simple sensors in GPS fields
    String url = "/update?api_key=" + String(THINGSPEAK_API_KEY_GROUP1);
    url += "&field1=" + String(batteryVoltage, 3);           // Main battery voltage
    url += "&field2=" + String(batteryPercentage);          // Main battery percentage
    url += "&field3=" + String(backupBatteryVoltage, 3);    // Backup battery voltage
    url += "&field4=" + String(backupBatteryPercentage);    // Backup battery percentage
    // Using GPS reserved fields for simple sensors
    url += "&field5=" + String(simpleSensor1.temperature, 1);  // Simple sensor 1 temp (addr 13)
    url += "&field6=" + String(simpleSensor1.humidity, 1);     // Simple sensor 1 humidity (addr 13)
    url += "&field7=" + String(simpleSensor2.temperature, 1);  // Simple sensor 2 temp (addr 10)
    url += "&field8=" + String(simpleSensor2.humidity, 1);     // Simple sensor 2 humidity (addr 10)

    Serial.println("Group 1 URL: " + url);

    // Send HTTP request
    String response = sendHTTPRequest("AT+SHREQ=\"" + url + "\",1", HTTP_TIMEOUT);

    if (response.indexOf("+SHREQ: \"GET\",200") >= 0) {
        Serial.println("✅ Group 1 data sent successfully");

        // Extract and read response
        int commaPos = response.lastIndexOf(',');
        if (commaPos > 0) {
            String byteCountStr = response.substring(commaPos + 1);
            byteCountStr.trim();
            int byteCount = byteCountStr.toInt();

            if (byteCount > 0) {
                String readCmd = "AT+SHREAD=0," + String(byteCount);
                sendATCommand(readCmd);
            }
        }
        return true;

    } else {
        Serial.println("❌ Group 1 upload failed");
        return false;
    }
}

bool sendThingSpeakGroup2() {
    Serial.println("📡 Sending Group 2 data (Full Soil Sensor) to ThingSpeak...");

    // Build ThingSpeak URL for Group 2: Full soil sensor data (address 2)
    String url = "/update?api_key=" + String(THINGSPEAK_API_KEY_GROUP2);
    url += "&field1=" + String(fullSensorData.temperature, 1);       // Full sensor temperature
    url += "&field2=" + String(fullSensorData.humidity, 1);          // Full sensor humidity
    url += "&field3=" + String((int)fullSensorData.ec);              // EC (raw) - cast to int to avoid spaces
    url += "&field4=" + String(fullSensorData.ph, 1);                // pH (raw)
    url += "&field5=" + String((int)fullSensorData.nitrogen);        // Nitrogen (raw) - cast to int
    url += "&field6=" + String((int)fullSensorData.phosphorus);      // Phosphorus (raw) - cast to int
    url += "&field7=" + String((int)fullSensorData.potassium);       // Potassium (raw) - cast to int
    url += "&field8=" + String(fullSensorData.valid ? 1 : 0);        // Data validity flag

    Serial.println("Group 2 URL: " + url);

    // Send HTTP request
    String response = sendHTTPRequest("AT+SHREQ=\"" + url + "\",1", HTTP_TIMEOUT);

    if (response.indexOf("+SHREQ: \"GET\",200") >= 0) {
        Serial.println("✅ Group 2 data sent successfully");

        // Extract and read response
        int commaPos = response.lastIndexOf(',');
        if (commaPos > 0) {
            String byteCountStr = response.substring(commaPos + 1);
            byteCountStr.trim();
            int byteCount = byteCountStr.toInt();

            if (byteCount > 0) {
                String readCmd = "AT+SHREAD=0," + String(byteCount);
                sendATCommand(readCmd);
            }
        }
        return true;

    } else {
        Serial.println("❌ Group 2 upload failed");
        return false;
    }
}

void modem_sleep()
{
    if (!modemPowered) return;

    Serial.println("Putting SIM7000 to sleep for ESP32 deep sleep...");

    // Step 1: Disconnect any active connections gracefully
    sendATCommand("AT+SHDISC", 3000);
    delay(100);

    // Step 2: Deactivate PDP context
    sendATCommand("AT+CNACT=1,0", 5000);
    delay(200);

    // Step 3: Set DTR HIGH to prepare for sleep mode
    pinMode(PIN_DTR, OUTPUT);
    digitalWrite(PIN_DTR, HIGH);
    delay(500);

    // Step 4: Enable sleep mode (AT+CSCLK=1)
    sendATCommand("AT+CSCLK=1", 5000);
    delay(200);

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
        delay(200);

        // 2. Force GPRS Mode (Critical for TCP/HTTP)
        Serial.println("Setting GPRS mode...");
        response = sendATCommand("AT+CNMP=13", AT_RESPONSE_TIMEOUT);
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to set GPRS mode");
            continue;
        }
        delay(300);

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
            delay(2500); // Wait 2.5 seconds between checks
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
        delay(200);

        // 5. Activate Data Connection
        Serial.println("Activating data connection...");
        response = sendATCommand("AT+CNACT=1,1", 30000); // Extended timeout
        if (response.indexOf("OK") < 0) {
            Serial.println("Failed to activate data connection");
            continue;
        }
        delay(500);

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
        delay(500);
    }

    Serial.println("All network connection attempts failed");
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

    // Configure timer wake-up for 15 minutes
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
            delay(500);
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
        delay(100);
        sendATCommand("AT+CNACT=1,0", 5000);
        delay(200);

        // Step 2: Set DTR HIGH and enable sleep
        pinMode(PIN_DTR, OUTPUT);
        digitalWrite(PIN_DTR, HIGH);
        delay(100);
        sendATCommand("AT+CSCLK=1", 5000);
        delay(200);

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
        delay(200);
        sendATCommand("AT+CSCLK=0", 5000);
        delay(500);
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
        delay(100);

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
    delay(200);

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
        delay(100);
    }

    Serial.println("Modem is not responding");
    return false;
}

void modem_power_off() {
    Serial.println("Powering off SIM7000...");

    // Try graceful shutdown first
    sendATCommand("AT+CPOWD=1", 10000);
    delay(500);

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
            delayMicroseconds(200);  // Doubled delay between readings for stability
        }

        // Sort the readings and get median
        sortBatteryData(voltageBuffer, BATTERY_SAMPLES);
        uint32_t medianReading = (uint32_t)voltageBuffer[(BATTERY_SAMPLES - 1) / 2];
        readBuffer += medianReading;

        Serial.printf("Median ADC: %d\n", medianReading);
        delay(100);  // Doubled delay between sets for extended stabilization
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

void read_backup_battery_advanced() {
    Serial.println("=== Backup Battery Measurement Started ===");
    unsigned long startTime = millis();

    // Configure ADC for backup battery reading
    analogSetAttenuation(ADC_11db);  // For 0-3.3V range
    analogSetWidth(12);              // 12-bit resolution (0-4095)

    float voltageBuffer[BATTERY_SAMPLES];
    uint32_t readBuffer = 0;

    Serial.printf("Taking %d sets of %d readings each (%d total samples)...\n",
                  BATTERY_SAMPLES, BATTERY_SAMPLES, BATTERY_SAMPLES * BATTERY_SAMPLES);

    // Outer loop: Take BATTERY_SAMPLES sets of readings
    for (int x = 0; x < BATTERY_SAMPLES; x++) {
        Serial.printf("Backup sample set %d/%d: ", x + 1, BATTERY_SAMPLES);

        // Inner loop: Take BATTERY_SAMPLES readings for this set
        for (int i = 0; i < BATTERY_SAMPLES; i++) {
            voltageBuffer[i] = (float)analogRead(BACKUP_BATTERY_ADC_PIN);
            delayMicroseconds(200);  // Delay between readings for stability
        }

        // Sort the readings and get median
        sortBatteryData(voltageBuffer, BATTERY_SAMPLES);
        uint32_t medianReading = (uint32_t)voltageBuffer[(BATTERY_SAMPLES - 1) / 2];
        readBuffer += medianReading;

        Serial.printf("Median ADC: %d\n", medianReading);
        delay(100);  // Delay between sets for stabilization
    }

    // Calculate average of all median readings
    float avgMedianReading = (float)readBuffer / BATTERY_SAMPLES;

    // Convert to voltage using your measured ratio
    // ADC reading -> voltage at pin -> actual backup battery voltage
    float pinVoltage = (avgMedianReading / 4095.0) * 3.3;
    backupBatteryVoltage = pinVoltage * BACKUP_BATTERY_RATIO;

    // Calculate backup battery percentage
    backupBatteryPercentage = calculate_battery_percentage(backupBatteryVoltage);

    unsigned long duration = millis() - startTime;

    Serial.printf("=== Backup Battery Measurement Complete ===\n");
    Serial.printf("Total samples: %d\n", BATTERY_SAMPLES * BATTERY_SAMPLES);
    Serial.printf("Average median ADC: %.1f\n", avgMedianReading);
    Serial.printf("Pin voltage: %.3fV\n", pinVoltage);
    Serial.printf("Backup battery voltage: %.3fV\n", backupBatteryVoltage);
    Serial.printf("Backup battery percentage: %d%%\n", backupBatteryPercentage);
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

uint16_t calculateCRC(byte *data, uint8_t length) {
    uint16_t crc = 0xFFFF;

    for (uint8_t i = 0; i < length; i++) {
        crc ^= data[i];
        for (uint8_t j = 0; j < 8; j++) {
            if (crc & 0x0001) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }

    return crc;
}

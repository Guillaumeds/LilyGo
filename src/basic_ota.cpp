/*
  Basic ESP32 OTA Example
  Based on Arduino BasicOTA example
  
  This example shows the simplest way to do OTA updates on ESP32.
  
  Steps:
  1. Upload this code via USB first
  2. Connect to WiFi and note the IP address
  3. Update platformio.ini with the IP address
  4. Use wireless upload: pio run -e esp32-ota-wireless -t upload
*/

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

// WiFi credentials
const char* ssid = "Guillaume Phone";
const char* password = "0840866917";

void setup() {
  Serial.begin(115200);
  Serial.println("Booting");
  
  // Connect to WiFi
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    Serial.println("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }

  // Print IP address
  Serial.println("Ready");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  // Port defaults to 3232
  // ArduinoOTA.setPort(3232);

  // Hostname defaults to esp3232-[MAC]
  ArduinoOTA.setHostname("esp32-ota");

  // No authentication by default
  ArduinoOTA.setPassword("admin123");

  // Password can be set with it's md5 value as well
  // MD5(admin) = 21232f297a57a5a743894a0e4a801fc3
  // ArduinoOTA.setPasswordHash("21232f297a57a5a743894a0e4a801fc3");

  ArduinoOTA
    .onStart([]() {
      String type;
      if (ArduinoOTA.getCommand() == U_FLASH)
        type = "sketch";
      else // U_SPIFFS
        type = "filesystem";

      // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
      Serial.println("Start updating " + type);
    })
    .onEnd([]() {
      Serial.println("\nEnd");
    })
    .onProgress([](unsigned int progress, unsigned int total) {
      Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
    })
    .onError([](ota_error_t error) {
      Serial.printf("Error[%u]: ", error);
      if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
      else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
      else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
      else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
      else if (error == OTA_END_ERROR) Serial.println("End Failed");
    });

  ArduinoOTA.begin();
  
  Serial.println("Ready for OTA updates");
  Serial.printf("Use this IP in platformio.ini: %s\n", WiFi.localIP().toString().c_str());
  Serial.println("Password: admin123");
}

void loop() {
  ArduinoOTA.handle();
  
  // Blink LED to show it's working
  static unsigned long lastBlink = 0;
  if (millis() - lastBlink > 1000) {
    Serial.println("Running... IP: " + WiFi.localIP().toString());
    lastBlink = millis();
  }
  
  delay(100);
}

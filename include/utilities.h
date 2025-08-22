/**
 * @file      utilities.h
 * @author    LilyGO T-SIM7000G Pin Definitions
 * @license   MIT
 * @date      2025-01-21
 */

#pragma once

// LilyGO T-SIM7000G Pin Definitions
// Note: LILYGO_SIM7000G is defined in build flags

#if defined(LILYGO_SIM7000G)

    // Modem communication pins
    #define MODEM_DTR_PIN                       (25)
    #define MODEM_RX_PIN                        (26)
    #define MODEM_TX_PIN                        (27)
    #define MODEM_BAUDRATE                      (115200)

    // Power control pins
    #define BOARD_PWRKEY_PIN                    (4)
    #define BOARD_LED_PIN                       (12)
    #define LED_ON                              (LOW)

    // SPI pins for SD card
    #define BOARD_MISO_PIN                      (2)
    #define BOARD_MOSI_PIN                      (15)
    #define BOARD_SCK_PIN                       (14)
    #define BOARD_SD_CS_PIN                     (13)
    
    // ADC pins for monitoring
    #define BOARD_BAT_ADC_PIN                   (35)
    #define BOARD_SOLAR_ADC_PIN                 (36)
    
    // Serial interface for modem
    #define SerialAT                            Serial1

    // TinyGSM modem type
    #ifndef TINY_GSM_MODEM_SIM7000SSL
        #define TINY_GSM_MODEM_SIM7000SSL
    #endif

    // GPS control (SIM7000G modem GPIO)
    #define MODEM_GPS_ENABLE_GPIO               (48)
    #define MODEM_GPS_ENABLE_LEVEL              (1)
    
    // Power timing
    #define MODEM_POWERON_PULSE_WIDTH_MS        (1000)
    #define MODEM_POWEROFF_PULSE_WIDTH_MS       (1300)
    #define MODEM_START_WAIT_MS                 (3000)

    #define PRODUCT_MODEL_NAME                  "LilyGo-SIM7000G ESP32 Version"

#endif

// I2C pins (standard ESP32)
#define I2C_SDA_PIN                         (21)
#define I2C_SCL_PIN                         (22)

// Available GPIO pins for sensors
#define GPIO_PIN_18                         (18)
#define GPIO_PIN_19                         (19)
#define GPIO_PIN_23                         (23)
#define GPIO_PIN_32                         (32)
#define GPIO_PIN_33                         (33)
#define GPIO_PIN_34                         (34)
#define GPIO_PIN_39                         (39)

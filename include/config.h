#ifndef CONFIG_H
#define CONFIG_H
#include "stdint.h"
// Firmware title and version used to compare with remote version, to check if an update is needed.
// Title needs to be the same and version needs to be different --> downgrading is possible
constexpr char CURRENT_FIRMWARE_TITLE[] = "ESP32";
constexpr char CURRENT_FIRMWARE_VERSION[] = "0.0.0";
// Maximum amount of retries we attempt to download each firmware chunck over MQTT
constexpr uint8_t FIRMWARE_FAILURE_RETRIES = 12U;
// Size of each firmware chunck downloaded over MQTT,
// increased packet size, might increase download speed
constexpr uint16_t FIRMWARE_PACKET_SIZE = 32768U;
//RPC configuration
constexpr uint8_t MAX_RPC_SUBSCRIPTIONS = 1U;
constexpr uint8_t MAX_RPC_RESPONSE = 5U;
constexpr char CONNECTING_MSG[] = "Connecting to: (%s) with token (%s)";
constexpr char RPC_METHOD[] = "rpc_method";

constexpr char WIFI_SSID[] = "OXY 24H 2.4G";
constexpr char WIFI_PASSWORD[] = "oxy24hcoffee";
constexpr char TOKEN[] = "b7qjhj8epxb6mrzdbjg8";
constexpr char THINGSBOARD_SERVER[] = "app.coreiot.io";
constexpr uint16_t THINGSBOARD_PORT = 1883U;
constexpr uint16_t MAX_MESSAGE_SEND_SIZE = 512U;
constexpr uint16_t MAX_MESSAGE_RECEIVE_SIZE = 512U;
constexpr uint32_t SERIAL_DEBUG_BAUD = 115200U;
constexpr uint64_t REQUEST_TIMEOUT_MICROSECONDS = 10000U * 1000U;

// #include "pins_yolobit.h"
#define USE_MQTT
#define DHT_PIN 6
// #define USE_I2C
// #define USE_LCD1602
// #define USE_DHT20
// #define PUMP1_PIN P10
// #define PUMP2_PIN P13
// #define RGB_PIN         45
// #define ADC_MOIS_PIN    P1_ADC
// #define ADC_LIGHT_PIN   P2_ADC
#ifdef USE_I2C
#define I2C_SDA 11
#define I2C_SCL 12
#endif //USE_I2C
#endif //CONFIG_H
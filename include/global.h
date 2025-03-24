#ifndef GLOBAL_H
#define GLOBAL_H
#include <Arduino.h>
#include <SPI.h>

#define SPI2_SCK    SCK
#define SPI2_MISO   -1
#define SPI2_MOSI   MOSI
#define SPI2_SS     -1

#define SPI3_SCK    12
#define SPI3_MISO   14
#define SPI3_MOSI   13
#define SPI3_SS     11
extern SPIClass spi2;
struct TelemetryData {
    float temperature;
    float humidity;
    uint8_t light_value;
    uint8_t soil_moisture;
};
struct SharedData {
    uint8_t pump1_state;
    uint8_t pump2_state;
    uint8_t light_state;
    uint8_t tele_period;
};
extern volatile TelemetryData telemetry;
extern volatile SharedData shared;
void updateRGB();
#endif
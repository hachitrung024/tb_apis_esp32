#include "global.h"
SPIClass spi2 = SPIClass(FSPI);
volatile TelemetryData telemetry = {12.34, 12.34, 123, 123};
volatile SharedData shared = {1, 1, 1, 10};
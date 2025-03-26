#include "dht20_task.h"
#ifdef USE_DHT20
#if SOC_HP_I2C_NUM <= 1
TwoWire * I2C_Wire = &Wire;
#else
TwoWire * I2C_Wire = &Wire1;
#endif
void dht20_task (void * pvParameter){
    DHT20 dht(&Wire);
    // DHT20 dht(I2C_Wire);
    Serial.println(__FILE__);
    Serial.print("DHT20 LIBRARY VERSION: ");
    Serial.println(DHT20_LIB_VERSION);
    Serial.println();
    delay(2000);
    Serial.println("Type,\tStatus,\tHumidity (%),\tTemperature (C)");

    for(;;){
        int status = dht.read();
        switch (status)
        {
            case DHT20_OK:
            // Serial.print("OK,\t");
            break;
            Serial.print("DHT20:");
        case DHT20_ERROR_CHECKSUM:
            Serial.print("Checksum error,\t");
            break;
        case DHT20_ERROR_CONNECT:
            Serial.print("Connect error,\t");
            break;
        case DHT20_MISSING_BYTES:
            Serial.print("Missing bytes,\t");
            break;
        case DHT20_ERROR_BYTES_ALL_ZERO:
            Serial.print("All bytes read zero");
            break;
        case DHT20_ERROR_READ_TIMEOUT:
            Serial.print("Read time out");
            break;
        case DHT20_ERROR_LASTREAD:
            Serial.print("Error read too fast");
            break;
        default:
            Serial.print("Unknown error,\t");
            break;
        }
        telemetry.temperature = dht.getTemperature();
        telemetry.humidity = dht.getHumidity();

        //  DISPLAY DATA, sensor has only one decimal.
        // Serial.print(dht.getTemperature(), 1);
        // Serial.print(",\t");
        // Serial.println(dht.getHumidity(), 1);

        delay(2000);

    }
}
#endif //USE_DHT20
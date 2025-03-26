#include "dht_task.h"
#ifdef DHT_PIN
void dht_task (void * pvParameter){
    DHT dht(DHT_PIN, DHT_TYPE);
    dht.begin();
    for(;;) {
        delay(1000);
        telemetry.temperature = dht.readTemperature();
        telemetry.humidity = dht.readHumidity();
        if (isnan(telemetry.temperature) || isnan(telemetry.humidity)) {
            Serial.println(F("Failed to read from DHT sensor!"));
            delay(2000);
            continue;
        }
    }
}
#endif //DHT_PIN
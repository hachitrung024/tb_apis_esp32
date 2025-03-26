#include "send_task.h"

void send_task(void * pvParameter){
    ThingsBoard * tb = (ThingsBoard*) pvParameter;
    StaticJsonDocument<200> telemetryJson;
    for(;;){
        delay(2 * 1000);
        while(!tb->connected()){
            delay(1000);
        }
        telemetryJson.clear();
        telemetryJson["temperature"] = String(telemetry.temperature, 1);
        telemetryJson["humidity"] = String(telemetry.humidity, 1);
        tb->sendTelemetryJson(telemetryJson, Helper::Measure_Json(telemetryJson));
        // tb->Send_Json("v1/devices/me/telemetry",telemetryJson, Helper::Measure_Json(telemetryJson) );
        // tb->Send_Json("v1/gateway/telemetry",telemetryJson, Helper::Measure_Json(telemetryJson) );

    }
}
#ifndef THINGSBOARD_TASK_H
#define THINGSBOARD_TASK_H
#define CONFIG_THINGSBOARD_ENABLE_DEBUG false
#include "config.h"
#include <WiFi.h>
#include <Arduino_MQTT_Client.h>
#include <OTA_Firmware_Update.h>
#include <ThingsBoard.h>
#include <Server_Side_RPC.h>
#include <Shared_Attribute_Update.h>
#include <Attribute_Request.h>
#include <Espressif_Updater.h>
#include "tasks/send_task.h"

void thingsboard_task(void * );
void InitWiFi();
#endif //THINGSBOARD_TASK_H
#ifndef DHT_TASK_H
#define DHT_TASK_H
#include "DHT.h"
#include "config.h"
#include "global.h"
#ifndef DHT_TYPE
#define DHT_TYPE DHT11
#endif
void dht_task(void * pvParameter);

#endif
// #include "tasks/thingsboard_task.h"
// void setup() {
//   // Initalize serial connection for debugging
//   Serial.begin(SERIAL_DEBUG_BAUD);
//   delay(1000);
//   xTaskCreate(thingsboard_task, "thingsboard", 16384, NULL, 10, NULL);
// }
// void loop() {

// }
#include <Arduino.h>
#include "config.h"
#include "global.h"
#ifdef USE_MQTT
#include "tasks/thingsboard_task.h"
#endif
#ifdef DHT_PIN
#include "tasks/dht_task.h"
#endif //DHT_PIN
#ifdef USE_DHT20
#include "tasks/dht20_task.h"
#endif
#ifdef RGB_PIN
#include "FastLED.h"
CRGB leds[4];
void updateRGB(){
  FastLED.showColor(shared.rgb_bright >0 ?CRGB::White : CRGB::Black);
  FastLED.setBrightness(shared.rgb_bright);
}
#endif
#ifdef USE_LCD1602
#include "LiquidCrystal_I2C.h"
LiquidCrystal_I2C lcd(0x21, 16, 2);
void lcd1602_task(void * pvParameters){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Hello, World");
  delay(1000);
  char line1[20];
  char line2[20];
  lcd.clear();
  for(;;){
    lcd.setCursor(0, 0);
    sprintf(line1, "Temp:%.1f", telemetry.temperature);
    lcd.print(line1);
    sprintf(line2, "Humi:%.1f", telemetry.humidity);
    lcd.setCursor(0, 1);
    lcd.print(line2);
    delay(1000);
  }
}
#endif
// put function declarations here:
#ifdef ADC_LIGHT_PIN
void light_task(void * pvParameter){
  while(1){
    vTaskDelay(2000);
    telemetry.light_value = map(analogRead(ADC_LIGHT_PIN),0, 4095, 0, 100);
  }
}
#endif
#ifdef ADC_MOIS_PIN
void mois_task(void * pvParameter){
  while(1){
    vTaskDelay(2000);
    telemetry.soil_moisture = map(analogRead(ADC_MOIS_PIN),0, 4095, 0, 100);
  }
}
#endif
void setup() {
  Serial.begin(SERIAL_DEBUG_BAUD);
  // Serial1.begin(SERIAL_BAUD, SERIAL_8N1, 6, 7);
#ifdef LED_PIN
  pinMode(LED_PIN, OUTPUT);
#endif
#ifdef USE_I2C
  Wire.begin(I2C_SDA,I2C_SCL);
#endif
#ifdef PUMP1_PIN
  pinMode(PUMP1_PIN, OUTPUT);
#endif
#ifdef PUMP2_PIN
  pinMode(PUMP2_PIN, OUTPUT);
#endif
#ifdef USE_MQTT
  xTaskCreate(thingsboard_task, "MQTT", 16384, NULL, 10, NULL);
#endif
#ifdef DHT_PIN
  xTaskCreate(dht_task, "TempHumiSensor", 2048, NULL, 2, NULL);
#endif //DHT_PIN
#ifdef USE_DHT20
  xTaskCreate(dht20_task, "DHT20", 4096, NULL, 2, NULL);
#endif
#ifdef ADC_LIGHT_PIN
  xTaskCreate(light_task, "Light", 1024, NULL, 2, NULL);
#endif
#ifdef ADC_MOIS_PIN
  xTaskCreate(mois_task, "Mois", 1024, NULL, 2, NULL);
#endif
#ifdef RGB_PIN
FastLED.addLeds<NEOPIXEL, RGB_PIN>(leds, 4); 
#endif
#ifdef USE_LCD1602
  xTaskCreate(lcd1602_task, "LCD1602", 2048, NULL, 2, NULL);
#endif
}

void loop() {
  // put your main code here, to run repeatedly:

}


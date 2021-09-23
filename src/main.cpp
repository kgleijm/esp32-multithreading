// Implemented from:
//https://randomnerdtutorials.com/esp32-dual-core-arduino-ide/

#include <Arduino.h>



TaskHandle_t Task1;

void Task1code( void * parameter) {
  for(;;) {
    Serial.print("loop() running on core ");
    Serial.println(xPortGetCoreID());
    delay(500);
  }
}


void setup() {
  delay(2000);
  Serial.begin(9600);
  Serial.print("setup() running on core ");
  Serial.println(xPortGetCoreID());

  xTaskCreatePinnedToCore(
      Task1code, /* Function to implement the task */
      "Task1", /* Name of the task */
      10000,  /* Stack size in words */
      NULL,  /* Task input parameter */
      0,  /* Priority of the task */
      &Task1,  /* Task handle. */
      0); /* Core where the task should run */



}

void loop() {
  Serial.print("loop() running on core ");
  Serial.println(xPortGetCoreID());
  delay(2000);
}
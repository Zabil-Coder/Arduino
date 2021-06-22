#include <Arduino_FreeRTOS.h>
#include "task.h"

void print_ms(void*);

void setup() {
  Serial.begin(9600);
  if(xTaskCreate(print_ms, "print_func", 100, NULL, 1, NULL) != pdPASS)
    Serial.println("Task not created");
  else
    Serial.println("Task created successfully");
  
}


void loop() {
  
}

void print_ms(void *param)
{
  const TickType_t xperiod = pdMS_TO_TICKS(2000);
  TickType_t xlast = xTaskGetTickCount();
  
  while(1){
    Serial.println("Hello! I was created by Zabil and L1F17BSCS0361");
    vTaskDelayUntil(&xlast, xperiod);
  }
  
}

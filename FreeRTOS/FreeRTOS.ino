#include <Arduino_FreeRTOS.h>
const int a_pin = 2, b_pin = 3, c_pin = 4, d_pin = 5, e_pin = 6, f_pin = 7, g_pin = 8;
int Count_data_G = 0;
TaskHandle_t xTaskA;

void xPrintTask();    //TASK 1
void xPrintSegment(); //TASK 2
void xIncCount();     //TASK 3

void clearSegment();
void zeroSegment();
void oneSegment();
void twoSegment();
void threeSegment();
void fourSegment();
void fiveSegment();
void sixSegment();
void sevenSegment();
void eightSegment();
void nineSegment();
void numberToSegment(int);



void setup()
{
    pinMode(a_pin, OUTPUT);
    pinMode(b_pin, OUTPUT);
    pinMode(c_pin, OUTPUT);
    pinMode(d_pin, OUTPUT);
    pinMode(e_pin, OUTPUT);
    pinMode(f_pin, OUTPUT);
    pinMode(g_pin, OUTPUT);
    Serial.begin(9600);
    BaseType_t task_a = xTaskCreate(xPrintTask, "Task_A", 100, NULL, 1, &xTaskA);
    BaseType_t task_b = xTaskCreate(xPrintSegment, "Task_B", 100, NULL, 1, NULL);
    BaseType_t task_c = xTaskCreate(xIncCount, "Task_B", 100, NULL, 1, NULL);
    if(task_a != pdPASS || task_b != pdPASS || task_c != pdPASS)
    {
       Serial.println("Tasks not created");  
       vTaskSuspendAll();
    }
    else
      Serial.println("Tasks created successfully");
}

void loop()
{
   
}

void xPrintTask()
{
  const TickType_t xperiod = pdMS_TO_TICKS(2000);
  TickType_t xlast = xTaskGetTickCount();
  
  while(1){
    Serial.println("Hello! I was created by Zabil and L1F17BSCS0361");
    vTaskDelayUntil(&xlast, xperiod);
  }
  
}

void xPrintSegment()
{
  const TickType_t ticks = 2;
  
  while(1){
    numberToSegment(Count_data_G);
    vTaskDelay(ticks);
  }
}

void xIncCount()
{
  const TickType_t xperiod = pdMS_TO_TICKS(1000);
  TickType_t xlast = xTaskGetTickCount();
   while(1){
      Count_data_G++; 
      if(Count_data_G >= 7)
      {
        Count_data_G = 0;
        vTaskSuspend(xTaskA);
      }
      vTaskDelayUntil(&xlast, xperiod);
   }
}

void clearSegment()
{
    digitalWrite(a_pin, LOW);
    digitalWrite(b_pin, LOW);
    digitalWrite(c_pin, LOW);
    digitalWrite(d_pin, LOW);
    digitalWrite(e_pin, LOW);
    digitalWrite(f_pin, LOW);
    digitalWrite(g_pin, LOW);
}

void zeroSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(e_pin, HIGH);
    digitalWrite(f_pin, HIGH);
}

void oneSegment()
{
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
}

void twoSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(e_pin, HIGH);
    digitalWrite(d_pin, HIGH);
}

void threeSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
}

void fourSegment()
{
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
}

void fiveSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
}

void sixSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(e_pin, HIGH);
}

void sevenSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
}

void eightSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(e_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
}

void nineSegment()
{
    digitalWrite(a_pin, HIGH);
    digitalWrite(b_pin, HIGH);
    digitalWrite(c_pin, HIGH);
    digitalWrite(d_pin, HIGH);
    digitalWrite(f_pin, HIGH);
    digitalWrite(g_pin, HIGH);
}

void numberToSegment(int number)
{
    clearSegment();  
    switch (number)
    {
    case 0:
        zeroSegment();
        break;
    case 1:
        oneSegment();
        break;
    case 2:
        twoSegment();
        break;
    case 3:
        threeSegment();
        break;
    case 4:
        fourSegment();
        break;
    case 5:
        fiveSegment();
        break;
    case 6:
        sixSegment();
        break;
    case 7:
        sevenSegment();
        break;
    case 8:
        eightSegment();
        break;
    case 9:
        nineSegment();
        break;
    default:
        clearSegment();
        break;
    }
}

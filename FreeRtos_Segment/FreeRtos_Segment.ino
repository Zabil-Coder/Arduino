#include <Arduino_FreeRTOS.h>
const int a_pin = 2, b_pin = 3, c_pin = 4, d_pin = 5, e_pin = 6, f_pin = 7, g_pin = 8;
int Count_data_G = 0;

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
void xPrintSegment();

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
    if(xTaskCreate(xPrintSegment, "print_func", 100, NULL, 1, NULL) != pdPASS)
      Serial.println("Task not created");
    else
      Serial.println("Task created successfully");
}

void loop()
{
   
}

void xPrintSegment()
{
  const TickType_t ticks = 2;
  
  while(1){
    if(Serial.available())
      Count_data_G = Serial.read() - '0';
    if(Count_data_G >= 0 && Count_data_G <= 9) 
        numberToSegment(Count_data_G);
    vTaskDelay(ticks);
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

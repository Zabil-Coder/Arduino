/*program for tick rate of 10ms.
created by Zabil on 31 May 2021
program will toggle on board light after 10ms
*/

const short int led_pin = 13;   //built_in pin
const int tick_rate = 10;       //10ms
int previous = 0, current = 0;

void setup()
{
    pinMode(led_pin, OUTPUT);
}

void loop()
{
    current = millis();
    if(current - previous >= tick_rate){
      previous += tick_rate;  
      digitalWrite(led_pin, !digitalRead(led_pin));  
    }
}

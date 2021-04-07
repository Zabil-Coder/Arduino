const int led_pin = 10;

int brightness = 0;
bool inc_flag = true;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  
  switch(brightness){
    case 0:
      inc_flag = true;
      break;
    case 255:
      inc_flag = false;  
      break;
  }

  analogWrite(led_pin, brightness);
  
  if(inc_flag)
    brightness += 5;
  else
    brightness -= 5;
  
  delay(20);
 
}

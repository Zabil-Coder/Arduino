int old = 0, curr = 0;

void setup()
{
}

void loop()
{
    curr = millis();
    if(curr - old >= 10)
      old += 10;  
    
}

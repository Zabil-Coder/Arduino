int hh = 0, mm = 0, ss = 0;
char clock_str[10];

void setTime();
void verifyTime();
void updateTime();

void setup() {
  Serial.begin(9600);
  Serial.println("For setting time, enter in format: hh:mm:ss");
}

void loop() {
  if(Serial.available()) {
    setTime();
    verifyTime();
    Serial.println("Your new time is: ");
  } 
  updateTime();
  delay(1000);
}


void verifyTime() {
  if(hh < 0 || hh > 23)
  {
    Serial.println("hours are not correct so set to zero");
    hh = 0;
  }
  if(mm < 0 || mm > 59)
  {
    Serial.println("minutes are not correct so set to zero");
    mm = 0;
  }
   if(ss < 0 || ss > 59)
  {
    Serial.println("seconds are not correct so set to zero");
    ss = 0;
  }
}

void setTime()
{
   String set_time = Serial.readString();
    char *token = strtok(set_time.c_str(), ":");
    int i = 0; //keep track of string
    while(token != NULL) {
      if(i == 0)
        hh = atoi(token);
      else if(i == 1)
        mm = atoi(token);
      else
        ss = atoi(token);
      token = strtok(NULL, ":");
      i++;
    }
}

void updateTime()
{
  sprintf(clock_str,"%d:%d:%d", hh, mm, ss);
  ss++;
  if(ss == 60) {
    ss = 0;
    mm++;
  }
  if(mm == 60) {
    mm = 0;
    hh++;
  }
  if(hh == 24) {
    hh = 0;
  }
  Serial.println(clock_str);
}

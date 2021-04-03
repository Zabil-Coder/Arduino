int led_pin = 3;
void setup()
{
  pinMode(led_pin, OUTPUT);
}

void loop()
{
  digitalWrite(led_pin, HIGH);
  delay(200);
  digitalWrite(led_pin, LOW);
  delay(200);
  digitalWrite(led_pin, HIGH);
  delay(200);
  digitalWrite(led_pin, LOW);
  delay(1400);
}

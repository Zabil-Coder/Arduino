/* led 1 on pin 3 timing: .5s on and .5s off
 * led 2 on pin 4 timing: .75s on and 1.25s off
 */
int led1_pin = 3, led2_pin = 4;
void setup()
{
  pinMode(led1_pin, OUTPUT);
  pinMode(led2_pin, OUTPUT);
}

void loop()
{
  digitalWrite(led1_pin, HIGH);
  digitalWrite(led2_pin, HIGH);
  delay(500);                   //time .5s
  digitalWrite(led1_pin, LOW);  //off led 1 after .5s
  delay(250);                   //led 1 time off .25s, time .75s
  digitalWrite(led2_pin, LOW);  //off led 2 after .75s
  delay(250);                   //led 1 time .5s, led 2 time .25s
  digitalWrite(led1_pin, HIGH); //on led 1 after .5s
  delay(500);                   //led 2 time .75s
  digitalWrite(led1_pin, LOW);  //off led 1 after .5s, total time .75s
  delay(500);                   //led 2 time 1.25s
  /*led 1 on after .5s, led 2 on after 1.25s*/
}

int i=0;
void setup() {
  Serial.begin(9600);
  Serial.print("Hello Zabil\n");
}

void loop() {
  Serial.print(i);
  Serial.print("\n");
  delay(500);
  i++;
}

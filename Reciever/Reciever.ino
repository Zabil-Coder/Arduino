#include <printf.h>
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <SPI.h>
#include <Servo.h>

int yawX,  pitchY, thrust;
int x, y;
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";
void print_values();

Servo pitch, yaw, aileronL, aileronR; 

void setup()
{
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.startListening();
  pitch.attach(3); 
  yaw.attach(5);
  aileronL.attach(6);
  aileronR.attach(10);
}

void loop()
{
  if (radio.available())
  {
    radio.read(&yawX, sizeof(int));
    radio.read(&pitchY, sizeof(int));
    radio.read(&thrust, sizeof(int));
    x = map(yawX, 0, 1023, 0, 180);
    y = map(pitchY, 0, 1023, 0, 180);
    yaw.write(x);
    pitch.write(y);
    print_values();
    if (x == 0 && y == 0) //roll right
    {
      //left alieron down, right alieron up
      aileronL.write(0);
      aileronR.write(180);
      Serial.println("\tRoll Right");
    }
    if (x == 0 && y == 180) //roll left
    {
      //left alieron up, right alieron down
      aileronL.write(180);
      aileronR.write(0);
      Serial.println("\tRoll Left");
    }
    delay(100);
  }
  
  
  
  
}


void print_values()
{
  Serial.print("Yaw: ");
  Serial.print(yawX);
  Serial.print("\tPitch: ");
  Serial.print(pitchY);
  Serial.print("\tTrust: ");
  Serial.println(thrust);
}

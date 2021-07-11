#include <printf.h>
#include <RF24_config.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <SPI.h>

#define joyX A0
#define joyY A1
#define potMeter A2 //potentiometer

int yawX,  pitchY, thrust;
RF24 radio(9, 8);  // CE, CSN

//address through which two modules communicate.
const byte address[6] = "00001";

void print_values()
{
  Serial.print("Yaw: ");
  Serial.print(yawX);
  Serial.print("\tPitch: ");
  Serial.print(pitchY);
  Serial.print("\tTrust: ");
  Serial.println(thrust);
}

void setup()
{
   Serial.begin(9600);
  radio.begin();
  
  //set the address
  radio.openWritingPipe(address);
  
  //Set module as transmitter
  radio.stopListening();
}
void loop()
{
  yawX = analogRead(joyX);
  pitchY = analogRead(joyY);
  thrust = analogRead(potMeter);
  radio.write(&yawX, sizeof(int));
  radio.write(&pitchY, sizeof(int));
  radio.write(&thrust, sizeof(int));
  print_values();
}

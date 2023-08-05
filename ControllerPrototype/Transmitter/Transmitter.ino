#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

int potval;
int spos;
RF24 radio(7,8); //CNS,CE

const byte address[6] = "00001";

void setup() {
  // put your setup code here, to run once:
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  Serial.begin(9600);
  pinMode(A1,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval = analogRead(A1);
  Serial.println(potval);
  radio.write(&potval, sizeof(potval));
  
}

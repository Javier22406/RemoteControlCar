#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>
#include <Servo.h>
Servo servo;
RF24 radio(7,8);

const byte address[6] = "00001";

int spos;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();

  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (radio.available()) {
    int potval = "";
    radio.read(&potval, sizeof(potval));
    spos = map(potval, 0,1053,0,180);
    Serial.println(spos);
    if ( 90 < spos <80) { 
      servo.write(spos);
    }
  }
}

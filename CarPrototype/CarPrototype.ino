#include <Servo.h>
int servopin=34;
int servopos;
Servo myservo;

int fpin2=7;
int bpin2=8;
int spin2=6;

int fpin=2; 
int bpin=4;
int spin=3;
int speed;

int spin3=9;
int fpin3=12;
int bpin3=11;

int fpin4=5;
int bpin4=22;
int spin4=10;

int xpin=A0;
int ypin=A1;
int swpin=13;
int xval;
int yval;
int bval;
int dt=500;

void setup() {
  // put your setup code here, to run once:
  pinMode(fpin,OUTPUT);
  pinMode(bpin,OUTPUT);
  pinMode(spin,OUTPUT);
  Serial.begin(9600);
  pinMode(fpin2,OUTPUT);
  pinMode(bpin2,OUTPUT);
  pinMode(spin2,OUTPUT);
  pinMode(fpin3,OUTPUT);
  pinMode(bpin3,OUTPUT);
  pinMode(spin3,OUTPUT);
  pinMode(fpin4,OUTPUT);
  pinMode(bpin4,OUTPUT);
  pinMode(spin4,OUTPUT);
  
  pinMode(xpin,INPUT);
  pinMode(ypin,INPUT);
  pinMode(swpin,INPUT);
  digitalWrite(bpin,HIGH);

  myservo.attach(servopin);
}

void loop() {
  // put your main code here, to run repeatedly:
  xval=analogRead(xpin);
  yval=analogRead(ypin);
  bval=digitalRead(swpin);
  Serial.print("Xvalue= ");
  Serial.print(xval);
  Serial.print(" Yvalue= ");
  Serial.print(yval);
  Serial.print(" Bvalue= ");
  Serial.println(bval); 

if (yval<507){
  speed=.000849*pow((yval-508),2);
  digitalWrite(fpin,HIGH);
  digitalWrite(bpin,LOW);
  analogWrite(spin,speed);
  
  digitalWrite(fpin2,HIGH);
  digitalWrite(bpin2,LOW);
  analogWrite(spin2,speed);

  digitalWrite(fpin3,HIGH);
  digitalWrite(bpin3,LOW);
  analogWrite(spin3,speed);

  digitalWrite(fpin4,LOW);
  digitalWrite(bpin4,HIGH);
  analogWrite(spin4,speed);
  }
if(yval>506){ 
  speed=.000849*pow((yval-508),2);
  digitalWrite(fpin,LOW);
  digitalWrite(bpin,HIGH);
  analogWrite(spin,speed);

  digitalWrite(fpin2,LOW);
  digitalWrite(bpin2,HIGH);
  analogWrite(spin2,speed);

  digitalWrite(fpin3,LOW);
  digitalWrite(bpin3,HIGH);
  analogWrite(spin3,speed);
 
  digitalWrite(fpin4,HIGH);
  digitalWrite(bpin4,LOW);
  analogWrite(spin4,speed);
  }
 
  xval=analogRead(xpin);
  servopos=(180./1055.)*xval;
  Serial.println(servopos);
  myservo.write(servopos);
}

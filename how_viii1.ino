#include <Servo.h>

int distanciaCm = 0;
int pos;
int pinoSensorForca = A0;
int pinoServo = 2;
int valorForca;
int i = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  digitalWrite(triggerPin, HIGH);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

Servo servo_2;

void setup()
{
  servo_2.attach(2);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop()
{
  digitalWrite(7, LOW);
  digitalWrite(6, LOW);
  digitalWrite(5, LOW);
  distanciaCm = 0.01720 * readUltrasonicDistance(3, 4);
  if (distanciaCm < 15) {
    digitalWrite(7, HIGH);
  }
  if (distanciaCm >= 15 && distanciaCm < 30) {
    digitalWrite(6, HIGH);
  }
  if (distanciaCm >= 30) {
    digitalWrite(5, HIGH);
  }
  pos = 90;
  valorForca = analogRead(pinoSensorForca);
  if (valorForca > 140) {
   	pos = 0;
   	servo_2.write(pos);
   	delay(15);
  }
  else
    pos = 90;
  	servo_2.write(pos);
  	delay(15);
}
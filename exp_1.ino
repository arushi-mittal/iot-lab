#include <Servo.h>
float dist;
Servo servo;
  
void isr () {
  servo.write(90);
}

long readDist (int triggerPin,int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}
  
void setup()
{
  Serial.begin(9600);
  pinMode(2, OUTPUT);
  pinMode(5, OUTPUT);
  servo.attach(5);
  attachInterrupt(digitalPinToInterrupt(2), isr, HIGH);
}

void loop()
{	
	dist = readDist(7, 6) * 0.01723;
  	if (dist < 50) {
		digitalWrite(2, HIGH);
    }
  	else {
      servo.write(0);
	  digitalWrite(2, LOW);
    }
    delay(1000);
    digitalWrite(2, LOW);
  	delay(1000);
}
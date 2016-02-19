#include "Ping.h"

Ping::Ping()
{
  
}

Ping::Ping(int trigPin, int echoPin)
{
  this->trigPin = trigPin;
  this->echoPin = echoPin;
}

// samples for ping distance every 100us
double Ping::Read()
{
  double duration;
  double cm;
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);

  //delay(100);
  return cm;
}

double Ping::microsecondsToCentimeters(double microseconds) 
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29.387 / 2;
}

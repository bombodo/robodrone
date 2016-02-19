#ifndef PING_H
#define PING_H
#include "Arduino.h"

class Ping
{
  private:
  int trigPin;
  int echoPin;
  
  public:
  Ping();
  Ping(int, int);
  double microsecondsToCentimeters(double);
  double Read(); 
};

#endif // PING_H

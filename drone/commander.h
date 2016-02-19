#ifndef COMMANDER_H
#define COMMANDER_H
#include "Imu.h"
#include "Ping.h"
#include "Arduino.h"

class Commander
{
  private:
  Imu* imu;
  Ping* pingF;
  Ping* pingB;
  Ping* pingL;
  Ping* pingR;
  
  public:
  Commander();
  void Run();
  int Listen();
  void checkFlags(bool[]);
};

#endif // COMMANDER_H

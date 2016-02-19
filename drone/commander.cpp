#include "commander.h"

Commander::Commander()
{
  Imu* imu = new Imu();
  Ping* pingF = new Ping(2,3);
  Ping* pingB = new Ping(4,5);
  Ping* pingL = new Ping(6,7);
  Ping* pingR = new Ping(8,9);
}

void Commander::Run()
{
  //WaveLeft wl;
  int value = 0;
  int lastValue = 0;
  int lastGoodValue = 0;
  int count = 0;
  double seconds;
  unsigned long time1 = 0;
  unsigned long time2 = 0;
  unsigned long timeMilli = 0;

  while(0<1)
  {
  //---------------------------
    int value = Listen();
      
    if(value == 0 && lastValue != 0)
    {
      time1 = millis();
      value = lastGoodValue;
    }

    if(value == 0 && lastValue == 0)
    {
      time2 = millis();
      timeMilli = (time2 - time1);

      if(timeMilli < 2000)
      {
        value = lastGoodValue;
        //Act as if good value was recieved for 2 seconds
      }

      //implicit else - system will begin to idle
    }

    //if(value != 0)
      //lastGoodValue = value;
      
    //if(value==0)
      //do nothing

    //if(value == 1)
      //wl.Run();

  //---------------------------
   }
}

int Commander::Listen()
{
  int value = 0;
  
  if(Serial.available())
  {
    value = Serial.parseInt();
  }
  
  return value;
}

// flag array values:
// 0 - imu accel and mag data
// 1 - imu gyro data
// 2 - ping data
void Commander::checkFlags(bool flags[])
{
  double r = imu->getRoll();
  double p = imu->getPitch();
  double h = imu->getHeading();
  double x = imu->getXAcceleration();
  double y = imu->getYAcceleration();
  double z = imu->getZAcceleration();
  double distF = pingF->Read();
  
  // print only imu accel and mag data
  if(flags[0] == true && flags[1] == false) {
    Serial.println("Roll: " + String(r) + "   Pitch: " + String(p) + "   Heading: " + String(h));
  }
  // print only imu gyro data
  else if(flags[1] == true && flags[0] == false) {
    Serial.println("AccelX: " + String(x) + "   AccelY: " + String(y) + "   AccelZ: " + String(z));
  }
  // print both imu accel/mag data and gyro data
  else if(flags[0] == true && flags[1] == true) {
    Serial.println("Roll: " + String(r) + "   Pitch: " + String(p) + "   Heading: " + String(h));
    Serial.println("AccelX: " + String(x) + "   AccelY: " + String(y) + "   AccelZ: " + String(z));
  }
  
  // print ping data
  if(flags[2] == true) {
    if (distF >= 200 || distF <= 0) {
      Serial.println("front out of range");
    } else {
      Serial.println("Front Distance: " + String(distF) + "cm");
    }
  }
  Serial.println("test");
  Serial.println();
}



#include <Adafruit_9DOF.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>


/*
 * Welcome to the SMU Robotics Drone System.
 * If you see this message, chances are you are using the Arduino IDE. Congratulations!
 * All work will be execute through this system!
 * Peace and Love,
 * Andrew Timmins
 */

#include "Arduino.h"
#include "commander.h"

Commander* com = new Commander(); // initialize new commander
bool flags[3]; // flags array
bool v = true; // show verbose

void setup() 
{
  // initialize serial communication:
  Serial.begin(9600);
  
  // verbose flags
  flags[0] = true; // imu accel and mag data
  flags[1] = true; // imu gyro data
  flags[2] = true; // ping data
}

void loop() 
{
  if (v) com->checkFlags(flags);
  delay(500);
}



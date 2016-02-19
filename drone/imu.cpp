#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <Adafruit_L3GD20_U.h>
#include <Adafruit_9DOF.h>
#include "Imu.h"

Adafruit_9DOF dof   = Adafruit_9DOF();
Adafruit_LSM303_Accel_Unified accel = Adafruit_LSM303_Accel_Unified(30301);
Adafruit_LSM303_Mag_Unified mag   = Adafruit_LSM303_Mag_Unified(30302);
Adafruit_L3GD20_Unified gyro  = Adafruit_L3GD20_Unified(20);

sensors_event_t accel_event;
sensors_event_t mag_event;
sensors_vec_t   orientation;
sensors_event_t gyroevent;

Imu::Imu()
{
  initSensors();
}

// initialize pitch, roll, heading, and gyro
void Imu::initSensors()
{
  if(!accel.begin()) {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println(F("Ooops, no LSM303 detected ... Check your wiring!"));
    while(1);
  }
  if(!mag.begin()) {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
    while(1);
  }
  if(!gyro.begin()) {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.print("Ooops, no L3GD20 detected ... Check your wiring or I2C ADDR!");
    while(1);
  }
}

// accelerometer X axis data
double Imu::getRoll()
{
  double roll;
  
  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
    roll = double(orientation.roll);
  return roll;
}

// accelerometer Y axis data
double Imu::getPitch()
{
  double pitch;

  accel.getEvent(&accel_event);
  if (dof.accelGetOrientation(&accel_event, &orientation))
    pitch = double(orientation.pitch);
  return pitch;
}

// magnetometer Z axis data
double Imu::getHeading()
{
  double heading;

  mag.getEvent(&mag_event);
  if (dof.magGetOrientation(SENSOR_AXIS_Z, &mag_event, &orientation))
    heading = double(orientation.heading);
  return heading;
}

// gyro X axis data
double Imu::getXAcceleration()
{
  double accelX;
  
  gyro.getEvent(&gyroevent);
  accelX = double(gyroevent.gyro.x);
  return accelX;
}

// gyro Y axis data
double Imu::getYAcceleration()
{
  double accelY;
  
  gyro.getEvent(&gyroevent);
  accelY = double(gyroevent.gyro.y);
  return accelY;
}

// gyro Z axis data
double Imu::getZAcceleration()
{
  double accelZ;
  
  gyro.getEvent(&gyroevent);
  accelZ = double(gyroevent.gyro.z);
  return accelZ;
}


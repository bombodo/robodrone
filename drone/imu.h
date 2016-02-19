#ifndef IMU_H
#define IMU_H

class Imu
{
  private:
  
  public:
  Imu();
  void initSensors();
  double getRoll();
  double getPitch();
  double getHeading();
  double getXAcceleration();
  double getYAcceleration();
  double getZAcceleration();
};

#endif // IMU_H

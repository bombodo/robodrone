#include "Arduino.h"
#include "commander.h"
#include "Imu.h"
#include "WaveLeft.h"

WaveLeft::WaveLeft()
{

}

void WaveLeft::Run()
{
    Imu mvmt;
    double roll = mvmt.getRoll();
    double pitch = mvmt.getPitch();
    double heading = mvmt.getHeading();  

    Serial.print(F("Roll: "));
    Serial.print(roll);
    Serial.print(F("; "));
    Serial.print(F("Pitch: "));
    Serial.print(pitch);
    Serial.print(F("; "));
    Serial.print(F("Heading: "));
    Serial.print(heading);
    Serial.println(F("; "));

    double xAcc = mvmt.getXAcceleration();
    double yAcc = mvmt.getYAcceleration();
    double zAcc = mvmt.getZAcceleration();  

    Serial.print(F("x: "));
    Serial.print(xAcc);
    Serial.print(F(" rad/s; "));
    Serial.print(F("y: "));
    Serial.print(yAcc);
    Serial.print(F(" rad/s; "));
    Serial.print(F("z: "));
    Serial.print(zAcc);
    Serial.println(F(" rad/s; "));
    Serial.println(F(""));

    delay(1000);
}


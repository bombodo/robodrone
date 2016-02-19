#include <Servo.h>

Servo rearL;
Servo rearR;
Servo frontL;
Servo frontR;

int spd = 0;
int pot = A0;

//bool prime = false;

void setup() {
  frontL.attach(6);
  frontR.attach(7);
  rearL.attach(8);
  rearR.attach(9);
  Serial.begin(9600);
}

void loop() {
    spd = analogRead(pot);
    spd = map(spd, 0, 1023, 0, 180);
    Serial.println(spd);
    
    frontL.write(spd);
    frontR.write(spd);
    rearL.write(spd);
    rearR.write(spd);
    delay(2000);
}

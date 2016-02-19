#define trigPin 2
#define echoPin 3

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  double duration;
  double inches;
  double cm;
  
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
  inches = microsecondsToInches(duration) + 0.25;
  cm = microsecondsToCentimeters(duration);
  if (cm >= 200 || cm <= 0) {
    Serial.println("out of range");
  } else {
    Serial.print(inches);
    Serial.print("in, ");
    Serial.print(cm);
    Serial.print("cm");
    Serial.println();
  }

  delay(100);
}

double microsecondsToInches(double ms) {
  return ms / 74.642 / 2;
}

double microsecondsToCentimeters(double ms) {
  return ms / 29.387 /2;
}


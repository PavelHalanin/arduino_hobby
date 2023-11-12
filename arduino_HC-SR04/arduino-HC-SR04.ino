/*
Items:
- Arduino UNO R3
- Papa-mama (4 pieces)
- HC-SR04

[Vcc]----[5V]
[Trig]---[D3]
[Echo]---[D2]
[Gnd]----[GND]
*/

int echoPin = 2;
int trigPin = 3;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  int duration, cm, inch;

  // Generation of a short pulse with a duration of 2 microseconds
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Within 10 microseconds, the sensor sends signals at 40 kHz
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Getting the delay time from the Echo output
  duration = pulseIn(echoPin, HIGH);

  cm = duration / 58;
  inch = duration / 148;

  Serial.print("Centimeters: ");
  Serial.print(cm);
  Serial.print("\t");
  Serial.print("Inches: ");
  Serial.print(inch);
  Serial.print("\n");
}

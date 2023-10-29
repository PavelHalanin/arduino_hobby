/*
Items:
- Arduino UNO R3
- BreadBoard MB-1022
- 10K

+---+[10K]+---[5V]
|
|
|
+---+---------[pin 3]
    |
    |    +--------+
    |    |        |
    +---+|        |+-
         | BUTTON |
    +---+|        |+-
    |    |        |
    |    +--------+
    |
    +---------[GND]
*/

boolean isButtonClick = false;

void setup() {
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
}

void loop() {
  const int buttonSignal = digitalRead(3);
  setButton(buttonSignal);
}

void setButton(int buttonSignal) {
  if (isButtonClick && buttonSignal == 1) {
    isButtonClick = false;
    Serial.println("Button 1");
    return;
  }
  
  if (!isButtonClick && buttonSignal == 0) {
    isButtonClick = true;
    Serial.println("Button 0");
    return;
  }
}

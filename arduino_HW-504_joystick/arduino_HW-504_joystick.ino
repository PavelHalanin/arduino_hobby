/*
Items:
- Arduino UNO R3
- HW-504 joystick
- papa-mama (5 pieces)

        +-------------------------------+
        |            **********         |
[GDN]---|GDN     ****          ****     |
        |      **                  **   |
 [5V]---|+5V  **                    **  |
        |    **                      ** |
 [A0]---|VRx **                      ** |
        |    **                      ** |
 [A1]---|VRy  **                    **  |
        |      **                  **   |
 [D2]---|SW      ****          ****     |
        |            **********         |
        +-------------------------------+
*/

const int pinX = A0;
const int pinY = A1;
const int pinButton = 2;

void setup() {
  Serial.begin(9600);

  pinMode(pinX, INPUT);
  pinMode(pinY, INPUT);
  pinMode(pinButton, INPUT_PULLUP);
}

void loop() {
  int XValue = analogRead(pinX);
  int YValue = analogRead(pinY);

  Serial.print(XValue);
  Serial.print("\t");

  Serial.print(YValue);
  Serial.print("\t");

  digitalRead(pinButton) ? Serial.print("Button not pressed") : Serial.print("Button pressed");
  Serial.println();
}

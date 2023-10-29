/*
Items:
- Arduino UNO R3
- Keyboard 4x4

[pin 9]---[C4]
[pin 8]---[C3]
[pin 7]---[C2]
[pin 6]---[C1]
[pin 5]---[R1]
[pin 4]---[R2]
[pin 3]---[R3]
[pin 2]---[R4]
*/

#include <Key.h>
#include <Keypad.h>

const byte ROWS = 4;
const byte COLS = 4;

char MatrixKeyPad[ROWS][COLS] = {
  { 'a', 'b', 'c', 'd' },
  { 'e', 'f', 'g', 'h' },
  { 'i', 'j', 'k', 'l' },
  { 'm', 'n', 'o', 'p' }
};

byte rowPins[ROWS] = { 6, 7, 8, 9 };
byte colPins[COLS] = { 5, 4, 3, 2 };

Keypad customKeypad = Keypad(makeKeymap(MatrixKeyPad), colPins, rowPins, COLS, ROWS);

void setup() {
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();
  buttonsLogic(customKey);
}

void buttonsLogic(char customKey) {
  switch (customKey) {
    case 'a':
      Serial.println("S1");
      return;
    case 'b':
      Serial.println("S2");
      return;
    case 'c':
      Serial.println("S3");
      return;
    case 'd':
      Serial.println("S4");
      return;
    case 'e':
      Serial.println("S5");
      return;
    case 'f':
      Serial.println("S6");
      return;
    case 'g':
      Serial.println("S7");
      return;
    case 'h':
      Serial.println("S8");
      return;
    case 'i':
      Serial.println("S9");
      return;
    case 'j':
      Serial.println("S10");
      return;
    case 'k':
      Serial.println("S11");
      return;
    case 'l':
      Serial.println("S12");
      return;
    case 'm':
      Serial.println("S13");
      return;
    case 'n':
      Serial.println("S14");
      return;
    case 'o':
      Serial.println("S15");
      return;
    case 'p':
      Serial.println("S16");
      return;
  }
}

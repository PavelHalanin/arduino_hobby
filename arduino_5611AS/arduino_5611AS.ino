/*
Items:
- Arduino UNO R3
- LED 7-segment display 5611AS
- BreadBoard MB-1022
- 220R

   +---------------------- [pin 8]
   |  +------------------- [pin 7]
   |  |  + ----+[220R]+----[GND]---+
   |  |  |  +------------- [pin 2] |
   |  |  |  |  + --------- [pin 3] |
   |  |  |  |  |                   |
   G  F  ~  A  B                   |
   |  |  |  |  |                   |
+--+--+--+--+--+--+                |
|  FF AAAAAA BB   |                |
|  FF        BB   |                |
|  FF        BB   |                |
|  FF        BB   |                |
|   GGGGGGGGG     |                |
|  EE        CC   |                |
|  EE        CC   |                |
|  EE        CC   |                |
|  EE DDDDDD CC DP|                |
+--+--+--+--+--+--+                |
   |  |  |  |  |                   |
   E  D GDN C  DP                  |
   |  |  |  |  + --------- [pin 9] |
   |  |  |  +------------- [pin 4] |
   |  |  + ----+[220R]+------------+
   |  +------------------- [pin 5]
   +---------------------- [pin 6]
*/

void writeNumber(int number, int d = 500);

void setup() {
  for (int i = 2; i <= 9; ++i) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  for (int i = 0; i <= 10; ++i) {
    writeNumber(i, 1000);
  }
}

/*
writeNumber(-2) => do nothing
writeNumber(-1) => do nothing
writeNumber(0) => 0
writeNumber(1) => 1
writeNumber(2) => 2
writeNumber(3) => 3
writeNumber(4) => 4
writeNumber(5) => 5
writeNumber(6) => 6
writeNumber(7) => 7
writeNumber(8) => 8
writeNumber(9) => 9
writeNumber(10) => .
writeNumber(11) => do nothing
writeNumber(12) => do nothing
*/
void writeNumber(int number, int d) {
  const int ledNumbers[11][8] = {
    {1,1,1,1,1,1,0,0},
    {0,1,1,0,0,0,0,0},
    {1,1,0,1,1,0,1,0},
    {1,1,1,1,0,0,1,0},
    {0,1,1,0,0,1,1,0},
    {1,0,1,1,0,1,1,0},
    {1,0,1,1,1,1,1,0},
    {1,1,1,0,0,0,0,0},
    {1,1,1,1,1,1,1,0},
    {1,1,1,1,0,1,1,0},
    {0,0,0,0,0,0,0,1}
};

  if (number < 0 || number > 10) {
    return;
  }

  for (int i = 0; i <= 7; ++i) {
    if (ledNumbers[number][i]) {
      digitalWrite(i + 2, HIGH);
      continue;
    }
    digitalWrite(i + 2, LOW);
  }

  delay(d);
}

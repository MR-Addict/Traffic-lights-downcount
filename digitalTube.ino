int ledCount = 11;
const unsigned char DuanMa[10 + 6] = {0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};
int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
                };

void setup() {
  for (int thisLed = 0; thisLed < ledCount; thisLed++) {
    pinMode(ledPins[thisLed], OUTPUT);
  }
}

void loop() {
  digitalWrite(10, HIGH);
  downCount(9);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  downCount(2);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  downCount(9);
  digitalWrite(12, LOW);
}

void deal(unsigned char value) {
  for (int i = 0; i < 8; i++)
    digitalWrite(ledPins[i], bitRead(value, i));
  delay(1000);
}

void downCount(int val) {

  for (int i = val; i >= 0; i--) {
    deal(DuanMa[i]);
    delay(1000);
  }
}

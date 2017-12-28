const uint8_t pinSize = 10;
const uint8_t pins[pinSize] = {0, 1, 2, 3, 4, 5, 10, 9, 8, 7};
void setup() {
  // put your setup code here, to run once:
  for(uint8_t i = 0; i < pinSize; i++) pinMode(pins[i], OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(uint8_t i = 0; i < pinSize; i++) {
    digitalWrite(pins[i], 1);
    delay(200);
    digitalWrite(pins[i], 0);
    delay(200);
  }
}

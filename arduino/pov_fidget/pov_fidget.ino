#define FRAME_DELAY 2 
#define CHAR_DELAY 7 
#define TEXT_DELAY 15
#define BTN_PIN 6
const uint8_t pinSize = 10;
const uint8_t pins[pinSize] = {0, 1, 2, 3, 4, 5, 10, 9, 8, 7};
const uint16_t E[] = {3, 0b1111111111, 0b1100110011, 0b1100110011}; 
const uint16_t Y[] = {5, 0b1100000000, 0b0011000000, 0b0000111111, 0b0011000000, 0b1100000000};
const uint16_t N[] = {5, 0b1111111111, 0b0011000000, 0b0000110000, 0b0000001100, 0b1111111111};
const uint16_t T[] = {5, 0b1100000000, 0b1100000000, 0b1111111111, 0b1100000000, 0b1100000000};
const uint16_t U[] = {4, 0b1111111111, 0b0000000011, 0b0000000011, 0b1111111111};
const uint16_t F[] = {3, 0b1111111111, 0b1100110000, 0b1100110000, 0b1100000000, 0b1100000000};
const uint16_t S[] = {5, 0b0010001000, 0b0101000100, 0b1000100011, 0b0100010100, 0b0010001000};
const uint16_t star[] = {8, 0b1100000000, 0b0000110000, 0b0000001100, 0b0000000011, 0b0000001100, 0b0000110000, 0b0011000000, 0b1100000000};
const uint16_t stars[] = {19, 0b1000000000, 0b0100000000, 0b0010000000, 0b0001000000, 0b0000100000, 0b0000010000, 0b0000001000, 0b0000000100, 0b0000000010, 0b0000000001,
                              0b0000000010, 0b0000000100, 0b0000001000, 0b0000010000, 0b0000100000, 0b0001000000, 0b0010000000, 0b0100000000, 0b1000000000};
const uint16_t love[] = {9, 0b0001110000, 0b0010001000, 0b0100000100, 0b0010000010, 0b0001000001, 0b0010000010, 0b0100000100, 0b0010001000, 0b0001110000};
const uint8_t modeSize = 4;
uint8_t mode = 0;
void setup() {
  // put your setup code here, to run once:
  for(uint8_t i = 0; i < pinSize; i++) pinMode(pins[i], OUTPUT);
  pinMode(BTN_PIN, INPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  
  if(digitalRead(BTN_PIN)) {
    mode = (mode + 1) % modeSize;
    clearAll();
    delay(2000);
  }
  output(mode);
  clearAll(); 
  if(!mode) 
    delay(TEXT_DELAY);
}

void displayText(uint16_t* img) {
  const uint8_t imgLen = img[0] + 1;
  for(uint8_t j = 1; j < imgLen; j++) {
    for(uint8_t i = 0; i < pinSize; i++) {
      digitalWrite(pins[i], bitRead(img[j], i));
    }
    delay(FRAME_DELAY);
  }
  clearAll();
  delay(CHAR_DELAY);
}

void clearAll() {
  for(uint8_t i = 0; i < pinSize; i++) {
    digitalWrite(pins[i], 0);
  }
}

void output(uint8_t mode) {
  uint16_t* text[] = {N, T, U, F, S};
  switch(mode) {
    case 0: 
      for(uint8_t i = 0; i < 5; i++) {
        displayText(text[i]);
        delay(CHAR_DELAY);
      }
      break;
    case 1: 
      displayText(love);
      break;
    case 2:
      displayText(stars);
      break;
    case 3:
      displayText(star);
      break;
    default:
      clearAll();
  }
  delay(CHAR_DELAY);
}


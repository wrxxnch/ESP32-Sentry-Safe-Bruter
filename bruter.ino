#include <Arduino.h>
#define PIN_C1  4 // GPIO usado para C1

void send_request(uint8_t command, const uint8_t* code) {
  int checksum = command + code[0] + code[1] + code[2] + code[3] + code[4];
  pinMode(PIN_C1, OUTPUT);
  digitalWrite(PIN_C1, LOW);
  delayMicroseconds(3400);
  digitalWrite(PIN_C1, HIGH);
  Serial.begin(4800);
  uint8_t data[] = {0x00, command, code[0], code[1], code[2], code[3], code[4], (uint8_t)checksum};
  Serial.write(data, sizeof(data));
  Serial.flush();
  Serial.end();
  delay(100);
}

void setup() {
  uint8_t code[5];
  for (long i = 0; i <= 99999; i++) {
    code[0] = (i / 10000) % 10;
    code[1] = (i / 1000) % 10;
    code[2] = (i / 100) % 10;
    code[3] = (i / 10) % 10;
    code[4] = i % 10;
    send_request(0x71, code);
  }
}

void loop() {}

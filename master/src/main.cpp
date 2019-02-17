#include <Arduino.h>
#include <Wire.h>

byte x = 1;

void sendData(int addr, int data) {
  Wire.beginTransmission(addr);
  Wire.write(data);
  Wire.endTransmission();
}

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

void loop() {
  if (Serial.available() > 0) {
    String temp = Serial.readString();
    sendData((int)temp.charAt(0)-48, (int)temp.charAt(3)-48);
    Serial.println((int)temp.charAt(0)-48);
    Serial.println((int)temp.charAt(2)-48);
  }
}

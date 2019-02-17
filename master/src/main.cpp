#include <Arduino.h>
#include <Wire.h>

byte x = 1;
<<<<<<< HEAD
int bob = 5;
=======
>>>>>>> 49dfb57137afb02f5d1b72439821831bb8e13a8e

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

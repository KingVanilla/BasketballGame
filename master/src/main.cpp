#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();
byte x = 0;

void sendData(int addr, int data) {
  Serial.print("Sending: ");
  Serial.println(addr + " " + data);
  Wire.beginTransmission(addr);
  Wire.write(data);
  Wire.endTransmission();
  lcd.setCursor(0, 0);
  lcd.print(data);
}

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
  lcd.begin(16, 2);
  lcd.setBacklight(0x7);
}

void loop() {
  if (Serial.available() > 0) {
    String temp = Serial.readString();
    Serial.println(temp);
    sendData((int)temp.charAt(0)-48, (int)temp.charAt(2)-48);
  }
}

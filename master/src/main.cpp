#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_RGBLCDShield.h>
#include <utility/Adafruit_MCP23017.h>

Adafruit_RGBLCDShield lcd = Adafruit_RGBLCDShield();

char destinationAddress;
char destinationMessage;

void sendData() {
  Serial.print("Sending: ");
  Serial.println(destinationAddress + " " + destinationMessage);
  Wire.beginTransmission(destinationAddress);
  Wire.write(destinationMessage);
  Wire.endTransmission();
  lcd.setCursor(0, 0);
  lcd.print(destinationMessage);
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
    destinationAddress = temp.charAt(0);
    destinationMessage = temp.charAt(2);
    sendData();
  }
}

#include <Arduino.h>
#include <Wire.h>

byte zero[] = {1,1,1,1,1,1,0};
byte one[] = {0,1,1,0,0,0,0};
byte two[] = {1,1,0,1,1,0,1};
byte three[] = {1,1,1,1,0,0,1};
byte four[] = {0,1,1,0,0,1,1};
byte five[] = {0,1,1,1,0,1,1};
byte six[] = {1,0,1,1,1,1,1};
byte seven[] = {1,1,1,0,0,0,0};
byte eight[] = {1,1,1,1,1,1,1};
byte nine[] = {1,1,1,0,0,1,1};
int pins[] = {0};

int slaveAddress = 2;
boolean newData = false;
int data;

void receiveEvent() {
  while (Wire.available()) {
    data = (int)Wire.read() - 48;
    Serial.println(data);
    newData = true;
  }
}

void displayNumber() {
  byte lights[7];
  switch(data) {
    case 0:
      memcpy(lights, zero, 7);
      break;
    case 1:
      memcpy(lights, one, 7);
      break;
    case 2:
      memcpy(lights, two, 7);
      break;
    case 3:
      memcpy(lights, three, 7);
      break;
    case 4:
      memcpy(lights, four, 7);
      break;
    case 5:
      memcpy(lights, five, 7);
      break;
    case 6:
      memcpy(lights, six, 7);
      break;
    case 7:
      memcpy(lights, seven, 7);
      break;
    case 8:
      memcpy(lights, eight, 7);
      break;
    case 9:
      memcpy(lights, nine, 7);
      break;
    }

  for(int j = 0; j < 7; j++) {
    Serial.print((int)lights[j]);
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600);

  Wire.begin(slaveAddress);
  Wire.onReceive(receiveEvent);
}

void loop() {
  if(newData) {
    displayNumber();
    newData = false;
  }
  delay(100);
}

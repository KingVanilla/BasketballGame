#include <Arduino.h>
#include <Wire.h>

byte zero[] = {1,1,1,1,1,1,0}; // 1 dimension definition for the SSD
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

//int addr = 2;
//boolean newData = false;
//int data;

void receiveEvent(int howMany) {
  while (Wire.available()) { // loop through all but the last
    char c = Wire.read(); // receive byte as a character
    Serial.print(c);         // print the character
  }

  //data = (int)Wire.read();    // receive byte as an integer
  Serial.println(Wire.read());         // print the integer
  //newData = true;
}

// void displayNumber(int num) {
//   byte lights[1][7];
//   switch(num) {
//     case 0:
//       memcpy(lights, zero, sizeof(zero));
//       break;
//     case 1:
//       memcpy(lights, one, sizeof(one));
//       break;
//     case 2:
//       memcpy(lights, two, sizeof(two));
//       break;
//     case 3:
//       memcpy(lights, three, sizeof(three));
//       break;
//     case 4:
//       memcpy(lights, four, sizeof(four));
//       break;
//     case 5:
//       memcpy(lights, five, sizeof(five));
//       break;
//     case 6:
//       memcpy(lights, six, sizeof(six));
//       break;
//     case 7:
//       memcpy(lights, seven, sizeof(seven));
//       break;
//     case 8:
//       memcpy(lights, eight, sizeof(eight));
//       break;
//     case 9:
//       memcpy(lights, nine, sizeof(nine));
//       break;
//     }
//   for(int j = 0; j < sizeof(lights)/sizeof(lights[0]); j++) {
//     for(int k = 0; k < sizeof(lights[0])/sizeof(lights[0][0]); k++) {
//       Serial.print((int)lights[k][j]);
//     }
//     Serial.println();
//   }
// }

void setup() {
  Wire.begin(2);
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
}

void loop() {
  // if(newData) {
  //   displayNumber(data);
  //   newData = false;
  // }
  delay(100);
}

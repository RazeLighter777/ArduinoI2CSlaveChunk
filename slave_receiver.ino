// Wire Slave Receiver
// by Nicholas Zambetti <http://www.zambetti.com>

// Demonstrates use of the Wire library
// Receives data as an I2C/TWI slave device
// Refer to the "Wire Master Writer" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>


char buffer[150];
int i = 0;

void setup() {
  Wire.begin(0x29);                // join i2c bus with address #1
  Wire.onReceive(receiveEvent); // register event
  Serial.begin(9600);           // start serial for output
  Serial.print("Waiting for I2C . . . \n");
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  if (howMany == 0) {
    Serial.println("hello");
    for (int k = 0; k < i; k++) {
      Serial.print(buffer[k]);
    }
    i = 0;
  }
  Serial.println("Got request:");
  while (Wire.available()) {
    char c = Wire.read();
    buffer[i] = c;
    i++;
    Wire.write(c);
  }
  
}

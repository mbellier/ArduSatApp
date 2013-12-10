#include "Arduino.h"

#include "Plan13.h"



Plan13 p13;

void setup () {
  p13.setLocation(-64.375, 45.8958, 20); // lon, lat, height
  Serial.begin(38400);
}

void loop() { 
  // year, mount, day, hour, minute, second
  p13.setTime(2009, 10, 1, 19, 5, 0);
  // TLE
  p13.setElements(2009, 232.55636497, 98.0531, 238.4104, 83652*1.0e-7, 290.6047,
  68.6188, 14.406497342, -0.00000001, 27022, 180.0); 
  p13.calculate();
  p13.printdata();
  
  delay(2000);
}


#include "Plan13.h"

// object used to compute the satellite position
Plan13 p13;

void setup () {
  Serial.begin(38400);

  // set the position of an observer
  p13.setLocation(0.607696, 44.806265, 20); // lon, lat, height
  
}

void loop() { 
  
  // TODO time
  // year, mounth, day, hour, minute, second
  p13.setTime(2013, 12, 8, 13, 37, 42);
  // TLE (example values)
  p13.setElements(2009, 232.55636497, 98.0531, 238.4104, 83652*1.0e-7, 290.6047,
  68.6188, 14.406497342, -0.00000001, 27022, 180.0); 
  // compute satellite position
  p13.calculate();
  // display satellite position (and position from an observer)
  p13.printdata();
  
  delay(2000);
}


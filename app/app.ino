/*
 * This is an application for the ArduSat satellite.
 * Its purpose is to take pictures above a certain
 * position on earth.
 */

#include <Wire.h>
#include <EEPROM.h>
#include "I2C_add.h"
#include "OnboardCommLayer.h"
#include "nanosat_message.h"

#include "Plan13.h"

// Elevation in degree (0 to 90°) above which the satellite
// can be considered to be over the observator location on earth
#define ELEVATION_TRESHOLD 60


// object used to compute the satellite position
Plan13 p13;

// camera
OnboardCommLayer ocl;
uint8_t nodeAddress;
bool halted;


void setup () {
  // initialize camera
  Serial.begin(115200);
  Wire.begin();
  halted = false;
  ocl = OnboardCommLayer();
  nodeAddress = EEPROM.read(0x00);
  Serial.println("Initialized Serial and I2C bus");
   
  // set the position of an observer
  // this position will be the one where we want to take a photo
  p13.setLocation(0.607696, 44.806265, 20); // lon, lat, height
}

void loop() { 
  if(!halted) {
    // TODO get time
    // year, mounth, day, hour, minute, second
    p13.setTime(2013, 12, 8, 13, 37, 42);
  
    // TODO store TLE ?
    // TLE (example values) 
    p13.setElements(2009, 232.55636497, 98.0531, 238.4104, 83652*1.0e-7, 290.6047,
		    68.6188, 14.406497342, -0.00000001, 27022, 180.0); 
  
    // compute satellite position
    p13.calculate();
    // display satellite position (and position from an observer)
    p13.printdata();
  
    // Check position :
    // If the elevation of the satellite from the osbervator point
    // is high enough, the satellite can be considered to be
    // at the right place to take a photo
    if(p13.getElevation() > ELEVATION_TRESHOLD){
      // take a photo
      nanosat_message_t msg;
      msg.node_addr = nodeAddress;
      msg.prefix = NODE_COMM_MESSAGE_PREFIX;
      msg.type = CAM;
      ocl.sendMessage(msg);
      delay(1000);
      ocl.sendExit();
      delay(1000);
      halted = true;

    }
  
  }
  delay(2000);
  
}


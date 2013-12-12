ArduSatApp
==========

[Work in progress] Application for the ArduSat

Description
----------

This open-source project is using the Arduino SDK and the ArduSat SDK to build an application for the ArduSat satellite.

The code is divided in two modules:
 * __main.cpp__ : the application main code, which purpose is to take a photo over a specific location on earth.
 * __Plan13.cpp__ : module computing the satellite position given a TLE and the current time. The algorithm used is called Plan13 from James Miller G3RUH's paper (http://www.amsat.org/amsat/articles/g3ruh/111.html). The code is adapted from the open-source implementation from the qrptracker project (http://code.google.com/p/qrptracker/).

Progress
---------

Currently, the first feature developped is the localization of a satellite, from a TLE and a given time. The satellite position is given by its longitude and latitude, or its azimuth and elevation given an observation point. These values can be used to check when the satellite is over a certain position on earth and then, take a picture.

The Plan13 module has been tested on an Arduino Uno.


Features that will be implemented next:
 * Get current time
 * Store TLE
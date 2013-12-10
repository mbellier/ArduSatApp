ArduSatApp
==========

[Work in progress] Application for the ArduSat

Description
----------

This open-source project is using the Arduino SDK and the ArduSat SDK to build an application for the ArduSat satellite.

The code is divided in two modules:
    * __main.cpp__ : the application main code
    * __Plan13.cpp__ : module computing the satellite position given a TLE and the current time. The algorithm used is called Plan13 from James Miller G3RUH's paper (http://www.amsat.org/amsat/articles/g3ruh/111.html). The code is adapted from the open-source implementation from the qrptracker project (http://code.google.com/p/qrptracker/).

Progress
---------

Currently, the first feature developped is the localization of a satellite, from a TLE and a given time. The satellite position is given by its longitude and latitude, or its azimuth and elevation given an observation point.

 The program has been tested on a regular desktop computer and not cross-compiled yet.

Features that will be implemented next:
	 * Getting current time
	 * Using sensors (camera) at a specific location and store the data
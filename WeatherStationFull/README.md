Weather Station Arduino - Raspberry Pi (Full)
===================================================

This weather station combines the MongoDB and the SensApp version _i.e._, it locally stores data and periodically uploads them to SensApp (and clear the local data that have been uploaded).

How-to:
-------

Please refer to the README of the original weather station for the code related to Arduino. Make sure you upload the new firmware, though.

To initialize the Raspberry Pi node (in src/main/rpi):

1. start mongodb (you can get some information in ArduPi/mongodb-rpi/linux-test to install and run MongoDB. Make sure you can run the test program.)

2. compile and run, as usual

3. access your local data from the REST interface (please also look at the MongoDB tutorial)

4. access your data in the SensApp server, via the [SensApp-admin](http://sintef-9012.github.io/sensapp-admin/), which you should configure so that it can visualize the data of your SensApp server.

Useful links:
-------------------
* http://thingml.org/
* http://www.raspberrypi.org/
* http://arduino.cc/
* http://www.seeedstudio.com/blog/tag/electronic-brick/
* http://www.mongodb.org/display/DOCS/C+Language+Center
* https://github.com/SINTEF-9012/sensapp
* https://github.com/SINTEF-9012/sensapp-admin

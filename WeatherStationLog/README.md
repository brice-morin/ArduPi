Weather Station Arduino - Raspberry Pi with MongoDB
===================================================

This weather station is pretty much the same as the original one, which I recommend you to test beforehand. The code running on the Arduino now embeds a timer and sends (via USB) a value every 2 seconds. On the Raspberry Pi, one big difference though: the data received from the Arduino are now pushed into a local MongoDB database (accessible in REST from any web-browser on the same LAN as the Pi, or anywhere in the world if you Pi as a public IP), in addition of printing temperature and light values on the terminal.

How-to:
-------

Please refer to the README of the original weather station for the code related to Arduino. Make sure you upload the new firmware, though.

To initialize the Raspberry Pi node (in src/main/rpi):

1. start mongodb (you can get some information in ArduPi/mongodb-rpi/linux-test to install and run MongoDB. Make sure you can run the test program.)

2. compile and run, as usual

3. access your data from the REST interface (please also look at the MongoDB tutorial)

Useful links:
-------------------
* http://thingml.org/
* http://www.raspberrypi.org/
* http://arduino.cc/
* http://www.seeedstudio.com/blog/tag/electronic-brick/
* http://www.mongodb.org/display/DOCS/C+Language+Center

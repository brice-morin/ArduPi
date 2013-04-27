Weather Station Arduino - Raspberry Pi with SensApp
===================================================

This weather station is pretty much the same as the original one, which I recommend you to test beforehand. On the Raspberry Pi, one big difference though: the data received from the Arduino are now pushed into a remote SensApp server, which you can access via a REST interface, or using the [SensApp admin front-end](http://admin.sensapp.org).

How-to:
-------

Please refer to the README of the original weather station for the code related to Arduino. Make sure you upload the new firmware, though.

To initialize the Raspberry Pi node (in src/main/rpi):

1. start a SensApp server (e.g. on your PC). Please refer to [that README](https://github.com/SINTEF-9012/sensapp/tree/master/net.modelbased.sensapp.system.sprints.first)

2. Go to [SensApp-admin](http://admin.sensapp.org) and configure the SensApp admin so that it can access to your SensApp server

3. On the Pi
  1. Setup the firmware with the IP and port of your SensApp server, by changing [this line](https://github.com/brice-morin/ArduPi/blob/master/WeatherStationSensapp/src/main/rpi/RaspiNode.c#L617), and the following.
  
  > Alternatively, you can change [this line](https://github.com/brice-morin/ArduPi/blob/master/WeatherStationSensapp/src/main/thingml/studies/WeatherStation/_rpi/WeatherStationPi.thingml#L246) and the following in the ThingML model and re-generate the code

  2 .compile the code run it, as usual

3. access your data from the SensApp admin

Useful links:
-------------------
* http://thingml.org/
* http://www.raspberrypi.org/
* http://arduino.cc/
* http://www.seeedstudio.com/blog/tag/electronic-brick/
* http://admin.sensapp.org

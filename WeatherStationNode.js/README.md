Weather Station Arduino - Raspberry Pi
======================================

The weather station is composed of:
* an Arduino board equipped with
* an electronic brick shield, connected via USB to
* a Raspberry Pi board. 

![Weather Station](https://raw.github.com/brice-morin/ArduPi/master/WeatherStationLocal/images/WeatherStation.jpg)

The Arduino board contains all the necessary logic to sample temperature and light and locally display these values on a LCD screen.

Every 2 seconds, the Raspberry Pi remotely changes the LCD display of the Arduino board, which in turn sends the displayed value (either temprature or light) to the Pi.

Alternatively, 

- it is possible to push the button on the Arduino to force the Arduino to send data to the Pi.
- it is possible to send a WebSocket request to the Raspberry, which will in turn force the Arduino to send a value

All the source code (in Node.js for the Raspberry and Arduino/C for the Arduino) if fully generated from ThingML specifications.

How-to:
-------

Beginners are invited to directly use the code that has been generated from ThingML. 

The Arduino should be flashed (see other projects)

Electronic bricks should be connected on the Arduino shield as follows:
* LCD Screen on Bus2
* Button on Pin8
* LED on Pin9
* Light sensor on Pin1
* Temperature sensor on Pin3

The code located in this folder should be uploaded (via SCP or USB stick)

You can now run the executable (obtained from compiling the source code using make) using: node behavior-compiled.js

> We assume you have [Node.js installed on your Raspberry Pi](http://raspberryalphaomega.org.uk/2014/06/11/installing-and-using-node-js-on-raspberry-pi/#comment-34950), and that the Arduino board is connected to your Raspberry Pi on /dev/ttyACM0 before you run the program.

To remotely force the Arduino to send a value (via the Raspberry Pi), send a WebSocket request (e.g. via the Chrome REST console) to the Pi `ws://<IP-of-you-Pi>:8080/` with the following payload `{"message":"changeDisplay","port":"gui"}` 

Advanced users are invited to fully regenerate the source code from the ThingML specification. 


Useful links:
-------------------
* http://thingml.org/
* http://www.raspberrypi.org/
* http://arduino.cc/
* http://www.seeedstudio.com/blog/tag/electronic-brick/
* http://nodejs.org/

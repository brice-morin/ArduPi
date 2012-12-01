Weather Station Arduino - Raspberry Pi
======================================

The weather station is composed of:
* an Arduino board equipped with
* an electronic brick shield, connected via USB to
* a Raspberry Pi board. 

The Arduino board contains all the necessary logic to sample temperature and light and locally display these values on a LCD screen.

Every 2 seconds, the Raspberry Pi remotely changes the LCD display of the Arduino board, which in turn sends the displayed value (either temprature or light) to the Pi.

Alternatively, it is possible to push the button on the Arduino to force the Arduino to send data to the Pi.

All the source code (in C) if fully generated from ThingML specifications.

How-to:
-------

Beginners are invited to directly use the code that has been generated from ThingML. 

The code located in src/main/arduino should be uploaded on the Arduino board (please refer to the Arduino website to get instructions on how to flash an Arduino board). After the code has been uploaded, you can connect the Arduino board to your Raspberry Pi.

Electronic bricks should be connected on the Arduino shield as follows:
* LCD Screen on Bus2
* Button on Pin8
* LED on Pin9
* Light sensor on Pin1
* Temperature sensor on Pin3

The code located in src/main/rpi should be uploaded (via SCP or USB stick) and compiled (using make). 

You can now run the executable (obtained from compiling the source code using make) using: ./Raspinode

Note: We assume the Arduino board is connected to your Raspberry Pi on /dev/ttyACM0 before you run the program.

Advanced users are invited to fully regenerate the source code from the ThingML specification. 

Useful links:
-------------------
* http://thingml.org/
* http://www.raspberrypi.org/
* http://arduino.cc/
* http://www.seeedstudio.com/blog/tag/electronic-brick/

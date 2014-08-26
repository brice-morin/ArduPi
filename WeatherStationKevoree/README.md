Weather Station Arduino - Kevoree
==============================

The weather station is composed of:
* an Arduino board equipped with
* an electronic brick shield, connected via USB to
* a PC with Maven and JDK installed, the Kevoree Editor and the Kevoree runtime (it may work on a Raspberry Pi board, though I haven't tested). 

The Arduino board contains all the necessary logic to sample temperature and light and locally display these values on a LCD screen.

Every 2 seconds, the PC remotely changes the LCD display of the Arduino board, which in turn sends the displayed value (either temprature or light) to the Pi. It is possible to change the sampling rate by modifying the attribute and the Kevoree editor and enacting this change dynamically to the runtime.

Alternatively, it is possible to push the button on the Arduino to force the Arduino to send data to the PC.

All the source code (in C/Arduino, Java and KevScript) if fully generated from ThingML specifications.

How-to:
-------

Beginners are invited to directly use the code that has been generated from ThingML. 

The code located in `src/main/arduino` should be uploaded on the Arduino board (please refer to the Arduino website to get instructions on how to flash an Arduino board). After the code has been uploaded, you can connect the Arduino board to your Raspberry Pi.

Electronic bricks should be connected on the Arduino shield as follows:
* LCD Screen on Bus2
* Button on Pin8
* LED on Pin9
* Light sensor on Pin1
* Temperature sensor on Pin3

The code located in `src/main/java` should be compiled with Maven

	mvn clean install exec:java -Dexec.mainClass="org.thingml.generated.JavaNode"
	
> You need Maven properly installed on your computer, with a proper JDK (not JRE)

The KevScript can be run from the Kevoree Editor, and Executed on the Kevoree runtime.

Useful links:
-------------------
* http://thingml.org/
* http://kevoree.org
* http://www.raspberrypi.org/
* http://arduino.cc/
* http://www.seeedstudio.com/blog/tag/electronic-brick/

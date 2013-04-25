Install
=======
1. Copy the binaries of MondoDB in e.g., /opt
2. Copy the libraries (*.so files) provided on this repo in /lib
3. Install those libs
```bash
$ cd /lib
$ ldconfig
```

4. you can run MongoDB: 
```bash
$ mkdir /home/pi/db
$ cd /opt/mongo/bin 
$ ./mongod --dbpath="/home/pi/db" --rest
```

5. compile mongo_client.c using 
```bash
$ make
```

6. run the program
```bash
$ ./mongo_client
```

7. In a web-browser (on the same LAN as your RPi) go to (check the IP address of your RPi using ifconfig)
```
http://raspberry-pi-IP:28017/sensor1/temp/_find
http://raspberry-pi-IP:28017/sensor1/light/_find
http://raspberry-pi-IP:28017/sensor2/temp/_find
http://raspberry-pi-IP:28017/sensor2/light/_find
```

You will see the values for the light and temperature of two (virtual) sensors.

> Mongo is started on port 27017. You should add 1000 to access it via REST, hence port 28017

8. You should see something like:
```json
{
  "offset" : 0,
  "rows": [
    { "_id" : { "$oid" : "51716303c3a33e4051858ca5" }, "t" : 1319625, "v" : 25 } ,
    { "_id" : { "$oid" : "51716305c3a33e4051858ca7" }, "t" : 1319627, "v" : 24 }
  ],

  "total_rows" : 2 ,
  "query" : {} ,
  "millis" : 1
}
```

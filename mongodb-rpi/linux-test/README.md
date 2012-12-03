Install
=======
1. Copy the binaries of MondoDB in e.g., /opt
2. Copy the libraries (*.so files) provided on this repo in /lib
3. In /lib run ldconfig to properly install those libs
4. you can run MongoDB: 

```bash
$ cd /opt/mongo/bin 
$ ./mongod --dbpath="/home/pi/db" --rest //note: make sure you have created the db folder prior execution
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
http://raspberry-pi-IP:28017/sensapp/sensor1/_find
```

8. You should see something like (with probably less data):

```json
{
  "offset" : 0,
  "rows": [
    { "_id" : { "$oid" : "50bce8b2bdf0e5a03a96d520" }, "t" : 1354557618, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd0272ca1a7a42bf999e8b" }, "t" : 1354564210, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd0272ca1a7a42bf999e8c" }, "t" : 1354564210, "light" : 50 } ,
    { "_id" : { "$oid" : "50bd0272ca1a7a42bf999e8d" }, "t" : 1354564210, "temp" : 24 } ,
    { "_id" : { "$oid" : "50bd0272ca1a7a42bf999e8e" }, "t" : 1354564210, "light" : 47 } ,
    { "_id" : { "$oid" : "50bd02cbca1a7a42bf999e93" }, "t" : 1354564299, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd02cbca1a7a42bf999e94" }, "t" : 1354564299, "light" : 50 } ,
    { "_id" : { "$oid" : "50bd02cbca1a7a42bf999e95" }, "t" : 1354564299, "temp" : 24 } ,
    { "_id" : { "$oid" : "50bd02cbca1a7a42bf999e96" }, "t" : 1354564299, "light" : 47 } ,
    { "_id" : { "$oid" : "50bd07ffca1a7a42bf999e9b" }, "t" : 1354565631, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd07ffca1a7a42bf999e9c" }, "t" : 1354565631, "light" : 50 } ,
    { "_id" : { "$oid" : "50bd07ffca1a7a42bf999e9d" }, "t" : 1354565631, "temp" : 24 } ,
    { "_id" : { "$oid" : "50bd07ffca1a7a42bf999e9e" }, "t" : 1354565631, "light" : 47 } ,
    { "_id" : { "$oid" : "50bd080dca1a7a42bf999ea3" }, "t" : 1354565645, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd080dca1a7a42bf999ea4" }, "t" : 1354565645, "light" : 50 } ,
    { "_id" : { "$oid" : "50bd080dca1a7a42bf999ea5" }, "t" : 1354565645, "temp" : 24 } ,
    { "_id" : { "$oid" : "50bd080dca1a7a42bf999ea6" }, "t" : 1354565645, "light" : 47 } ,
    { "_id" : { "$oid" : "50bd095be6a5b1b8728c0349" }, "t" : 1354565979, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd095be6a5b1b8728c034a" }, "t" : 1354565979, "light" : 50 } ,
    { "_id" : { "$oid" : "50bd095be6a5b1b8728c034b" }, "t" : 1354565979, "temp" : 24 } ,
    { "_id" : { "$oid" : "50bd095be6a5b1b8728c034c" }, "t" : 1354565979, "light" : 47 } ,
    { "_id" : { "$oid" : "50bd09ede6a5b1b8728c0351" }, "t" : 1354566125, "temp" : 25 } ,
    { "_id" : { "$oid" : "50bd09ede6a5b1b8728c0352" }, "t" : 1354566125, "light" : 50 } ,
    { "_id" : { "$oid" : "50bd09ede6a5b1b8728c0353" }, "t" : 1354566125, "temp" : 24 } ,
    { "_id" : { "$oid" : "50bd09ede6a5b1b8728c0354" }, "t" : 1354566125, "light" : 47 }
  ],

  "total_rows" : 25 ,
  "query" : {} ,
  "millis" : 9
}
```
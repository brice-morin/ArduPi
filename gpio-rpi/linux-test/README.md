This is currently on-going work (i.e, it does not work, yet)

Install
=======
1. You should make sure you have access to an instance of SensApp, running somewhere (in the cloud, your own computer, or whatever). See for example: https://github.com/SINTEF-9012/sensapp/tree/master/net.modelbased.sensapp.system.sprints.first

2. Make sure the IP addresses in curl_client.c point to this instance of SensApp

3. compile curl_client.c using 
```bash
$ make
```

4. run the program
```bash
$ ./curl_client
```

5. In a web-browser go to (make sure you replace IP-OF-SENSAPP by... the IP address of SensApp)
```
http://IP-OF-SENSAPP/sensapp/databases/raw/data/curl-test
```

6. You should see something like (with probably less data):
```json
{}
```

#include <time.h>
#include <stdio.h>
#include <stdlib.h>


char* exec(const char* command);
long int timestamp();

char* registerSensor(const char* id, const char* descr, const char* backend, const char* tpl);
char* getSensorDetails(const char* sensor);
char* pushData(const char* data);
char* getData(const char* sensor, const char* contentType);
int checkConnection();

char* server = "http://internal.sensapp.org";
char* port = "8080";

int main() {

  if (checkConnection() == 0) {
  printf("Can connect to the internet\n");

  char* sensorID = "demo-curl/a-sensor";

  printf("Registering sensor...\n");
  printf(registerSensor(sensorID, "example sensor registered from a RPi via CURL", "raw", "Numerical"));
  printf("\n\n");

  printf("Sensor details...\n");
  printf(getSensorDetails(sensorID));
  printf("\n\n");
  
  printf("Pushing data...\n");
  char data[5120];
  sprintf(data, "{\"bn\":\"%s\", \"bu\":\"m\", \"e\":[{\"v\":10, \"t\":%d}]}", sensorID, timestamp());
  printf(pushData(data));
  printf("\n\n");

  
  printf("Retrieving data in JSON...\n");
  printf(getData(sensorID, "application/json"));
  printf("\n\n");

  printf("Retrieving data in XML...\n");
  printf(getData(sensorID, "text/xml"));
  printf("\n\n");
  
  return 0;
  } else {
        printf("Cannot connect to the internet\n");
	return -1;
  }
}

int checkConnection() {
	printf("checkConnection\n\n");
	char command[1024];
	sprintf(command, "curl %s:%s/sensapp", server, port);

	if (system(command) != 0) {//sensapp does not respond
		perror("Cannot reach sensapp!\n");
		if (system("curl http://www.google.com") != 0) {//even google does not respond
			perror("Cannot even reach google\n");
			return -2;
		}
		return -1;
	}
	return 0;
}

long int timestamp() {
	return time(NULL);
}

char* exec(const char* command) {
	FILE* fp;
	char* result = NULL;
	size_t len = 0;

	fflush(NULL);
	fp = popen(command, "r");
	if (fp == NULL) {
		printf("Cannot execute command:\n");
		printf(command);
		printf("\n");
		return;
	}

	while(getline(&result, &len, fp) != -1) {
		fputs(result, stdout);
	}

	free(result);
	fflush(fp);
	if (pclose(fp) != 0) {
		perror("Cannot close stream.\n");
	}
	return result;
}

char* registerSensor(const char* id, const char* descr, const char* backend, const char* tpl) {
	char json[4096];
        sprintf(json, "{\"id\":\"%d\", \"descr\":\"%s\", \"schema\": {\"backend\":\"%s\", \"template\":\"%s\"}}", id, descr, backend, tpl);
	
	char url[1024];
        sprintf(url, "%s:%s/sensapp/registry/sensors", server, port);
	
	char command[5135];
	sprintf(command, "curl -s --data'%s' --header 'Content-Type: application/json; charset=ISO-8859-1' %s", json, url);

	return exec(command);	
}

char* getSensorDetails(const char* sensor) {
	char command[1024];
	sprintf(command, "curl -s %s:%s/sensapp/registry/sensors/%s", server, port, sensor);

	return exec(command);
}

char* pushData(const char* data) {
	char command[1024];
	sprintf(command, "curl -s --request PUT --data '%s' --header 'Content-Type: application/senml+json; charset=ISO-8859-1' %s:%s/sensapp/dispatch", data, server, port);
	
	return exec(command);
}

char* getData(const char* sensor, const char* contentType) {
	char command[1024];
	sprintf(command, "curl -s --header 'Accept: %s; charset=ISO-8859-1' %s:%s/sensapp/databases/raw/data/%s", contentType, server, port, sensor);
	
	return exec(command);
}


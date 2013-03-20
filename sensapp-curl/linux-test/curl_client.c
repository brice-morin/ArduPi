#include <time.h>
#include <stdio.h>
#include <stdlib.h>


char* exec(const char* command);
long int timestamp();
char* timestampCh();

char* registerSensor(const char* id, const char* descr, const char* backend, const char* tpl);
char* getSensorDetails(const char* sensor);
char* pushData(const char* data);
char* getData(const char* sensor, const char* contentType);

char* server = "localhost";
char* port = "8080";

int main() {

  char* sensorID = "demo-curl/a-sensor";

  printf("Registering sensor...\n");
  printf(registerSensor(sensorID, "example sensor registered from a RPi via CURL", "raw", "Numerical"));
  printf("\n\n");

  printf("Sensor details...\n");
  printf(getSensorDetails(sensorID));
  printf("\n\n");
  
  printf("Pushing data...\n");
  char data[5120];
  strcpy(data, "{\"bn\":\"");
  strcat(data, sensorID);
  strcat(data, "\", \"bu\":\"m\", \"e\":[{\"v\":10, \"t\": ");
  strcat(data, timestampCh());
  strcat(data, " }]}");
  printf(pushData(data));
  printf("\n\n");

  
  printf("Retrieving data in JSON...\n");
  printf(getData(sensorID, "application/json"));
  printf("\n\n");

  printf("Retrieving data in XML...\n");
  printf(getData(sensorID, "text/xml"));
  printf("\n\n");
  
  return 0;
}

char* timestampCh() {
	char result[12];
	sprintf(result, "%d", timestamp());
	return result;
}

long int timestamp() {
	return time(NULL);
}

char* exec(const char* command) {
	FILE* fp;
	int status;
	char path[16384];
	char result[65536];

	fp = popen(command, "r");
	if (fp == NULL) {
		printf("Cannot execute command:\n");
		printf(command);
		printf("\n");
		return;
	}

	while(fgets(path, (sizeof(path)/sizeof(*(path)))+1, fp) != NULL) {
		strcat(result, path);
	}

	pclose(fp);
	return result;
}

char* registerSensor(const char* id, const char* descr, const char* backend, const char* tpl) {
	char json[4096];
	strcpy(json, "{\"id\": \"");
	strcat(json, id);
	strcat(json, "\", \"descr\": \"");
	strcat(json, descr);
	strcat(json, "\",");
	strcat(json, "\"schema\": { \"backend\": \"");
	strcat(json, backend);
	strcat(json, "\", \"template\": \"");
	strcat(json, tpl);
	strcat(json, "\"}}");
	
	char url[1024];
	strcpy(url, server);
	strcat(url, ":");
	strcat(url, port);
	strcat(url, "/sensapp/registry/sensors");
	
	char command[5135];
	strcpy(command, "curl -s --data '");
	strcat(command, json);
	strcat(command, "' ");
	strcat(command, "--header 'Content-Type: application/json; charset=ISO-8859-1' ");
	strcat(command, url);

	return exec(command);	
}

char* getSensorDetails(const char* sensor) {
	char command[1024];
	strcpy(command, "curl -s ");
	strcat(command, server);
	strcat(command, ":");
	strcat(command, port);
	strcat(command, "/sensapp/registry/sensors/");
	strcat(command, sensor);

	return exec(command);
}

char* pushData(const char* data) {
	char command[1024];
	strcpy(command, "curl -s --request PUT --data '");
	strcat(command, data);
	strcat(command, "' --header 'Content-Type: application/senml+json; charset=ISO-8859-1' ");
	strcat(command, server);
	strcat(command, ":");
	strcat(command, port);
	strcat(command, "/sensapp/dispatch");
	
	return exec(command);
}

char* getData(const char* sensor, const char* contentType) {
	char command[1024];
	strcpy(command, "curl -s --header 'Accept: ");
	strcat(command, contentType);
	strcat(command, "; charset=ISO-8859-1' ");
	strcat(command, server);
	strcat(command, ":");
	strcat(command, port);
	strcat(command, "/sensapp/databases/raw/data/");
	strcat(command, sensor);
	
	return exec(command);
}


#include <stdio.h>
#include <stdlib.h>


int registerSensor(char* id, char* descr, char* backend, char* tpl);
int getSensorDetails(char* url);
//int pushData(char* data);
//int getData(char* url, char* contentType);

char* server = "localhost";
char* port = "8080";

int main() {
  printf("Registering sensor...\n");
  printf(registerSensor("demo-curl/a-sensor", "example sensor", "raw", "Numerical"));
  printf("\n\n");
  
/*  printf("Pushing data...\n");
  char* data = "{\"bn\":\"demo-curl/a-sensor\", \"bu\":\"m\", \"e\":[{\"v\":10, \"t\": 0 }, {\"v\":12, \"t\": 1 }]}";
  printf(pushData(data));
  printf("\n\n");
*/
  /*
  printf("Retrieving data in JSON...\n");
  printf(getData("/sensapp/databases/raw/data/demo-curl/a-sensor", "application/json"));
  printf("\n");
  printf("\n");
  printf("Retrieving data in XML...\n");
  printf(getData("/sensapp/databases/raw/data/demo-curl/a-sensor", "text/xml"));
  */
  
  return 0;
}

int registerSensor(char* id, char* descr, char* backend, char* tpl) {

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
	strcpy(command, "curl --data '");
	strcat(command, json);
	strcat(command, "' ");
	strcat(command, "--header 'Content-Type: application/json; charset=ISO-8859-1' ");
	strcat(command, url);

	printf("Sending command to SensApp:\n");
	printf(command);
	printf("\n");
		
	return system(command);
}

int getSensorDetails(char* u) {

	char command[1024];
	strcpy(command, "curl ");
	strcat(command, server);
	strcat(command, port);
	strcat(command, u);
	
	return system(command);
}

/*void pushData(char* data) {
	CURLcode res;
	
	char url[256] = "http://";
	strcat(url, server);
	strcat(url, port);
	strcat(url, "/sensapp/dispatch");
	
	CURL *curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_PUT, 1L);
		res = curl_easy_perform(curl);
		printf("\nStatus:: %d\n", res);
		curl_easy_cleanup(curl);
	}
}

void getData(char* u, char* contentType) {
	CURLcode res;
	
	char url[256] = "http://";
	strcat(url, server);
	strcat(url, port);
	strcat(url, u);
	
	CURL *curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		res = curl_easy_perform(curl);
		printf("\nData:: %d\n", res);
		curl_easy_cleanup(curl);
	}
}
*/

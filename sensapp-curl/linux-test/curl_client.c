#include <stdio.h>
#include <stdlib.h>
#include<curl/curl.h>


void registerSensor(char* id, char* descr, char* backend, char* tpl);
void getSensorDetails(char* url);
void pushData(char* data);
void getData(char* url, char* contentType);

char* server = "localhost";
int port = 8080;

int main() {
  printf("Registering sensor... ");
  /*char* sensorURL = */registerSensor("demo-curl/a-sensor", "example sensor", "raw", "Numerical");
  /*printf(sensorURL);
  printf("\n");
  printf("\n");*/
  
  printf("Pushing data... ");
  char* data = "{\"bn\":\"demo-curl/a-sensor\", \"bu\":\"m\", \"e\":[{\"v\":10, \"t\": 0 }, {\"v\":12, \"t\": 1 }]}";
  /*char* status = */pushData(data);
  /*printf(status);
  printf("\n");
  printf("\n");*/
  
  /*printf("Retrieving data in JSON...\n");
  printf(getData("/sensapp/databases/raw/data/demo-curl/a-sensor", "application/json"));
  printf("\n");
  printf("\n");
  printf("Retrieving data in XML...\n");
  printf(getData("/sensapp/databases/raw/data/demo-curl/a-sensor", "text/xml"));*/
  
  return 0;
}

void registerSensor(char* id, char* descr, char* backend, char* tpl) {
	CURLcode res;

	char json[1024] = "{\"id\": \"";
	strcat(json, id);
	strcat(json, "\", \"descr\": \"");
	strcat(json, descr);
	strcat(json, "\",");
	strcat(json, "\"schema\": { \"backend\": \"");
	strcat(json, backend);
	strcat(json, "\", \"template\": \"");
	strcat(json, "\"}}");
	
	CURL *curl = curl_easy_init();
	if(curl) {
		char url[256] = "http://";
		strcat(url, server);
		strcat(url, port);
		strcat(url, "/sensapp/registry/sensors");
		
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, json);
		res = curl_easy_perform(curl);
		printf("\nStatus:: %d\n", res);
		curl_easy_cleanup(curl);
	}
}

void getSensorDetails(char* u) {
	CURLcode res;
	
	char url[256] = "http://";
	strcat(url, server);
	strcat(url, port);
	strcat(url, u);
	
	CURL *curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		res = curl_easy_perform(curl);
		printf("\nSensor details:: %d\n", res);
		curl_easy_cleanup(curl);
	}
}

void pushData(char* data) {
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

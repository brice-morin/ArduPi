#include <time.h>
#include <stdio.h>
#include <stdlib.h>
//#include "strmap.h"

char* exec(const char* command);
long int timestamp();

char* registerSensor(const char* node, const char* sensor, const char* descr, const char* backend, const char* tpl, const char* unit);
char* getSensorDetails(const char* node, const char* sensor);
char* pushData(char* node, char* sensor, int value);
char* getData(const char* node, const char* sensor, const char* contentType);
int checkConnection();
char* getSensorID(const char* node, const char* sensor);

char* server = "http://internal.sensapp.org";
char* port = "8080";

/*
 * Contains sensorID->unit
 * Mapping stored when registering the sensor
 * Used anytime a data is pushed (to avoid transmitting redundant info)
 */
//StrMap *sm;//TODO: this will be stored and retrieved into/from the Mongo DB

int main() {

    if (checkConnection() == 0) {
        printf("Can connect to the internet\n");

        /*sm = sm_new(2);
        if (sm == NULL) {
          perror("Cannot init hash map...\n");
        }*/

        const char* node = "demo-curl";
        const char* sensor = "a-sensor";

        printf("Registering sensor...\n%s\n\n", registerSensor(node, sensor, "example sensor registered from a RPi via CURL", "raw", "Numerical", "degC"));
        printf("Sensor details...\n%s\n\n", getSensorDetails(node, sensor));
        printf("Pushing data... \n%s\n\n", pushData(node, sensor, 10));
        printf("Retrieving data in JSON...\n%s\n\n", getData(node, sensor, "application/json"));
        printf("Retrieving data in XML...\n%s\n\n", getData(node, sensor, "text/xml"));

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

char* registerSensor(const char* node, const char* sensor, const char* descr, const char* backend, const char* tpl, const char* unit) {
    char json[4096];
    sprintf(json, "{\"id\":\"%s\", \"descr\":\"%s\", \"schema\": {\"backend\":\"%s\", \"template\":\"%s\"}}", getSensorID(node, sensor), descr, backend, tpl);

    char url[1024];
    sprintf(url, "%s:%s/sensapp/registry/sensors", server, port);

    char command[5135];
    sprintf(command, "curl -s --data'%s' --header 'Content-Type: application/json; charset=ISO-8859-1' %s", json, url);

    //sm_put(sm, id, unit);

    return exec(command);
}

char* getSensorID(const char* node, const char* sensor) {
    char fullName[256];
    sprintf("%s/%s", node, sensor);
    return fullName;
}

char* getSensorDetails(const char* node, const char* sensor) {
    char command[1024];
    sprintf(command, "curl -s %s:%s/sensapp/registry/sensors/%s", server, port, getSensorID(node, sensor));

    return exec(command);
}

char* pushData(char* node, char* sensor, int value) {
    char data[5120];
    char unit[8] = "degC";

    /*result = sm_get(sm, getSensorID(node, sensor), unit, sizeof(unit));
    if (result == 0) {
    	perror("Cannot retrieve unit\n");
    }*/
    sprintf(data, "{\"bn\":\"%s\", \"bu\":\"%d\", \"e\":[{\"v\":%d, \"t\":%d}]}", getSensorID(node, sensor), unit, value, timestamp());

    char command[1024];
    sprintf(command, "curl -s --request PUT --data '%s' --header 'Content-Type: application/senml+json; charset=ISO-8859-1' %s:%s/sensapp/dispatch", data, server, port);

    //TODO: we need to parse the result of the command and return a proper status (int)

    return exec(command);
}

char* getData(const char* node, const char* sensor, const char* contentType) {
    char command[1024];
    sprintf(command, "curl -s --header 'Accept: %s; charset=ISO-8859-1' %s:%s/sensapp/databases/raw/data/%s", contentType, server, port, getSensorID(node, sensor));

    return exec(command);
}

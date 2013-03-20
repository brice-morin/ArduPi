/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing LinuxSensapp
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "LinuxSensapp.h"

/*****************************************************************************
 * Implementation for type : LinuxSensapp
 *****************************************************************************/


// BEGIN: Code from the c_global annotation LinuxSensapp

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

char* exec(const char* command);
long int timestamp();
char* timestampCh();

char* registerSensor(const char* id, const char* descr, const char* backend, const char* tpl);
char* pushData(const char* data);

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

    printf("DEBUG: execute command:\n");
	printf(command);
	printf("\n");

	while(fgets(path, (sizeof(path)/sizeof(*(path)))+1, fp) != NULL) {
		strcat(result, path);
	}

	pclose(fp);

    printf("DEBUG: command has returned:\n");
	printf(result);
	printf("\n");

	return result;
}

// END: Code from the c_global annotation LinuxSensapp

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void LinuxSensapp_LinuxSensappImpl_OnExit(int state, struct LinuxSensapp_Instance *_instance);
void f_LinuxSensapp_register(struct LinuxSensapp_Instance *_instance, char * id, char * desc);
void f_LinuxSensapp_push(struct LinuxSensapp_Instance *_instance, char * sensorID, char * key, int value, char * unit);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function register
void f_LinuxSensapp_register(struct LinuxSensapp_Instance *_instance, char * id, char * desc) {
{

	char json[4096];
	strcpy(json, "{\"id\": \"");
	strcat(json, id);
	strcat(json, "\", \"descr\": \"");
	strcat(json, desc);
	strcat(json, "\",");
	strcat(json, "\"schema\": { \"backend\": \"");
	strcat(json, "raw");
	strcat(json, "\", \"template\": \"");
	strcat(json, "Numerical");
	strcat(json, "\"}}");
	
	char url[1024];
	strcpy(url, _instance->LinuxSensapp_server_var);
	strcat(url, ":");
	strcat(url, _instance->LinuxSensapp_p_var);
	strcat(url, "/sensapp/registry/sensors");
	
	char command[5135];
	strcpy(command, "curl --data '");
	strcat(command, json);
	strcat(command, "' ");
	strcat(command, "--header 'Content-Type: application/json; charset=ISO-8859-1' ");
	strcat(command, url);

	exec(command);	
    
}
}

// Definition of function push
void f_LinuxSensapp_push(struct LinuxSensapp_Instance *_instance, char * sensorID, char * key, int value, char * unit) {
{

    char data[5120];
    strcpy(data, "{\"bn\":\"");
    strcat(data, sensorID);
    strcat(data, "/");
    strcat(data, key);
    strcat(data, "\", \"bu\":\"");
    strcat(data, unit);
    strcat(data, "\", \"e\":[{\"v\":"); 
    
    char stringValue[8];
    sprintf(stringValue, "%d", value);
    
    strcat(data, stringValue);
    strcat(data, ", \"t\": ");
    strcat(data, timestampCh());
    strcat(data, " }]}");   
    
    char command[1024];
	strcpy(command, "curl --request PUT --data '");
	strcat(command, data);
	strcat(command, "' --header 'Content-Type: application/senml+json; charset=ISO-8859-1' ");
	strcat(command, _instance->LinuxSensapp_server_var);
	strcat(command, ":");
	strcat(command, _instance->LinuxSensapp_p_var);
	strcat(command, "/sensapp/dispatch");

    exec(command); 
    
}
}


// On Entry Actions:
void LinuxSensapp_LinuxSensappImpl_OnEntry(int state, struct LinuxSensapp_Instance *_instance) {
switch(state) {
case LINUXSENSAPP_LINUXSENSAPPIMPL_STATE:
_instance->LinuxSensapp_LinuxSensappImpl_State = LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE;
LinuxSensapp_LinuxSensappImpl_OnEntry(_instance->LinuxSensapp_LinuxSensappImpl_State, _instance);
break;
case LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE:
break;
default: break;
}
}

// On Exit Actions:
void LinuxSensapp_LinuxSensappImpl_OnExit(int state, struct LinuxSensapp_Instance *_instance) {
switch(state) {
case LINUXSENSAPP_LINUXSENSAPPIMPL_STATE:
LinuxSensapp_LinuxSensappImpl_OnExit(_instance->LinuxSensapp_LinuxSensappImpl_State, _instance);
break;
case LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void LinuxSensapp_handle_sensapp_pushData(struct LinuxSensapp_Instance *_instance, char * sensorID, char * key, int value) {
if (_instance->LinuxSensapp_LinuxSensappImpl_State == LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxSensapp_push(_instance, sensorID, key, value, "m");
}
}
}
}
void LinuxSensapp_handle_sensapp_registerSensor(struct LinuxSensapp_Instance *_instance, char * name) {
if (_instance->LinuxSensapp_LinuxSensappImpl_State == LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxSensapp_register(_instance, name, "");
}
}
}
}

// Observers for outgoing messages:


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
		printf("Cannot execute command: %s\n", command);
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

// END: Code from the c_global annotation LinuxSensapp

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void LinuxSensapp_LinuxSensappImpl_OnExit(int state, struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_send_sensapp_doneRegister(struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_send_sensapp_failRegister(struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_send_sensapp_donePush(struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_send_sensapp_failPush(struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_send_sensapp_donePushRaw(struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_send_sensapp_failPushRaw(struct LinuxSensapp_Instance *_instance);
int f_LinuxSensapp_checkConnection(struct LinuxSensapp_Instance *_instance);
void f_LinuxSensapp_register(struct LinuxSensapp_Instance *_instance, char * node, char * sensor);
void f_LinuxSensapp_push(struct LinuxSensapp_Instance *_instance, char * node, char * sensor, int value, char * unit);
int f_LinuxSensapp_pushRaw(struct LinuxSensapp_Instance *_instance, char * data);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function checkConnection
int f_LinuxSensapp_checkConnection(struct LinuxSensapp_Instance *_instance) {
{

	char command[1024];
	sprintf(command, "curl %s:%s/sensapp", _instance->LinuxSensapp_server_var, _instance->LinuxSensapp_p_var);
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
}

// Definition of function register
void f_LinuxSensapp_register(struct LinuxSensapp_Instance *_instance, char * node, char * sensor) {
{
if(f_LinuxSensapp_checkConnection(_instance) == 0) {

	 char json[4096];
     sprintf(json, "{\"id\":\"%s/%s\", \"descr\":\"ThingML device\", \"schema\": {\"backend\":\"raw\", \"template\":\"Numerical\"}}", node, sensor);
	
	 char url[1024];
     sprintf(url, "%s:%s/sensapp/registry/sensors", _instance->LinuxSensapp_server_var, _instance->LinuxSensapp_p_var);
	
	 char command[5135];
	 sprintf(command, "curl -s --data '%s' --header 'Content-Type: application/json; charset=ISO-8859-1' %s", json, url);

	 exec(command);	
    
}
}
}

// Definition of function push
void f_LinuxSensapp_push(struct LinuxSensapp_Instance *_instance, char * node, char * sensor, int value, char * unit) {
{
if(f_LinuxSensapp_checkConnection(_instance) == 0) {

        char data[5120];
        sprintf(data, "{\"bn\":\"%s/%s\", \"bu\":\"%s\", \"e\":[{\"v\":%d, \"t\":%d}]}", node, sensor, unit, value, timestamp());
        char command[6144];
	    sprintf(command, "curl -s --request PUT --data '%s' --header 'Content-Type: application/senml+json; charset=ISO-8859-1' %s:%s/sensapp/dispatch", data, _instance->LinuxSensapp_server_var, _instance->LinuxSensapp_p_var);

        //TODO: we need to parse the result of the command and return a proper status (int)

	   exec(command);
    
LinuxSensapp_send_sensapp_donePush(_instance);
}
 else {
LinuxSensapp_send_sensapp_failPush(_instance);
}
}
}

// Definition of function pushRaw
int f_LinuxSensapp_pushRaw(struct LinuxSensapp_Instance *_instance, char * data) {
{
if(f_LinuxSensapp_checkConnection(_instance) == 0) {

        char command[6144];
	    sprintf(command, "curl --request PUT --data '%s' --header 'Content-Type: application/senml+json; charset=ISO-8859-1' %s:%s/sensapp/dispatch", data, _instance->LinuxSensapp_server_var, _instance->LinuxSensapp_p_var);

        //TODO: we need to parse the result of the command and return a proper status (int)

        printf("\n%s\n\n", command);
	   exec(command);
    
LinuxSensapp_send_sensapp_donePushRaw(_instance);
}
 else {
LinuxSensapp_send_sensapp_failPushRaw(_instance);
}
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
void LinuxSensapp_handle_sensapp_pushRawData(struct LinuxSensapp_Instance *_instance, char * data) {
if (_instance->LinuxSensapp_LinuxSensappImpl_State == LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxSensapp_pushRaw(_instance, data);
}
}
}
}
void LinuxSensapp_handle_sensapp_pushData(struct LinuxSensapp_Instance *_instance, char * node, char * sensor, int value, char * unit) {
if (_instance->LinuxSensapp_LinuxSensappImpl_State == LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxSensapp_push(_instance, node, sensor, value, unit);
}
}
}
}
void LinuxSensapp_handle_sensapp_registerSensor(struct LinuxSensapp_Instance *_instance, char * node, char * sensor) {
if (_instance->LinuxSensapp_LinuxSensappImpl_State == LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxSensapp_register(_instance, node, sensor);
}
}
}
}

// Observers for outgoing messages:
void (*LinuxSensapp_send_sensapp_doneRegister_listener)(struct LinuxSensapp_Instance*)= 0x0;
void register_LinuxSensapp_send_sensapp_doneRegister_listener(void (*_listener)(struct LinuxSensapp_Instance*)){
LinuxSensapp_send_sensapp_doneRegister_listener = _listener;
}
void LinuxSensapp_send_sensapp_doneRegister(struct LinuxSensapp_Instance *_instance){
if (LinuxSensapp_send_sensapp_doneRegister_listener != 0x0) LinuxSensapp_send_sensapp_doneRegister_listener(_instance);
}
void (*LinuxSensapp_send_sensapp_failRegister_listener)(struct LinuxSensapp_Instance*)= 0x0;
void register_LinuxSensapp_send_sensapp_failRegister_listener(void (*_listener)(struct LinuxSensapp_Instance*)){
LinuxSensapp_send_sensapp_failRegister_listener = _listener;
}
void LinuxSensapp_send_sensapp_failRegister(struct LinuxSensapp_Instance *_instance){
if (LinuxSensapp_send_sensapp_failRegister_listener != 0x0) LinuxSensapp_send_sensapp_failRegister_listener(_instance);
}
void (*LinuxSensapp_send_sensapp_donePush_listener)(struct LinuxSensapp_Instance*)= 0x0;
void register_LinuxSensapp_send_sensapp_donePush_listener(void (*_listener)(struct LinuxSensapp_Instance*)){
LinuxSensapp_send_sensapp_donePush_listener = _listener;
}
void LinuxSensapp_send_sensapp_donePush(struct LinuxSensapp_Instance *_instance){
if (LinuxSensapp_send_sensapp_donePush_listener != 0x0) LinuxSensapp_send_sensapp_donePush_listener(_instance);
}
void (*LinuxSensapp_send_sensapp_failPush_listener)(struct LinuxSensapp_Instance*)= 0x0;
void register_LinuxSensapp_send_sensapp_failPush_listener(void (*_listener)(struct LinuxSensapp_Instance*)){
LinuxSensapp_send_sensapp_failPush_listener = _listener;
}
void LinuxSensapp_send_sensapp_failPush(struct LinuxSensapp_Instance *_instance){
if (LinuxSensapp_send_sensapp_failPush_listener != 0x0) LinuxSensapp_send_sensapp_failPush_listener(_instance);
}
void (*LinuxSensapp_send_sensapp_donePushRaw_listener)(struct LinuxSensapp_Instance*)= 0x0;
void register_LinuxSensapp_send_sensapp_donePushRaw_listener(void (*_listener)(struct LinuxSensapp_Instance*)){
LinuxSensapp_send_sensapp_donePushRaw_listener = _listener;
}
void LinuxSensapp_send_sensapp_donePushRaw(struct LinuxSensapp_Instance *_instance){
if (LinuxSensapp_send_sensapp_donePushRaw_listener != 0x0) LinuxSensapp_send_sensapp_donePushRaw_listener(_instance);
}
void (*LinuxSensapp_send_sensapp_failPushRaw_listener)(struct LinuxSensapp_Instance*)= 0x0;
void register_LinuxSensapp_send_sensapp_failPushRaw_listener(void (*_listener)(struct LinuxSensapp_Instance*)){
LinuxSensapp_send_sensapp_failPushRaw_listener = _listener;
}
void LinuxSensapp_send_sensapp_failPushRaw(struct LinuxSensapp_Instance *_instance){
if (LinuxSensapp_send_sensapp_failPushRaw_listener != 0x0) LinuxSensapp_send_sensapp_failPushRaw_listener(_instance);
}


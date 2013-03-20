/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing LinuxSensapp
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef LinuxSensapp_H_
#define LinuxSensapp_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : LinuxSensapp
 *****************************************************************************/


// BEGIN: Code from the c_header annotation LinuxSensapp

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
// END: Code from the c_header annotation LinuxSensapp

// Definition of the instance stuct:
struct LinuxSensapp_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int LinuxSensapp_LinuxSensappImpl_State;
// Variables for the properties of the instance
char * LinuxSensapp_server_var;
char * LinuxSensapp_p_var;
};

// Declaration of prototypes outgoing messages:
void LinuxSensapp_LinuxSensappImpl_OnEntry(int state, struct LinuxSensapp_Instance *_instance);
void LinuxSensapp_handle_sensapp_pushData(struct LinuxSensapp_Instance *_instance, char * sensorID, char * key, int value);
void LinuxSensapp_handle_sensapp_registerSensor(struct LinuxSensapp_Instance *_instance, char * name);
// Declaration of callbacks for incomming messages:

// Definition of the states:
#define LINUXSENSAPP_LINUXSENSAPPIMPL_STATE 0
#define LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //LinuxSensapp_H_
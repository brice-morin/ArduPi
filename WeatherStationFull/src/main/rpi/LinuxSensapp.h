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
    void LinuxSensapp_handle_sensapp_pushRawData(struct LinuxSensapp_Instance *_instance, char * data);
    void LinuxSensapp_handle_sensapp_registerSensor(struct LinuxSensapp_Instance *_instance, char * node, char * sensor);
    void LinuxSensapp_handle_sensapp_pushData(struct LinuxSensapp_Instance *_instance, char * node, char * sensor, int value, char * unit);
// Declaration of callbacks for incomming messages:
    void register_LinuxSensapp_send_sensapp_doneRegister_listener(void (*_listener)(struct LinuxSensapp_Instance*));
    void register_LinuxSensapp_send_sensapp_failRegister_listener(void (*_listener)(struct LinuxSensapp_Instance*));
    void register_LinuxSensapp_send_sensapp_donePush_listener(void (*_listener)(struct LinuxSensapp_Instance*));
    void register_LinuxSensapp_send_sensapp_failPush_listener(void (*_listener)(struct LinuxSensapp_Instance*));
    void register_LinuxSensapp_send_sensapp_donePushRaw_listener(void (*_listener)(struct LinuxSensapp_Instance*));
    void register_LinuxSensapp_send_sensapp_failPushRaw_listener(void (*_listener)(struct LinuxSensapp_Instance*));

// Definition of the states:
#define LINUXSENSAPP_LINUXSENSAPPIMPL_STATE 0
#define LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //LinuxSensapp_H_
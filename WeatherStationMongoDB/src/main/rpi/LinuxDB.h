/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing LinuxDB
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef LinuxDB_H_
#define LinuxDB_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : LinuxDB
 *****************************************************************************/


// BEGIN: Code from the c_header annotation LinuxDB

#include <stdio.h>
#include <time.h>
#include "mongo.h"

// END: Code from the c_header annotation LinuxDB

// Definition of the instance stuct:
struct LinuxDB_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int LinuxDB_LinuxDBImpl_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void LinuxDB_LinuxDBImpl_OnEntry(int state, struct LinuxDB_Instance *_instance);
void LinuxDB_handle_db_push_int(struct LinuxDB_Instance *_instance, char * db, char * sensor, int value);
void LinuxDB_handle_db_db_init(struct LinuxDB_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_LinuxDB_send_db_db_init_done_listener(void (*_listener)(struct LinuxDB_Instance*));

// Definition of the states:
#define LINUXDB_LINUXDBIMPL_STATE 0
#define LINUXDB_LINUXDBIMPL_RUNNING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //LinuxDB_H_
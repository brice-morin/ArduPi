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
        int LinuxDB_LinuxDBImpl_Upload_State;
// Variables for the properties of the instance
        long int LinuxDB_baseTime_var;
        long int LinuxDB_LinuxDBImpl_currentTime_var;
        char * LinuxDB_LinuxDBImpl_node_var;
        char * LinuxDB_LinuxDBImpl_sensor_var;
    };

// Declaration of prototypes outgoing messages:
    void LinuxDB_LinuxDBImpl_OnEntry(int state, struct LinuxDB_Instance *_instance);
    void LinuxDB_handle_db_db_init(struct LinuxDB_Instance *_instance);
    void LinuxDB_handle_db_db_upload(struct LinuxDB_Instance *_instance, char * node, char * sensor);
    void LinuxDB_handle_db_push_int(struct LinuxDB_Instance *_instance, char * node, char * sensor, int value);
    void LinuxDB_handle_sensapp_donePushRaw(struct LinuxDB_Instance *_instance);
    void LinuxDB_handle_sensapp_failPushRaw(struct LinuxDB_Instance *_instance);
    void LinuxDB_handle_timer_timer_timeout(struct LinuxDB_Instance *_instance);
// Declaration of callbacks for incomming messages:
    void register_LinuxDB_send_db_db_init_done_listener(void (*_listener)(struct LinuxDB_Instance*));
    void register_LinuxDB_send_sensapp_registerSensor_listener(void (*_listener)(struct LinuxDB_Instance*, char *, char *));
    void register_LinuxDB_send_sensapp_pushData_listener(void (*_listener)(struct LinuxDB_Instance*, char *, char *, int, char *));
    void register_LinuxDB_send_sensapp_pushRawData_listener(void (*_listener)(struct LinuxDB_Instance*, char *));
    void register_LinuxDB_send_timer_timer_start_listener(void (*_listener)(struct LinuxDB_Instance*, int));
    void register_LinuxDB_send_timer_timer_cancel_listener(void (*_listener)(struct LinuxDB_Instance*));

// Definition of the states:
#define LINUXDB_LINUXDBIMPL_STATE 0
#define LINUXDB_LINUXDBIMPL_RUNNING_STATE 1
#define LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE 2
#define LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE 3
#define LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE 4



#ifdef __cplusplus
}
#endif

#endif //LinuxDB_H_
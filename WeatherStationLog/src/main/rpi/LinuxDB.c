/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing LinuxDB
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "LinuxDB.h"

/*****************************************************************************
 * Implementation for type : LinuxDB
 *****************************************************************************/


// BEGIN: Code from the c_global annotation LinuxDB

#include <stdio.h>
#include <time.h>
#include "mongo.h"

void push_int(char* db, char* sensor, int value);
void push_string(char* db, char* sensor, char* value);
int init();
int destroy();
long int timestamp();
void initEntry();
void pushEntry(char* dbName);

mongo conn[1];
bson b[1];

// END: Code from the c_global annotation LinuxDB

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void LinuxDB_LinuxDBImpl_OnExit(int state, struct LinuxDB_Instance *_instance);
void LinuxDB_send_db_db_init_done(struct LinuxDB_Instance *_instance);
int f_LinuxDB_init_db(struct LinuxDB_Instance *_instance);
int f_LinuxDB_destroy(struct LinuxDB_Instance *_instance);
long int f_LinuxDB_timestamp(struct LinuxDB_Instance *_instance);
void f_LinuxDB_initEntry(struct LinuxDB_Instance *_instance);
void f_LinuxDB_pushEntry(struct LinuxDB_Instance *_instance, char * db);
void f_LinuxDB_push_int(struct LinuxDB_Instance *_instance, char * db, char * sensor, int value);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function init_db
int f_LinuxDB_init_db(struct LinuxDB_Instance *_instance) {
{

    int status = mongo_client( conn, "127.0.0.1", 27017 );
    if( status != MONGO_OK ) {
      switch ( conn->err ) {
        case MONGO_CONN_NO_SOCKET:  printf( "no socket\n" ); return 1;
        case MONGO_CONN_FAIL:       printf( "connection failed\n" ); return 1;
        case MONGO_CONN_NOT_MASTER: printf( "not master\n" ); return 1;
      }
      return conn->err;
    } else {
	   return 0;
    }
    
}
}

// Definition of function destroy
int f_LinuxDB_destroy(struct LinuxDB_Instance *_instance) {
{

	mongo_destroy( conn );
	bson_destroy( b );
	return 0;    
    
}
}

// Definition of function timestamp
long int f_LinuxDB_timestamp(struct LinuxDB_Instance *_instance) {
{

    long int ltime = /*static_cast<long int>*/ time(NULL);
    return ltime;
    
}
}

// Definition of function initEntry
void f_LinuxDB_initEntry(struct LinuxDB_Instance *_instance) {
{

	bson_init( b );
    bson_append_long(b, "t", f_LinuxDB_timestamp(_instance));    
    
}
}

// Definition of function pushEntry
void f_LinuxDB_pushEntry(struct LinuxDB_Instance *_instance, char * db) {
{

    mongo_write_concern options;
	mongo_write_concern_init(&options);
	bson_finish( b );
	mongo_insert( conn, db, b, &options);
	bson_destroy( b );
    
}
}

// Definition of function push_int
void f_LinuxDB_push_int(struct LinuxDB_Instance *_instance, char * db, char * sensor, int value) {
{
f_LinuxDB_initEntry(_instance);
bson_append_int(b, sensor, value);
f_LinuxDB_pushEntry(_instance, db);
}
}


// On Entry Actions:
void LinuxDB_LinuxDBImpl_OnEntry(int state, struct LinuxDB_Instance *_instance) {
switch(state) {
case LINUXDB_LINUXDBIMPL_STATE:
_instance->LinuxDB_LinuxDBImpl_State = LINUXDB_LINUXDBIMPL_RUNNING_STATE;
LinuxDB_LinuxDBImpl_OnEntry(_instance->LinuxDB_LinuxDBImpl_State, _instance);
break;
case LINUXDB_LINUXDBIMPL_RUNNING_STATE:
break;
default: break;
}
}

// On Exit Actions:
void LinuxDB_LinuxDBImpl_OnExit(int state, struct LinuxDB_Instance *_instance) {
switch(state) {
case LINUXDB_LINUXDBIMPL_STATE:
LinuxDB_LinuxDBImpl_OnExit(_instance->LinuxDB_LinuxDBImpl_State, _instance);
break;
case LINUXDB_LINUXDBIMPL_RUNNING_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void LinuxDB_handle_db_push_int(struct LinuxDB_Instance *_instance, char * db, char * sensor, int value) {
if (_instance->LinuxDB_LinuxDBImpl_State == LINUXDB_LINUXDBIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxDB_push_int(_instance, db, sensor, value);
}
}
}
}
void LinuxDB_handle_db_db_init(struct LinuxDB_Instance *_instance) {
if (_instance->LinuxDB_LinuxDBImpl_State == LINUXDB_LINUXDBIMPL_RUNNING_STATE) {
if (1) {
{
if(f_LinuxDB_init_db(_instance) == 0) {
LinuxDB_send_db_db_init_done(_instance);
}
}
}
}
}

// Observers for outgoing messages:
void (*LinuxDB_send_db_db_init_done_listener)(struct LinuxDB_Instance*)= 0x0;
void register_LinuxDB_send_db_db_init_done_listener(void (*_listener)(struct LinuxDB_Instance*)){
LinuxDB_send_db_db_init_done_listener = _listener;
}
void LinuxDB_send_db_db_init_done(struct LinuxDB_Instance *_instance){
if (LinuxDB_send_db_db_init_done_listener != 0x0) LinuxDB_send_db_db_init_done_listener(_instance);
}


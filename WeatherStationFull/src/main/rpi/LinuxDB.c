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

mongo conn[1];
bson b[1];
bson query[1];

// END: Code from the c_global annotation LinuxDB

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void LinuxDB_LinuxDBImpl_OnExit(int state, struct LinuxDB_Instance *_instance);
void LinuxDB_send_db_db_init_done(struct LinuxDB_Instance *_instance);
void LinuxDB_send_sensapp_registerSensor(struct LinuxDB_Instance *_instance, char * node, char * sensor);
void LinuxDB_send_sensapp_pushData(struct LinuxDB_Instance *_instance, char * node, char * sensor, int value, char * unit);
void LinuxDB_send_sensapp_pushRawData(struct LinuxDB_Instance *_instance, char * data);
void LinuxDB_send_timer_timer_start(struct LinuxDB_Instance *_instance, int delay);
void LinuxDB_send_timer_timer_cancel(struct LinuxDB_Instance *_instance);
void f_LinuxDB_createBT(struct LinuxDB_Instance *_instance);
void f_LinuxDB_initBT(struct LinuxDB_Instance *_instance);
int f_LinuxDB_init_db(struct LinuxDB_Instance *_instance);
int f_LinuxDB_destroy(struct LinuxDB_Instance *_instance);
long int f_LinuxDB_timestamp(struct LinuxDB_Instance *_instance);
void f_LinuxDB_initEntry(struct LinuxDB_Instance *_instance);
int f_LinuxDB_pushEntry(struct LinuxDB_Instance *_instance, char * db);
void f_LinuxDB_push_int(struct LinuxDB_Instance *_instance, char * node, char * sensor, int value);
char * f_LinuxDB_getDbName(struct LinuxDB_Instance *_instance, char * node, char * sensor);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function createBT
void f_LinuxDB_createBT(struct LinuxDB_Instance *_instance) {
{

    printf("Creating base time\n");
_instance->LinuxDB_baseTime_var = f_LinuxDB_timestamp(_instance);
bson_init( b );
    bson_append_long(b, "bt", _instance->LinuxDB_baseTime_var);
f_LinuxDB_pushEntry(_instance, "gateway.base");
}
}

// Definition of function initBT
void f_LinuxDB_initBT(struct LinuxDB_Instance *_instance) {
{

    mongo_cursor cursor[1];
    mongo_cursor_init(cursor, conn, "gateway.base" );

    if( mongo_cursor_next( cursor ) == MONGO_OK ) {
        bson_print( &cursor->current );
        bson_iterator iterator[1];
        if ( bson_find( iterator, mongo_cursor_bson( cursor ), "bt" )) {//base time is present in DB
_instance->LinuxDB_baseTime_var = bson_iterator_long( iterator );
            printf("Base time fetched from DB\n");
        } else {;
f_LinuxDB_createBT(_instance);
}
    } else {
f_LinuxDB_createBT(_instance);
}

    mongo_cursor_destroy( cursor );
    
}
}

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
f_LinuxDB_initBT(_instance);
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

    return time(NULL);
    
}
}

// Definition of function initEntry
void f_LinuxDB_initEntry(struct LinuxDB_Instance *_instance) {
{

	bson_init( b );
    bson_append_long(b, "t", f_LinuxDB_timestamp(_instance) - _instance->LinuxDB_baseTime_var);    
    
}
}

// Definition of function pushEntry
int f_LinuxDB_pushEntry(struct LinuxDB_Instance *_instance, char * db) {
{

    printf("pushing data to: %s\n", db);
    mongo_write_concern options[1];
    mongo_write_concern_init(options);
    options->w = 1;//ack
    options->j = 1;//journaled
    mongo_write_concern_finish(options);

    bson_finish( b );
int status = mongo_insert( conn, db, b, options);
    bson_destroy( b );
    mongo_write_concern_destroy(options);
    ;
return status;
}
}

// Definition of function push_int
void f_LinuxDB_push_int(struct LinuxDB_Instance *_instance, char * node, char * sensor, int value) {
{
f_LinuxDB_initEntry(_instance);
bson_append_int(b, "v", value);
f_LinuxDB_pushEntry(_instance, f_LinuxDB_getDbName(_instance, node, sensor));
}
}

// Definition of function getDbName
char * f_LinuxDB_getDbName(struct LinuxDB_Instance *_instance, char * node, char * sensor) {
{

    char* dbName[256];
    sprintf(dbName, "%s.%s", node, sensor);
    return dbName;
    
}
}


// On Entry Actions:
void LinuxDB_LinuxDBImpl_OnEntry(int state, struct LinuxDB_Instance *_instance) {
switch(state) {
case LINUXDB_LINUXDBIMPL_STATE:
_instance->LinuxDB_LinuxDBImpl_State = LINUXDB_LINUXDBIMPL_RUNNING_STATE;
_instance->LinuxDB_LinuxDBImpl_Upload_State = LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE;
LinuxDB_LinuxDBImpl_OnEntry(_instance->LinuxDB_LinuxDBImpl_State, _instance);
LinuxDB_LinuxDBImpl_OnEntry(_instance->LinuxDB_LinuxDBImpl_Upload_State, _instance);
break;
case LINUXDB_LINUXDBIMPL_RUNNING_STATE:
break;
case LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE:
break;
case LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE:
{

                    const char* dbName = 
f_LinuxDB_getDbName(_instance, _instance->LinuxDB_LinuxDBImpl_node_var, _instance->LinuxDB_LinuxDBImpl_sensor_var);
;
                    char data[262144];
                    mongo_cursor cursor[1];
                    bson_init(query);
                    bson_append_start_object(query, "t");
                    bson_append_long(query, "$lte", _instance->LinuxDB_LinuxDBImpl_currentTime_var);
                    bson_append_finish_object(query);
                    bson_finish(query);
                    
                    
                    mongo_cursor_init(cursor, conn, dbName);
                    mongo_cursor_set_query(cursor, query);

                    sprintf(data, "{\"bn\":\"%s/%s\", \"bu\":\"m\", \"bt\":%d, \"e\":[", _instance->LinuxDB_LinuxDBImpl_node_var, _instance->LinuxDB_LinuxDBImpl_sensor_var, _instance->LinuxDB_baseTime_var);

                    int i = 0;
                    while(mongo_cursor_next(cursor) == MONGO_OK) {
                        bson_iterator iterator[1];
                        if (bson_find(iterator, mongo_cursor_bson(cursor), "t")) {
                            char singleData[512];
                            long t = bson_iterator_long(iterator);
                            if (bson_find(iterator, mongo_cursor_bson(cursor), "v")) {
                                const long value = bson_iterator_long(iterator);
                                sprintf(singleData, "{\"t\":%d, \"v\":%d}", t, value);
                                if (i > 0)
                                    strcat(data, ", ");
                                strcat(data, singleData);
		                          printf("data: %s\n", singleData);
                                i++;
                            } else {
                                perror("Cannot find value\n");
                            }
                        } else {
                            perror("Cannot find timestamp\n");
                        }
                    }

                    strcat(data, "]}");
                    //printf("%s\n", data);
                    
LinuxDB_send_sensapp_pushRawData(_instance, data);
}
break;
case LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE:
{

                 mongo_write_concern con[1];
                 mongo_write_concern_init(con);
                 if(mongo_remove(conn, f_LinuxDB_getDbName(_instance, _instance->LinuxDB_LinuxDBImpl_node_var, _instance->LinuxDB_LinuxDBImpl_sensor_var), query, con) == MONGO_OK) {
                    printf("Uploaded data have been removed\n");
                 } else {
                    perror("Problem while removing uploaded data\n");
                 }
                 
LinuxDB_send_timer_timer_start(_instance, 1);
}
break;
default: break;
}
}

// On Exit Actions:
void LinuxDB_LinuxDBImpl_OnExit(int state, struct LinuxDB_Instance *_instance) {
switch(state) {
case LINUXDB_LINUXDBIMPL_STATE:
LinuxDB_LinuxDBImpl_OnExit(_instance->LinuxDB_LinuxDBImpl_State, _instance);
LinuxDB_LinuxDBImpl_OnExit(_instance->LinuxDB_LinuxDBImpl_Upload_State, _instance);
break;
case LINUXDB_LINUXDBIMPL_RUNNING_STATE:
break;
case LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE:
break;
case LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE:
break;
case LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
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
void LinuxDB_handle_db_db_upload(struct LinuxDB_Instance *_instance, char * node, char * sensor) {
if (_instance->LinuxDB_LinuxDBImpl_Upload_State == LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE) {
if (1) {
LinuxDB_LinuxDBImpl_OnExit(LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE, _instance);
_instance->LinuxDB_LinuxDBImpl_Upload_State = LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE;
{
_instance->LinuxDB_LinuxDBImpl_node_var = node;
_instance->LinuxDB_LinuxDBImpl_sensor_var = sensor;
_instance->LinuxDB_LinuxDBImpl_currentTime_var = f_LinuxDB_timestamp(_instance) - _instance->LinuxDB_baseTime_var;
}
LinuxDB_LinuxDBImpl_OnEntry(LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE, _instance);
}
}
}
void LinuxDB_handle_db_push_int(struct LinuxDB_Instance *_instance, char * node, char * sensor, int value) {
if (_instance->LinuxDB_LinuxDBImpl_State == LINUXDB_LINUXDBIMPL_RUNNING_STATE) {
if (1) {
{
f_LinuxDB_push_int(_instance, node, sensor, value);
}
}
}
}
void LinuxDB_handle_timer_timer_timeout(struct LinuxDB_Instance *_instance) {
if (_instance->LinuxDB_LinuxDBImpl_Upload_State == LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE) {
if (1) {
LinuxDB_LinuxDBImpl_OnExit(LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE, _instance);
_instance->LinuxDB_LinuxDBImpl_Upload_State = LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE;
LinuxDB_LinuxDBImpl_OnEntry(LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE, _instance);
}
}
}
void LinuxDB_handle_sensapp_failPushRaw(struct LinuxDB_Instance *_instance) {
if (_instance->LinuxDB_LinuxDBImpl_Upload_State == LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE) {
if (1) {
LinuxDB_LinuxDBImpl_OnExit(LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE, _instance);
_instance->LinuxDB_LinuxDBImpl_Upload_State = LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE;
LinuxDB_LinuxDBImpl_OnEntry(LINUXDB_LINUXDBIMPL_UPLOAD_WAITING_STATE, _instance);
}
}
}
void LinuxDB_handle_sensapp_donePushRaw(struct LinuxDB_Instance *_instance) {
if (_instance->LinuxDB_LinuxDBImpl_Upload_State == LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE) {
if (1) {
LinuxDB_LinuxDBImpl_OnExit(LINUXDB_LINUXDBIMPL_UPLOAD_UPLOADING_STATE, _instance);
_instance->LinuxDB_LinuxDBImpl_Upload_State = LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE;
LinuxDB_LinuxDBImpl_OnEntry(LINUXDB_LINUXDBIMPL_UPLOAD_DELETING_STATE, _instance);
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
void (*LinuxDB_send_sensapp_registerSensor_listener)(struct LinuxDB_Instance*, char *, char *)= 0x0;
void register_LinuxDB_send_sensapp_registerSensor_listener(void (*_listener)(struct LinuxDB_Instance*, char *, char *)){
LinuxDB_send_sensapp_registerSensor_listener = _listener;
}
void LinuxDB_send_sensapp_registerSensor(struct LinuxDB_Instance *_instance, char * node, char * sensor){
if (LinuxDB_send_sensapp_registerSensor_listener != 0x0) LinuxDB_send_sensapp_registerSensor_listener(_instance, node, sensor);
}
void (*LinuxDB_send_sensapp_pushData_listener)(struct LinuxDB_Instance*, char *, char *, int, char *)= 0x0;
void register_LinuxDB_send_sensapp_pushData_listener(void (*_listener)(struct LinuxDB_Instance*, char *, char *, int, char *)){
LinuxDB_send_sensapp_pushData_listener = _listener;
}
void LinuxDB_send_sensapp_pushData(struct LinuxDB_Instance *_instance, char * node, char * sensor, int value, char * unit){
if (LinuxDB_send_sensapp_pushData_listener != 0x0) LinuxDB_send_sensapp_pushData_listener(_instance, node, sensor, value, unit);
}
void (*LinuxDB_send_sensapp_pushRawData_listener)(struct LinuxDB_Instance*, char *)= 0x0;
void register_LinuxDB_send_sensapp_pushRawData_listener(void (*_listener)(struct LinuxDB_Instance*, char *)){
LinuxDB_send_sensapp_pushRawData_listener = _listener;
}
void LinuxDB_send_sensapp_pushRawData(struct LinuxDB_Instance *_instance, char * data){
if (LinuxDB_send_sensapp_pushRawData_listener != 0x0) LinuxDB_send_sensapp_pushRawData_listener(_instance, data);
}
void (*LinuxDB_send_timer_timer_start_listener)(struct LinuxDB_Instance*, int)= 0x0;
void register_LinuxDB_send_timer_timer_start_listener(void (*_listener)(struct LinuxDB_Instance*, int)){
LinuxDB_send_timer_timer_start_listener = _listener;
}
void LinuxDB_send_timer_timer_start(struct LinuxDB_Instance *_instance, int delay){
if (LinuxDB_send_timer_timer_start_listener != 0x0) LinuxDB_send_timer_timer_start_listener(_instance, delay);
}
void (*LinuxDB_send_timer_timer_cancel_listener)(struct LinuxDB_Instance*)= 0x0;
void register_LinuxDB_send_timer_timer_cancel_listener(void (*_listener)(struct LinuxDB_Instance*)){
LinuxDB_send_timer_timer_cancel_listener = _listener;
}
void LinuxDB_send_timer_timer_cancel(struct LinuxDB_Instance *_instance){
if (LinuxDB_send_timer_timer_cancel_listener != 0x0) LinuxDB_send_timer_timer_cancel_listener(_instance);
}


#include <stdio.h>
#include<time.h>
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

int main() {
  init();
  
  //Pushing 2*2 data related to sensor1
  push_int("sensapp.sensor1", "temp", 25);
  push_int("sensapp.sensor1", "light", 50);
  
  wait(2000);
  
  push_int("sensapp.sensor1", "temp", 24);
  push_int("sensapp.sensor1", "light", 47);

  //Pushing 2*2 data related to sensor1
  push_int("sensapp.sensor2", "temp", 12);
  push_int("sensapp.sensor2", "light", 37);
  
  wait(2000);
  
  push_int("sensapp.sensor2", "temp", 13);
  push_int("sensapp.sensor2", "light", 39);
  
  destroy();
  return 0;
}

int init() {
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

int destroy() {
	mongo_destroy( conn );
	bson_destroy( b );
	return 0;
}


long int timestamp()
{
    long int ltime = /*static_cast<long int>*/ time(NULL);
    return ltime;
}

void initEntry() {
	bson_init( b );
    bson_append_long(b, "t", timestamp());
}

void push_int(char* dbName, char* name, int value) {
	initEntry();
	bson_append_int(b, name, value);
	pushEntry(dbName);
}

void push_string(char* dbName, char* name, char* value) {
	initEntry();
	bson_append_string(b, name, value);
	pushEntry(dbName);
}

void pushEntry(char* dbName) {
	mongo_write_concern options;
	mongo_write_concern_init(&options);
	bson_finish( b );
	mongo_insert( conn, dbName, b, &options);
	bson_destroy( b );
}

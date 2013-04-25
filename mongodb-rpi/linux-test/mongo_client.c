#include <stdio.h>
#include<time.h>
#include "mongo.h"

int push_int(const char* nodeName, const char* sensorName, const int value);
int push_string(const char* nodeName, const char* sensorName, const char* value);
int init();
int destroy();
long int timestamp();
char* getDbName(const char* nodeName, const char* sensorName);
void initEntry();
int pushEntry(const char* dbName);
void initBT();
void createBT();
char* processNonUploaded(const char* nodeName, const char* sensorName, int upload(char* data));//uploads non already uploaded data
int fakeUpload(const char* data);//this should upload data to SensApp (see sensapp-curl tutorial)

mongo conn[1];
bson b[1];
long int baseTime = 0;

//TODO: base unit should be stored
int main() {
    init();
    printf("Base time: %ld\n", baseTime);

    //we drop all the sensors' db (just for testing purpose)
    mongo_cmd_drop_db(conn, "sensor1");
    mongo_cmd_drop_db(conn, "sensor2");

    //Pushing 2*2 data related to sensor1
    push_int("sensor1", "temp", 25);

    processNonUploaded("sensor1", "temp", &fakeUpload);//should upload one data
    processNonUploaded("sensor2", "temp", &fakeUpload);//should do nothing. In any case, should not crash the whole thing

    push_int("sensor1", "light", 50);

    sleep(2);

    push_int("sensor1", "temp", 24);
    push_int("sensor1", "light", 47);

    //Pushing 2*2 data related to sensor2
    push_int("sensor2", "temp", 12);
    push_int("sensor2", "light", 37);

    sleep(2);

    push_int("sensor2", "temp", 13);
    push_int("sensor2", "light", 39);

    processNonUploaded("sensor1", "temp", &fakeUpload);//should upload one data

    destroy();
    return 0;
}

//TODO: we should be more flexible on the size of the data (i.e., split into chunks if we have too much non-uploaded data)
//TODO: we could probably make it more agile on the update of data...
char* processNonUploaded(const char* nodeName, const char* sensorName, int upload(char* data)) {
    const long currentTime = timestamp() - baseTime;
    const char* dbName = getDbName(nodeName, sensorName);
    char data[262144];
    mongo_cursor cursor[1];

    bson query[1];
    bson_init(query);
    bson_append_start_object(query, "t");
    bson_append_long(query, "$lte", currentTime);
    bson_append_finish_object(query);
    bson_finish(query);

    mongo_cursor_init(cursor, conn, dbName);
    mongo_cursor_set_query(cursor, query);

    sprintf(data, "{\"bn\":\"%s/%s\", \"bu\":\"m\", \"bt\":%d, \"e\":[", nodeName, sensorName, baseTime);

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
    printf("%s\n", data);

    const int status = upload(data);
    if (status == 0) {
        mongo_write_concern con[1];
        mongo_write_concern_init(con);
        if(mongo_remove(conn, dbName, query, con) == MONGO_OK) {
            printf("Uploaded data have been removed\n");
        } else {
            perror("Problem while removing uploaded data\n");
        }
    }

    return status;

}

int fakeUpload(const char* data) {
    printf(data);
    printf("\n");
    return -1;//We simulate a fail (to keep data in the DB)
}

void createBT() {
    printf("Creating base time\n");
    baseTime = timestamp();
    bson_init( b );
    bson_append_long(b, "bt", baseTime);
    pushEntry("gateway.base");
}

/**
* Fetch base time from MongoDB, or initializes it
*/
void initBT() {
    mongo_cursor cursor[1];
    mongo_cursor_init(cursor, conn, "gateway.base" );

    if( mongo_cursor_next( cursor ) == MONGO_OK ) {
        bson_print( &cursor->current );
        bson_iterator iterator[1];
        if ( bson_find( iterator, mongo_cursor_bson( cursor ), "bt" )) {//base time is present in DB
            baseTime = bson_iterator_long( iterator );
            printf("Base time fetched from DB\n");
        } else {
            createBT();
        }
    } else {
        createBT();
    }

    mongo_cursor_destroy( cursor );
}

int init() {
    int status = mongo_client( conn, "127.0.0.1", 27017 );
    if( status != MONGO_OK ) {
        switch ( conn->err ) {
        case MONGO_CONN_NO_SOCKET:
            printf( "no socket\n" );
            return 1;
        case MONGO_CONN_FAIL:
            printf( "connection failed\n" );
            return 1;
        case MONGO_CONN_NOT_MASTER:
            printf( "not master\n" );
            return 1;
        }
        return conn->err;
    } else {
        initBT();
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
    return time(NULL);
}

char* getDbName(const char* nodeName, const char* sensorName) {
    char* dbName[256];
    sprintf(dbName, "%s.%s", nodeName, sensorName);
    return dbName;
}

void initEntry() {
    bson_init( b );
    bson_append_long(b, "t", timestamp() - baseTime);
}

int push_int(const char* nodeName, const char* sensorName, const int value) {
    initEntry();
    bson_append_int(b, "v", value);
    return pushEntry(getDbName(nodeName, sensorName));
}

int push_string(const char* nodeName, const char* sensorName, const char* value) {
    initEntry();
    bson_append_string(b, "v", value);
    return pushEntry(getDbName(nodeName, sensorName));
}

int pushEntry(const char* dbName) {
    printf("pushing data to: ");
    printf(dbName);
    printf("\n");
    mongo_write_concern options[1];
    mongo_write_concern_init(options);
    options->w = 1;//ack
    options->j = 1;//journaled
    mongo_write_concern_finish(options);

    bson_finish( b );
    int status = mongo_insert( conn, dbName, b, options);
    bson_destroy( b );
    mongo_write_concern_destroy(options);

    return status;
}

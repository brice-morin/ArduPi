/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing SerialProxy
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef SerialProxy_H_
#define SerialProxy_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : SerialProxy
 *****************************************************************************/

// Definition of the instance stuct:
struct SerialProxy_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int SerialProxy_SensorsDisplayImpl_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void SerialProxy_SensorsDisplayImpl_OnEntry(int state, struct SerialProxy_Instance *_instance);
void SerialProxy_handle_serializer_serial_tx(struct SerialProxy_Instance *_instance, uint8_t b);
void SerialProxy_handle_serial_serial_rx(struct SerialProxy_Instance *_instance, uint8_t b);
void SerialProxy_handle_serial_serial_opened(struct SerialProxy_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_SerialProxy_send_Start_start_listener(void (*_listener)(struct SerialProxy_Instance*));
void register_SerialProxy_send_serial_serial_open_listener(void (*_listener)(struct SerialProxy_Instance*, char *, int16_t));
void register_SerialProxy_send_serial_serial_tx_listener(void (*_listener)(struct SerialProxy_Instance*, uint8_t));
void register_SerialProxy_send_deserializer_serial_rx_listener(void (*_listener)(struct SerialProxy_Instance*, uint8_t));

// Definition of the states:
#define SERIALPROXY_SENSORSDISPLAYIMPL_STATE 0
#define SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE 1
#define SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE 2



#ifdef __cplusplus
}
#endif

#endif //SerialProxy_H_
/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing MessageDeserializer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef MessageDeserializer_H_
#define MessageDeserializer_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : MessageDeserializer
 *****************************************************************************/

// Definition of the instance stuct:
struct MessageDeserializer_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int MessageDeserializer_receive_State;
// Variables for the properties of the instance
uint8_t PacketManager_lengthInteger_var;
uint8_t PacketManager_lengthString_var;
uint8_t PacketManager_lengthUInt16_var;
int PacketManager_MAX_PACKET_SIZE_var;
uint8_t PacketManager_START_BYTE_var;
uint8_t PacketManager_STOP_BYTE_var;
uint8_t PacketManager_ESCAPE_BYTE_var;
int PacketManager_CODE_POSITION_var;
int PacketManager_LENGTH_POSITION_var;
int PacketManager_DATA_POSITION_var;
uint8_t PacketManager_buffer_var[16];
int PacketManager_index_var;
};

// Declaration of prototypes outgoing messages:
void MessageDeserializer_receive_OnEntry(int state, struct MessageDeserializer_Instance *_instance);
void MessageDeserializer_handle_serial_serial_rx(struct MessageDeserializer_Instance *_instance, uint8_t b);
// Declaration of callbacks for incomming messages:
void register_MessageDeserializer_send_RemoteControl_temperature_listener(void (*_listener)(struct MessageDeserializer_Instance*, uint16_t));
void register_MessageDeserializer_send_RemoteControl_light_listener(void (*_listener)(struct MessageDeserializer_Instance*, uint16_t));

// Definition of the states:
#define MESSAGEDESERIALIZER_RECEIVE_STATE 0
#define MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE 1
#define MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE 2
#define MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE 3



#ifdef __cplusplus
}
#endif

#endif //MessageDeserializer_H_
/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing MessageSerializer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef MessageSerializer_H_
#define MessageSerializer_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

    /*****************************************************************************
     * Headers for type : MessageSerializer
     *****************************************************************************/

// Definition of the instance stuct:
    struct MessageSerializer_Instance {
// Variables for the ID of the instance
        int id;
// Variables for the current instance state
        int MessageSerializer_SerializerBehavior_State;
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
    void MessageSerializer_SerializerBehavior_OnEntry(int state, struct MessageSerializer_Instance *_instance);
    void MessageSerializer_handle_RemoteControl_changeDisplay(struct MessageSerializer_Instance *_instance);
// Declaration of callbacks for incomming messages:
    void register_MessageSerializer_send_serial_serial_tx_listener(void (*_listener)(struct MessageSerializer_Instance*, uint8_t));

// Definition of the states:
#define MESSAGESERIALIZER_SERIALIZERBEHAVIOR_STATE 0
#define MESSAGESERIALIZER_SERIALIZERBEHAVIOR_SERIALIZE_STATE 1



#ifdef __cplusplus
}
#endif

#endif //MessageSerializer_H_
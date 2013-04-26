/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing MessageSerializer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "MessageSerializer.h"

/*****************************************************************************
 * Implementation for type : MessageSerializer
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
    void MessageSerializer_SerializerBehavior_OnExit(int state, struct MessageSerializer_Instance *_instance);
    void MessageSerializer_send_serial_serial_tx(struct MessageSerializer_Instance *_instance, uint8_t b);
    void f_MessageSerializer_serializeInteger(struct MessageSerializer_Instance *_instance, int d);
    void f_MessageSerializer_serializeUInt16(struct MessageSerializer_Instance *_instance, uint16_t d);
    void f_MessageSerializer_send(struct MessageSerializer_Instance *_instance);
    void f_MessageSerializer_setHeader(struct MessageSerializer_Instance *_instance, uint8_t code, uint8_t length);
    void f_MessageSerializer_storeByte(struct MessageSerializer_Instance *_instance, uint8_t b);
    uint8_t f_MessageSerializer_readByte(struct MessageSerializer_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function serializeInteger
void f_MessageSerializer_serializeInteger(struct MessageSerializer_Instance *_instance, int d) {
    {
        f_MessageSerializer_storeByte(_instance, (d >> 8) & 0x00ff);
        f_MessageSerializer_storeByte(_instance, (d) & 0x00ff);
    }
}

// Definition of function serializeUInt16
void f_MessageSerializer_serializeUInt16(struct MessageSerializer_Instance *_instance, uint16_t d) {
    {
        f_MessageSerializer_storeByte(_instance, (d >> 8) & 0x00ff);
        f_MessageSerializer_storeByte(_instance, (d) & 0x00ff);
    }
}

// Definition of function send
void f_MessageSerializer_send(struct MessageSerializer_Instance *_instance) {
    {
        MessageSerializer_send_serial_serial_tx(_instance, _instance->PacketManager_START_BYTE_var);
        int stop = _instance->PacketManager_DATA_POSITION_var + _instance->PacketManager_buffer_var[_instance->PacketManager_LENGTH_POSITION_var];
        int i = 0;
        while(i < stop) {
            uint8_t b = _instance->PacketManager_buffer_var[i];
            if(b == _instance->PacketManager_START_BYTE_var || b == _instance->PacketManager_STOP_BYTE_var || b == _instance->PacketManager_ESCAPE_BYTE_var) {
                MessageSerializer_send_serial_serial_tx(_instance, _instance->PacketManager_ESCAPE_BYTE_var);
            }
            MessageSerializer_send_serial_serial_tx(_instance, b);
            i = i + 1;
        }
        MessageSerializer_send_serial_serial_tx(_instance, _instance->PacketManager_STOP_BYTE_var);
        _instance->PacketManager_index_var = 0;
    }
}

// Definition of function setHeader
void f_MessageSerializer_setHeader(struct MessageSerializer_Instance *_instance, uint8_t code, uint8_t length) {
    {
        _instance->PacketManager_index_var = 0;
        f_MessageSerializer_storeByte(_instance, 1);
        f_MessageSerializer_storeByte(_instance, 0);
        f_MessageSerializer_storeByte(_instance, 0);
        _instance->PacketManager_CODE_POSITION_var = _instance->PacketManager_index_var;
        f_MessageSerializer_storeByte(_instance, code);
        _instance->PacketManager_LENGTH_POSITION_var = _instance->PacketManager_index_var;
        f_MessageSerializer_storeByte(_instance, length);
        _instance->PacketManager_DATA_POSITION_var = _instance->PacketManager_index_var;
        _instance->PacketManager_index_var = _instance->PacketManager_DATA_POSITION_var;
    }
}

// Definition of function storeByte
void f_MessageSerializer_storeByte(struct MessageSerializer_Instance *_instance, uint8_t b) {
    {
        if(_instance->PacketManager_index_var == _instance->PacketManager_MAX_PACKET_SIZE_var) {
            fprintf(stderr, ("BUFFER OVERFLOW\n"));

        }
        if(_instance->PacketManager_index_var < _instance->PacketManager_MAX_PACKET_SIZE_var) {
            _instance->PacketManager_buffer_var[_instance->PacketManager_index_var] = b;
            _instance->PacketManager_index_var = _instance->PacketManager_index_var + 1;
        }
    }
}

// Definition of function readByte
uint8_t f_MessageSerializer_readByte(struct MessageSerializer_Instance *_instance) {
    {
        uint8_t b;
        if(_instance->PacketManager_index_var < _instance->PacketManager_MAX_PACKET_SIZE_var) {
            b = _instance->PacketManager_buffer_var[_instance->PacketManager_index_var];
            _instance->PacketManager_index_var = _instance->PacketManager_index_var + 1;
        }
        if(_instance->PacketManager_index_var == _instance->PacketManager_MAX_PACKET_SIZE_var) {
            fprintf(stderr, ("BUFFER OVERFLOW: trying to read out of buffer boundaries"));

            b = _instance->PacketManager_STOP_BYTE_var;
        }
        return b;
    }
}


// On Entry Actions:
void MessageSerializer_SerializerBehavior_OnEntry(int state, struct MessageSerializer_Instance *_instance) {
    switch(state) {
    case MESSAGESERIALIZER_SERIALIZERBEHAVIOR_STATE:
        _instance->MessageSerializer_SerializerBehavior_State = MESSAGESERIALIZER_SERIALIZERBEHAVIOR_SERIALIZE_STATE;
        MessageSerializer_SerializerBehavior_OnEntry(_instance->MessageSerializer_SerializerBehavior_State, _instance);
        break;
    case MESSAGESERIALIZER_SERIALIZERBEHAVIOR_SERIALIZE_STATE:
        break;
    default:
        break;
    }
}

// On Exit Actions:
void MessageSerializer_SerializerBehavior_OnExit(int state, struct MessageSerializer_Instance *_instance) {
    switch(state) {
    case MESSAGESERIALIZER_SERIALIZERBEHAVIOR_STATE:
        MessageSerializer_SerializerBehavior_OnExit(_instance->MessageSerializer_SerializerBehavior_State, _instance);
        break;
    case MESSAGESERIALIZER_SERIALIZERBEHAVIOR_SERIALIZE_STATE:
        break;
    default:
        break;
    }
}

// Event Handlers for incomming messages:
void MessageSerializer_handle_RemoteControl_changeDisplay(struct MessageSerializer_Instance *_instance) {
    if (_instance->MessageSerializer_SerializerBehavior_State == MESSAGESERIALIZER_SERIALIZERBEHAVIOR_SERIALIZE_STATE) {
        if (1) {
            {
                f_MessageSerializer_setHeader(_instance, 20, 0);
                f_MessageSerializer_send(_instance);
            }
        }
    }
}

// Observers for outgoing messages:
void (*MessageSerializer_send_serial_serial_tx_listener)(struct MessageSerializer_Instance*, uint8_t)= 0x0;
void register_MessageSerializer_send_serial_serial_tx_listener(void (*_listener)(struct MessageSerializer_Instance*, uint8_t)) {
    MessageSerializer_send_serial_serial_tx_listener = _listener;
}
void MessageSerializer_send_serial_serial_tx(struct MessageSerializer_Instance *_instance, uint8_t b) {
    if (MessageSerializer_send_serial_serial_tx_listener != 0x0) MessageSerializer_send_serial_serial_tx_listener(_instance, b);
}


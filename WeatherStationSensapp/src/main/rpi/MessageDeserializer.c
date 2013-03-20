/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing MessageDeserializer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "MessageDeserializer.h"

/*****************************************************************************
 * Implementation for type : MessageDeserializer
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void MessageDeserializer_receive_OnExit(int state, struct MessageDeserializer_Instance *_instance);
void MessageDeserializer_send_RemoteControl_temperature(struct MessageDeserializer_Instance *_instance, uint16_t temp);
void MessageDeserializer_send_RemoteControl_light(struct MessageDeserializer_Instance *_instance, uint16_t light);
void f_MessageDeserializer_forward(struct MessageDeserializer_Instance *_instance);
void f_MessageDeserializer_deserializeRemote_temperature(struct MessageDeserializer_Instance *_instance);
void f_MessageDeserializer_deserializeRemote_light(struct MessageDeserializer_Instance *_instance);
int f_MessageDeserializer_deserializeInteger(struct MessageDeserializer_Instance *_instance);
uint16_t f_MessageDeserializer_deserializeUInt16(struct MessageDeserializer_Instance *_instance);
void f_MessageDeserializer_setHeader(struct MessageDeserializer_Instance *_instance, uint8_t code, uint8_t length);
void f_MessageDeserializer_storeByte(struct MessageDeserializer_Instance *_instance, uint8_t b);
uint8_t f_MessageDeserializer_readByte(struct MessageDeserializer_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function forward
void f_MessageDeserializer_forward(struct MessageDeserializer_Instance *_instance) {
{
_instance->PacketManager_index_var = _instance->PacketManager_DATA_POSITION_var;
uint8_t code = _instance->PacketManager_buffer_var[_instance->PacketManager_CODE_POSITION_var];
if(code == 10) {
f_MessageDeserializer_deserializeRemote_temperature(_instance);
}
if(code == 11) {
f_MessageDeserializer_deserializeRemote_light(_instance);
}
}
}

// Definition of function deserializeRemote_temperature
void f_MessageDeserializer_deserializeRemote_temperature(struct MessageDeserializer_Instance *_instance) {
{
uint16_t t = f_MessageDeserializer_deserializeUInt16(_instance);
MessageDeserializer_send_RemoteControl_temperature(_instance, t);
}
}

// Definition of function deserializeRemote_light
void f_MessageDeserializer_deserializeRemote_light(struct MessageDeserializer_Instance *_instance) {
{
uint16_t t = f_MessageDeserializer_deserializeUInt16(_instance);
MessageDeserializer_send_RemoteControl_light(_instance, t);
}
}

// Definition of function deserializeInteger
int f_MessageDeserializer_deserializeInteger(struct MessageDeserializer_Instance *_instance) {
{
int res = f_MessageDeserializer_readByte(_instance) << 8  + f_MessageDeserializer_readByte(_instance);
return res;
}
}

// Definition of function deserializeUInt16
uint16_t f_MessageDeserializer_deserializeUInt16(struct MessageDeserializer_Instance *_instance) {
{
uint16_t res = f_MessageDeserializer_readByte(_instance) << 8 |  + f_MessageDeserializer_readByte(_instance);
return res;
}
}

// Definition of function setHeader
void f_MessageDeserializer_setHeader(struct MessageDeserializer_Instance *_instance, uint8_t code, uint8_t length) {
{
_instance->PacketManager_index_var = 0;
f_MessageDeserializer_storeByte(_instance, 1);
f_MessageDeserializer_storeByte(_instance, 0);
f_MessageDeserializer_storeByte(_instance, 0);
_instance->PacketManager_CODE_POSITION_var = _instance->PacketManager_index_var;
f_MessageDeserializer_storeByte(_instance, code);
_instance->PacketManager_LENGTH_POSITION_var = _instance->PacketManager_index_var;
f_MessageDeserializer_storeByte(_instance, length);
_instance->PacketManager_DATA_POSITION_var = _instance->PacketManager_index_var;
_instance->PacketManager_index_var = _instance->PacketManager_DATA_POSITION_var;
}
}

// Definition of function storeByte
void f_MessageDeserializer_storeByte(struct MessageDeserializer_Instance *_instance, uint8_t b) {
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
uint8_t f_MessageDeserializer_readByte(struct MessageDeserializer_Instance *_instance) {
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
void MessageDeserializer_receive_OnEntry(int state, struct MessageDeserializer_Instance *_instance) {
switch(state) {
case MESSAGEDESERIALIZER_RECEIVE_STATE:
_instance->MessageDeserializer_receive_State = MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE;
MessageDeserializer_receive_OnEntry(_instance->MessageDeserializer_receive_State, _instance);
break;
case MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE:
_instance->PacketManager_index_var = 0;
break;
case MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE:
break;
case MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE:
break;
default: break;
}
}

// On Exit Actions:
void MessageDeserializer_receive_OnExit(int state, struct MessageDeserializer_Instance *_instance) {
switch(state) {
case MESSAGEDESERIALIZER_RECEIVE_STATE:
MessageDeserializer_receive_OnExit(_instance->MessageDeserializer_receive_State, _instance);
break;
case MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE:
break;
case MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE:
break;
case MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void MessageDeserializer_handle_serial_serial_rx(struct MessageDeserializer_Instance *_instance, uint8_t b) {
if (_instance->MessageDeserializer_receive_State == MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE) {
if (b == _instance->PacketManager_START_BYTE_var) {
MessageDeserializer_receive_OnExit(MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE, _instance);
_instance->MessageDeserializer_receive_State = MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE;
{
}
MessageDeserializer_receive_OnEntry(MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE, _instance);
}
}
else if (_instance->MessageDeserializer_receive_State == MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE) {
if (b == _instance->PacketManager_ESCAPE_BYTE_var) {
MessageDeserializer_receive_OnExit(MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE, _instance);
_instance->MessageDeserializer_receive_State = MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE;
{
}
MessageDeserializer_receive_OnEntry(MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE, _instance);
}
else if (b == _instance->PacketManager_STOP_BYTE_var) {
MessageDeserializer_receive_OnExit(MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE, _instance);
_instance->MessageDeserializer_receive_State = MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE;
{
f_MessageDeserializer_forward(_instance);
}
MessageDeserializer_receive_OnEntry(MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE, _instance);
}
else if ( !(b == _instance->PacketManager_ESCAPE_BYTE_var || b == _instance->PacketManager_STOP_BYTE_var || b == _instance->PacketManager_START_BYTE_var)) {
{
f_MessageDeserializer_storeByte(_instance, b);
}
}
else if (b == _instance->PacketManager_START_BYTE_var) {
{
_instance->PacketManager_index_var = 0;
}
}
}
else if (_instance->MessageDeserializer_receive_State == MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE) {
if (1) {
MessageDeserializer_receive_OnExit(MESSAGEDESERIALIZER_RECEIVE_ESCAPE_STATE, _instance);
_instance->MessageDeserializer_receive_State = MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE;
f_MessageDeserializer_storeByte(_instance, b);
MessageDeserializer_receive_OnEntry(MESSAGEDESERIALIZER_RECEIVE_RECEIVEMESSAGE_STATE, _instance);
}
}
}

// Observers for outgoing messages:
void (*MessageDeserializer_send_RemoteControl_temperature_listener)(struct MessageDeserializer_Instance*, uint16_t)= 0x0;
void register_MessageDeserializer_send_RemoteControl_temperature_listener(void (*_listener)(struct MessageDeserializer_Instance*, uint16_t)){
MessageDeserializer_send_RemoteControl_temperature_listener = _listener;
}
void MessageDeserializer_send_RemoteControl_temperature(struct MessageDeserializer_Instance *_instance, uint16_t temp){
if (MessageDeserializer_send_RemoteControl_temperature_listener != 0x0) MessageDeserializer_send_RemoteControl_temperature_listener(_instance, temp);
}
void (*MessageDeserializer_send_RemoteControl_light_listener)(struct MessageDeserializer_Instance*, uint16_t)= 0x0;
void register_MessageDeserializer_send_RemoteControl_light_listener(void (*_listener)(struct MessageDeserializer_Instance*, uint16_t)){
MessageDeserializer_send_RemoteControl_light_listener = _listener;
}
void MessageDeserializer_send_RemoteControl_light(struct MessageDeserializer_Instance *_instance, uint16_t light){
if (MessageDeserializer_send_RemoteControl_light_listener != 0x0) MessageDeserializer_send_RemoteControl_light_listener(_instance, light);
}


/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing SerialProxy
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "SerialProxy.h"

/*****************************************************************************
 * Implementation for type : SerialProxy
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void SerialProxy_SensorsDisplayImpl_OnExit(int state, struct SerialProxy_Instance *_instance);
void SerialProxy_send_Start_start(struct SerialProxy_Instance *_instance);
void SerialProxy_send_serial_serial_open(struct SerialProxy_Instance *_instance, char * device, int16_t baudrate);
void SerialProxy_send_serial_serial_tx(struct SerialProxy_Instance *_instance, uint8_t b);
void SerialProxy_send_deserializer_serial_rx(struct SerialProxy_Instance *_instance, uint8_t b);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void SerialProxy_SensorsDisplayImpl_OnEntry(int state, struct SerialProxy_Instance *_instance) {
switch(state) {
case SERIALPROXY_SENSORSDISPLAYIMPL_STATE:
_instance->SerialProxy_SensorsDisplayImpl_State = SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE;
SerialProxy_SensorsDisplayImpl_OnEntry(_instance->SerialProxy_SensorsDisplayImpl_State, _instance);
break;
case SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE:
{
SerialProxy_send_serial_serial_open(_instance, _instance->SerialProxy_serialPort_var, 9600);
}
break;
case SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE:
break;
default: break;
}
}

// On Exit Actions:
void SerialProxy_SensorsDisplayImpl_OnExit(int state, struct SerialProxy_Instance *_instance) {
switch(state) {
case SERIALPROXY_SENSORSDISPLAYIMPL_STATE:
SerialProxy_SensorsDisplayImpl_OnExit(_instance->SerialProxy_SensorsDisplayImpl_State, _instance);
break;
case SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE:
break;
case SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void SerialProxy_handle_serial_serial_opened(struct SerialProxy_Instance *_instance) {
if (_instance->SerialProxy_SensorsDisplayImpl_State == SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE) {
if (1) {
SerialProxy_SensorsDisplayImpl_OnExit(SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE, _instance);
_instance->SerialProxy_SensorsDisplayImpl_State = SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE;
SerialProxy_send_Start_start(_instance);
SerialProxy_SensorsDisplayImpl_OnEntry(SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
}
}
}
void SerialProxy_handle_serial_serial_rx(struct SerialProxy_Instance *_instance, uint8_t b) {
if (_instance->SerialProxy_SensorsDisplayImpl_State == SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
{
SerialProxy_send_deserializer_serial_rx(_instance, b);
}
}
}
}
void SerialProxy_handle_serializer_serial_tx(struct SerialProxy_Instance *_instance, uint8_t b) {
if (_instance->SerialProxy_SensorsDisplayImpl_State == SERIALPROXY_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
{
SerialProxy_send_serial_serial_tx(_instance, b);
}
}
}
}

// Observers for outgoing messages:
void (*SerialProxy_send_Start_start_listener)(struct SerialProxy_Instance*)= 0x0;
void register_SerialProxy_send_Start_start_listener(void (*_listener)(struct SerialProxy_Instance*)){
SerialProxy_send_Start_start_listener = _listener;
}
void SerialProxy_send_Start_start(struct SerialProxy_Instance *_instance){
if (SerialProxy_send_Start_start_listener != 0x0) SerialProxy_send_Start_start_listener(_instance);
}
void (*SerialProxy_send_serial_serial_open_listener)(struct SerialProxy_Instance*, char *, int16_t)= 0x0;
void register_SerialProxy_send_serial_serial_open_listener(void (*_listener)(struct SerialProxy_Instance*, char *, int16_t)){
SerialProxy_send_serial_serial_open_listener = _listener;
}
void SerialProxy_send_serial_serial_open(struct SerialProxy_Instance *_instance, char * device, int16_t baudrate){
if (SerialProxy_send_serial_serial_open_listener != 0x0) SerialProxy_send_serial_serial_open_listener(_instance, device, baudrate);
}
void (*SerialProxy_send_serial_serial_tx_listener)(struct SerialProxy_Instance*, uint8_t)= 0x0;
void register_SerialProxy_send_serial_serial_tx_listener(void (*_listener)(struct SerialProxy_Instance*, uint8_t)){
SerialProxy_send_serial_serial_tx_listener = _listener;
}
void SerialProxy_send_serial_serial_tx(struct SerialProxy_Instance *_instance, uint8_t b){
if (SerialProxy_send_serial_serial_tx_listener != 0x0) SerialProxy_send_serial_serial_tx_listener(_instance, b);
}
void (*SerialProxy_send_deserializer_serial_rx_listener)(struct SerialProxy_Instance*, uint8_t)= 0x0;
void register_SerialProxy_send_deserializer_serial_rx_listener(void (*_listener)(struct SerialProxy_Instance*, uint8_t)){
SerialProxy_send_deserializer_serial_rx_listener = _listener;
}
void SerialProxy_send_deserializer_serial_rx(struct SerialProxy_Instance *_instance, uint8_t b){
if (SerialProxy_send_deserializer_serial_rx_listener != 0x0) SerialProxy_send_deserializer_serial_rx_listener(_instance, b);
}


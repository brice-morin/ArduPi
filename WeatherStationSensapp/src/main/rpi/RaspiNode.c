/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *      Implementation for Application RaspiNode
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <signal.h>
#include <pthread.h>
#include "thingml_typedefs.h"
#include "runtime.h"
#include "LinuxSerial.h"
#include "LinuxClock.h"
#include "LinuxSensapp.h"
#include "MessageDeserializer.h"
#include "MessageSerializer.h"
#include "ClockTimer.h"
#include "WeatherStation.h"
#include "SerialProxy.h"



/*****************************************************************************
 * Definitions for configuration : RaspiNode
 *****************************************************************************/

//Declaration of instance variables
struct LinuxSerial_Instance RaspiNode_serial_var;
struct LinuxClock_Instance RaspiNode_c_var;
struct LinuxSensapp_Instance RaspiNode_server_var;
struct MessageDeserializer_Instance RaspiNode_deserializer_var;
struct MessageSerializer_Instance RaspiNode_serializer_var;
struct ClockTimer_Instance RaspiNode_t_var;
struct WeatherStation_Instance RaspiNode_app_var;
struct SerialProxy_Instance RaspiNode_proxy_var;

// Enqueue of messages LinuxSerial::serial::serial_rx
void enqueue_LinuxSerial_send_serial_serial_rx(struct LinuxSerial_Instance *_instance, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (1 >> 8) & 0xFF );
_fifo_enqueue( 1 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter b
_fifo_enqueue(b & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages LinuxSerial::serial::serial_opened
void enqueue_LinuxSerial_send_serial_serial_opened(struct LinuxSerial_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (2 >> 8) & 0xFF );
_fifo_enqueue( 2 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages LinuxClock::signal::clock_tick
void enqueue_LinuxClock_send_signal_clock_tick(struct LinuxClock_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (3 >> 8) & 0xFF );
_fifo_enqueue( 3 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages MessageDeserializer::RemoteControl::temperature
void enqueue_MessageDeserializer_send_RemoteControl_temperature(struct MessageDeserializer_Instance *_instance, uint16_t temp){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (4 >> 8) & 0xFF );
_fifo_enqueue( 4 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter temp
_fifo_enqueue((temp>>8) & 0xFF);
_fifo_enqueue(temp & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages MessageDeserializer::RemoteControl::light
void enqueue_MessageDeserializer_send_RemoteControl_light(struct MessageDeserializer_Instance *_instance, uint16_t light){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (5 >> 8) & 0xFF );
_fifo_enqueue( 5 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter light
_fifo_enqueue((light>>8) & 0xFF);
_fifo_enqueue(light & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages MessageSerializer::serial::serial_tx
void enqueue_MessageSerializer_send_serial_serial_tx(struct MessageSerializer_Instance *_instance, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (6 >> 8) & 0xFF );
_fifo_enqueue( 6 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter b
_fifo_enqueue(b & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages ClockTimer::timer::timer_timeout
void enqueue_ClockTimer_send_timer_timer_timeout(struct ClockTimer_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (7 >> 8) & 0xFF );
_fifo_enqueue( 7 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages WeatherStation::RemoteControlOut::changeDisplay
void enqueue_WeatherStation_send_RemoteControlOut_changeDisplay(struct WeatherStation_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (8 >> 8) & 0xFF );
_fifo_enqueue( 8 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages WeatherStation::timer::timer_start
void enqueue_WeatherStation_send_timer_timer_start(struct WeatherStation_Instance *_instance, int delay){
fifo_lock();
if ( fifo_byte_available() > 6 ) {

_fifo_enqueue( (9 >> 8) & 0xFF );
_fifo_enqueue( 9 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter delay
_fifo_enqueue((delay>>8) & 0xFF);
_fifo_enqueue(delay & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages WeatherStation::timer::timer_cancel
void enqueue_WeatherStation_send_timer_timer_cancel(struct WeatherStation_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (10 >> 8) & 0xFF );
_fifo_enqueue( 10 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages WeatherStation::sensapp::pushData
void enqueue_WeatherStation_send_sensapp_pushData(struct WeatherStation_Instance *_instance, char * sensorID, char * key, int value){
fifo_lock();
if ( fifo_byte_available() > 22 ) {

_fifo_enqueue( (11 >> 8) & 0xFF );
_fifo_enqueue( 11 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter sensorID
ptr_union_t __ptrunion_sensorID;
__ptrunion_sensorID.pointer = (void*)sensorID;
_fifo_enqueue( __ptrunion_sensorID.buffer[0] );
_fifo_enqueue( __ptrunion_sensorID.buffer[1] );
_fifo_enqueue( __ptrunion_sensorID.buffer[2] );
_fifo_enqueue( __ptrunion_sensorID.buffer[3] );
_fifo_enqueue( __ptrunion_sensorID.buffer[4] );
_fifo_enqueue( __ptrunion_sensorID.buffer[5] );
_fifo_enqueue( __ptrunion_sensorID.buffer[6] );
_fifo_enqueue( __ptrunion_sensorID.buffer[7] );

// parameter key
ptr_union_t __ptrunion_key;
__ptrunion_key.pointer = (void*)key;
_fifo_enqueue( __ptrunion_key.buffer[0] );
_fifo_enqueue( __ptrunion_key.buffer[1] );
_fifo_enqueue( __ptrunion_key.buffer[2] );
_fifo_enqueue( __ptrunion_key.buffer[3] );
_fifo_enqueue( __ptrunion_key.buffer[4] );
_fifo_enqueue( __ptrunion_key.buffer[5] );
_fifo_enqueue( __ptrunion_key.buffer[6] );
_fifo_enqueue( __ptrunion_key.buffer[7] );

// parameter value
_fifo_enqueue((value>>8) & 0xFF);
_fifo_enqueue(value & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages WeatherStation::sensapp::registerSensor
void enqueue_WeatherStation_send_sensapp_registerSensor(struct WeatherStation_Instance *_instance, char * name){
fifo_lock();
if ( fifo_byte_available() > 12 ) {

_fifo_enqueue( (12 >> 8) & 0xFF );
_fifo_enqueue( 12 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter name
ptr_union_t __ptrunion_name;
__ptrunion_name.pointer = (void*)name;
_fifo_enqueue( __ptrunion_name.buffer[0] );
_fifo_enqueue( __ptrunion_name.buffer[1] );
_fifo_enqueue( __ptrunion_name.buffer[2] );
_fifo_enqueue( __ptrunion_name.buffer[3] );
_fifo_enqueue( __ptrunion_name.buffer[4] );
_fifo_enqueue( __ptrunion_name.buffer[5] );
_fifo_enqueue( __ptrunion_name.buffer[6] );
_fifo_enqueue( __ptrunion_name.buffer[7] );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SerialProxy::Start::start
void enqueue_SerialProxy_send_Start_start(struct SerialProxy_Instance *_instance){
fifo_lock();
if ( fifo_byte_available() > 4 ) {

_fifo_enqueue( (13 >> 8) & 0xFF );
_fifo_enqueue( 13 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );
}
fifo_unlock_and_notify();
}
// Enqueue of messages SerialProxy::serial::serial_open
void enqueue_SerialProxy_send_serial_serial_open(struct SerialProxy_Instance *_instance, char * device, int16_t baudrate){
fifo_lock();
if ( fifo_byte_available() > 14 ) {

_fifo_enqueue( (14 >> 8) & 0xFF );
_fifo_enqueue( 14 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter device
ptr_union_t __ptrunion_device;
__ptrunion_device.pointer = (void*)device;
_fifo_enqueue( __ptrunion_device.buffer[0] );
_fifo_enqueue( __ptrunion_device.buffer[1] );
_fifo_enqueue( __ptrunion_device.buffer[2] );
_fifo_enqueue( __ptrunion_device.buffer[3] );
_fifo_enqueue( __ptrunion_device.buffer[4] );
_fifo_enqueue( __ptrunion_device.buffer[5] );
_fifo_enqueue( __ptrunion_device.buffer[6] );
_fifo_enqueue( __ptrunion_device.buffer[7] );

// parameter baudrate
_fifo_enqueue((baudrate>>8) & 0xFF);
_fifo_enqueue(baudrate & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages SerialProxy::serial::serial_tx
void enqueue_SerialProxy_send_serial_serial_tx(struct SerialProxy_Instance *_instance, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (15 >> 8) & 0xFF );
_fifo_enqueue( 15 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter b
_fifo_enqueue(b & 0xFF);
}
fifo_unlock_and_notify();
}
// Enqueue of messages SerialProxy::deserializer::serial_rx
void enqueue_SerialProxy_send_deserializer_serial_rx(struct SerialProxy_Instance *_instance, uint8_t b){
fifo_lock();
if ( fifo_byte_available() > 5 ) {

_fifo_enqueue( (16 >> 8) & 0xFF );
_fifo_enqueue( 16 & 0xFF );

// ID of the source instance
_fifo_enqueue( (_instance->id >> 8) & 0xFF );
_fifo_enqueue( _instance->id & 0xFF );

// parameter b
_fifo_enqueue(b & 0xFF);
}
fifo_unlock_and_notify();
}

// Dispatch for messages LinuxSerial::serial::serial_rx
void dispatch_LinuxSerial_send_serial_serial_rx(struct LinuxSerial_Instance *_instance, uint8_t b){
if (_instance == &RaspiNode_serial_var) {
SerialProxy_handle_serial_serial_rx(&RaspiNode_proxy_var, b);
}
}
// Dispatch for messages LinuxSerial::serial::serial_opened
void dispatch_LinuxSerial_send_serial_serial_opened(struct LinuxSerial_Instance *_instance){
if (_instance == &RaspiNode_serial_var) {
SerialProxy_handle_serial_serial_opened(&RaspiNode_proxy_var);
}
}
// Dispatch for messages LinuxClock::signal::clock_tick
void dispatch_LinuxClock_send_signal_clock_tick(struct LinuxClock_Instance *_instance){
if (_instance == &RaspiNode_c_var) {
ClockTimer_handle_clock_clock_tick(&RaspiNode_t_var);
}
}
// Dispatch for messages MessageDeserializer::RemoteControl::temperature
void dispatch_MessageDeserializer_send_RemoteControl_temperature(struct MessageDeserializer_Instance *_instance, uint16_t temp){
if (_instance == &RaspiNode_deserializer_var) {
WeatherStation_handle_RemoteControlIn_temperature(&RaspiNode_app_var, temp);
}
}
// Dispatch for messages MessageDeserializer::RemoteControl::light
void dispatch_MessageDeserializer_send_RemoteControl_light(struct MessageDeserializer_Instance *_instance, uint16_t light){
if (_instance == &RaspiNode_deserializer_var) {
WeatherStation_handle_RemoteControlIn_light(&RaspiNode_app_var, light);
}
}
// Dispatch for messages MessageSerializer::serial::serial_tx
void dispatch_MessageSerializer_send_serial_serial_tx(struct MessageSerializer_Instance *_instance, uint8_t b){
if (_instance == &RaspiNode_serializer_var) {
SerialProxy_handle_serializer_serial_tx(&RaspiNode_proxy_var, b);
}
}
// Dispatch for messages ClockTimer::timer::timer_timeout
void dispatch_ClockTimer_send_timer_timer_timeout(struct ClockTimer_Instance *_instance){
if (_instance == &RaspiNode_t_var) {
WeatherStation_handle_timer_timer_timeout(&RaspiNode_app_var);
}
}
// Dispatch for messages WeatherStation::RemoteControlOut::changeDisplay
void dispatch_WeatherStation_send_RemoteControlOut_changeDisplay(struct WeatherStation_Instance *_instance){
if (_instance == &RaspiNode_app_var) {
MessageSerializer_handle_RemoteControl_changeDisplay(&RaspiNode_serializer_var);
}
}
// Dispatch for messages WeatherStation::timer::timer_start
void dispatch_WeatherStation_send_timer_timer_start(struct WeatherStation_Instance *_instance, int delay){
if (_instance == &RaspiNode_app_var) {
ClockTimer_handle_timer_timer_start(&RaspiNode_t_var, delay);
}
}
// Dispatch for messages WeatherStation::timer::timer_cancel
void dispatch_WeatherStation_send_timer_timer_cancel(struct WeatherStation_Instance *_instance){
if (_instance == &RaspiNode_app_var) {
ClockTimer_handle_timer_timer_cancel(&RaspiNode_t_var);
}
}
// Dispatch for messages WeatherStation::sensapp::pushData
void dispatch_WeatherStation_send_sensapp_pushData(struct WeatherStation_Instance *_instance, char * sensorID, char * key, int value){
if (_instance == &RaspiNode_app_var) {
LinuxSensapp_handle_sensapp_pushData(&RaspiNode_server_var, sensorID, key, value);
}
}
// Dispatch for messages WeatherStation::sensapp::registerSensor
void dispatch_WeatherStation_send_sensapp_registerSensor(struct WeatherStation_Instance *_instance, char * name){
if (_instance == &RaspiNode_app_var) {
LinuxSensapp_handle_sensapp_registerSensor(&RaspiNode_server_var, name);
}
}
// Dispatch for messages SerialProxy::Start::start
void dispatch_SerialProxy_send_Start_start(struct SerialProxy_Instance *_instance){
if (_instance == &RaspiNode_proxy_var) {
WeatherStation_handle_Start_start(&RaspiNode_app_var);
}
}
// Dispatch for messages SerialProxy::serial::serial_open
void dispatch_SerialProxy_send_serial_serial_open(struct SerialProxy_Instance *_instance, char * device, int16_t baudrate){
if (_instance == &RaspiNode_proxy_var) {
LinuxSerial_handle_serial_serial_open(&RaspiNode_serial_var, device, baudrate);
}
}
// Dispatch for messages SerialProxy::serial::serial_tx
void dispatch_SerialProxy_send_serial_serial_tx(struct SerialProxy_Instance *_instance, uint8_t b){
if (_instance == &RaspiNode_proxy_var) {
LinuxSerial_handle_serial_serial_tx(&RaspiNode_serial_var, b);
}
}
// Dispatch for messages SerialProxy::deserializer::serial_rx
void dispatch_SerialProxy_send_deserializer_serial_rx(struct SerialProxy_Instance *_instance, uint8_t b){
if (_instance == &RaspiNode_proxy_var) {
MessageDeserializer_handle_serial_serial_rx(&RaspiNode_deserializer_var, b);
}
}

void processMessageQueue() {
fifo_lock();
while (fifo_empty()) fifo_wait();
byte mbuf[20];
uint8_t mbufi = 0;

// Read the code of the next port/message in the queue
uint16_t code = fifo_dequeue() << 8;

code += fifo_dequeue();

// Switch to call the appropriate handler
switch(code) {
case 1:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_LinuxSerial_send_serial_serial_rx((struct LinuxSerial_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* b */ );
break;
case 2:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_LinuxSerial_send_serial_serial_opened((struct LinuxSerial_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 3:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_LinuxClock_send_signal_clock_tick((struct LinuxClock_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 4:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_MessageDeserializer_send_RemoteControl_temperature((struct MessageDeserializer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* temp */ );
break;
case 5:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_MessageDeserializer_send_RemoteControl_light((struct MessageDeserializer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* light */ );
break;
case 6:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_MessageSerializer_send_serial_serial_tx((struct MessageSerializer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* b */ );
break;
case 7:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_ClockTimer_send_timer_timer_timeout((struct ClockTimer_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 8:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WeatherStation_send_RemoteControlOut_changeDisplay((struct WeatherStation_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 9:
while (mbufi < 4) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WeatherStation_send_timer_timer_start((struct WeatherStation_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(mbuf[2]<<8) + mbuf[3] /* delay */ );
break;
case 10:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WeatherStation_send_timer_timer_cancel((struct WeatherStation_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 11:
while (mbufi < 20) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WeatherStation_send_sensapp_pushData((struct WeatherStation_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* sensorID */ ,
(char *)((ptr_union_t*)(mbuf + 10))->pointer /* key */ ,
(mbuf[18]<<8) + mbuf[19] /* value */ );
break;
case 12:
while (mbufi < 10) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_WeatherStation_send_sensapp_registerSensor((struct WeatherStation_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* name */ );
break;
case 13:
while (mbufi < 2) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_SerialProxy_send_Start_start((struct SerialProxy_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */);
break;
case 14:
while (mbufi < 12) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_SerialProxy_send_serial_serial_open((struct SerialProxy_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
(char *)((ptr_union_t*)(mbuf + 2))->pointer /* device */ ,
(mbuf[10]<<8) + mbuf[11] /* baudrate */ );
break;
case 15:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_SerialProxy_send_serial_serial_tx((struct SerialProxy_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* b */ );
break;
case 16:
while (mbufi < 3) mbuf[mbufi++] = fifo_dequeue();
fifo_unlock();
dispatch_SerialProxy_send_deserializer_serial_rx((struct SerialProxy_Instance*)instance_by_id((mbuf[0] << 8) + mbuf[1]) /* instance */,
mbuf[2] /* b */ );
break;
}
}

void initialize_configuration_RaspiNode() {
// Initialize connectors
register_LinuxSerial_send_serial_serial_rx_listener(enqueue_LinuxSerial_send_serial_serial_rx);
register_LinuxSerial_send_serial_serial_opened_listener(enqueue_LinuxSerial_send_serial_serial_opened);
register_LinuxClock_send_signal_clock_tick_listener(enqueue_LinuxClock_send_signal_clock_tick);
register_MessageDeserializer_send_RemoteControl_temperature_listener(enqueue_MessageDeserializer_send_RemoteControl_temperature);
register_MessageDeserializer_send_RemoteControl_light_listener(enqueue_MessageDeserializer_send_RemoteControl_light);
register_MessageSerializer_send_serial_serial_tx_listener(enqueue_MessageSerializer_send_serial_serial_tx);
register_ClockTimer_send_timer_timer_timeout_listener(enqueue_ClockTimer_send_timer_timer_timeout);
register_WeatherStation_send_RemoteControlOut_changeDisplay_listener(enqueue_WeatherStation_send_RemoteControlOut_changeDisplay);
register_WeatherStation_send_timer_timer_start_listener(enqueue_WeatherStation_send_timer_timer_start);
register_WeatherStation_send_timer_timer_cancel_listener(enqueue_WeatherStation_send_timer_timer_cancel);
register_WeatherStation_send_sensapp_registerSensor_listener(enqueue_WeatherStation_send_sensapp_registerSensor);
register_WeatherStation_send_sensapp_pushData_listener(enqueue_WeatherStation_send_sensapp_pushData);
register_SerialProxy_send_Start_start_listener(enqueue_SerialProxy_send_Start_start);
register_SerialProxy_send_serial_serial_open_listener(enqueue_SerialProxy_send_serial_serial_open);
register_SerialProxy_send_serial_serial_tx_listener(enqueue_SerialProxy_send_serial_serial_tx);
register_SerialProxy_send_deserializer_serial_rx_listener(enqueue_SerialProxy_send_deserializer_serial_rx);

// Init the ID, state variables and properties for instance RaspiNode_serial
RaspiNode_serial_var.id = add_instance( (void*) &RaspiNode_serial_var);
RaspiNode_serial_var.LinuxSerial_LinuxSerialImpl_State = LINUXSERIAL_LINUXSERIALIMPL_RUNNING_STATE;

// Init the ID, state variables and properties for instance RaspiNode_c
RaspiNode_c_var.id = add_instance( (void*) &RaspiNode_c_var);
RaspiNode_c_var.LinuxClock_ClockImpl_State = LINUXCLOCK_CLOCKIMPL_TICKING_STATE;
RaspiNode_c_var.Clock_period_var = 1000;

// Init the ID, state variables and properties for instance RaspiNode_server
RaspiNode_server_var.id = add_instance( (void*) &RaspiNode_server_var);
RaspiNode_server_var.LinuxSensapp_LinuxSensappImpl_State = LINUXSENSAPP_LINUXSENSAPPIMPL_RUNNING_STATE;
RaspiNode_server_var.LinuxSensapp_server_var = "http://internal.sensapp.org";
RaspiNode_server_var.LinuxSensapp_p_var = "8080";

// Init the ID, state variables and properties for instance RaspiNode_deserializer
RaspiNode_deserializer_var.id = add_instance( (void*) &RaspiNode_deserializer_var);
RaspiNode_deserializer_var.MessageDeserializer_receive_State = MESSAGEDESERIALIZER_RECEIVE_IDLE_STATE;
RaspiNode_deserializer_var.PacketManager_lengthInteger_var = 2;
RaspiNode_deserializer_var.PacketManager_lengthString_var = 8;
RaspiNode_deserializer_var.PacketManager_lengthUInt16_var = 2;
RaspiNode_deserializer_var.PacketManager_MAX_PACKET_SIZE_var = 16;
RaspiNode_deserializer_var.PacketManager_START_BYTE_var = 0x7F;
RaspiNode_deserializer_var.PacketManager_STOP_BYTE_var = 0x7E;
RaspiNode_deserializer_var.PacketManager_ESCAPE_BYTE_var = 0x7D;
RaspiNode_deserializer_var.PacketManager_CODE_POSITION_var = 3;
RaspiNode_deserializer_var.PacketManager_LENGTH_POSITION_var = 4;
RaspiNode_deserializer_var.PacketManager_DATA_POSITION_var = 5;
RaspiNode_deserializer_var.PacketManager_index_var = 0;

// Init the ID, state variables and properties for instance RaspiNode_serializer
RaspiNode_serializer_var.id = add_instance( (void*) &RaspiNode_serializer_var);
RaspiNode_serializer_var.MessageSerializer_SerializerBehavior_State = MESSAGESERIALIZER_SERIALIZERBEHAVIOR_SERIALIZE_STATE;
RaspiNode_serializer_var.PacketManager_lengthInteger_var = 2;
RaspiNode_serializer_var.PacketManager_lengthString_var = 8;
RaspiNode_serializer_var.PacketManager_lengthUInt16_var = 2;
RaspiNode_serializer_var.PacketManager_MAX_PACKET_SIZE_var = 16;
RaspiNode_serializer_var.PacketManager_START_BYTE_var = 0x7F;
RaspiNode_serializer_var.PacketManager_STOP_BYTE_var = 0x7E;
RaspiNode_serializer_var.PacketManager_ESCAPE_BYTE_var = 0x7D;
RaspiNode_serializer_var.PacketManager_CODE_POSITION_var = 3;
RaspiNode_serializer_var.PacketManager_LENGTH_POSITION_var = 4;
RaspiNode_serializer_var.PacketManager_DATA_POSITION_var = 5;
RaspiNode_serializer_var.PacketManager_index_var = 0;

// Init the ID, state variables and properties for instance RaspiNode_t
RaspiNode_t_var.id = add_instance( (void*) &RaspiNode_t_var);
RaspiNode_t_var.ClockTimer_ClockTimerImpl_State = CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE;
RaspiNode_t_var.ClockTimer_ClockTimerImpl_remaining_var = 0;

// Init the ID, state variables and properties for instance RaspiNode_app
RaspiNode_app_var.id = add_instance( (void*) &RaspiNode_app_var);
RaspiNode_app_var.WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE;

// Init the ID, state variables and properties for instance RaspiNode_proxy
RaspiNode_proxy_var.id = add_instance( (void*) &RaspiNode_proxy_var);
RaspiNode_proxy_var.SerialProxy_SensorsDisplayImpl_State = SERIALPROXY_SENSORSDISPLAYIMPL_INIT_STATE;

LinuxSerial_LinuxSerialImpl_OnEntry(LINUXSERIAL_LINUXSERIALIMPL_STATE, &RaspiNode_serial_var);
LinuxClock_ClockImpl_OnEntry(LINUXCLOCK_CLOCKIMPL_STATE, &RaspiNode_c_var);
LinuxSensapp_LinuxSensappImpl_OnEntry(LINUXSENSAPP_LINUXSENSAPPIMPL_STATE, &RaspiNode_server_var);
MessageDeserializer_receive_OnEntry(MESSAGEDESERIALIZER_RECEIVE_STATE, &RaspiNode_deserializer_var);
MessageSerializer_SerializerBehavior_OnEntry(MESSAGESERIALIZER_SERIALIZERBEHAVIOR_STATE, &RaspiNode_serializer_var);
ClockTimer_ClockTimerImpl_OnEntry(CLOCKTIMER_CLOCKTIMERIMPL_STATE, &RaspiNode_t_var);
WeatherStation_SensorsDisplayImpl_OnEntry(WEATHERSTATION_SENSORSDISPLAYIMPL_STATE, &RaspiNode_app_var);
SerialProxy_SensorsDisplayImpl_OnEntry(SERIALPROXY_SENSORSDISPLAYIMPL_STATE, &RaspiNode_proxy_var);
}


int main(int argc, char *argv[]) {
  init_runtime();
  initialize_configuration_RaspiNode();


  while (1) {
    
    processMessageQueue();
  }
}
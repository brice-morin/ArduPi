/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing WeatherStation
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "WeatherStation.h"

/*****************************************************************************
 * Implementation for type : WeatherStation
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void WeatherStation_SensorsDisplayImpl_OnExit(int state, struct WeatherStation_Instance *_instance);
void WeatherStation_send_RemoteControlOut_changeDisplay(struct WeatherStation_Instance *_instance);
void WeatherStation_send_timer_timer_start(struct WeatherStation_Instance *_instance, int delay);
void WeatherStation_send_timer_timer_cancel(struct WeatherStation_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void WeatherStation_SensorsDisplayImpl_OnEntry(int state, struct WeatherStation_Instance *_instance) {
switch(state) {
case WEATHERSTATION_SENSORSDISPLAYIMPL_STATE:
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE;
WeatherStation_SensorsDisplayImpl_OnEntry(_instance->WeatherStation_SensorsDisplayImpl_State, _instance);
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE:
{
fprintf(stdout, ("Waiting...\n"));

}
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE:
{
WeatherStation_send_timer_timer_start(_instance, 2);
}
break;
default: break;
}
}

// On Exit Actions:
void WeatherStation_SensorsDisplayImpl_OnExit(int state, struct WeatherStation_Instance *_instance) {
switch(state) {
case WEATHERSTATION_SENSORSDISPLAYIMPL_STATE:
WeatherStation_SensorsDisplayImpl_OnExit(_instance->WeatherStation_SensorsDisplayImpl_State, _instance);
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE:
{
fprintf(stdout, ("Processing...\n"));

}
break;
case WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:
void WeatherStation_handle_RemoteControlIn_temperature(struct WeatherStation_Instance *_instance, uint16_t temp) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
{
fprintf(stdout, ("Temperature is: "));

printf("%u", temp);
fprintf(stdout, ("\n"));

}
}
}
}
void WeatherStation_handle_RemoteControlIn_light(struct WeatherStation_Instance *_instance, uint16_t light) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
{
fprintf(stdout, ("Light is: "));

printf("%u", light);
fprintf(stdout, ("\n"));

}
}
}
}
void WeatherStation_handle_timer_timer_timeout(struct WeatherStation_Instance *_instance) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE) {
if (1) {
WeatherStation_SensorsDisplayImpl_OnExit(WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE;
{
fprintf(stdout, ("Changing Display on Arduino\n"));

WeatherStation_send_RemoteControlOut_changeDisplay(_instance);
}
WeatherStation_SensorsDisplayImpl_OnEntry(WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
}
}
}
void WeatherStation_handle_Start_start(struct WeatherStation_Instance *_instance) {
if (_instance->WeatherStation_SensorsDisplayImpl_State == WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE) {
if (1) {
WeatherStation_SensorsDisplayImpl_OnExit(WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE, _instance);
_instance->WeatherStation_SensorsDisplayImpl_State = WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE;
WeatherStation_SensorsDisplayImpl_OnEntry(WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE, _instance);
}
}
}

// Observers for outgoing messages:
void (*WeatherStation_send_RemoteControlOut_changeDisplay_listener)(struct WeatherStation_Instance*)= 0x0;
void register_WeatherStation_send_RemoteControlOut_changeDisplay_listener(void (*_listener)(struct WeatherStation_Instance*)){
WeatherStation_send_RemoteControlOut_changeDisplay_listener = _listener;
}
void WeatherStation_send_RemoteControlOut_changeDisplay(struct WeatherStation_Instance *_instance){
if (WeatherStation_send_RemoteControlOut_changeDisplay_listener != 0x0) WeatherStation_send_RemoteControlOut_changeDisplay_listener(_instance);
}
void (*WeatherStation_send_timer_timer_start_listener)(struct WeatherStation_Instance*, int)= 0x0;
void register_WeatherStation_send_timer_timer_start_listener(void (*_listener)(struct WeatherStation_Instance*, int)){
WeatherStation_send_timer_timer_start_listener = _listener;
}
void WeatherStation_send_timer_timer_start(struct WeatherStation_Instance *_instance, int delay){
if (WeatherStation_send_timer_timer_start_listener != 0x0) WeatherStation_send_timer_timer_start_listener(_instance, delay);
}
void (*WeatherStation_send_timer_timer_cancel_listener)(struct WeatherStation_Instance*)= 0x0;
void register_WeatherStation_send_timer_timer_cancel_listener(void (*_listener)(struct WeatherStation_Instance*)){
WeatherStation_send_timer_timer_cancel_listener = _listener;
}
void WeatherStation_send_timer_timer_cancel(struct WeatherStation_Instance *_instance){
if (WeatherStation_send_timer_timer_cancel_listener != 0x0) WeatherStation_send_timer_timer_cancel_listener(_instance);
}


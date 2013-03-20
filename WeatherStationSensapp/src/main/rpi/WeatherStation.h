/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing WeatherStation
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef WeatherStation_H_
#define WeatherStation_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : WeatherStation
 *****************************************************************************/

// Definition of the instance stuct:
struct WeatherStation_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int WeatherStation_SensorsDisplayImpl_State;
// Variables for the properties of the instance
};

// Declaration of prototypes outgoing messages:
void WeatherStation_SensorsDisplayImpl_OnEntry(int state, struct WeatherStation_Instance *_instance);
void WeatherStation_handle_timer_timer_timeout(struct WeatherStation_Instance *_instance);
void WeatherStation_handle_RemoteControlIn_temperature(struct WeatherStation_Instance *_instance, uint16_t temp);
void WeatherStation_handle_RemoteControlIn_light(struct WeatherStation_Instance *_instance, uint16_t light);
void WeatherStation_handle_Start_start(struct WeatherStation_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_WeatherStation_send_RemoteControlOut_changeDisplay_listener(void (*_listener)(struct WeatherStation_Instance*));
void register_WeatherStation_send_timer_timer_start_listener(void (*_listener)(struct WeatherStation_Instance*, int));
void register_WeatherStation_send_timer_timer_cancel_listener(void (*_listener)(struct WeatherStation_Instance*));
void register_WeatherStation_send_sensapp_registerSensor_listener(void (*_listener)(struct WeatherStation_Instance*, char *));
void register_WeatherStation_send_sensapp_pushData_listener(void (*_listener)(struct WeatherStation_Instance*, char *, char *, int));

// Definition of the states:
#define WEATHERSTATION_SENSORSDISPLAYIMPL_STATE 0
#define WEATHERSTATION_SENSORSDISPLAYIMPL_INIT_STATE 1
#define WEATHERSTATION_SENSORSDISPLAYIMPL_PROCESS_STATE 2



#ifdef __cplusplus
}
#endif

#endif //WeatherStation_H_
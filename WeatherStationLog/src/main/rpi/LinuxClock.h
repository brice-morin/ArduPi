/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing LinuxClock
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef LinuxClock_H_
#define LinuxClock_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : LinuxClock
 *****************************************************************************/

// Definition of the instance stuct:
struct LinuxClock_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int LinuxClock_ClockImpl_State;
// Variables for the properties of the instance
int Clock_period_var;
};

// Declaration of prototypes outgoing messages:
void LinuxClock_ClockImpl_OnEntry(int state, struct LinuxClock_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_LinuxClock_send_signal_clock_tick_listener(void (*_listener)(struct LinuxClock_Instance*));

// Definition of the states:
#define LINUXCLOCK_CLOCKIMPL_STATE 0
#define LINUXCLOCK_CLOCKIMPL_TICKING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //LinuxClock_H_
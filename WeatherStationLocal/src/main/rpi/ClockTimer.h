/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing ClockTimer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef ClockTimer_H_
#define ClockTimer_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : ClockTimer
 *****************************************************************************/

// Definition of the instance stuct:
struct ClockTimer_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int ClockTimer_ClockTimerImpl_State;
// Variables for the properties of the instance
int ClockTimer_ClockTimerImpl_remaining_var;
};

// Declaration of prototypes outgoing messages:
void ClockTimer_ClockTimerImpl_OnEntry(int state, struct ClockTimer_Instance *_instance);
void ClockTimer_handle_timer_timer_start(struct ClockTimer_Instance *_instance, int delay);
void ClockTimer_handle_timer_timer_cancel(struct ClockTimer_Instance *_instance);
void ClockTimer_handle_clock_clock_tick(struct ClockTimer_Instance *_instance);
// Declaration of callbacks for incomming messages:
void register_ClockTimer_send_timer_timer_timeout_listener(void (*_listener)(struct ClockTimer_Instance*));

// Definition of the states:
#define CLOCKTIMER_CLOCKTIMERIMPL_STATE 0
#define CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE 1
#define CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE 2



#ifdef __cplusplus
}
#endif

#endif //ClockTimer_H_
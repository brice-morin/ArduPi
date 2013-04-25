/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing ClockTimer
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "ClockTimer.h"

/*****************************************************************************
 * Implementation for type : ClockTimer
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
    void ClockTimer_ClockTimerImpl_OnExit(int state, struct ClockTimer_Instance *_instance);
    void ClockTimer_send_timer_timer_timeout(struct ClockTimer_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:

// On Entry Actions:
void ClockTimer_ClockTimerImpl_OnEntry(int state, struct ClockTimer_Instance *_instance) {
    switch(state) {
    case CLOCKTIMER_CLOCKTIMERIMPL_STATE:
        _instance->ClockTimer_ClockTimerImpl_State = CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE;
        ClockTimer_ClockTimerImpl_OnEntry(_instance->ClockTimer_ClockTimerImpl_State, _instance);
        break;
    case CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE:
        break;
    case CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE:
        break;
    default:
        break;
    }
}

// On Exit Actions:
void ClockTimer_ClockTimerImpl_OnExit(int state, struct ClockTimer_Instance *_instance) {
    switch(state) {
    case CLOCKTIMER_CLOCKTIMERIMPL_STATE:
        ClockTimer_ClockTimerImpl_OnExit(_instance->ClockTimer_ClockTimerImpl_State, _instance);
        break;
    case CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE:
        break;
    case CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE:
        break;
    default:
        break;
    }
}

// Event Handlers for incomming messages:
void ClockTimer_handle_timer_timer_start(struct ClockTimer_Instance *_instance, int delay) {
    if (_instance->ClockTimer_ClockTimerImpl_State == CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE) {
        if (1) {
            ClockTimer_ClockTimerImpl_OnExit(CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE, _instance);
            _instance->ClockTimer_ClockTimerImpl_State = CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE;
            _instance->ClockTimer_ClockTimerImpl_remaining_var = delay;
            ClockTimer_ClockTimerImpl_OnEntry(CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE, _instance);
        }
    }
}
void ClockTimer_handle_timer_timer_cancel(struct ClockTimer_Instance *_instance) {
    if (_instance->ClockTimer_ClockTimerImpl_State == CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE) {
        if (1) {
            ClockTimer_ClockTimerImpl_OnExit(CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE, _instance);
            _instance->ClockTimer_ClockTimerImpl_State = CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE;
            ClockTimer_ClockTimerImpl_OnEntry(CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE, _instance);
        }
    }
}
void ClockTimer_handle_clock_clock_tick(struct ClockTimer_Instance *_instance) {
    if (_instance->ClockTimer_ClockTimerImpl_State == CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE) {
        if (_instance->ClockTimer_ClockTimerImpl_remaining_var == 0) {
            ClockTimer_ClockTimerImpl_OnExit(CLOCKTIMER_CLOCKTIMERIMPL_COUNTING_STATE, _instance);
            _instance->ClockTimer_ClockTimerImpl_State = CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE;
            ClockTimer_send_timer_timer_timeout(_instance);
            ClockTimer_ClockTimerImpl_OnEntry(CLOCKTIMER_CLOCKTIMERIMPL_IDLE_STATE, _instance);
        }
        else if (_instance->ClockTimer_ClockTimerImpl_remaining_var > 0) {
            _instance->ClockTimer_ClockTimerImpl_remaining_var = _instance->ClockTimer_ClockTimerImpl_remaining_var - 1;
        }
    }
}

// Observers for outgoing messages:
void (*ClockTimer_send_timer_timer_timeout_listener)(struct ClockTimer_Instance*)= 0x0;
void register_ClockTimer_send_timer_timer_timeout_listener(void (*_listener)(struct ClockTimer_Instance*)) {
    ClockTimer_send_timer_timer_timeout_listener = _listener;
}
void ClockTimer_send_timer_timer_timeout(struct ClockTimer_Instance *_instance) {
    if (ClockTimer_send_timer_timer_timeout_listener != 0x0) ClockTimer_send_timer_timer_timeout_listener(_instance);
}


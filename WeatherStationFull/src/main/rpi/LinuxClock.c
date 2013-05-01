/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *        Implementation for Thing LinuxClock
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#include "LinuxClock.h"

/*****************************************************************************
 * Implementation for type : LinuxClock
 *****************************************************************************/

// Declaration of prototypes:
#ifdef __cplusplus
extern "C" {
#endif
void LinuxClock_ClockImpl_OnExit(int state, struct LinuxClock_Instance *_instance);
void LinuxClock_send_signal_clock_tick(struct LinuxClock_Instance *_instance);
void f_LinuxClock_sleep_ms(struct LinuxClock_Instance *_instance, int timeout_ms);
void f_LinuxClock_start_clock_process(struct LinuxClock_Instance *_instance);
#ifdef __cplusplus
}
#endif

// Declaration of functions:
// Definition of function sleep_ms
void f_LinuxClock_sleep_ms(struct LinuxClock_Instance *_instance, int timeout_ms) {
{
struct timeval tv;
        tv.tv_sec = timeout_ms/1000;
        tv.tv_usec = (timeout_ms%1000) * 1000;
        select(0, NULL, NULL, NULL, &tv);
}
}

// Fork a thread to execute the function f_LinuxClock_start_clock_process

// Struct for the parameters of the function  f_LinuxClock_start_clock_process
struct f_LinuxClock_start_clock_process_struct {
  struct LinuxClock_Instance *_instance;

  pthread_mutex_t *lock;
  pthread_cond_t *cv;
};

// Definition of function start_receiver_process (executed in a separate thread)
void f_LinuxClock_start_clock_process_run(struct LinuxClock_Instance *_instance)
{
  {
while(1) {
f_LinuxClock_sleep_ms(_instance, _instance->Clock_period_var);
LinuxClock_send_signal_clock_tick(_instance);
}
}

}


void f_LinuxClock_start_clock_process_proc(void * p)
{
  // Get parameters from the main thread
  struct f_LinuxClock_start_clock_process_struct params = *((struct f_LinuxClock_start_clock_process_struct *) p);
  
  // Unblock the main thread
  pthread_mutex_lock(params.lock);
  pthread_cond_signal(params.cv);
  pthread_mutex_unlock(params.lock);
  
  // Run the function
  //f_LinuxClock_start_clock_process_run(params._instance, params.esums_device);
  f_LinuxClock_start_clock_process_run(params._instance);
}

// Operation called by the runtime and forking a new thread
void f_LinuxClock_start_clock_process(struct LinuxClock_Instance *_instance)
{
  // Store parameters
  struct f_LinuxClock_start_clock_process_struct params;
  pthread_mutex_t lock;
  pthread_cond_t cv;
  params.lock = &lock;
  params.cv = &cv;
  params._instance = _instance;

  pthread_mutex_init(params.lock, NULL);
  pthread_cond_init(params.cv, NULL);
  //Start the new thread
  pthread_mutex_lock(params.lock);
  pthread_t thread; 
  pthread_create( &thread, NULL, f_LinuxClock_start_clock_process_proc, (void*) &params);
  // Wait until it has started and read its parameters
  pthread_cond_wait(params.cv, params.lock);
  // Realease mutex
  pthread_mutex_unlock(params.lock);
}

// On Entry Actions:
void LinuxClock_ClockImpl_OnEntry(int state, struct LinuxClock_Instance *_instance) {
switch(state) {
case LINUXCLOCK_CLOCKIMPL_STATE:
_instance->LinuxClock_ClockImpl_State = LINUXCLOCK_CLOCKIMPL_TICKING_STATE;
f_LinuxClock_start_clock_process(_instance);
LinuxClock_ClockImpl_OnEntry(_instance->LinuxClock_ClockImpl_State, _instance);
break;
case LINUXCLOCK_CLOCKIMPL_TICKING_STATE:
break;
default: break;
}
}

// On Exit Actions:
void LinuxClock_ClockImpl_OnExit(int state, struct LinuxClock_Instance *_instance) {
switch(state) {
case LINUXCLOCK_CLOCKIMPL_STATE:
LinuxClock_ClockImpl_OnExit(_instance->LinuxClock_ClockImpl_State, _instance);
break;
case LINUXCLOCK_CLOCKIMPL_TICKING_STATE:
break;
default: break;
}
}

// Event Handlers for incomming messages:

// Observers for outgoing messages:
void (*LinuxClock_send_signal_clock_tick_listener)(struct LinuxClock_Instance*)= 0x0;
void register_LinuxClock_send_signal_clock_tick_listener(void (*_listener)(struct LinuxClock_Instance*)){
LinuxClock_send_signal_clock_tick_listener = _listener;
}
void LinuxClock_send_signal_clock_tick(struct LinuxClock_Instance *_instance){
if (LinuxClock_send_signal_clock_tick_listener != 0x0) LinuxClock_send_signal_clock_tick_listener(_instance);
}


/*****************************************************
 *      THIS IS A GENERATED FILE. DO NOT EDIT.
 *           Header for Thing LinuxSerial
 *  Generated from ThingML (http://www.thingml.org)
 *****************************************************/

#ifndef LinuxSerial_H_
#define LinuxSerial_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "thingml_typedefs.h"

/*****************************************************************************
 * Headers for type : LinuxSerial
 *****************************************************************************/


// BEGIN: Code from the c_header annotation LinuxSerial

#include <string.h> // string function definitions
#include <fcntl.h> // File control definitions
#include <errno.h> // Error number definitions
#include <termios.h> // POSIX terminal control definitions
#include <time.h>   // time calls

#define TIMEOUT 10 // timeout waiting for messages from the serial device
#define INPUT_BUFFER_SIZE 128 // for possible future optimizations
// END: Code from the c_header annotation LinuxSerial

// Definition of the instance stuct:
struct LinuxSerial_Instance {
// Variables for the ID of the instance
int id;
// Variables for the current instance state
int LinuxSerial_LinuxSerialImpl_State;
// Variables for the properties of the instance
int LinuxSerial_LinuxSerialImpl_serial_device_var;
};

// Declaration of prototypes outgoing messages:
void LinuxSerial_LinuxSerialImpl_OnEntry(int state, struct LinuxSerial_Instance *_instance);
void LinuxSerial_handle_serial_serial_tx(struct LinuxSerial_Instance *_instance, uint8_t b);
void LinuxSerial_handle_serial_serial_open(struct LinuxSerial_Instance *_instance, char * device, int16_t baudrate);
// Declaration of callbacks for incomming messages:
void register_LinuxSerial_send_serial_serial_rx_listener(void (*_listener)(struct LinuxSerial_Instance*, uint8_t));
void register_LinuxSerial_send_serial_serial_closed_listener(void (*_listener)(struct LinuxSerial_Instance*));
void register_LinuxSerial_send_serial_serial_opened_listener(void (*_listener)(struct LinuxSerial_Instance*));

// Definition of the states:
#define LINUXSERIAL_LINUXSERIALIMPL_STATE 0
#define LINUXSERIAL_LINUXSERIALIMPL_RUNNING_STATE 1



#ifdef __cplusplus
}
#endif

#endif //LinuxSerial_H_
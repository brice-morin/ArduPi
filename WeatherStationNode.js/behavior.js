var state_js = require('./lib/state.js');
function buildStateMachine(name) {
return new state_js.StateMachine(name);
}

function buildRegion(name, container){
return new state_js.Region(name, container);
}

function buildInitialState(name, container){
return new state_js.PseudoState(name, state_js.PseudoStateKind.Initial, container);
}

function buildFinalState(name, container){
return new state_js.PseudoState(name, state_js.PseudoStateKind.Final, container);
}

function buildHistoryState(name, container){
return new state_js.PseudoState(name, state_js.PseudoStateKind.ShallowHistory, container);
}

function buildSimpleState(name, container){
return new state_js.SimpleState(name, container);
}

function buildCompositeState(name, container){
return new state_js.CompositeState(name, container);
}

function buildEmptyTransition(source, target){
return new state_js.Transition(source, target);
}

function buildTransition(source, target, guard){
return new state_js.Transition(source, target, guard);
}

function Connector(client, server, clientPort, serverPort) {
this.client = client;
this.server = server;
this.clientPort = clientPort;
this.serverPort = serverPort;
}

Connector.prototype.forward = function(message) {//JSONified messsage, we need to update port before we send to server
var json = JSON.parse(message);
if (json.port === this.clientPort) {
json.port = this.serverPort;
this.server._receive(JSON.stringify(json));
} else {
json.port = this.clientPort;
this.client._receive(JSON.stringify(json));
}
}


/**
 * Definition for type : MessageSerializer
 **/
function MessageSerializer(PacketManager_lengthInteger__var, PacketManager_lengthString__var, PacketManager_lengthUInt16__var, PacketManager_MAX_PACKET_SIZE__var, PacketManager_START_BYTE__var, PacketManager_STOP_BYTE__var, PacketManager_ESCAPE_BYTE__var, PacketManager_CODE_POSITION__var, PacketManager_LENGTH_POSITION__var, PacketManager_DATA_POSITION__var, PacketManager_buffer__var, PacketManager_index__var) {

this.ready = false;
//Attributes
this.PacketManager_lengthInteger__var =PacketManager_lengthInteger__var;
this.PacketManager_lengthString__var =PacketManager_lengthString__var;
this.PacketManager_lengthUInt16__var =PacketManager_lengthUInt16__var;
this.PacketManager_MAX_PACKET_SIZE__var =PacketManager_MAX_PACKET_SIZE__var;
this.PacketManager_START_BYTE__var =PacketManager_START_BYTE__var;
this.PacketManager_STOP_BYTE__var =PacketManager_STOP_BYTE__var;
this.PacketManager_ESCAPE_BYTE__var =PacketManager_ESCAPE_BYTE__var;
this.PacketManager_CODE_POSITION__var =PacketManager_CODE_POSITION__var;
this.PacketManager_LENGTH_POSITION__var =PacketManager_LENGTH_POSITION__var;
this.PacketManager_DATA_POSITION__var =PacketManager_DATA_POSITION__var;
this.PacketManager_buffer__var =PacketManager_buffer__var;
this.PacketManager_index__var =PacketManager_index__var;//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
function serializeInteger(SerializerJS_serializeInteger_d__var) {

        var l = SerializerJS_serializeInteger_d__var;
        for ( var index = 0; index < 2; index ++ ) {
            var b = l & 0xff;
            storeByte(b)
            l = (l - b) / 256 ;
        }
        
}

this.serializeInteger = function(SerializerJS_serializeInteger_d__var) {
serializeInteger(SerializerJS_serializeInteger_d__var);}

function serializeUInt16(SerializerJS_serializeUInt16_d__var) {
serializeInteger(SerializerJS_serializeUInt16_d__var);
}

this.serializeUInt16 = function(SerializerJS_serializeUInt16_d__var) {
serializeUInt16(SerializerJS_serializeUInt16_d__var);}

function escape() {
var escaped__var = [];

var stop__var = PacketManager_DATA_POSITION__var + PacketManager_buffer__var[PacketManager_LENGTH_POSITION__var]
;

var i__var = 0;

var j__var = 0;

escaped__var[j__var] = PacketManager_START_BYTE__var;
j__var = j__var + 1;
var current__var;

while(i__var < stop__var) {
current__var = PacketManager_buffer__var[i__var]
;
if(current__var === PacketManager_START_BYTE__var || current__var === PacketManager_STOP_BYTE__var || current__var === PacketManager_ESCAPE_BYTE__var) {
escaped__var[j__var] = PacketManager_ESCAPE_BYTE__var;
j__var = j__var + 1;

}
escaped__var[j__var] = current__var;
j__var = j__var + 1;
i__var = i__var + 1;

}
escaped__var[j__var] = PacketManager_STOP_BYTE__var;
return escaped__var;
}

this.escape = function() {
escape();}

function send() {
sendWrite_bytesOnOut(escape());
}

this.send = function() {
send();}

function setHeader(PacketManager_setHeader_code__var, PacketManager_setHeader_length__var) {
PacketManager_index__var = 0;
storeByte(1);
storeByte(0);
storeByte(0);
PacketManager_CODE_POSITION__var = PacketManager_index__var;
storeByte(PacketManager_setHeader_code__var);
PacketManager_LENGTH_POSITION__var = PacketManager_index__var;
storeByte(PacketManager_setHeader_length__var);
PacketManager_DATA_POSITION__var = PacketManager_index__var;
PacketManager_index__var = PacketManager_DATA_POSITION__var;
}

this.setHeader = function(PacketManager_setHeader_code__var, PacketManager_setHeader_length__var) {
setHeader(PacketManager_setHeader_code__var, PacketManager_setHeader_length__var);}

function storeByte(PacketManager_storeByte_b__var) {
if(PacketManager_index__var === PacketManager_MAX_PACKET_SIZE__var) {
console.log("ERROR: " + "BUFFER OVERFLOW: " + PacketManager_storeByte_b__var + " has been ignored. Current index = " + PacketManager_index__var);

}
if(PacketManager_index__var < PacketManager_MAX_PACKET_SIZE__var) {
PacketManager_buffer__var[PacketManager_index__var] = PacketManager_storeByte_b__var;
PacketManager_index__var = PacketManager_index__var + 1;

}
}

this.storeByte = function(PacketManager_storeByte_b__var) {
storeByte(PacketManager_storeByte_b__var);}

function readByte() {
var b__var;

if(PacketManager_index__var < PacketManager_MAX_PACKET_SIZE__var) {
b__var = PacketManager_buffer__var[PacketManager_index__var]
;
PacketManager_index__var = PacketManager_index__var + 1;

}
if(PacketManager_index__var === PacketManager_MAX_PACKET_SIZE__var) {
console.log("ERROR: " + "BUFFER OVERFLOW: trying to read out of buffer boundaries");
b__var = PacketManager_STOP_BYTE__var;

}
return b__var;
}

this.readByte = function() {
readByte();}

//Internal functions
function _send(message) {
var json = JSON.parse(message);
var port = json.port;
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
var c = connectors[i];
c.forward(message);
}
}

function sendWrite_bytesOnOut(b) {
var msg = '{"message":"write_bytes","port":"out_c", "b":[' + b + ']}';
_send(msg);
}

//Init state machine
this.MessageSerializer_SerializerBehavior = buildStateMachine("SerializerBehavior");
var MessageSerializer_SerializerBehavior_default = buildRegion("_default", this.MessageSerializer_SerializerBehavior);
this._initial_MessageSerializer_SerializerBehavior = buildInitialState("_initial", MessageSerializer_SerializerBehavior_default);
//State machine (states and regions)
var MessageSerializer_SerializerBehavior_Serialize = buildSimpleState("Serialize", MessageSerializer_SerializerBehavior_default);
MessageSerializer_SerializerBehavior_Serialize.entry = [MessageSerializer_SerializerBehavior_Serialize_entry];
//State machine (transitions)
var t0 = new buildEmptyTransition(this._initial_MessageSerializer_SerializerBehavior, MessageSerializer_SerializerBehavior_Serialize);
var t1 = buildTransition(MessageSerializer_SerializerBehavior_Serialize, null, function (s, c) {var json = JSON.parse(c); return json.port === "RemoteControl_c" && json.message === "changeDisplay"});
t1.effect = [t1_effect];
//State machine (actions on states and transitions)
function MessageSerializer_SerializerBehavior_entry(context, message) {
console.log("Coder ready!");
}

function MessageSerializer_SerializerBehavior_Serialize_entry(context, message) {
console.log("Coder ready indeed!");
}

function t1_effect(context, message) {
var json = JSON.parse(message);
console.log("Serializing changeDisplay message");
setHeader(20, 0);
send();
}

}
//Public API for lifecycle management
MessageSerializer.prototype._stop = function() {
}

//Public API for third parties
MessageSerializer.prototype._init = function() {
console.log("Coder ready!");
this.MessageSerializer_SerializerBehavior.initialise( this._initial_MessageSerializer_SerializerBehavior );
var msg = this.getQueue().shift();
while(msg != null) {
this.MessageSerializer_SerializerBehavior.process(this._initial_MessageSerializer_SerializerBehavior, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

MessageSerializer.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.MessageSerializer_SerializerBehavior.process(this._initial_MessageSerializer_SerializerBehavior, msg);
msg = this.getQueue().shift();
}
}
}
MessageSerializer.prototype.getName = function() {
return "MessageSerializer";
}


/**
 * Definition for type : WeatherStation
 **/
function WeatherStation() {

this.ready = false;
//Attributes
//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
var guiListeners = [];
this.getGuiListeners = function() {
return guiListeners;
}
//ThingML-defined functions
//Internal functions
function _send(message) {
var json = JSON.parse(message);
var port = json.port;
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
var c = connectors[i];
c.forward(message);
}
}

function sendTemperatureOnGui(temp) {
var msg = '{"message":"temperature","port":"gui_c", "temp":' + temp + '}';
_send(msg);
//notify listeners
var arrayLength = guiListeners.length;
for (var i = 0; i < arrayLength; i++) {
guiListeners[i](msg);
}
}

function sendLightOnGui(light) {
var msg = '{"message":"light","port":"gui_c", "light":' + light + '}';
_send(msg);
//notify listeners
var arrayLength = guiListeners.length;
for (var i = 0; i < arrayLength; i++) {
guiListeners[i](msg);
}
}

function sendChangeDisplayOnRemoteControlOut() {
var msg = '{"message":"changeDisplay","port":"RemoteControlOut_s"}';
_send(msg);
}

function sendTimer_startOnTimer(delay) {
var msg = '{"message":"timer_start","port":"timer_c", "delay":' + delay + '}';
_send(msg);
}

function sendTimer_cancelOnTimer() {
var msg = '{"message":"timer_cancel","port":"timer_c"}';
_send(msg);
}

//Init state machine
this.WeatherStation_SensorsDisplayImpl = buildStateMachine("SensorsDisplayImpl");
var WeatherStation_SensorsDisplayImpl_default = buildRegion("_default", this.WeatherStation_SensorsDisplayImpl);
this._initial_WeatherStation_SensorsDisplayImpl = buildInitialState("_initial", WeatherStation_SensorsDisplayImpl_default);
//State machine (states and regions)
var WeatherStation_SensorsDisplayImpl_Process = buildSimpleState("Process", WeatherStation_SensorsDisplayImpl_default);
WeatherStation_SensorsDisplayImpl_Process.entry = [WeatherStation_SensorsDisplayImpl_Process_entry];
//State machine (transitions)
var t0 = new buildEmptyTransition(this._initial_WeatherStation_SensorsDisplayImpl, WeatherStation_SensorsDisplayImpl_Process);
var t1 = buildTransition(WeatherStation_SensorsDisplayImpl_Process, null, function (s, c) {var json = JSON.parse(c); return json.port === "RemoteControlIn_s" && json.message === "temperature"});
t1.effect = [t1_effect];
var t2 = buildTransition(WeatherStation_SensorsDisplayImpl_Process, null, function (s, c) {var json = JSON.parse(c); return json.port === "RemoteControlIn_s" && json.message === "light"});
t2.effect = [t2_effect];
var t3 = buildTransition(WeatherStation_SensorsDisplayImpl_Process, WeatherStation_SensorsDisplayImpl_Process, function (s, c) {var json = JSON.parse(c); return json.port === "timer_c" && json.message === "timer_timeout"});
t3.effect = [t3_effect];
var t4 = buildTransition(WeatherStation_SensorsDisplayImpl_Process, null, function (s, c) {var json = JSON.parse(c); return json.port === "gui_c" && json.message === "changeDisplay"});
t4.effect = [t4_effect];
//State machine (actions on states and transitions)
function WeatherStation_SensorsDisplayImpl_entry(context, message) {
console.log("Weather station ready!");
}

function WeatherStation_SensorsDisplayImpl_Process_entry(context, message) {
sendTimer_startOnTimer(3000);
}

function t1_effect(context, message) {
var json = JSON.parse(message);
console.log("Temperature is: " + json.temp);
sendTemperatureOnGui(json.temp);
}

function t2_effect(context, message) {
var json = JSON.parse(message);
console.log("Light is: " + json.light);
sendLightOnGui(json.light);
}

function t3_effect(context, message) {
var json = JSON.parse(message);
console.log("Changing Display on Arduino");
sendChangeDisplayOnRemoteControlOut();
}

function t4_effect(context, message) {
var json = JSON.parse(message);
console.log("Changing Display on Arduino");
sendChangeDisplayOnRemoteControlOut();
}

}
//Public API for lifecycle management
WeatherStation.prototype._stop = function() {
}

//Public API for third parties
WeatherStation.prototype._init = function() {
console.log("Weather station ready!");
this.WeatherStation_SensorsDisplayImpl.initialise( this._initial_WeatherStation_SensorsDisplayImpl );
var msg = this.getQueue().shift();
while(msg != null) {
this.WeatherStation_SensorsDisplayImpl.process(this._initial_WeatherStation_SensorsDisplayImpl, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

WeatherStation.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.WeatherStation_SensorsDisplayImpl.process(this._initial_WeatherStation_SensorsDisplayImpl, msg);
msg = this.getQueue().shift();
}
}
}
WeatherStation.prototype.getName = function() {
return "WeatherStation";
}

WeatherStation.prototype.receivechangeDisplayOngui = function() {
this._receive('{"message":"changeDisplay","port":"gui_c"}');
}


/**
 * Definition for type : SerialJS
 **/
function SerialJS(SerialJS_serialPort__var, SerialJS_lib__var, SerialJS_serialP__var, SerialJS_buffer__var, SerialJS_index__var) {

this.ready = false;
//Attributes
this.SerialJS_serialPort__var =SerialJS_serialPort__var;
this.SerialJS_lib__var =SerialJS_lib__var;
this.SerialJS_serialP__var =SerialJS_serialP__var;
this.SerialJS_buffer__var =SerialJS_buffer__var;
this.SerialJS_index__var =SerialJS_index__var;//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
function receive(SerialJS_receive_byte__var) {
if(SerialJS_buffer__var[0]
 === 0x13 && SerialJS_receive_byte__var === 0x12 || SerialJS_buffer__var[0]
 === 0x12) {
if( !(SerialJS_receive_byte__var === 0x13) || SerialJS_buffer__var[SerialJS_index__var - 1]
 === 0x7D) {
SerialJS_buffer__var[SerialJS_index__var] = SerialJS_receive_byte__var;
SerialJS_index__var = SerialJS_index__var + 1;

}
if(SerialJS_receive_byte__var === 0x13 &&  !(SerialJS_buffer__var[SerialJS_index__var - 1]
 === 0x7D)) {
sendReceive_bytesOnRead(SerialJS_buffer__var);
SerialJS_index__var = 0;
var i__var = 0;

while(i__var < 18) {
SerialJS_buffer__var[i__var] = 0x13;
i__var = i__var + 1;

}

}

}
}

this.receive = function(SerialJS_receive_byte__var) {
receive(SerialJS_receive_byte__var);}

function initSerial() {
var i__var = 0;

while(i__var < 18) {
SerialJS_buffer__var[i__var] = 0x13;
i__var = i__var + 1;

}
SerialJS_serialP__var = new SerialJS_lib__var.SerialPort(SerialJS_serialPort__var, {baudrate: 9600,   parser: SerialJS_lib__var.parsers.byteLength(1)}, false);;
SerialJS_serialP__var.open(function (error) {
if (error)
console.log("ERROR: " + "Problem opening the serial port... It might work, though most likely not :-)");
else
SerialJS_serialP__var.on('data', function(data) {
receive(data[0]);
});
console.log("Serial port opened sucessfully!");
})
}

this.initSerial = function() {
initSerial();}

function killSerial() {
SerialJS_serialP__var.close(function (error) {
if (error)
console.log("ERROR: " + "Problem closing the serial port...");
else
console.log("serial port closed!");
});
}

this.killSerial = function() {
killSerial();}

//Internal functions
function _send(message) {
var json = JSON.parse(message);
var port = json.port;
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
var c = connectors[i];
c.forward(message);
}
}

function sendReceive_bytesOnRead(b) {
var msg = '{"message":"receive_bytes","port":"read_s", "b":[' + b + ']}';
_send(msg);
}

function sendReceive_bytesOnIOStream(b) {
var msg = '{"message":"receive_bytes","port":"IOStream_s", "b":[' + b + ']}';
_send(msg);
}

//Init state machine
this.SerialJS_behavior = buildStateMachine("behavior");
var SerialJS_behavior_default = buildRegion("_default", this.SerialJS_behavior);
this._initial_SerialJS_behavior = buildInitialState("_initial", SerialJS_behavior_default);
//State machine (states and regions)
var SerialJS_behavior_default = buildSimpleState("default", SerialJS_behavior_default);
//State machine (transitions)
var t0 = new buildEmptyTransition(this._initial_SerialJS_behavior, SerialJS_behavior_default);
var t1 = buildTransition(SerialJS_behavior_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "write_s" && json.message === "write_bytes"});
t1.effect = [t1_effect];
//State machine (actions on states and transitions)
function SerialJS_behavior_entry(context, message) {
initSerial();
console.log("Serial port ready!");
}

function SerialJS_behavior_exit(context, message) {
killSerial();
console.log("Serial port killed, RIP!");
}

function t1_effect(context, message) {
var json = JSON.parse(message);
SerialJS_serialP__var.write(json.b, function(err, results) {
});
}

}
//Public API for lifecycle management
SerialJS.prototype._stop = function() {
this.killSerial();
console.log("Serial port killed, RIP!");
}

//Public API for third parties
SerialJS.prototype._init = function() {
this.initSerial();
console.log("Serial port ready!");
this.SerialJS_behavior.initialise( this._initial_SerialJS_behavior );
var msg = this.getQueue().shift();
while(msg != null) {
this.SerialJS_behavior.process(this._initial_SerialJS_behavior, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

SerialJS.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.SerialJS_behavior.process(this._initial_SerialJS_behavior, msg);
msg = this.getQueue().shift();
}
}
}
SerialJS.prototype.getName = function() {
return "SerialJS";
}


/**
 * Definition for type : MessageDeserializer
 **/
function MessageDeserializer(PacketManager_lengthInteger__var, PacketManager_lengthString__var, PacketManager_lengthUInt16__var, PacketManager_MAX_PACKET_SIZE__var, PacketManager_START_BYTE__var, PacketManager_STOP_BYTE__var, PacketManager_ESCAPE_BYTE__var, PacketManager_CODE_POSITION__var, PacketManager_LENGTH_POSITION__var, PacketManager_DATA_POSITION__var, PacketManager_buffer__var, PacketManager_index__var) {

this.ready = false;
//Attributes
this.PacketManager_lengthInteger__var =PacketManager_lengthInteger__var;
this.PacketManager_lengthString__var =PacketManager_lengthString__var;
this.PacketManager_lengthUInt16__var =PacketManager_lengthUInt16__var;
this.PacketManager_MAX_PACKET_SIZE__var =PacketManager_MAX_PACKET_SIZE__var;
this.PacketManager_START_BYTE__var =PacketManager_START_BYTE__var;
this.PacketManager_STOP_BYTE__var =PacketManager_STOP_BYTE__var;
this.PacketManager_ESCAPE_BYTE__var =PacketManager_ESCAPE_BYTE__var;
this.PacketManager_CODE_POSITION__var =PacketManager_CODE_POSITION__var;
this.PacketManager_LENGTH_POSITION__var =PacketManager_LENGTH_POSITION__var;
this.PacketManager_DATA_POSITION__var =PacketManager_DATA_POSITION__var;
this.PacketManager_buffer__var =PacketManager_buffer__var;
this.PacketManager_index__var =PacketManager_index__var;//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
function forward() {
PacketManager_index__var = PacketManager_DATA_POSITION__var;
var code__var = PacketManager_buffer__var[PacketManager_CODE_POSITION__var]
;

if(code__var === 10) {
deserializeRemote_temperature();

}
if(code__var === 11) {
deserializeRemote_light();

}
}

this.forward = function() {
forward();}

function deserializeRemote_temperature() {
var t__var = deserializeUInt16();

console.log("t: " + t__var);
sendTemperatureOnRemoteControl(t__var);
}

this.deserializeRemote_temperature = function() {
deserializeRemote_temperature();}

function deserializeRemote_light() {
var t__var = deserializeUInt16();

console.log("l: " + t__var);
sendLightOnRemoteControl(t__var);
}

this.deserializeRemote_light = function() {
deserializeRemote_light();}

function deserializeInteger() {

        var value = 0;
        for ( var i = 1; i >= 0; i--) {
            value = (value * 256) + readByte();
        }
        return value;        
        
}

this.deserializeInteger = function() {
deserializeInteger();}

function deserializeUInt16() {
return deserializeInteger();
}

this.deserializeUInt16 = function() {
deserializeUInt16();}

function receive(ArrayDeserializer_receive_bytes__var) {
PacketManager_index__var = 0;
var size__var = PacketManager_DATA_POSITION__var + ArrayDeserializer_receive_bytes__var[PacketManager_LENGTH_POSITION__var + 1]
 + 1;

var i__var = 0;

var current__var = ArrayDeserializer_receive_bytes__var[i__var]
;

if(current__var === PacketManager_START_BYTE__var) {
i__var = i__var + 1;
var next__var = ArrayDeserializer_receive_bytes__var[i__var]
;

if( !(next__var === PacketManager_STOP_BYTE__var)) {
var continue__var = true;

while(continue__var && i__var < size__var) {
current__var = next__var;
i__var = i__var + 1;
next__var = ArrayDeserializer_receive_bytes__var[i__var]
;
if(current__var === PacketManager_ESCAPE_BYTE__var) {
current__var = next__var;
i__var = i__var + 1;
size__var = size__var + 1;
next__var = ArrayDeserializer_receive_bytes__var[i__var]
;

}
storeByte(current__var);
continue__var =  !(next__var === PacketManager_STOP_BYTE__var &&  !(current__var === PacketManager_ESCAPE_BYTE__var));

}
storeByte(current__var);
forward();

}

}
}

this.receive = function(ArrayDeserializer_receive_bytes__var) {
receive(ArrayDeserializer_receive_bytes__var);}

function setHeader(PacketManager_setHeader_code__var, PacketManager_setHeader_length__var) {
PacketManager_index__var = 0;
storeByte(1);
storeByte(0);
storeByte(0);
PacketManager_CODE_POSITION__var = PacketManager_index__var;
storeByte(PacketManager_setHeader_code__var);
PacketManager_LENGTH_POSITION__var = PacketManager_index__var;
storeByte(PacketManager_setHeader_length__var);
PacketManager_DATA_POSITION__var = PacketManager_index__var;
PacketManager_index__var = PacketManager_DATA_POSITION__var;
}

this.setHeader = function(PacketManager_setHeader_code__var, PacketManager_setHeader_length__var) {
setHeader(PacketManager_setHeader_code__var, PacketManager_setHeader_length__var);}

function storeByte(PacketManager_storeByte_b__var) {
if(PacketManager_index__var === PacketManager_MAX_PACKET_SIZE__var) {
console.log("ERROR: " + "BUFFER OVERFLOW: " + PacketManager_storeByte_b__var + " has been ignored. Current index = " + PacketManager_index__var);

}
if(PacketManager_index__var < PacketManager_MAX_PACKET_SIZE__var) {
PacketManager_buffer__var[PacketManager_index__var] = PacketManager_storeByte_b__var;
PacketManager_index__var = PacketManager_index__var + 1;

}
}

this.storeByte = function(PacketManager_storeByte_b__var) {
storeByte(PacketManager_storeByte_b__var);}

function readByte() {
var b__var;

if(PacketManager_index__var < PacketManager_MAX_PACKET_SIZE__var) {
b__var = PacketManager_buffer__var[PacketManager_index__var]
;
PacketManager_index__var = PacketManager_index__var + 1;

}
if(PacketManager_index__var === PacketManager_MAX_PACKET_SIZE__var) {
console.log("ERROR: " + "BUFFER OVERFLOW: trying to read out of buffer boundaries");
b__var = PacketManager_STOP_BYTE__var;

}
return b__var;
}

this.readByte = function() {
readByte();}

function escape() {
var escaped__var = [];

var stop__var = PacketManager_DATA_POSITION__var + PacketManager_buffer__var[PacketManager_LENGTH_POSITION__var]
;

var i__var = 0;

var j__var = 0;

escaped__var[j__var] = PacketManager_START_BYTE__var;
j__var = j__var + 1;
var current__var;

while(i__var < stop__var) {
current__var = PacketManager_buffer__var[i__var]
;
if(current__var === PacketManager_START_BYTE__var || current__var === PacketManager_STOP_BYTE__var || current__var === PacketManager_ESCAPE_BYTE__var) {
escaped__var[j__var] = PacketManager_ESCAPE_BYTE__var;
j__var = j__var + 1;

}
escaped__var[j__var] = current__var;
j__var = j__var + 1;
i__var = i__var + 1;

}
escaped__var[j__var] = PacketManager_STOP_BYTE__var;
return escaped__var;
}

this.escape = function() {
escape();}

function send() {
sendWrite_bytesOnOut(escape());
}

this.send = function() {
send();}

//Internal functions
function _send(message) {
var json = JSON.parse(message);
var port = json.port;
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
var c = connectors[i];
c.forward(message);
}
}

function sendTemperatureOnRemoteControl(temp) {
var msg = '{"message":"temperature","port":"RemoteControl_c", "temp":' + temp + '}';
_send(msg);
}

function sendLightOnRemoteControl(light) {
var msg = '{"message":"light","port":"RemoteControl_c", "light":' + light + '}';
_send(msg);
}

function sendWrite_bytesOnOut(b) {
var msg = '{"message":"write_bytes","port":"out_c", "b":[' + b + ']}';
_send(msg);
}

//Init state machine
this.MessageDeserializer_receive = buildStateMachine("receive");
var MessageDeserializer_receive_default = buildRegion("_default", this.MessageDeserializer_receive);
this._initial_MessageDeserializer_receive = buildInitialState("_initial", MessageDeserializer_receive_default);
//State machine (states and regions)
var MessageDeserializer_receive_Idle = buildSimpleState("Idle", MessageDeserializer_receive_default);
MessageDeserializer_receive_Idle.entry = [MessageDeserializer_receive_Idle_entry];
//State machine (transitions)
var t0 = new buildEmptyTransition(this._initial_MessageDeserializer_receive, MessageDeserializer_receive_Idle);
var t1 = buildTransition(MessageDeserializer_receive_Idle, null, function (s, c) {var json = JSON.parse(c); return json.port === "in_c" && json.message === "receive_bytes"});
t1.effect = [t1_effect];
//State machine (actions on states and transitions)
function MessageDeserializer_receive_entry(context, message) {
console.log("Decoder ready!");
}

function MessageDeserializer_receive_Idle_entry(context, message) {
console.log("Decoder ready indeed!");
}

function t1_effect(context, message) {
var json = JSON.parse(message);
console.log("byte[] received from serial. Will try to decode it!...");
receive(json.b);
}

}
//Public API for lifecycle management
MessageDeserializer.prototype._stop = function() {
}

//Public API for third parties
MessageDeserializer.prototype._init = function() {
console.log("Decoder ready!");
this.MessageDeserializer_receive.initialise( this._initial_MessageDeserializer_receive );
var msg = this.getQueue().shift();
while(msg != null) {
this.MessageDeserializer_receive.process(this._initial_MessageDeserializer_receive, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

MessageDeserializer.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.MessageDeserializer_receive.process(this._initial_MessageDeserializer_receive, msg);
msg = this.getQueue().shift();
}
}
}
MessageDeserializer.prototype.getName = function() {
return "MessageDeserializer";
}


/**
 * Definition for type : TimerJS
 **/
function TimerJS() {

this.ready = false;
//Attributes
//bindings
var connectors = [];
this.getConnectors = function() {
return connectors;
}

//message queue
var queue = [];
this.getQueue = function() {
return queue;
}

//callbacks for third-party listeners
//ThingML-defined functions
function cancel() {
clearTimeout(this.timer);
}

this.cancel = function() {
cancel();}

function start(TimerJS_start_delay__var) {
console.log("timer.start");
this.timer = setTimeout(onTimeout,TimerJS_start_delay__var);
}

this.start = function(TimerJS_start_delay__var) {
start(TimerJS_start_delay__var);}

function onTimeout() {
console.log("timer.onTimeout");
sendTimer_timeoutOnTimer();
}

this.onTimeout = function() {
onTimeout();}

//Internal functions
function _send(message) {
var json = JSON.parse(message);
var port = json.port;
var arrayLength = connectors.length;
for (var i = 0; i < arrayLength; i++) {
var c = connectors[i];
c.forward(message);
}
}

function sendTimer_timeoutOnTimer() {
var msg = '{"message":"timer_timeout","port":"timer_s"}';
_send(msg);
}

//Init state machine
this.TimerJS_SoftTimer = buildStateMachine("SoftTimer");
var TimerJS_SoftTimer_default = buildRegion("_default", this.TimerJS_SoftTimer);
this._initial_TimerJS_SoftTimer = buildInitialState("_initial", TimerJS_SoftTimer_default);
//State machine (states and regions)
var TimerJS_SoftTimer_default = buildSimpleState("default", TimerJS_SoftTimer_default);
TimerJS_SoftTimer_default.entry = [TimerJS_SoftTimer_default_entry];
//State machine (transitions)
var t0 = new buildEmptyTransition(this._initial_TimerJS_SoftTimer, TimerJS_SoftTimer_default);
var t1 = buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_cancel"});
t1.effect = [t1_effect];
var t2 = buildTransition(TimerJS_SoftTimer_default, null, function (s, c) {var json = JSON.parse(c); return json.port === "timer_s" && json.message === "timer_start" && json.delay > 0});
t2.effect = [t2_effect];
//State machine (actions on states and transitions)
function TimerJS_SoftTimer_default_entry(context, message) {
console.log("debug timer on entry");
}

function t1_effect(context, message) {
var json = JSON.parse(message);
cancel();
}

function t2_effect(context, message) {
var json = JSON.parse(message);
console.log("debug timer");
start(json.delay);
}

}
//Public API for lifecycle management
TimerJS.prototype._stop = function() {
}

//Public API for third parties
TimerJS.prototype._init = function() {
this.TimerJS_SoftTimer.initialise( this._initial_TimerJS_SoftTimer );
var msg = this.getQueue().shift();
while(msg != null) {
this.TimerJS_SoftTimer.process(this._initial_TimerJS_SoftTimer, msg);
msg = this.getQueue().shift();
}
this.ready = true;
}

TimerJS.prototype._receive = function(message) {//takes a JSONified message
this.getQueue().push(message);
if (this.ready) {
var msg = this.getQueue().shift();
while(msg != null) {
this.TimerJS_SoftTimer.process(this._initial_TimerJS_SoftTimer, msg);
msg = this.getQueue().shift();
}
}
}
TimerJS.prototype.getName = function() {
return "TimerJS";
}

var JSWeatherNode_app = new WeatherStation();
var JSWeatherNode_serializer_buffer_array = [];
var JSWeatherNode_serializer = new MessageSerializer(2, 8, 2, 16, 0x12, 0x13, 0x7D, 3, 4, 5, JSWeatherNode_serializer_buffer_array, 0);
var JSWeatherNode_serial_buffer_array = [];
var JSWeatherNode_serial = new SerialJS("COM13", require("serialport"), null, JSWeatherNode_serial_buffer_array, 0);
var JSWeatherNode_timer = new TimerJS();
var JSWeatherNode_deserializer_buffer_array = [];
var JSWeatherNode_deserializer = new MessageDeserializer(2, 8, 2, 16, 0x12, 0x13, 0x7D, 3, 4, 5, JSWeatherNode_deserializer_buffer_array, 0);
JSWeatherNode_serializer.getConnectors().push(new Connector(JSWeatherNode_serial, JSWeatherNode_serializer, "write_s", "out_c"));
JSWeatherNode_serial.getConnectors().push(new Connector(JSWeatherNode_serializer, JSWeatherNode_serial, "out_c", "write_s"));
JSWeatherNode_serializer.getConnectors().push(new Connector(JSWeatherNode_app, JSWeatherNode_serializer, "RemoteControlOut_s", "RemoteControl_c"));
JSWeatherNode_app.getConnectors().push(new Connector(JSWeatherNode_serializer, JSWeatherNode_app, "RemoteControl_c", "RemoteControlOut_s"));
JSWeatherNode_app.getConnectors().push(new Connector(JSWeatherNode_timer, JSWeatherNode_app, "timer_s", "timer_c"));
JSWeatherNode_timer.getConnectors().push(new Connector(JSWeatherNode_app, JSWeatherNode_timer, "timer_c", "timer_s"));
JSWeatherNode_deserializer.getConnectors().push(new Connector(JSWeatherNode_serial, JSWeatherNode_deserializer, "read_s", "in_c"));
JSWeatherNode_serial.getConnectors().push(new Connector(JSWeatherNode_deserializer, JSWeatherNode_serial, "in_c", "read_s"));
JSWeatherNode_deserializer.getConnectors().push(new Connector(JSWeatherNode_app, JSWeatherNode_deserializer, "RemoteControlIn_s", "RemoteControl_c"));
JSWeatherNode_app.getConnectors().push(new Connector(JSWeatherNode_deserializer, JSWeatherNode_app, "RemoteControl_c", "RemoteControlIn_s"));
JSWeatherNode_app._init();
JSWeatherNode_serializer._init();
JSWeatherNode_timer._init();
JSWeatherNode_deserializer._init();
JSWeatherNode_serial._init();
//terminate all things on SIGINT (e.g. CTRL+C)
process.on('SIGINT', function() {
JSWeatherNode_app._stop();
JSWeatherNode_serial._stop();
JSWeatherNode_deserializer._stop();
JSWeatherNode_serializer._stop();
JSWeatherNode_timer._stop();
});




function WebSocketGuiListener(thing, port) {

var WebSocketServer = require('websocket').server;
var WebSocketClient = require('websocket').client;
var http = require('http');

//Server
var server = http.createServer(function(request, response) {
    console.log((new Date()) + ' Received request for ' + request.url);
    response.writeHead(404);
    response.end();
});
server.listen(port, function() {
    console.log((new Date()) + ' Server is listening on port ' + port);
});

wsServer = new WebSocketServer({
    httpServer: server,
    // You should not use autoAcceptConnections for production
    // applications, as it defeats all standard cross-origin protection
    // facilities built into the protocol and the browser.  You should
    // *always* verify the connection's origin and decide whether or not
    // to accept it.
    autoAcceptConnections: false
});

function originIsAllowed(origin) {
  // put logic here to detect whether the specified origin is allowed.
  return true;
}

var clients = [];

wsServer.on('request', function(request) {
    if (!originIsAllowed(request.origin)) {
      // Make sure we only accept requests from an allowed origin
      request.reject();
      console.log((new Date()) + ' Connection from origin ' + request.origin + ' rejected.');
      return;
    }

	
    var connection = request.accept(null, request.origin);
	clients.push(connection);
    console.log((new Date()) + ' Connection accepted.');
    connection.on('message', function(message) {
        if (message.type === 'utf8') {
            console.log('Received Message: ' + message.utf8Data);
			var arrayLength = clients.length;
			for (var i = 0; i < arrayLength; i++) {
				clients[i].sendUTF(message.utf8Data);
			}            
        }
    });
    connection.on('close', function(reasonCode, description) {
        console.log((new Date()) + ' Peer ' + connection.remoteAddress + ' disconnected.');
		var index = clients.indexOf(connection);
		if (index > -1) {
			clients.splice(index, 1);
		}
    });
});




	//client
	var client = new WebSocketClient();
	var clientConnection = null;

	client.on('connectFailed', function(error) {
		console.log('Connect Error: ' + error.toString());
	});

	client.on('connect', function(connection) {
		clientConnection = connection;
		console.log('WebSocket client connected');
		connection.on('error', function(error) {
			console.log("Connection Error: " + error.toString());
		});
		connection.on('close', function() {
			console.log('thingml-protocol Connection Closed');
			clientConnection = null;
		});
		connection.on('message', function(message) {
			if (message.type === 'utf8') {
				var json = JSON.parse(message.utf8Data);
				if (json.port.split("_")[0] === "gui" && json.message === "changeDisplay") {
					thing.receivechangeDisplayOngui();
				}
				console.log("Received: '" + message.utf8Data + "'");
			}
		});
	});    

	client.connect('ws://localhost:' + port + '/', null);

	this.onMessage = function(message) {
		console.log(message);
		var json = JSON.parse(message);
		json.thing = thing.getName();
		json.port = json.port.split("_")[0];
		if (json.port === "gui" && json.message === "light" || json.message === "temperature") {
			clientConnection.sendUTF(JSON.stringify(json));
		}
	}	
	
	this._stop = function() {
		console.log("Stopping WebSocket...");
		clientConnection.close();
		wsServer.shutDown();
		server.close();
		console.log("Stopping WebSocket... done!");
	}
}

var wsGuiListener = new WebSocketGuiListener(JSWeatherNode_app, 8080);
JSWeatherNode_app.getGuiListeners().push(wsGuiListener.onMessage);

process.on('SIGINT', function() {
wsGuiListener._stop();
});

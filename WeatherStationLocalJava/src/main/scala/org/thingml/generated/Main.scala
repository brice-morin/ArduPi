/**
 * File generated by the ThingML IDE
 * /!\Do not edit this file/!\
 * In case of a bug in the generated code,
 * please submit an issue on our GitHub
 **/

package org.thingml.generated
import org.thingml.generated._
import org.sintef.smac._
object Main {

def main(args: Array[String]): Unit = {

//Initializing arrays
val PacketManager_buffer_var_JavaNode_deserializer = new Array[Byte](16)
//Initializing arrays
val PacketManager_buffer_var_JavaNode_serializer = new Array[Byte](16)
//Things
val MessageDeserializer_JavaNode_deserializer = new MessageDeserializer(PacketManager_lengthInteger_var = 2.asInstanceOf[Byte], PacketManager_lengthString_var = 8.asInstanceOf[Byte], PacketManager_lengthUInt16_var = 2.asInstanceOf[Byte], PacketManager_MAX_PACKET_SIZE_var = 16.asInstanceOf[Int], PacketManager_START_BYTE_var = 0x12.asInstanceOf[Byte], PacketManager_STOP_BYTE_var = 0x13.asInstanceOf[Byte], PacketManager_ESCAPE_BYTE_var = 0x7D.asInstanceOf[Byte], _PacketManager_CODE_POSITION_var = 3.asInstanceOf[Int], _PacketManager_LENGTH_POSITION_var = 4.asInstanceOf[Int], _PacketManager_DATA_POSITION_var = 5.asInstanceOf[Int], _PacketManager_index_var = 0.asInstanceOf[Int], _PacketManager_buffer_var = PacketManager_buffer_var_JavaNode_deserializer)
val MessageSerializer_JavaNode_serializer = new MessageSerializer(PacketManager_lengthInteger_var = 2.asInstanceOf[Byte], PacketManager_lengthString_var = 8.asInstanceOf[Byte], PacketManager_lengthUInt16_var = 2.asInstanceOf[Byte], PacketManager_MAX_PACKET_SIZE_var = 16.asInstanceOf[Int], PacketManager_START_BYTE_var = 0x12.asInstanceOf[Byte], PacketManager_STOP_BYTE_var = 0x13.asInstanceOf[Byte], PacketManager_ESCAPE_BYTE_var = 0x7D.asInstanceOf[Byte], _PacketManager_CODE_POSITION_var = 3.asInstanceOf[Int], _PacketManager_LENGTH_POSITION_var = 4.asInstanceOf[Int], _PacketManager_DATA_POSITION_var = 5.asInstanceOf[Int], _PacketManager_index_var = 0.asInstanceOf[Int], _PacketManager_buffer_var = PacketManager_buffer_var_JavaNode_serializer)
val WeatherStation_JavaNode_app = new WeatherStation()
val SerialScala_JavaNode_serial = new SerialScala(SerialScala_serialPort_var = "COM8".asInstanceOf[String])
val TimerScala_JavaNode_t = new TimerScala(_TimerScala_scalaTimer_var = null.asInstanceOf[org.thingml.utils.timer.Timer])
//Bindings
new Channel(
MessageDeserializer_JavaNode_deserializer.getPort("in").get,
SerialScala_JavaNode_serial.getPort("IOStream").get
)

  new Channel(
MessageDeserializer_JavaNode_deserializer.getPort("RemoteControl").get,
WeatherStation_JavaNode_app.getPort("RemoteControlIn").get
)


  new Channel(
MessageSerializer_JavaNode_serializer.getPort("out").get,
SerialScala_JavaNode_serial.getPort("IOStream").get
)


  new Channel(
MessageSerializer_JavaNode_serializer.getPort("RemoteControl").get,
WeatherStation_JavaNode_app.getPort("RemoteControlOut").get
)


  new Channel(
WeatherStation_JavaNode_app.getPort("timer").get,
TimerScala_JavaNode_t.getPort("timer").get
)

//Starting Things
MessageDeserializer_JavaNode_deserializer.asInstanceOf[Component].start
MessageSerializer_JavaNode_serializer.asInstanceOf[Component].start
WeatherStation_JavaNode_app.asInstanceOf[Component].start
SerialScala_JavaNode_serial.asInstanceOf[Component].start
TimerScala_JavaNode_t.asInstanceOf[Component].start

}

}


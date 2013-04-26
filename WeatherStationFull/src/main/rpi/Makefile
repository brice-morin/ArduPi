CC = cc
LIBS = -lpthread -lbson -lmongoc
CFLAGS = -O -w
SRCS = SerialProxy.c LinuxDB.c MessageSerializer.c ClockTimer.c LinuxSerial.c MessageDeserializer.c LinuxClock.c WeatherStation.c LinuxSensapp.c RaspiNode.c runtime.c
OBJS = SerialProxy.o LinuxDB.o MessageSerializer.o ClockTimer.o LinuxSerial.o MessageDeserializer.o LinuxClock.o WeatherStation.o LinuxSensapp.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $< -DMONGO_HAVE_STDINT=1

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
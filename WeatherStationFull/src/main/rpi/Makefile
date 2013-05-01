CC = cc
LIBS = -lpthread -lbson -lmongoc
CFLAGS = -O -w
SRCS = LinuxSerial.c SerialProxy.c ClockTimer.c LinuxSensapp.c LinuxClock.c WeatherStation.c MessageSerializer.c MessageDeserializer.c LinuxDB.c RaspiNode.c runtime.c
OBJS = LinuxSerial.o SerialProxy.o ClockTimer.o LinuxSensapp.o LinuxClock.o WeatherStation.o MessageSerializer.o MessageDeserializer.o LinuxDB.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $< -DMONGO_HAVE_STDINT=1

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
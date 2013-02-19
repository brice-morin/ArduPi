CC = cc
LIBS = -lpthread -lmongoc -lbson 
CFLAGS = -O -w
SRCS = SerialProxy.c ClockTimer.c LinuxSerial.c MessageSerializer.c WeatherStation.c LinuxClock.c MessageDeserializer.c LinuxDB.c RaspiNode.c runtime.c
OBJS = SerialProxy.o ClockTimer.o LinuxSerial.o MessageSerializer.o WeatherStation.o LinuxClock.o MessageDeserializer.o LinuxDB.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $< -DMONGO_HAVE_STDINT=1

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode

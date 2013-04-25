CC = cc
LIBS = -lpthread -lbson -lmongoc
CFLAGS = -O -w
SRCS = MessageSerializer.c ClockTimer.c LinuxDB.c LinuxSerial.c SerialProxy.c WeatherStation.c LinuxClock.c MessageDeserializer.c RaspiNode.c runtime.c
OBJS = MessageSerializer.o ClockTimer.o LinuxDB.o LinuxSerial.o SerialProxy.o WeatherStation.o LinuxClock.o MessageDeserializer.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $< -DMONGO_HAVE_STDINT=1

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
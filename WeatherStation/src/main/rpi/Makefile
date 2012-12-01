CC = cc
LIBS = -lpthread
CFLAGS = -O -w
SRCS = LinuxClock.c MessageDeserializer.c SerialProxy.c LinuxSerial.c MessageSerializer.c ClockTimer.c WeatherStation.c RaspiNode.c runtime.c
OBJS = LinuxClock.o MessageDeserializer.o SerialProxy.o LinuxSerial.o MessageSerializer.o ClockTimer.o WeatherStation.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $<

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
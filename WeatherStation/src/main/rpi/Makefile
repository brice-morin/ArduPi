CC = cc
LIBS = -lpthread 
CFLAGS = -O -w
SRCS = ClockTimer.c MessageDeserializer.c MessageSerializer.c WeatherStation.c SerialProxy.c LinuxSerial.c LinuxClock.c RaspiNode.c runtime.c
OBJS = ClockTimer.o MessageDeserializer.o MessageSerializer.o WeatherStation.o SerialProxy.o LinuxSerial.o LinuxClock.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $<

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
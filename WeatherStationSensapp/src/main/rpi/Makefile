CC = cc
LIBS = -lpthread 
CFLAGS = -O -w
SRCS = LinuxSerial.c LinuxClock.c LinuxSensapp.c MessageDeserializer.c MessageSerializer.c ClockTimer.c WeatherStation.c SerialProxy.c RaspiNode.c runtime.c
OBJS = LinuxSerial.o LinuxClock.o LinuxSensapp.o MessageDeserializer.o MessageSerializer.o ClockTimer.o WeatherStation.o SerialProxy.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $< 

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
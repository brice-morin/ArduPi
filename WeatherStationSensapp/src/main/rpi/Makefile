CC = cc
LIBS = -lpthread 
CFLAGS = -O -w
SRCS = WeatherStation.c SerialProxy.c ClockTimer.c LinuxSensapp.c LinuxSerial.c LinuxClock.c MessageSerializer.c MessageDeserializer.c RaspiNode.c runtime.c
OBJS = WeatherStation.o SerialProxy.o ClockTimer.o LinuxSensapp.o LinuxSerial.o LinuxClock.o MessageSerializer.o MessageDeserializer.o RaspiNode.o runtime.o

all : RaspiNode

.c.o :
	${CC} ${CFLAGS} -c $< 

RaspiNode : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ RaspiNode
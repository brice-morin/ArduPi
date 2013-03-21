CC = gcc
LIBS = -l bcm2835
CFLAGS = -O -w
SRCS = gpio_client.c
OBJS = gpio_client.o

all : gpio_client

.c.o :
	${CC} ${CFLAGS} -c $<

gpio_client : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ gpio_client

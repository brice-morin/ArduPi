CC = c99
LIBS = -lpthread -lmongoc -lbson
CFLAGS = -O -w
SRCS = mongo_client.c
OBJS = mongo_client.o

all : mongo_client

.c.o :
	${CC} ${CFLAGS} -c $<

mongo_client : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ mongo_client

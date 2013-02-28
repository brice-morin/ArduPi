CC = c99
LIBS = 
CFLAGS = -O -w
SRCS = curl_client.c
OBJS = curl_client.o

all : curl_client

.c.o :
	${CC} ${CFLAGS} -c $<

mongo_client : $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS) -lm

clean:
	rm -f *.o *~ curl_client

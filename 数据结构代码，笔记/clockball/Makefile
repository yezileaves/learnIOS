CC:= gcc
CFLAGS:= -Wall -O2
LDFLAGS:=
LIBS:=
OBJS:= queue.o stack.o main.o

.PHONY:clean

ballclock: $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)
%*.o: %*.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-rm *.o ballclock

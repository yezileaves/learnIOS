CC:= gcc
CFLAGS:= -Wall -O2
LDFLAGS:=
LIBS:=
OBJS:= queue.o  bitree.o
OUT:= main

.PHONY:clean memcheck

$(OUT): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) $(LIBS)
%*.o: %*.c
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	-rm *.o $(OUT)
memcheck:
	valgrind --tool=memcheck ./$(OUT)

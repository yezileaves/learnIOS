CC:= gcc
CFLAGS:= -Wall -O2
OBJS:= main.o seqlist.o

.PHONY: clean

main: $(OBJS)
	$(CC) -o $@ $^ 
%*.o: %*.c
	$(CC) -o $@ $^  $(CFLAGS)


clean:
	-rm *.o main

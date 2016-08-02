OBJS = sqstack.o dc.o
CC = gcc
CFLAGS = -g -Wall -O

dc:dc.o sqstack.o sqstack.h
	$(CC) $^ -o dc $(CFLAGS)
$(OBJS):%.o:%.c
	$(CC) -c $^ -o $@ $(CFLAGS)

.PHONY:clean
clean:
	@rm *.o dc


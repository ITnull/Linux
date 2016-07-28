#这是注释行
.SUFFIXES:.c.o

CC=gcc
SRCS=mc.c
OBJS=$(SRCS:.c=.o)
EXEC=mc
start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS) -lpthread
	@echo '--------------ok----------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -f core*


#这是注释行
.SUFFIXES:.c.o

CC=gcc
SRCS=a.c
OBJS=$(SRCS:.c=.o)
EXEC=a
start:$(OBJS)
	$(CC) -L. -lmc -o $(EXEC) $(OBJS)
	@echo '--------------ok----------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -f core*


#这是注释行
.SUFFIXES:.c.o

CC=gcc
SRCS=my_c.c
OBJS=$(SRCS:.c=.o)
EXEC=my_c
start:$(OBJS)
	$(CC) -o $(EXEC) $(OBJS)
	@echo '--------------ok----------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -f core*


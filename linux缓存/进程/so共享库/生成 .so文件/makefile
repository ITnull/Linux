#这是注释行
.SUFFIXES:.c.o

CC=gcc
SRCS=mc.c
OBJS=$(SRCS:.c=.o)
EXEC=libmc.so
start:$(OBJS)
	$(CC) -shared -o $(EXEC) $(OBJS)
	@echo '--------------ok----------------'
.c.o:
	$(CC) -Wall -g -fPIC -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -f core*


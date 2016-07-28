#这是注释行
.SUFFIXES:.c.o

CC=gcc
SRCS1=mc.c
SRCS2=ms.c
OBJS1=$(SRCS1:.c=.o)
OBJS2=$(SRCS2:.c=.o)
EXEC1=mc
EXEC2=ms
start:$(OBJS1) $(OBJS2) 
	$(CC) -o $(EXEC1) $(OBJS1) 
	$(CC) -o $(EXEC2) $(OBJS2) 
	@echo '--------------ok----------------'
.c.o:
	$(CC) -Wall -g -o $@ -c $<
clean:
	@rm -f $(OBJS)
	@rm -f core*


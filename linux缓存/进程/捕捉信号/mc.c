#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <signal.h>

void catch_signal(int sign)
{
	switch(sign)
	{
	case SIGINT:
		printf("SIGINT Signal\n");
		break;
	case SIGALRM:
		printf("world\n");
		exit(0);
	}
}

int main(int arg, char *args[])
{
	signal(SIGINT,  catch_signal);
	signal(SIGALRM,  catch_signal);
	int i = 0;
	while(1)
	{
		printf("hello%d\n",i++);
		sleep(1);
	}
	return EXIT_SUCCESS;
}

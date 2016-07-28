/*
 ============================================================================
 Name        : my_c.c
 Author      : gaopeng
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//调用库函数     fopen   fclose   fread  fwrite
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <pwd.h>
int main(int arg, char *args[])
{
	if(arg >1)
	{
		int pid = atoi(args[1]);
		kill(pid, SIGKILL);
	}
	else
	{
		printf("pid = %u\n", getpid());
		sleep(100);
	}
	return 100;
}

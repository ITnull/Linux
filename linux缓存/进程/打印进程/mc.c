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
#include<errno.h>

int main(int arg, char *args[])
{
	printf("PID=%d\n",getpid());
        printf("PPID=%d\n",getppid());
        return EXIT_SUCCESS;
}

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
#include <sys/wait.h>
#include <pwd.h>

int main(void)
{
	pid_t pid = fork();
	int status;
	if(pid == -1)
	{
		printf("fork failed\n");
		return 0;
	}
	if(pid == 0)
	{
		printf("child process start\n");
		sleep(2);
		printf("child process end\n");
		return 100;
	}
	else
	{
		printf("parent process start\n");
		wait(&status);     //等待子进程退出的返回值
		printf("status = %d\n", WEXITSTATUS(status)); //打印子进程退出的返回值
		printf("parent process end\n");
		return 0;
	}
        return EXIT_SUCCESS;
}

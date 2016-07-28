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
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
	int fd = open("abc.txt", O_RDONLY);
	pid_t child =  fork();    //这是关键
	char buf[20];
	memset(buf, 0 ,sizeof(buf));
	if(child == 0)   //子进程
	{
		while(read(fd, buf, sizeof(buf)-1)>0)
		{
			printf("%s",buf);
			memset(buf, 0 ,sizeof(buf));
		}
		printf("我是子进程\n");
		close(fd);
	}
	if(child > 0)    //父进程
	{
		printf("我是父进程\n");
		close(fd);
	}
        return EXIT_SUCCESS;
}
//两个进程没有同时对1个i进行操作. 子进程拷贝了一个i,对其操作
/*
int main(void)
{
	pid_t pid = fork();
	int i = 0;
	if(pid == 0)
	{
		while(i<10)
		{
			i++;
			printf("子的 i = %d\n",i);
			sleep(1);
		}
	}
	if(pid > 0)
	{
		while(i<10)
		{
			i++;
			printf("父的 i = %d\n",i);
			sleep(1);
		}
	}
        return EXIT_SUCCESS;
}  */

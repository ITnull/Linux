/*
 ============================================================================
 Name        : my_c.c
 Author      : gaopeng
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>

int main(int arg, char *args[])
{
	char s[] = "abc.txt";
	int fd = open(s, O_RDWR | O_APPEND);
	if (fd == -1)
	{
		printf("error is %s\n", strerror(errno));
	} else
	{
		printf("success fd = %d\n", fd);
		char buf[100];
		memset(buf, 0, sizeof(buf));
		strcpy(buf, "hello world!\n");
		int i = write(fd, buf, strlen(buf));
		close(fd);
	}
	return 0;
}

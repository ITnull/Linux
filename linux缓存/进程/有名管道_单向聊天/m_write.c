/*
 * wc.c
 *
 *  Created on: 2015-4-13
 *      Author: gaopeng
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int arg, char *args[])
{
	char buf[100];
	memset(buf, 0, sizeof(buf));
	int fd = open("fifol", O_WRONLY);
	while(1)
	{
//		scanf("%s", buf);    //不接受空格
		read(STDIN_FILENO, buf, sizeof(buf));
		if(buf[0] == '0')
			break;
		write(fd, buf, strlen(buf));
		memset(buf, 0, sizeof(buf));
	}
	close(fd);
	return 0;
}

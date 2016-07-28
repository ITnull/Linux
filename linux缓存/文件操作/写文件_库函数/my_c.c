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
#include<string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include<errno.h>

int main(int arg, char *args[])
{
	FILE *p = fopen(args[1], "a"); //w是写,a是追加
	if (p == NULL)
	{
		printf("error is %s\n", strerror(errno));
	} else
	{
		printf("success \n");
		char buf[100];
		memset(buf, 0, sizeof(buf));
		strcpy(buf,"hello ubuntu!\n");
		fwrite(buf,strlen(buf),1,p);
		fclose(p);
	}
	return 0;
}

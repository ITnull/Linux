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
	FILE *p = fopen(args[1], "r+"); //r是只读,r+是读写
	if (p == NULL)
	{
		printf("error is %s\n", strerror(errno));
	} else
	{
		printf("success \n");
		char buf[100];
		memset(buf, 0, sizeof(buf));
		size_t rc = 0;
		while(1)
		{
			size_t tmp = fread(buf, 1, sizeof(buf), p);
			rc += tmp;
			if(tmp == 0)
				break;
		}
			printf("rc = %d\n", rc);    //打印文件的大小
			fclose(p);
	}
	return 0;
}

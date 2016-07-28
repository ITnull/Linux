#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
void test()
{
	pthread_exit(NULL);
}
void *func(void *arg)  //arg是pthread_create函数的最后一个参数
{
	int i = *(int *)arg;
	int k = 0;
	while(1)
	{
		printf("pthread start%d\n", i);
		sleep(1);
		if((10== ++k)&&(1 == i))
		{
			test();     //退出进程1
		}
	}
	printf("pthread endt\n");
	return NULL;
}

int main(void)
{
	pthread_t thrd1, thrd2;
	int i1 = 1,i2 = 2;
	if(pthread_create(&thrd1, NULL, func, &i1) != 0) //func是线程入口函数
	{
		printf("error is %s\n", strerror(errno));
	}
	if(pthread_create(&thrd2, NULL, func, &i2) != 0) //func是线程入口函数
	{
		printf("error is %s\n", strerror(errno));
	}
	sleep(100);
	return EXIT_SUCCESS;
}

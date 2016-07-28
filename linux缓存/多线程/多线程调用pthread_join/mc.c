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
	printf("pthread start%d\n", i);
	int a = 0;
	for(a = 0; a<i;a++)
	{
		printf("hello pthread%d\n", a);
		sleep(1);
	}
	printf("pthread endt\n");
	return NULL;
}

int main(void)
{
	pthread_t thrd1, thrd2;
	int i1 = 8, i2 = 3;
	if(pthread_create(&thrd1, NULL, func, &i1) != 0) //func是线程入口函数
	{
		printf("error is %s\n", strerror(errno));
	}
	if(pthread_create(&thrd2, NULL, func, &i2) != 0) //func是线程入口函数
	{
		printf("error is %s\n", strerror(errno));
	}
	pthread_join(thrd1, NULL);    //主线程挂起,等待thrd1退出
	pthread_join(thrd2, NULL);
	printf("main end\n");
	return EXIT_SUCCESS;
}

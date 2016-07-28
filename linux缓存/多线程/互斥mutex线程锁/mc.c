#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //初始化一个mutex锁
void *func1(void *arg)  //arg是pthread_create函数的最后一个参数
{
	//给mutex加锁,这是一条原子操作, 不可能出现两个线程同事执行这个代码
	pthread_mutex_lock(&mutex);
	int *a = (int *)arg;
	printf("pthread%d start\n", *a);
	int i = 0;
	for(;i<10;i++)
	{
		printf("pthread%d is running\n", *a);
		sleep(1);
	}
	printf("pthread end\n");
	pthread_mutex_unlock(&mutex);
	pthread_exit(NULL);
}

void *func2(void *arg)  //arg是pthread_create函数的最后一个参数
{
	int i = 0;
	for(;i<10;i++)
	{
		printf("pthread3 is running\n");
		sleep(1);
	}
	return NULL;
}
int main(void)
{
	printf("process start\n");
	pthread_t thrd1, thrd2, thrd3;
	int i[2];
	i[0] = 1;
	i[1] = 2;
	pthread_create(&thrd1, NULL, func1, &i[0]);
	pthread_create(&thrd2, NULL, func1, &i[1]);
	pthread_create(&thrd3, NULL, func2, NULL);
	pthread_join(thrd1,NULL);    //主线程挂起,等待thrd1退出
	pthread_join(thrd2, NULL);
	printf("process end\n");
	return EXIT_SUCCESS;
}

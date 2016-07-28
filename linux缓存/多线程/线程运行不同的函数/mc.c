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
void *func1(void *arg)
{
	printf("pthread1 start\n");
	sleep(1);
	test();    //终止线程,以下的代码将不会被执行
	printf("pthread1 endt\n");
	return NULL;
}
void *func2(void *arg)
{
	printf("pthread2 start\n");
	while(1)
	{
		printf("pthread2 start\n");
		sleep(1);
	}
	printf("pthread2 end\n");
	return NULL;
}
int main(void)
{
	pthread_t thrd1, thrd2;
	if(pthread_create(&thrd1, NULL, func1, NULL) != 0) //func是线程入口函数
	{
		printf("error is %s\n", strerror(errno));
	}
	if(pthread_create(&thrd2, NULL, func2, NULL) != 0) //func是线程入口函数
	{
		printf("error is %s\n", strerror(errno));
	}
	sleep(100);
	return EXIT_SUCCESS;
}

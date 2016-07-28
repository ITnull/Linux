#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
 #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>     //inet_addr需要包含的头文件
#include <arpa/inet.h>     //inet_addr需要包含的头文件
#include <pthread.h>
void *recvsocket(void *arg)  //接受client端socket数据的线程
{
	int st = *(int *)arg;
	char s[1024];
	while(1)
	{
		memset(s, 0,sizeof(s));
		int rc = recv(st, s, sizeof(s), 0);
		if(rc <= 0)
			break;
		printf("%s\n", s);
	}
	return NULL;
}
void *sendsocket(void *arg)  //接受client端socket数据的线程
{
	int st = *(int *)arg;
	char s[1024];
	while(1)
	{
		memset(s, 0,sizeof(s));
		read(STDIN_FILENO, s, sizeof(s));
		send(st, s, sizeof(s), 0);
	}
	return NULL;
}
int main(void)
{
	int st = socket(AF_INET, SOCK_STREAM, 0);
	if(st == -1)
	{
		printf("create socket error :%s\n", strerror(errno));
		return -1;
	}
	struct sockaddr_in addr;  //定义一个IP地址结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080);
	addr.sin_addr.s_addr = inet_addr("10.141.89.15");
	if(connect(st, (struct sockaddr*)&addr, sizeof(addr)) == -1)
	{
		printf("connect failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	pthread_t thrd1, thrd2;
	pthread_create(&thrd1, NULL, recvsocket, &st);
	pthread_create(&thrd2, NULL, sendsocket, &st);
	pthread_join(thrd1,NULL);
	pthread_join(thrd2,NULL);
	close(st);
	return EXIT_SUCCESS;
}

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
 #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>     //inet_addr需要包含的头文件
#include <arpa/inet.h>     //inet_addr需要包含的头文件
int main(int arg, char *args[])
{
	int st = socket(AF_INET, SOCK_DGRAM, 0);
	if(st == -1)
	{
		printf("create socket error :%s\n", strerror(errno));
		return -1;
	}
	int on =1;
	if(setsockopt(st, SOL_SOCKET, SO_BROADCAST, &on, sizeof(on)) == -1)
	{
		printf("setsockopt failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	struct sockaddr_in addr;  //定义一个IP地址结构
	memset(&addr, 0, sizeof(addr));
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8080); //将本地字节顺序转化为网络字节顺序
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	char buf[1024];
	while(1)
	{
		memset(buf, 0, sizeof(buf));
		read(STDIN_FILENO, buf, sizeof(buf));
		int rc = sendto(st, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
		if(rc == -1)
		{
			printf("sendto failed %s\n", strerror(errno));
			break;
		}else
		{
			printf("rc = %d\n", rc);
		}
	}
	close(st);
	return EXIT_SUCCESS;
}

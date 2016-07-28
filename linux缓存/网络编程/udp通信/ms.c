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
		return 0;
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
	if(bind(st, (struct sockaddr*)&addr, sizeof(addr)) == -1)
	{
		printf("bind failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	char buf[1024];
	struct sockaddr_in client_addr;  //标识client端的IP地址
	socklen_t len = sizeof(client_addr);
	while(1)
	{
		memset(&client_addr, 0,sizeof(client_addr));
		memset(buf, 0, sizeof(buf));
		int rc = recvfrom(st, buf, sizeof(buf), 0, (struct sockaddr *)&client_addr, &len);
		if(rc == -1)
		{
			printf("recvfrom failed %s\n", strerror(errno));
			break;
		}else
		{
			printf("rc = %d\n", rc);
			printf("%s recv is %s\n", inet_ntoa(client_addr.sin_addr), buf);
		}
	}
	close(st);
	return EXIT_SUCCESS;
}

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
	int st = socket(AF_INET, SOCK_STREAM, 0);
	if(st == -1)
	{
		printf("create socket error :%s\n", strerror(errno));
		return -1;
	}
	int on =1;
	if(setsockopt(st, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) == -1)
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
	if(listen(st, 20) == -1)
	{
		printf("listen failed %s\n", strerror(errno));
		return EXIT_FAILURE;
	}
	char s[1024];
	int client_st = 0;
	struct sockaddr_in client_addr;  //标识client端的IP地址
	while(1)
	{
		memset(&client_addr, 0,sizeof(client_addr));
		socklen_t len = sizeof(client_addr);
		//accept等待客户端的连接, 返回客户端的socket
		client_st = accept(st, (struct sockaddr *)&client_addr, &len);
		if(client_st == -1)
		{
			printf("accept failed %s\n", strerror(errno));
			return EXIT_FAILURE;
		}
		printf("accept by %s\n", inet_ntoa(client_addr.sin_addr));
		while(1)
		{
			memset(s, 0, sizeof(1024));
			int rc = recv(client_st, s, sizeof(s),0);
			if(rc >0)
			{
				printf("revc is %s ", s);
				send(client_st, "发送成功!\n",sizeof("已收到!\n"),0);
			}else
			{
				if(rc == 0) //用户退出
				{
					printf("client socket closed\n");
				}else
				{
					printf("recv failed %s\n", strerror(errno));
				}
				break;
			}
		}
		close(client_st);
	}
	close(st);
	return EXIT_SUCCESS;
}

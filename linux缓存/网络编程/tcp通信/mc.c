#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>
 #include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>     //inet_addr需要包含的头文件
#include <arpa/inet.h>     //inet_addr需要包含的头文件

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
	char s[1024];
	while(1)
	{
		memset(s, 0, sizeof(s));
		read(STDIN_FILENO, s, sizeof(s));
		if(send(st, s, sizeof(s), 0) == -1)
		{
			printf("send failed %s\n", strerror(errno));
			return EXIT_FAILURE;
		}
		memset(s, 0, sizeof(s));
		if(recv(st, s, sizeof(s),0) > 0) //接受成功
			printf("recv %s\n",s);
		else
			break;
	}
	close(st);
	return EXIT_SUCCESS;
}

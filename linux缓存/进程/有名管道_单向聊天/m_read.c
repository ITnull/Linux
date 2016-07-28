#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
	mkfifo("fifol", 0666);  //创建fifo   
	char buf[100];
	memset(buf, 0, sizeof(buf));
	int fd = open("fifol", O_RDONLY);
	//循环从fiflol读取数据,直到fifol被关闭, 循环break
	while(read(fd, buf, sizeof(buf)) > 0)
	{
		printf("%s", buf);
		memset(buf, 0, sizeof(buf));
	}
	close(fd);
	return 0;
}

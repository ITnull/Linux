#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int arg, char *args[])
{
	int fd[2];  //管道描述符 , 第一个管道读,第二个管道写
	char buf[100];  //存放管道收发的数据
	int len ;//记录长度
	pipe(fd);  //打开管道
	memset(buf, 0, sizeof(buf));
	int pid = fork();
	if (pid ==  0)
	{
		close(fd[1]);  //关闭第二个管道, 进行读操作
		while((len = read(fd[0], buf, sizeof(buf))) >0)
		{
			write(STDOUT_FILENO, buf, len);
		}
		close(fd[0]);
	}
	else
	{
		close(fd[0]);             //关闭第一个管道
		strcpy(buf, "hello world\n");
		write(fd[1], buf, sizeof(buf));
		close(fd[1]);
		waitpid(pid, NULL, 0);   //等待子进程退出
	}
	return 0;

}

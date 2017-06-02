/*************************************************************************
	> File Name: pipe2.c
	> Author: lixiao
	> Mail: 736343194@qq.com 
	> Created Time: Mon 22 May 2017 07:54:42 PM CST
 ************************************************************************/
//管道的写端不关闭，父进程一直等待
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int main()
{
	int fds[2];
	int ret=pipe(fds);
	if(ret==-1)
	{
		printf("Create ppipe error!errno code is:%d\n",errno);
		return 1;
	}
	pid_t id=fork();
	if(id<0)
	{
		printf("fork error!");
		return 2;
	}
	else if(id==0)
	{
		close(fds[0]);//关闭读端
		char *msg="I am child!";
		int i=0;
		while(i<0)
		{
			if(i<5)
			{
				write(fds[1],msg,strlen(msg)+1);
				sleep(1);
			}
			sleep(1);
			++i;
		}
		close(fds[1]);
	}
	else
	{
		close(fds[1]);//关闭写端
		char buf[1024];
		int j=0;
		while(j<100)
		{
			ssize_t ret=read(fds[0],buf,sizeof(buf));
			printf("father read :%s,code is %d\n",buf,ret);
			++j;
		}
		if(waitpid(id,NULL,0)<0)
		{
			return 3;
		}
	}
	return 0;
}

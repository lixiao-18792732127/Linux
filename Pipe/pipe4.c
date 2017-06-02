/*************************************************************************
	> File Name: pipe4.c
	> Author: lixiao
	> Mail: 736343194@qq.com 
	> Created Time: Tue 23 May 2017 09:41:55 PM CST
 ************************************************************************/
//关闭读端和写端
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<errno.h>
#include<sys/wait.h>
int main()
{
	int fds[2];
	int ret=pipe(fds);
	if(ret==-1)
	{
		printf("Create pipe error!errno is :%d\n",errno);
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
		char* msg="I am child!";
		int i=0;
		while(i<10)
		{
			if(i<8)
			{
				write(fds[1],msg,strlen(msg)+1);
				sleep(1);
			}
			sleep(1);
			++i;
		}
	
	}
	else
	{
		close(fds[1]);//关闭写端
		char buf[1024];
		int j=0;
		while(j<3)
		{
			ssize_t ret=read(fds[0],buf,sizeof(buf));
			++j;
		}
		close(fds[0]);
		sleep(10);
		if(waitpid(id,NULL,0)<0)
		{
			return 3;
		}
	}
	return 0;
}

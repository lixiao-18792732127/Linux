/*************************************************************************
	> File Name: pipe.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Mon 22 May 2017 03:57:10 PM CST
 ************************************************************************/
//匿名管道
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
		printf("Create pipe error! errno code is :%d\n",errno);
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
		close(fds[0]);
		char* msg="I am child!";
		while(1)
		{
			write(fds[1],msg,strlen(msg)+1);
			sleep(1);
		}
	}
	else
	{
		close(fds[1]);
		char buf[1024];
		while(1)
		{
			read(fds[0],buf,sizeof(buf));
			printf("father read:%s\n",buf);
		}
	}
	return 0;
}

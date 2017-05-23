/*************************************************************************
	> File Name: pipe3.c
	> Author: ma6174
	> Mail: ma6174@163.com 
	> Created Time: Tue 23 May 2017 09:25:48 PM CST
 ************************************************************************/
//子进程写，父进程读
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>
#include<errno.h>

int main()
{
	int fds[2];//定义一个数组，存三个变量
	int ret=pipe(fds);//创建管道
	if(ret==-1)//如果ret等于-1，说明创建管道失败了,返回错误码
	{
		printf("Create pipe error!erron code is:%d\n",errno);
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
		while(1)
		{
			write(fds[1],msg,strlen(msg)+1);
			printf("%d\n",i);
			++i;
		}
	}
	else
	{
		close(fds[1]);//关闭写端
		char buf[1024];
		if(waitpid(id,NULL,0)<0)
		{
			return 3;
		}
	}
	return 0;
}

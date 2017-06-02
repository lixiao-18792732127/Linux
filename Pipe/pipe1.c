/*************************************************************************
	> File Name: pipe1.c
	> Author: lixiao
	> Mail: 736343194@qq.com 
	> Created Time: Mon 22 May 2017 07:31:45 PM CST
 ************************************************************************/
//关闭管道的写端
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
int main()
{
	int fds[2];
	int ret=pipe(fds);
	if(ret==-1)
	{
		printf("Create pipe error! errno code is:%d\n",errno);
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
		//child
		close(fds[0]);//close read
		char *msg="I am child!";
		int i=0;
		while(i<10)
		{
			write(fds[1],msg,strlen(msg)+1);
			sleep(1);
			++i;
		}
		close(fds[1]);
	}
	else
	{
		close(fds[1]);//close write
		char buf[1024];
		int j=0;
		while(j<100)
		{
			ssize_t ret=read(fds[0],buf,sizeof(buf));
			printf("father read:%s,code is %d\n",buf,ret);
			++j;
		}
		if(waitpid(id,NULL,0)<0)
		{
			return 3;
		}
	}
	return 0;
}

/*************************************************************************
	> File Name: test.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Sat 01 Jul 2017 03:50:14 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>

void daem()
{
	umask(0);//设置umask为0；
	pid_t pid=fork();//创建一个子进程
	if(pid<0)
	{
		perror("错误！");
		return;
	}
	else if(pid>0)
	{
		exit(0);
	}
	setsid();
	if(chdir("/")<0)
	{
		perror("chdir error~");
		return;
	}
	//关闭文件描述符
	close(0);//关闭stdin
	close(1);//关闭stdout
	close(2);//关闭stderror
	signal(SIGCHLD,SIG_IGN);
}
int main()
{
	daem();
	while(1);
	return 0;
}

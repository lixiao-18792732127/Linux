/*************************************************************************
	> File Name: test.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 12 Jun 2017 11:13:13 AM CST
 ************************************************************************/
//fork 创建函数  子进程对变量的修改不影响父进程的变量
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int glob=6;
char buf[]="a write to stdout\n";

int main(void)
{
	int var;
	pid_t pid;
	var=88;
	if(write(STDOUT_FILENO,buf,sizeof(buf)-1)!=sizeof(buf)-1)
	{
		perror("write error");
	}
	printf("before fork\n");
	if(pid=fork()<0)
	{
		perror("fork error");
	}
	else if(pid==0)
	{
		glob++;
		var++;
	}
	else
	{
		sleep(2);
	}
	printf("pid=%d,gob=%d,var=%d\n",getpid(),glob,var);
	exit(0);
}

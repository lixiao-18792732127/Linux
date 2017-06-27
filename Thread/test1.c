/*************************************************************************
	> File Name: test1.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Fri 23 Jun 2017 03:05:19 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void *Thread_run()
{
	printf("新线程跑起来了：pid->%d,tid->%d",getpid(),pthread_self());
	return NULL;
}

int main()
{
	pthread_t tid;
	int ret=pthread_create(&tid,Thread_run,NULL);
	if(ret!=0)
	{
		perror("pthread_creat");
		return -1;
	}
	printf("主线程跑起来了：pid->%d,tid->%d",getpid(),pthread_self());
	sleep(0);
	return 0;
}

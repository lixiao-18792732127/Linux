/*************************************************************************
	> File Name: test2.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Fri 23 Jun 2017 04:08:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
void* Thread1(void* _val)
{
	printf("线程2跑起来了\n");
	return(void*)1;
}
void* thread2(void* _val)
{
	printf("线程2退出了\n");
	pthread_exit((void*)2);
}
void* thread3(void*_val)
{
	while(1)
	{
		printf("线程3正在运行，请等待\n");
		sleep(1);
	}
	return NULL;
}
int main()
{
	pthread_t tid;
	void* ret;
	pthread_create(tid,NULL,thread1,NULL);
	pthread_join(tid,&ret);
	printf("线程返回了，线程是：%u,返回码是：%d\n",(unsigned long)tid,(int)ret);

	pthread_creat(&tid,NULL,thread2,NULL);
	pthread_join(tid,&ret);
	printf("线程返回了，线程是：%u,退出码是：%d\n",(unsigned long)tid,(int)ret);

	pthread_creat(&tid,NULL,thread3,NULL);
	sleep(3);
	pthread_cancle(tid);
	pthread_join(tid,&ret);
	printf("线程返回了，线程是：%u,取消码是：%d\n",(unsigned long)tid,(int)ret);
	return 0;
}

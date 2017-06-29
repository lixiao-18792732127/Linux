/*************************************************************************
	> File Name: test3.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Wed 28 Jun 2017 03:36:03 PM CST
 ************************************************************************/
//线程安全的测试代码
#include<stdio.h>
#include<pthread.h>
int g_count=0;
void* threadCount(void* arg)
{
	int tmp = 0;
	int count = 0;
	while(count<5000)
	{
		tmp = g_count;
		printf("线程的id是：%u,g_count:%d\n",pthread_self(),g_count);
		g_count = tmp+1;
		count++;
	}
}
int main()
{
	pthread_t thread1,thread2;
	pthread_creat(&thread1,NULL,threadCount,NULL);
	pthread_creat(&thread2,NULL,threadCount,NULL);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	return 0;
}

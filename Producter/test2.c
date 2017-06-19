/*************************************************************************
	> File Name: test2.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 19 Jun 2017 09:08:27 AM CST
 ************************************************************************/

#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define _SIZE_	 64
int Buf[_SIZE_];
sem_t semBlank;//定义格子
sem_t semData;//定义格子里面的数据
sem_t proLock;//生产者之间的互斥
sem_t conLock;//消费者之间的互斥

void *Consumer(void *arg)//定义消费者
{
	pthread_detach(pthread_self());
	static int i = 0;
	int id=(int)arg;
	while(1)
	{
		usleep(1000);
		sem_wait(&semData);
		sem_wait(&conLock);

		printf("消费者%d消费了：%d,tid: %1u\n",id,Buf[i++],pthread_self());
		i%= _SIZE_;
		sem_post(&conLock);
		sem_post(&semBlank);
	}
}

void *Producter(void *arg)//定义生产者
{
	pthread_detch(pthread_self());
	static int i = 0;
	int id=(int)arg;
	while(1)
	{
		sleep(1);
		sem_wait(&semBlank);//对临界区数据进行p操作
		sem_wait(&proLock);//对生产者互斥锁进行P操作
		int num = rand()%10;
		Buf[i+1]=num;
		prntf("生产者%d生产了：%d,tid:%1u\n",id,num,pthread_self());
		i%= _SIZE_;

		sem_post(&proLock);//对生产者互斥锁进行v操作
		sem_post(&semData);//对临界区资源进行v操作
	}
}

int main()
{
	pthread_t con0,con1,pro0,pro1;
	sem_init(&semData,0,0);
	sem_init(&semBlank,0,_SIZE_);
	sem_init(&proLock,0,1);
	sem_init(&conLock,0,1);

	int i=0;
	pthread_creat(&pro0,NULL,Producter,(void*)i);
	pthread_creat(&con0,NULL,Consumer,(void*)i);
	i=1;
	pthread_creat(&pro1,NULL,Producter,(void*)i);
	pthread_creat(&con1,NULL,Consumer,(void*)i);

	sem_destroy(&semBlank);
	sem_destroy(&semData);
	pthread_join(pro0,NULL);
	pthread_join(con0,NULL);
	return 0;
}

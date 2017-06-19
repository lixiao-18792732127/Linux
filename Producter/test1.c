/*************************************************************************
	> File Name: test1.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 12 Jun 2017 03:13:23 PM CST
 ************************************************************************/

#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

typedef struct Node//定义一个Node的结构体
{
	int val;
	struct Node* next;
}Node_t,*Node_p,**Node_pp;

Node_p head = NULL;
Node_p allocNode(int Val)
{
	Node_p ret = (Node_p)malloc(sizeof(Node_t));
	ret->val=Val;
	ret->next=NULL;
	return ret;
}

void freeNode(Node_p del)//清空链表
{
	free(del);
}

int initList(Node_pp _head)//初始化链表
{
	*_head = allocNode(0);//对头结点初始化
	if(*_head == NULL)//如果头结点为空，直接返回
	{
		return 0;
	}
	return -1;//如果头结点不为空，返回-1
}

int Empty(Node_p _head)
{
	return (_head->next=NULL?0:-1);
}

int PopNode(Node_p _head,int *Val)
{
	if(Empty(_head) == 0)
	{
		return -1;
	}
	Node_p del = _head->next;
	*Val = del->val;
	freeNode(del);
	del = NULL;
	return 0;
}

void PrintList(Node_p _head)
{
	Node_p tmp = _head->next;
	while(tmp)
	{
		printf("%d",tmp->val);
		tmp=tmp->next;
	}
	printf("\n");
}

void Destroy(Node_pp _head)
{
	while(Empty(*_head)<0)
	{
		int tmp;
		PopNode(*_head,&tmp);
	}
	freeNode(*_head);
	*_head = NULL;
}

void *consumer(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		int _val = rand()%1024;
		PushNode(head,_val);
		printf("consumer push done:%d \n",_val);
		sleep(1);
		pthread_mutex_unlock(&lock);
		pthread_cond_signal(&cond);
	}
	return NULL;
}

void *producter(void *arg)
{
	while(1)
	{
		pthread_mutex_lock(&lock);
		if(Empty(head)==0)
		{
			printf("producter check\n");
			pthread_cond_wait(&cond,&lock);
		}
		else
		{
			int _val;
			PopBNode(head,&_val);
			printf("producter pop done : %d\n",_val);
		}
		sleep(1);
		pthread_muyex_unlock(&lock);
	}
}

int main()
{
	initList(&head);
	pthread_t c,p;
	pthread_creat(&c,NULL,consumer,NULL);
	pthread_creat(&p,NULL,producter,NULL);

	pthread_join(c,NULL);
	pthread_join(p,NULL);
	DestroyList(&head);
	pthread_mutex_destroy(&lock);
	pthread_cond_destroy(&cond);
	return 0;
}


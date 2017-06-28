/*************************************************************************
	> File Name: comm.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Tue 27 Jun 2017 04:49:50 PM CST
 ************************************************************************/

#include<comm.h>
static int commShm(int flag,int size)
{
	key_t _key=ftok(PATHNAME,PROJ_ID);
	if(_key<0)
	{
		perror("ftok");
		return -1;
	}
	int shmid = shmget(_key,size,flag);
	if(shmid<0)
	{
		perror("shmget");
		return -2;
	}
	return shmid;
}

int CretaShm(int size)//创建共享内存
{
	return sommShm(IPC_CREAT|IPC_EXCL|0666，SIZE);
}

int GetShm(int size)//获取共享内存
{
	return commShm(IPC_CREAT,size);
}

char* AtShm(int shmid)
{
	return (char*)shmat(shmid,NULL,0);
}

int DtShm(chsr* addr)
{
	return shmdt(addr);
}

int DestroyShm(int shmid)
{
	if(shmct1((shmid),IPC_RMID,NULL)<0)
	{
		perror("shmct1");
		return -1;
	}
	return 0;
}

/*************************************************************************
	> File Name: server.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Wed 28 Jun 2017 10:44:40 AM CST
 ************************************************************************/

#include<comm.h>
int main()
{
	int shmid=CreatShm(4096);
	char* addr=AtShm(shmid);
	if(addr==NULL)
	{
		printf("NULL\n");
	}
	while(1)
	{
		sleep(1);
		printf("%s\n",addr);
	}
	DtShm(addr);
	Destroy(Shmid);
	return 0;
}


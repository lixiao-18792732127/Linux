/*************************************************************************
	> File Name: client.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Wed 28 Jun 2017 07:44:02 AM CST
 ************************************************************************/

#include<comm.h>
int main()
{
	int shmid = GetShm(4096);
	chra* addr StShm(shmid);
	if(addr==NULL)
	{
		printf("addr==NULL\n");
	}
	int i=0;
	while(i<4095)
	{
		addr[i]='a';
		addr[i+1]='\0';
		sleep(1);
		i++;
	}
	DtShm(addr);
	DestroyShm(shmid);
	return 0;
}

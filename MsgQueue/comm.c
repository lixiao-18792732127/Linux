/*************************************************************************
	> File Name: comm.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 05 Jun 2017 08:56:30 AM CST
 ************************************************************************/

#include<stdio.h>
#include"comm.h"

int main()
{
	int msqid=CreatMsgQueue();
	if(msqid<0)
	{
		perror("CreatMsgQueue");
		return -1;
	}

	char buf[1024];
	while(1)
	{
		buf[0]=0;
		if(RcvMsg(msqid,CLIENT_TYPE,buf)==-1)
		{
			perror("RevMsg");
			return -2;
		}
		printf("Client:%s",buf);
		printf("Server Enter:");
		fflush(stdout);

		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s<0)
		{
			perror("read");
			return -3;
		}
		buf[s]=0;
		if(SndMsg(msqid,SERVER_TYPE,buf)==-1)
		{
			perror("SndMsg");
			return -4;
		}
	}
	DestroyMsgQueue(msqid);
	return 0;
}


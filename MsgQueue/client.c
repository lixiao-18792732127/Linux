/*************************************************************************
	> File Name: client.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 05 Jun 2017 09:26:48 AM CST
 ************************************************************************/

#include<stdio.h>
#include<comm.h>
int main()
{
	int msqid=GetMsgQueue();
	if(msqid<0)
	{
		perror("GetMsgQueue");
		return -1;
	}

	char buf[1024];
	while(1)
	{
		buf[0]=0;
		printf("Client Enter:");
		fflush(stdout);
		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s<0)
		{
			perror("read");
			return -2;
		}
		buf[s]=0;
		if(SndMsg(msqid,CLIENT_TYPE,buf)<0)
		{
			perror("SndMsg");
			return -3;
		}
		if(RcvMsg(msqid,SENVER_TYPR,buf)<0)
		{
			perror("RcvMsg");
			return -4;
		}
		printf("Server echo:%s",buf);
	}
	return 0;
}

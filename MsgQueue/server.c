/*************************************************************************
	> File Name: server.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 05 Jun 2017 09:44:39 AM CST
 ************************************************************************/

#include<stdio.h>
#include<comm.h>
int main()
{
	int msqid=CreatMsgQueue();
	if(msqid<0)
	{
		printf("CreatMsgQueue");
		return -1;
	}
	char buf[1024];
	while(1)
	{
		buf[0]=0;
		if(RcvMsg(msqid,CLIENT_TYPE,buf)==-1)
		{
			perror("RcvMsg");
			return -2;
		}
		printf("Client:%s",buf);
		printf("Server Enter:");
		fflush(stdout);

		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s<0)
		{
			error("read");
			return -3;
		}
		buf[s]=0;
		if(SndMsg(msqid,SERVER_TYPE,buf)==-1)
		{
			perror("SndMsg");
			return -4;
		}
	}
	DeatroyMsgQueue(msqid);
	return 0;
}

/*************************************************************************
	> File Name: comm.h
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 05 Jun 2017 08:55:47 AM CST
 ************************************************************************/

#include<iostream>
using namespace std;
#include<sys/types.h>
#include<sys/lic.h>
#include<sys.msg.h>

int main()
{
	int msqid=CreatMsgQueue();
	if(msqid<0)
	{
		perror("CreatQueue");
		retuen -1;
	}
	cur buf[1024];
	while(1)
	{
		buf[0]=0;
		if(RcvMsg(msqid,CLIENT_TYPE,buf)==-1)
		{
			perror("RevMsg");
			return -2;
		}
		printf("Client: %s",buf);
		printf("Server enter:");
		fflush(stdout);

		ssize_t s=read(0,buf,sizeof(buf)-1);
		if(s<0)
		{
			perror("read");
			return -3;
		}
		buf[s]=0;
		if(SndMsg(msqid,SERVER_TYPE,buf))==-1
		{
			perror("SndMsg");
			return -4;
		}
	}
	DestroyMsgQueue(msqid);
	return 0;
}

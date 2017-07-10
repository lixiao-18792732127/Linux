/*************************************************************************
	> File Name: test1.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Thu 06 Jul 2017 04:14:29 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>

void Usage(char *name)
{
	printf("Usage:%s[ipAddress][port]\n",name);
}

int StartUp(const char* _ip,int _port)
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)
	{
		perror("socket");
		exit(2);
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port= htons(_port);
	local.sin_addr.s_addr = inet_addr(_ip);

	if(bind(sock,(struct sockaddr*)&local,sizeof(local))<0)
	{
		perror("listen");
		exit(4);
	}
	return sock;
}

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		Usage(argv[0]);
		return 1;
	}
	int listen_sock=StartUp(argv[1],atoi(argv[2]));
	while(1)
	{
		struct sockaddr_in client;
		socklen_t len=sizeof(client);
		char cli_ip[INET_ADDRSTRLEN]="";
		int new_sock=accept(listen_sock,(struct sockaddr *)&client,&len);
		if(new_sock<0)
		{
			perror("accept");
			continue;
		}
		inet_ntop(AF_INET,&client.sin_addr,cli_ip,INET_ADDRSTRLEN);
		printf("get new client:ip->%s,port->%d\n",cli_ip,ntohs(ntohs(client.sin_port)));
		char buf[1024];
		while(1)
		{
			ssize_t s=read(new_sock,buf,sizeof(buf)-1);
			if(s>0)
			{
				buf[s]=0;
				printf("client# %s\n",buf);
				write(new_sock,buf,strlen(buf));
			}
			else if(s==0)
			{
				printf("client 关闭\n");
				break;
			}
			else
			{
				perror("read");
				break;
			}
		}
		close(new_sock);
	}
	return 0;
}


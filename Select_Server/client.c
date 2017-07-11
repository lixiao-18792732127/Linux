/*************************************************************************
	> File Name: client.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Tue 11 Jul 2017 04:57:10 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<string.h>
#include<netinet/in.h>
#include<unistd.h>

static void  usage()
{
	printf("........:[ipaddr],[port]\n");
	exit(1);
}

int main(int argc,char* argv[])
{
	if(argc!=3)
	{
		usage();
	}
	int sockfd=socket(AF_INET,SOCK_STREAM,0);
	if(socket<0)
	{
		perror("socket");
		return 2;
	}
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port=htons(atoi(argv[2]));
	addr.sin_addr.s_addr = inet_addr(argv[1]);

	if(connect(sockfd,(struct sockaddr*)&addr,sizeof(addr))<0)
	{
		perror("connect");
		return 3;
	}
	else
	{
		printf("connect success\n");
		char buf[1024];
		while(1)
		{
			printf("client :");
			fflush(stdout);
			ssize_t s = read(0,buf,sizeof(buf)-1);
			if(s<0)
			{
				perror("read");
				return 4;
			}
			else
			{
				buf[s]='\0';
				int fd = dup(1);
				dup2(sockfd,1);
				printf("%s",buf);
				fflush(stdout);
				dup2(fd,1);
			}
			s = read(sockfd,buf,sizeof(buf)-1);
			if(s==0)
			{
				printf("server quit\n");
				break;
			}
			else if(s<0)
			{
				perror("read");
				return 5;
			}
			else
			{
				buf[s-1]='\0';
				printf("server:%s\n",buf);
			}
		}
		close(sockfd);
	}
	return 0;
}

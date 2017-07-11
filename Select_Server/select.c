/*************************************************************************
	> File Name: select.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Tue 11 Jul 2017 03:46:33 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<sys/time.h>
#include<sys/select.h>
#include<unistd.h>
#include<string.h>

static void usage(const char* proc)//打印字符串的函数
{
	printf("Usagr:%s[local_ip][local_proc]\n",proc);
}

int readfds[sizeof(fd_set)*8];//定义文件描述符数组，存储要等待的文件描述符
int startup(char *ip,int port)//监听服务器
{
	int sock = socket(AF_INET,SOCK_STREAM,0);
	if(sock<0)//如果sock的值小于0
	{
		perror("socket");//打印错去码
		exit(0);//直接退出
	}
	struct sockaddr_in local;
	local.sin_family = AF_INET;
	local.sin_port = htons(port);
	local.sin_addr.s_addr = inet_addr(ip);

	if(bind(sock,(struct sockaddr*)&local,sizeof(local))<0)
	{
		perror("bind");
		exit(2);
	}
	if(listen(sock,5)<0)
	{
		perror("listen");
		exit(3);
	}
	return sock;
}
int main(int argc,char* argv[])
{
	if(argc != 3)
	{
		usage(argv[0]);
		return 4;
	}
	int listen_sock = startup(argv[1],atoi(argv[2]));
	int i=1;
	int num =sizeof(fd_set)*8;
	readfds[0] = listen_sock;
	for(;i<num;++i)
	{
		readfds[i] = -1;
	}
	fd_set wfds,rfds;
	char buf[1024];
	while(1)
	{
		int maxfd = -1;
		FD_ZERO(&rfds);
		for(i=0;i<num;++i)
		{
			if(readfds[i]!=-1)
			{
				FD_SET(readfds[i],&rfds);
			}
			maxfd = maxfd<readfds[i]?readfds[i]:maxfd;
		}
		struct timeval time = {1,0};
		int n = select(maxfd+1,&rfds,&wfds,NULL,&time);
		switch(n)
		{
			case 0:

				printf("time out...\n");
				break;
			case -1:
				break;
			default:
				{
					i = 0;
					for(;i<num;++i)
					{
						if(i==0 && FD_ISSET(readfds[i],&rfds))
						{
							struct sockaddr_in client;
							socklen_t len =sizeof(client);
							int client_sock = accept(listen_sock,(struct sockaddr*)&client,&len);

							if(client_sock<0)
							{
								perror("accept");
								continue;
							}
							else

							{
								int j=0;
								for(j=1;j<num;++j)
								{
									if(readfds[j] == -1)

									{
										readfds[j] = client_sock;
										break;
									}

								}
								if(j>=num)

								{
									printf("readfds is full\n]");
									return 5;
								}
							}
						}

						if(i != 0 &&FD_ISSET(readfds[i],&rfds))
						{
							int s=read(readfds[i],buf,sizeof(buf)-1);
							if(s<0)
							{

								perror("read");
								return 6;
							}
							else if(s == 0)

							{
								printf("client qiut\n");
								readfds[i] = -1;
								close(readfds[i]);
								continue;

							}
							else
							{
								buf[s]=0;
								printf("client#: %s\n",buf);
								fflush(stdout);
								write(readfds[i],buf,strlen(buf));

							}
						}
					}
					break;
				}
		}
	}
	return 0;
}

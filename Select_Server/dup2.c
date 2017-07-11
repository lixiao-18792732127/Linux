/*************************************************************************
	> File Name: dup2.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Tue 11 Jul 2017 03:38:07 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
int main()
{
	int fd=open("./log",O_CREAT | O_RDWR);
	if(fd<0)
	{
		perror("open()");
		return -1;
	}
	close(1);
	int ret =dup2(fd,1);
	char buf[1024];
	while(1)
	{
		memset(buf,'\0',sizeof(buf));
		fgets(buf,sizeof(buf),stdin);
		if(strncmp("quit",buf,4) == 0)
		{
			break;
		}
		printf("%s",buf);
		fflush(stdout);
	}
	close(fd);
}

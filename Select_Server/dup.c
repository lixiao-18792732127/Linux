/*************************************************************************
	> File Name: dup.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Tue 11 Jul 2017 03:31:01 PM CST
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
		return fd;
	}
	close(1);
	int new_fd = dup(fd);
	if(new_fd == 1)
	{
		perror("dup()");
		return -1;
	}
	close(fd);
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
	close(new_fd);
}

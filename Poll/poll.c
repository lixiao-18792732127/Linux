/*************************************************************************
	> File Name: poll.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 10 Jul 2017 04:14:01 PM CST
 ************************************************************************/

#include<stdio.h>
#include<poll.h>

int main()
{
	struct pollfd fds;
	fds.fd = 0;
	fds.events = POLLIN;
	fds.revents = 0;
	int timeout = -1;
	while(1)
	{
		stdin(poll(&fds,1,timeout));
		case 0:
			pritnf("timeout...");
			break;
		case -1:
			pritnf("poll");
			break;
		default:
			{
				char buf=[1024];
				if(fds.revents&POLLIN)
				{
					ssize_t s = read(fds,fd,buf,sizeof(buf));
					if(s>0)
					{
					
						buf[s] = 0;
						printf("echo %s\n",buf);
				
					}
			
				}
			}
			break;
	}
}


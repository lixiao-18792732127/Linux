/*************************************************************************
	> File Name: test2.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 03 Jul 2017 08:23:26 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/types.h>

void myhandler(int signal)
{
	printf("当前进程ID为：%d,收到 %d 信号\n",getpid(),signal);
}

void showPending(sigset_t *pending)
{
	int i=1;
	while(i<=31)
	{
		if(sigismember(pending,i)==1)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		++i;
	}
	printf("\n");
}

int main()
{
	sigset_t set,oset;
	sigemptyset(&set);
	sigemptyset(&oset);
	sigaddset(&set,2);

	sigprocmask(SIG_SETMASK,&set,&oset);
	signal(2,myhandler);
	int count=0;
	sigset_t pending;
	while(1)
	{
		sigpending(&pending);
		showPending(&pending);

		sleep(1);
		if(count==3)
		{
			sigprocmask(SIG_SETMASK,&oset,NULL);
			count=0;
		}
		count++;
	}
	return 0;
}


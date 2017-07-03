/*************************************************************************
	> File Name: test2.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 03 Jul 2017 03:48:43 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void sigAlrm(int signal)
{}

unsigned int mysleep(unsigned int second)
{
	struct sigaction sig,osig;
	sigset_t mask,omask,smask;
	sig.sa_handler = sigAlrm;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;
	sigaction(SIGALRM,&sig,&osig);
	sigemptyset(&mask);
	sigaddset(&mask,SIGALRM);
	sigprocmask(SIG_BLOCK,&mask,&omask);
	alarm(second);

	smask = omask;
	sigdelset(&mask,SIGALRM);
	sigsuspend(&smask);

	unsigned int ret = alarm(0);
	sigaction(SIGALRM,&osig,NULL);

	sigprocmask(SIG_SETMASK,&omask,NULL);
	return ret;
}

int main()
{
	while(1)
	{
		mysleep(2);
		printf("sleep 2 second\n");
	}
	return 0;
}

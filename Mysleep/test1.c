/*************************************************************************
	> File Name: test1.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Mon 03 Jul 2017 03:35:15 PM CST
 ************************************************************************/

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
void sigAlrm(int signal)
{}

unsigned int mysleep(unsigned int second)
{
	struct sigaction sig,osig;
	sig.sa_handler = sigAlrm;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = 0;

	sigaction(SIGALRM,&sig,&osig);
	alarm(second);
	pause();
	unsigned int ret = alarm(0);
	sigaction(SIGALRM,&sig,NULL);
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

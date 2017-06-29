/*************************************************************************
	> File Name: test4.c
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Wed 28 Jun 2017 04:26:17 PM CST
 ************************************************************************/

#include<stdio.h>
int flag = 0;
void myhandler(int signal)
{
	flag = 1;
	printf("flag=%d\n",flag);
}
int main()
{
	signal(2,myhandler);
	printf("proc start!\n");
	while(!flag)
	{
		printf("proc end!\n");
	}
	return 0;
}

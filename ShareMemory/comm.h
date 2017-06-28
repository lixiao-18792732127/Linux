/*************************************************************************
	> File Name: comm.h
	> Author: lixiao
	> Mail: 736343194@qq.com
	> Created Time: Tue 27 Jun 2017 04:41:32 PM CST
 ************************************************************************/

#ifndef __SHM_H__
#define __SHM_H__

#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/wait.h>
#include<sys/shm.h>

#define PATHNAME"."
#define PROJ_ID 0X666

int CreatShm(int size);
int GetShm(int size);
char* AtShm(int shmid);
int DtShm(char* addr);
int Destroy(int shmid);

#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include"../apue.h"


int main(void)
{
    int     pos2 = 2;
    int     pos3 = 3;
    pid_t   pid;

    if ((pid = vfork()) < 0)
        err_sys("vfork error");
    else if (0 == pid)
    {
        execlp("ls","ls","-al",NULL);
    }
    else
    {
        sleep(2);
        printf("\n\n");
        //execlp("ls","ls","-a",NULL);
        printf("parent: pos2's value is:%d, and its address is:%p\n", pos2,&pos2);
        printf("parent: pos3's value is:%d, and its address is:%p\n", pos3,&pos3);
    }
    execlp("ls","ls","-a",NULL);


    return 0;
}

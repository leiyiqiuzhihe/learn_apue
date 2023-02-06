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
        pos2 += 1;
        pos3 -= 1;

        printf("pos2's value is:%d, and its address is:%p\n", pos2,&pos2);
        printf("pos3's value is:%d, and its address is:%p\n", pos3,&pos3);
        printf("address of main is: %p\n", &main);
        exit(0);
    }
    else
    {
        sleep(2);
        printf("\n\n");
        printf("parent: pos2's value is:%d, and its address is:%p\n", pos2,&pos2);
        printf("parent: pos3's value is:%d, and its address is:%p\n", pos3,&pos3);
        printf("address of main is: %p\n", &main);
    }


    return 0;
}

#include"../apue.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int         fd = -2;
    int         fd_flag = -2;

    
    if (argc < 2)
        err_sys("Usage: %s buffer");
    sscanf(argv[1], "%d",&fd);
    printf("fd = %d\n",fd);
    if ((fd_flag = fcntl(fd, F_GETFD, 0)) < 0)
    {
        perror("fcntl");
        exit(0);
    }
    if (fd_flag & FD_CLOEXEC)
        printf("close-on-exec is on\n");
    else
        printf("close-on-exec is off\n");


    return 0;
}


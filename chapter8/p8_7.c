/*
 * 编译后用 / 作为argv[1] 报错
 * open只能打开regular file 吗
 * 打开的文件，要关闭
 * 先放在这以后再改
 */
#include"../apue.h"
#include<dirent.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
    int             fd = -2;
    int             flag = 0;
    pid_t           pid = -2;
    DIR             *dp = NULL;
    struct dirent   *dirt = NULL;
    
    if (argc < 2)
    {
        printf("Usage: %s dirnamepath\n",argv[0]);
        exit(1);
    }
    if ((fd = open(argv[1], O_RDWR)) < 0)
    {
        err_sys("open error");
    }
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
    {
        if ((flag = fcntl(fd, F_GETFD)) < 0) 
            err_sys("fcntl error");
        else
            printf("FD_CLOEXEC flag have turned on  in  child\n");
        if ((dp = fdopendir(fd)))
        {
            while ((dirt = readdir(dp)))
            {
                printf("%s\n", dirt->d_name);
            }
            printf("\n");
        }
        else
            err_sys("fopendir error child");
        
        exit(0);
    }
    else
    {
        sleep(3);
        if ((flag = fcntl(fd, F_GETFD)) < 0)
            err_sys("fcntl error");
        else
            printf("\n\n\nFD_CLOEXEC flag have turned on  in  parent\n");
        if ((dp = fdopendir(fd)))
        {
            while ((dirt = readdir(dp)))
            {
                printf("%s\n", dirt->d_name);
            }
            printf("\n");
        }
        else
            err_sys("fopendir error child");
    }

    exit(0);
}



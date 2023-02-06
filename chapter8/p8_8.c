#include"../apue.h"
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc, char *argv[])
{
    DIR             *dp = NULL;
    int             fd = 0,d_flag = -1;
    struct dirent   *dirp = NULL; 
    pid_t           pid = -2;
    char            buf[20];

    if (argc < 2)
        err_sys("Usage: %s directoryname",argv[0]);
    if (!(dp = opendir(argv[1])))
        err_sys("opendir error");
    fd = dirfd(dp);
    sprintf(buf,"%d  ",fd);
/*    if ((d_flag = fcntl(fd, F_GETFD, 0)) < 0)
        err_sys("fcntl error");
    if (d_flag & O_CLOEXEC)
        printf("close-on-exec of %s have turned on\n");
    else
        printf("close-on-exec of %s have turned off\n");
*/
    if((pid = fork()) < 0)
        err_sys("fork error");
    else if(pid == 0)
    {
        printf("\n\nCHILD:\n\n");
        if ((execl("/home/lei/apue/chapter8/p8_8child.out", "p8_8child.out", buf,(char *)0)) == -1)
        {
            perror("exec error");
        }
        exit(0);
    /*    if ((d_flag = fcntl(fd, F_GETFD, 0)) < 0)
            err_sys("child process catch d_flag failed, close-on-exec flag have turned on");
        else
            printf("close-on-exec have turn off\n");
        while (dirp = readdir(dp))
        {
            printf("%s\n",dirp->d_name);
        }
        printf("\n\n");

        close(fd);
        closedir(dp);
        exit(0);
    */     /* 子进程要调用exec才行 */
    }
    else
    {
        sleep(2);
        printf("\nparent\n");
        if ((d_flag = fcntl(fd, F_GETFD, 0)) < 0)
            err_sys("fcntl error");
        if (d_flag & FD_CLOEXEC)         /* 一开始用的O_CLOEXEC不对 */
            printf("close-on-exec of %s have turned on\n",argv[1]);
        else
            printf("close-on-exec of %s have turned off\n",argv[1]);
        while (dirp = readdir(dp))
        {
            printf("%s\n",dirp->d_name);
        }
        printf("\n\n");

        close(fd);
        closedir(dp);
    }

    return 0;
}

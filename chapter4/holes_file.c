#include"../apue.h"
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void)
{
    int fd;

    fd = open("holesfile3.txt", O_RDWR | O_CREAT, 0777);
    if (fd == -1)
        err_ret("open failed");

    write(fd,"hello",sizeof("hello"));
    lseek(fd,14096,SEEK_CUR);
    write(fd,"hello",sizeof("hello"));
    lseek(fd,14096,SEEK_CUR);
    write(fd,"hello",sizeof("hello"));
    lseek(fd,14096,SEEK_CUR);

    close(fd);

    exit(0);
}

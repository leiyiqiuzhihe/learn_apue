#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>


int main(int argc, char **argv)
{
    int fd;

    if (argc != 2)
    {
        printf("usage:./a.out <filename>\n");
        exit(EXIT_FAILURE);
    }
    if ((fd = open(argv[1], O_RDWR | O_CREAT, 0444)) >= 0)
    {
        write(fd,"你好\n",sizeof("你好"));
        close(fd);
    }
    else
    {
        printf("open %s failed",argv[1]);
    }

    return 0;
}

#include"../apue.h"
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    int     status;
    struct stat    *buf = NULL;

    if ((status = stat(argv[1],buf)) != -1)
    {
        printf("stat OK\n");
    }
    else
        perror("stat");

    return 0;
}

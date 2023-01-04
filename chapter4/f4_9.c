#include"../apue.h"
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

#define RWRWRW  (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)

int main(void)
{
    mode_t i;

    i = umask(0);
    printf("current umask is 0, previous is %o \n",i);
    if (creat("foo", RWRWRW) < 0)
        err_sys("creat error for foo");
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    if (creat("bar", RWRWRW) < 0)
        err_sys("creat error for bar");
    exit(0);
}

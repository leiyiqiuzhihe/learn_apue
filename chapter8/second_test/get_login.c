#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{
    char    *log_name = NULL;

    if (!(log_name = getlogin()))
    {
        perror("getlogin");
        exit(1);
    }

    printf("current login name: %s\n", log_name);

    return 0;
}

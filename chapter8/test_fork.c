#include<stdio.h>
#include<unistd.h>

int main(void)
{
    pid_t pid;

    pid = fork();

flag:
    printf("hello, world\n");

    if (pid == 0)
    {
        sleep(1);
        printf("after sleep,");
        goto flag;
    }
    else if (pid > 0)
        printf("I am parent\n");
    else
        perror("fork");

    return 0;
}

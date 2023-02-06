#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>


int main(void)
{
    pid_t   pid;

    pid = fork();

    if (pid > 0)
    {
        pid = fork();
        printf("%d\n", pid);
        if (pid > 0)
        {
                while(1)
                {
                    printf("I am parent %d\n", getpid());
                    printf("My parent is %d\n", getppid());
                    sleep(1);
                }
        }
    }

    else if (pid == 0)
    {
        while (1)
        {
            printf("I am child %d\n",getpid());
            printf("My parent is %d\n", getppid());
            sleep(1);
        }
    }
    else
    {
        perror("fork");
        exit(1);
    }

    return 0;
}

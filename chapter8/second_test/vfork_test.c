#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int     global;

int main(void)
{
    int     a = 0;
    pid_t   pid;

    global = 5;
    if ((pid = vfork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0)
    {
        int b = 5;

        printf("address of global is: %p\n", &global);
        printf("address of a      is: %p\n", &a);
        a = 2;
        printf("\naddress of a      is: %p\n", &a);
        printf("address of b      is: %p\n", &b);
        printf("address of pid    is: %p\n", &pid);

        exit(0);
    }
    else
    {
        if (pid != wait(&a))
        {
            printf("wait error");
        }
        printf("\n\naddress of global is: %p\n", &global);
        printf("address of a      is: %p\n", &a);
        printf("address of pid    is: %p\n", &pid);
    }
    
    return 0;
}

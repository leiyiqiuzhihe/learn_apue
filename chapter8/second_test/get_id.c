#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


int main(void)
{
    /*pid_t       parent_id, child_id;
    uid_t       p_uid, c_uid, p_euid, c_euid;
    gid_t       p_gid, c_gid, p_egid, c_egid; */
    int         status = 0;
    pid_t       pid;


    if ((pid = fork()) < 0)
    {
        perror("fork");
        exit(1);
    }
    else if (pid == 0)
    {
        printf("\n\nchild:\n");
        printf("uid = %ld\n",(long)getuid());
        printf("gid = %ld\n", (long)getgid());
        printf("euid = %ld\n", (long)geteuid());
        printf("egid = %ld\n", (long)getegid());
        printf("pid = %ld\n", (long)getpid());
        printf("parent_id = %ld\n",(long)getppid());

    }
    else
    {
        if ((wait(&status)) == -1)
        {
            perror("wait");
            exit(1);
        }
        printf("\n\nchild:\n");
        printf("uid = %ld\n",(long)getuid());
        printf("gid = %ld\n", (long)getgid());
        printf("euid = %ld\n", (long)geteuid());
        printf("egid = %ld\n", (long)getegid());
        printf("pid = %ld\n", (long)getpid());
        printf("parent_id = %ld\n",(long)getppid());
    }
    return 0;
}

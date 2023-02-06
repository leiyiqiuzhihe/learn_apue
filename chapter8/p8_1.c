#include"../apue.h"
#include<unistd.h>
#include<sys/types.h>

int     globvar = 6;         /* external variable in initialized data */
char    buf[] = "a write to stdout\n";

int main(void)
{
    int     var;             /* automatic variable on stack */
    pid_t   pid;
    int     i;
    char    buffer[20] = {0};

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    fputs("before fork ",stdout);  /* we don't flush stdout */

    if ((pid = vfork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {
        globvar++;
        var++;
        fclose(stdout);
        exit(0);
    }
    else
        sleep(2);

    i = printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);
    sprintf(buffer, "%d\n",i);
    write(STDOUT_FILENO, buffer, strlen(buffer));

    exit(0);
}

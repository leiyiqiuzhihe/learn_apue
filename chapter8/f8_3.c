#include"../apue.h"

int     globvar = 6;         /* external variable in initialized data */
char    buf[] = "a write to stdout\n";

int main(void)
{
    int     var;             /* automatic variable on stack */
    pid_t   pid;

    var = 88;
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
        err_sys("write error");
    sleep(2);
    fputs("before fork ",stdout);  /* we don't flush stdout */

    if ((pid = vfork()) < 0)
    {
        err_sys("fork error");
    }
    else if (pid == 0)
    {
        sleep(2);
        globvar++;
        var++;
        exit(0);
    }

    printf("pid = %ld, glob = %d, var = %d\n", (long)getpid(), globvar, var);

    exit(0);
}

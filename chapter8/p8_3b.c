#include"../apue.h"
#include<sys/wait.h>

extern void pr_signal(siginfo_t *);

int main(void)
{
    int         test = 0;
    pid_t       pid;
    siginfo_t   sig_status;

    /* for exit, _exit, Exit */
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        exit(7);

    if (waitid(P_PID, pid, &sig_status, WEXITED | WSTOPPED | WCONTINUED) == -1)
        err_sys("wait error");
    pr_signal(&sig_status);


    /* for signal */
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        abort();

    if (waitid(P_PID, pid, &sig_status, WEXITED | WSTOPPED | WCONTINUED) == -1)
        err_sys("wait error");
    pr_signal(&sig_status);

    /* for signal */
    if ((pid = fork()) < 0)
        err_sys("fork error");
    else if (pid == 0)
        test /= 0;


    if (waitid(P_PID, pid, &sig_status, WEXITED | WSTOPPED | WCONTINUED) == -1)
        err_sys("wait error");
    pr_signal(&sig_status);

    exit(0);
}

#include"../apue.h"
#include<sys/wait.h>

/* void pr_exit(int status)
{
    if (WIFEXITED(status))
        printf("normal termination, exit status = %d\n",
                WEXITSTATUS(status));
    else if (WIFSIGNALED(status))
        printf("abnormal termination, signal number = %d %s\n",
                WTERMSIG(status),
#ifdef  WCOREDUMP
                WCOREDUMP(status) ? " (core file generated)" : "");
#else
                "");
#endif
    else if (WIFSTOPPED(status))
        printf("child stopped, signal number = %d\n",
                WSTOPSIG(status));
} */


void pr_signal(siginfo_t *sigi)
{
    int sig_code = 0;
    int sig_status = 0;

    sig_code = sigi->si_code;
    sig_status = sigi->si_status;

    switch (sig_code)
    {
        case CLD_EXITED:
            printf("normal termination,exit status = %d\n",sig_status);
            break;

        case CLD_KILLED:

        case CLD_DUMPED:

        case CLD_TRAPPED:

        case CLD_CONTINUED:
            printf("abnormal termination, signal number = %d\n",sig_status);
    }
}

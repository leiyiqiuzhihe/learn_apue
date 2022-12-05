#include"apue.h"
#include<errno.h>          /* for definition of errno */
#include<stdarg.h>         /* ISO C variable arguments */

static void err_doit(int, int , const char *, va_list);

/*
 * Nonfatal error related to a system call.
 * print a message and return.
 */

void  err_ret(const char *fmt, ...)
{
    va_list   ap;

    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
}

/*
 * Fatal error ralated to a system call.
 * Print a message and terminate.
 */
void  err_sys(const char *fmt, ...)
{
    va_list ap;

    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    exit(1);
}

/*
 * Nonfatal error unrelated to a system call.
 * Error code passed as explicit parameter.
 * Print a message and return.
 */

void err_cont(int error, const char *fmt, ...)
{
    va_list   ap;

    va_start(ap,fmt);
    err_doit(1,error,fmt,ap);
    va_end(ap);
}

/*
 * Fatal errot unrelated to a system call.
 * Error code passed as explicit parameter.
 * Print a message and return.
 */

void err_exit(int error,const char *fmt, ...)
{
    va_list   ap;
    
    va_start(ap,fmt);
    err_doit(1,error,fmt,ap);
    va_end(ap);
    exit(1);
}

/*
 * Fatal error related to a system call.
 * Print a message, dump core, and terminate.
 */
void err_dump(const char *fmt, ...)
{
    va_list   ap;

    va_start(ap,fmt);
    err_doit(1,errno,fmt,ap);
    va_end(ap);
    abort();        /*dump core and terminate*/
    exit(1);        /*sholdn't get here*/
}

/*
 * Nonfatal error unrelated to a system call.
 * Print a message and return.
 */
void err_msg(const char *fmt, ...)
{
    va_list  ap;


    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
}

/*
 * Fatal errot unrelated to a system call.
 * *Print a message and terminate.
 */
void err_quit(const char *fmt, ...)
{
    va_list  ap;

    va_start(ap,fmt);
    err_doit(0,0,fmt,ap);
    va_end(ap);
    exit(1);
}


/*
 * Print a message and return to caller.
 * Caller specifies "errorflag".
 */
static void err_doit(int errnoflag, int error, const char *fmt, va_list ap)
{
    char buf[MAXLINE];

    vsnprintf(buf,MAXLINE-1,fmt,ap);
    if (errnoflag)
        snprintf(buf+strlen(buf), MAXLINE-strlen(buf)-1,": %s",
                        strerror(error));
    strcat(buf,"\n");
    fflush(stdout);   /*in case stderr and stdout are the same*/
    fputs(buf,stderr);
    fflush(NULL);            /*flush all stdio output stream*/
}

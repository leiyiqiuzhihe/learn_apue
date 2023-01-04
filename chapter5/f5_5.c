#include"../apue.h"
#include<time.h>

int main(void)
{
    char buf[MAXLINE];
    clock_t start, finish;
    double  total_time;

    start = clock();
    while (fgets(buf, MAXLINE, stdin) != NULL)
        if (fputs(buf, stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");
    finish = clock();
    total_time = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time to do this cp: %.2f\n", total_time);


    exit(0);
}

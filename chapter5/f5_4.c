#include"../apue.h"
#include<time.h>


int main(void)
{
    int c;
    clock_t start, finish;
    double  total_time;

    start = clock();
    while ((c = getc(stdin)) != EOF)
        if (putc(c,stdout) == EOF)
            err_sys("output error");

    if (ferror(stdin))
        err_sys("input error");
    finish = clock();

    total_time = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("Time to do my cp: %f\n", total_time);

    exit(0);
}

#include<stdio.h>
#include<time.h>
#define MAXSIZE  60


int main(void)
{
    time_t  temp = 0;
    struct tm   *tmp = 0;
    char buf[MAXSIZE];

    time(&temp);
    printf("size of time_t is: %zd\n", sizeof(temp));
    if ((tmp = localtime(&temp)))
    {
        if (strftime(buf, MAXSIZE,"time and date: %T, %a %b %d, %Y",tmp))
            printf("%s\n", buf);
        else
            printf("strftime failed\n");
    }
    else
        printf("gmtime failed\n");
    printf("value of tm_isdst:%d\n",tmp->tm_isdst);

    return 0;
}

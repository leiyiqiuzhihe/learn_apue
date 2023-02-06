#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char    *str_tz;

    if (!(str_tz = getenv("LS_COLORS")))
    {
        perror("getenv failed");
    }

    printf("address of ENV_NAME is: %p\n",str_tz);
    printf("address of str_tz is: %p\n", &str_tz);
    printf("%s\n",str_tz);

    return 0;
}

#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    char *str = "hello";

    *str = "H";
    printf("%s\n",str);

    return 0;
}

#include<stdio.h>

#define SIZE  80


int main(void)
{
    char arr[SIZE];
    char *str = "hello world";

    printf("size of arr is %zd\n",sizeof(arr));
    printf("size of str is %zd\n",sizeof(str));

    return 0;
}

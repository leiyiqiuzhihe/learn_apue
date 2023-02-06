#include<stdio.h>

int main(int argc, char *argv[])
{
    int     b, a = 2;
    static int     c;
    char    s[4096];
    char    *p2;

    if (argc < 2)
        printf("Usage %s <string1> ...\n", argv[0]);
    printf("addr of argv : %p\n",argv);
    printf("addr of main : %p\n",main);
    printf("address of  b: %p\n",&b);
    printf("address of  a: %p\n", &a);
    printf("address of  c: %p\n", &c);
    printf("value of    s: %p\n",s);
    printf("address of  s；%p\n",&s);
    printf("value of   p2: %p\n", p2);
    printf("address of p2: %p\n",&p2);

    return 0;
}

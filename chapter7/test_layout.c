#include<stdio.h>
#include<stdlib.h>

#define SIZE 20
int called_func(void);

int     maxcount = 99;
int     minicount = 22;
char    sum[4096];
int     num;


int main(void)
{
    int m_t;
    char    *m_str = "hello world";
    char    m_char[SIZE];
    char    *m_temp = NULL;

    if (!(m_temp = malloc(SIZE)))
        perror("malloc failed");
    printf("address of m_t is:%p\n",&m_t);
    printf("address of m_char is:%p\n", m_str);
    printf("address of m_str is:%p\n", m_char);
    printf("address of main is:%p\n", &main);
    printf("address of called_func is:%p\n\n\n", &called_func);
    printf("address of m_temp is: %p\n\n",m_temp);
    printf("address of maxconut is: %p     data\n", &maxcount);
    printf("address of minicount is: %p\n",&minicount);
    printf("address of sum is: %p          bss\n",sum);
    printf("address of num is: %p\n", &num);
    called_func();

    return 0;
}


int called_func(void)
{
    int c_t;
    char    *c_str = "hello world";
    char    c_char[SIZE];
    char    *c_temp = NULL;

    if (!(c_temp = (char *)malloc(SIZE)))
        perror("c_temp malloc failed");
    printf("address of c_t is:%p\n",&c_t);
    printf("address of c_char is:%p\n", c_str);
    printf("address of c_str is:%p\n", c_char);
    printf("address of called_func is:%p\n", &called_func);
    printf("address of c_temp is: %p\n",c_temp);

    return 0;
}


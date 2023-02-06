#include"../apue.h"


int main(int argc, char *argv[])
{
    int i = 0;

    if (argc < 2)
    {
        printf("Usage:%s argv1...\n",argv[0]);
        exit(1);
    }
    for (i = 0; i < argc; i++)
        printf("argv[%d]: %s\n", i, argv[i]);


    exit (0);
}

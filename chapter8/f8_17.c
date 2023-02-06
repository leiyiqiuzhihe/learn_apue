#include"../apue.h"


int main(int argc, char *argv[])
{
    int             i = 0;
    char            **ptr = NULL;
    extern  char    **environ;
    for(i = 0; i < argc; i++)
        printf("%s\n",argv[i]);
 
    {
        printf("\nenvironment:\n");
        for(ptr = environ; *ptr != NULL; ptr++)
            printf("%s\n",*ptr);

    }
    return 0;
}

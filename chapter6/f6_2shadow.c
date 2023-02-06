#include"../apue.h"
#include<shadow.h>
#include<stddef.h>
#include<string.h>

struct spwd * getspnam(const char *name);

int main(int argc, char *argv[])
{
    int n = 0;
    struct spwd *spawd = NULL;

    if (1 == argc)
    {
        printf("Usage:%s <user name> ...\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    for (n = 1; n < argc; n++)
    {
        if (spawd = getspnam(argv[n]))
        {
            printf("Encrypted password of %s:%s\n",argv[n],spawd->sp_pwdp);
        }
        else
        {
            printf("getspnam(%s) failed\n",argv[n]);
            continue;
        }
    }
    
    return 0;
}


struct spwd * getspnam(const char *name)
{
    struct spwd *ptr;

    setspent();
    while ((ptr = getspent()) != NULL)
    {
        if (strcmp(name, ptr->sp_namp) == 0)
            break;          /* found a match */
    }
    endspent();
    return (ptr);      /* ptr is NULL if no match found */
}

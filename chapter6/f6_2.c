#include"../apue.h"
#include<pwd.h>
#include<stddef.h>
#include<string.h>

struct passwd * getpwnam(const char *name);

int main(int argc, char *argv[])
{
    int n = 0;
    struct passwd *pawd = NULL;

    if (1 == argc)
    {
        printf("Usage:%s <user name> ...\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    for (n = 1; n < argc; n++)
    {
        if (pawd = getpwnam(argv[n]))
        {
            printf("Encrypted password of %s:%s\n",argv[n],pawd->pw_passwd);
        }
        else
        {
            printf("getpwnam(%s) failed\n",argv[n]);
            continue;
        }
    }
    
    return 0;
}


struct passwd * getpwnam(const char *name)
{
    struct passwd *ptr;

    setpwent();
    while ((ptr = getpwent()) != NULL)
    {
        if (strcmp(name, ptr->pw_name) == 0)
            break;          /* found a match */
    }
    endpwent();
    return (ptr);      /* ptr is NULL if no match found */
}

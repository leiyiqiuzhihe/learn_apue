#include"../apue.h"

int main(void)
{
    char    name[L_tmpnam], line[MAXLINE];
    char    *nontemp = 0;
    FILE    *fp;

    printf("%s\n",tmpnam(NULL));
    tmpnam(name);
    nontemp = tmpnam(nontemp);
    printf("nontemp is %s\n",nontemp);
    printf("%s\n",name);
    printf("address for main: %p\naddress for name: %p\n",&main, &name);
    printf("value of nontemp is: %p\n",nontemp);

    if ((fp = tmpfile()) == NULL)
        err_sys("tmpfile error");
    fputs("one line of output\n",fp);
    rewind(fp);
    if (fgets(line,sizeof(line),fp) == NULL)
        err_sys("fgets error");
    fputs(line, stdout);

    exit(0);
}

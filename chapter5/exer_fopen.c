#include<stdio.h>

int main(int argc, char *argv[])
{
    FILE *fp;

    if (argc != 2)
    {
        printf("Usage: %s <filename>\n",argv[0]);
        return -1;
    }

    fp = fopen(argv[1],"w+");
    printf("%s opened\n",argv[1]);
    fwrite("hello world",sizeof("hello world")+1,1,fp);
    printf("written \n");
    fclose(fp);

    return 0;
}

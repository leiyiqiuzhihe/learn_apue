//总结：open时有必选项和可选项，sizeof有以前没有注意到的地方，看一此处的test
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

#define SIZE 4096


int main(void)
{
    int wn = 0;
    int rn = 0;
    char buffer[SIZE] = {0};
    int fd = open("hello.txt",O_APPEND | O_RDWR);
    long cur_pos = lseek(fd,0,SEEK_CUR);

    rn = read(fd,buffer,SIZE);
    printf("read %d characters\n",rn);
    printf("%s\n",buffer);
    cur_pos = lseek(fd,0,SEEK_SET);

    wn = write(fd,buffer,sizeof(buffer));
    printf("\nwrite %d characters",wn);
    printf("\nAfter write\n");
    cur_pos = lseek(fd,5,SEEK_CUR);
    cur_pos = lseek(fd,0,SEEK_SET);
    rn = read(fd,buffer,SIZE);
    printf("second read %d characters\n",rn);
    printf("%s\n position is %ld after write\n",buffer,cur_pos);

    return 0;
}

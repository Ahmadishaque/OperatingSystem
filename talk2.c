#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
//#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd1;
    char fifo1[]={"/home/g_2020itb098/fifo1"};
    mkfifo(fifo1, 0666);
    char s1[100], s2[100];
    while(1){
        fd1 = open(fifo1, O_RDONLY);
        read(fd1, s1, 100);
        printf("User1: %s\n", s1);
        close(fd1);

        fd1=open(fifo1, O_WRONLY);
        fgets(s2, 100, stdin);
        write(fd1, s2, 100);
        close(fd1);
    }
    return 0;
}

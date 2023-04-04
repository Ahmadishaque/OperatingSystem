#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
//#include <sys/types.h>
#include <unistd.h>

int main(){
    int fd;
    char fifo1[]={"/home/g_2020itb098/fifo1"};
    mkfifo(fifo1, 0666);
    char s1[100], s2[100];
    while(1){
        fd=open(fifo1, O_WRONLY);
        fgets(s1, 100, stdin);
        write(fd, s1, 100);
        close(fd);
    
        fd = open(fifo1, O_RDONLY);
        read(fd, s2, 100);
        printf("User2: %s\n", s2);
        close(fd);
    }
    return 0;
}

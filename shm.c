#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <sys/wait.h>

int main()
{
    char buff[5];
    int shmid = shmget((key_t)1122,1024,0666|IPC_CREAT);
    char* addr = (char*)shmat(shmid, 0 ,0);

    pid_t child1 = fork();
    if(child1==0){
        fgets(buff, sizeof(buff), stdin);
    }

    int i;
    sscanf(addr, "%d", &i);

    if(child1!=0){
        wait(NULL);
        if(i%4 == 0)
            printf("%d is leap year.", i);
        else
            printf("%d is not a leap year.", i);
    }
    shmdt(addr);
    return 0;
}
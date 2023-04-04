#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int fib(int n){
    if(n<2)
        return n;
    pid_t child1, child2;
    int x, y;
    int status, a, b;

    child1=fork();
    if(child1==0){
        x = fib(n-1);
        exit(x);
    }
    child2=fork();
    if(child2==0){
        y = fib(n-2);
        exit(y);
    }
    waitpid(child1, &status, 0);
    a = WEXITSTATUS(status);
    waitpid(child2, &status, 0);
    b = WEXITSTATUS(status);
    int ans = a+b;
    return ans;
}

int main(){
    int i;
    pid_t pid = getpid();
    printf("Enter the number: ");
    scanf("%d", &i);
    printf("%d", fib(i));
    return 0;
}
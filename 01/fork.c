#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){
    pid_t pid;
    pid = fork();
    int x = 100;
    printf("main x=%d\n",x);
    if(pid<0){
        fprintf(stderr,"fork() error");
        exit(1);
    }else if(pid==0){
        sleep(5);
        printf("child process x=%d\n",x);
    }else{
        printf("parent process x=%d\n",x);
    }
    printf("Main process\n");

    return 0;
}


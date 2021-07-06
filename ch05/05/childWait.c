#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    int fd;
    
    fd = fork();
    if(fd<0){
        fprintf(stderr,"fork() error");
        exit(1);
    } else if(fd==0){
        int status;
        int mywait = wait(&status);
        printf("wait return : %d\n",mywait);
    } else{
        printf("parent PID: %d\n",(int)getpid());

    }

    return 0;
}

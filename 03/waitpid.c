#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main(){
    pid_t pid;
    
    pid = fork();
    if(pid<0){
        fprintf(stderr,"fork error()");
        exit(1);   // 退出主进程
    } else if(pid==0){
        printf("hello\n");
    }else{
        int status;
        while(!waitpid(-1, &status,WNOHANG));  // 一直循环，直到子进程退出
        
        printf("goodbye\n");
    }
    


    return 0;
}
